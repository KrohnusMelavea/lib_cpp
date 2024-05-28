#include "types.hpp"
#include <string>

namespace tests {
 template <std::size_t size> struct pod_struct {
  u08 data[size];
 };
 struct non_pod_struct {
  std::string data;
 };
}