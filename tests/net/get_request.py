import urllib3
import subprocess
import socket
import ssl


path = "c:\\se\\personal\\lib_cpp\\tests\\net\\"
#result = subprocess.run(f"openssl ecparam -name secp256r1 -genkey -noout -out {path}client-secp256r1-pri.pem")
with open(f"{path}client-secp256r1-pri.pem", "r") as file_handler:
 file_contents = file_handler.read()
 #print(file_contents)
#result = subprocess.run(f"openssl ec -in {path}client-secp256r1-pri.pem -pubout -out {path}client-secp256r1-pub.pem")
with open(f"{path}client-secp256r1-pub.pem", "r") as file_handler:
 file_contents = file_handler.read()
 #print(file_contents)


context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
context.set_ecdh_curve("prime256v1")
client = context.wrap_socket(socket.socket(socket.AF_INET, socket.SOCK_STREAM), server_hostname="localhost")
client.connect(("localhost", 443))
