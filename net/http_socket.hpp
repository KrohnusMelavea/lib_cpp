#include "socket.hpp"
#include "socket_error_code.hpp"
#include "stl/status_type.hpp"
#include "stl/dynamic_array.hpp"

namespace net {
 class http_socket {
 public:
  http_socket(u32 const address, u16 const port);
  ~http_socket();
 };
}