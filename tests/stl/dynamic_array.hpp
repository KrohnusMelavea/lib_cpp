#include "tests/common.hpp"
#include "stl/dynamic_array.hpp"
#include <spdlog/spdlog.h>

namespace stl_tests {
 void dynamic_array_tests() {
  /* Allocation Test for POD */ { stl::dynamic_array<tests::pod_struct<8>> data(512); }
  /* Allocation Test for non-POD */ { stl::dynamic_array<tests::non_pod_struct> data(512); }
  /*  */
 }
}