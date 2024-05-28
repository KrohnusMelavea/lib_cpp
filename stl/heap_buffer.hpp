#pragma once

#include "types.hpp"
#include "stl/buffer.hpp"
#include <span>
#include <cstdlib>
#include <utility>
#include <spdlog/spdlog.h>

#undef free

namespace stl {
    class heap_buffer {
    public:
        heap_buffer() noexcept;
        heap_buffer(std::size_t const size) noexcept;
        heap_buffer(stl::buffer const& data) noexcept;
        heap_buffer(heap_buffer const& heap_buffer) noexcept;
        heap_buffer(heap_buffer&& heap_buffer) noexcept;
        ~heap_buffer() noexcept;

        heap_buffer& operator=(heap_buffer const& heap_buffer) noexcept;
        void operator=(heap_buffer&& heap_buffer) noexcept;

        operator stl::buffer() const noexcept;

        void free() noexcept;
        void* release() noexcept;

        void* data() noexcept;
        void* data() const noexcept;
        std::size_t size() const noexcept;

    private:
        stl::buffer m_data;
    };
}