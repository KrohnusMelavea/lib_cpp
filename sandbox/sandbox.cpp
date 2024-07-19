#include "types.hpp"
#include "net/socket.hpp"

#include <spdlog/spdlog.h>

int main() {
 net::socket::init_backend();

 net::socket server;

 server.bind(net::convert_ipv4_string_to_u32("127.0.0.1"), 6969);
 server.listen();

 net::socket client;
 client.connect(net::convert_ipv4_string_to_u32("127.0.0.1"), 6969);
 
 auto server_client_maybe = server.accept();
 auto server_client = server_client_maybe.value;

 server_client.send("testing");

 char data[8];
 client.receive({data, 8});

 SPDLOG_INFO("{}", data);

 client.close();
 server.close();

 //net::socket::deinit_backend();
}