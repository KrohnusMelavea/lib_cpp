#define _FILE_OFFSET_BITS 64

#include "stl/heap_buffer.hpp"
#include "stl/dynamic_array.hpp"
#include "file_sharer.hpp"
#include "file/path_ops.hpp"
#include "file/byte_reader.hpp"
#include "file/byte_writer.hpp"
#include <cstdio>
#include <format>

namespace net {
    file_sharer::file_sharer(socket const& socket) noexcept : m_socket{socket} {

    }

    void file_sharer::send_file(std::string_view const file_path) const noexcept {
        i32 result;

        auto const relative_file_path = file::path_to_filename(file_path);
        stl::heap_buffer header_buffer(sizeof(std::size_t) + std::size(relative_file_path) + 1 + sizeof(std::size_t));
        std::size_t header_size = *new(std::data(header_buffer)) std::size_t(std::size(header_buffer));
        (void)std::memcpy(reinterpret_cast<u08*>(std::data(header_buffer)) + sizeof(std::size_t), std::data(relative_file_path), std::size(relative_file_path) + 1);
        std::FILE* file;
        auto err = ::fopen_s(&file, std::data(file_path), "rb");
        auto const file_start = _ftelli64(file);
        result = _fseeki64(file, 0, SEEK_END);
        if (result != 0) [[unlikely]] {

        }
        std::size_t file_size = *new(reinterpret_cast<u08*>(std::data(header_buffer)) + sizeof(std::size_t) + std::size(relative_file_path) + 1) std::size_t(static_cast<std::size_t>(_ftelli64(file)));
        result = _fseeki64(file, file_start, SEEK_SET);
        if (result != 0) [[unlikely]] {

        }

        std::expected<u32, socket_error_code> send_result;
        send_result = m_socket.send(stl::buffer(header_buffer));
        if (!send_result && send_result.value() != std::size(header_buffer)) [[unlikely]] {
            
        }

        static constexpr std::size_t chunk_size = 8192;
        stl::heap_buffer buffer(chunk_size);
        file::byte_reader byte_reader(file);
        std::size_t sent = 0;
        while (sent < file_size) {
            auto [read_count, error_code] = byte_reader.read(stl::buffer(buffer));

            send_result = m_socket.send(stl::buffer{ std::data(buffer), read_count });
            if (!send_result) [[unlikely]] {
                break;
            }
            if (send_result.value() != read_count) [[unlikely]] {
            }
            sent += send_result.value();
        }
        ::fclose(byte_reader.file_handle());
    }
    void file_sharer::receive_file(std::string_view const path) const noexcept {
        std::expected<u32, socket_error_code> receive_result;
        
        std::size_t header_size;
        receive_result = m_socket.receive(stl::buffer{ &header_size, sizeof(std::size_t) });

        stl::dynamic_array<char> relative_file_path_buffer(header_size - sizeof(std::size_t) - sizeof(std::size_t));
        receive_result = m_socket.receive(stl::buffer{ std::data(relative_file_path_buffer), std::size(relative_file_path_buffer) });
        std::string file_path = std::string(path) + std::string(std::data(relative_file_path_buffer));

        std::size_t file_size;
        receive_result = m_socket.receive(stl::buffer{ &file_size, sizeof(std::size_t) });

        static constexpr std::size_t chunk_size = 8192;
        stl::heap_buffer file_contents_buffer(chunk_size);
        file::byte_writer byte_writer(file_path);
        std::size_t received = 0;
        while (received < file_size) {
            receive_result = m_socket.receive(stl::buffer{ std::data(file_contents_buffer), std::size(file_contents_buffer) });
            if (!receive_result) [[unlikely]] {
                break;
            }
            auto [write_count, error_code] = byte_writer.write(stl::buffer{ std::data(file_contents_buffer), receive_result.value() });
            if (write_count != receive_result.value()) [[unlikely]] {

            }
            received += write_count;
        }
        ::fclose(byte_writer.file_handle());
    }
}