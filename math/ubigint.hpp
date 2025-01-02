#include "types.hpp"
#include "stl/cvt/to_hex_string.hpp"
#include <ranges>
#include <string>
#include <type_traits>

namespace math {
 template <std::size_t byte_count> 
 class ubigint {
 public:
  constexpr ubigint() noexcept : 
   m_data{} 
  {

  }
  constexpr ubigint(std::unsigned_integral auto const n) noexcept {
   (void)std::copy(
    reinterpret_cast<u08 const*>(&n),
    reinterpret_cast<u08 const*>(&n) + sizeof(n),
    std::begin(this->m_data));
   std::fill(
    std::next(
     std::begin(this->m_data),
     sizeof(n)),
    std::end(this->m_data),
    0);
  }

  constexpr std::size_t size() const noexcept { 
   return byte_count;
  }
  template <class Self> 
  constexpr auto&& data(this Self&& self) noexcept { 
   return &std::forward<Self>(self).m_data; 
  }

  constexpr std::string to_hex_string() const noexcept {
   auto end_it = std::find(
    std::begin(this->m_data),
    std::end(this->m_data),
    '0');
   std::string str(
    std::distance(std::begin(this->m_data), end_it) * 2,
    '0');
   for (std::size_t i = 0, j = 0; i < std::size(this->m_data); ++i) {
    str[j++] = stl::cvt::HEX_LOOKUP[this->m_data[std::size(this->m_data) - i - 1] >> 4];
    str[j++] = stl::cvt::HEX_LOOKUP[this->m_data[std::size(this->m_data) - i - 1] & 15];
   }
   return str;
  }

 private:
  u08 m_data[byte_count];
 };
}