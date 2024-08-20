import urllib3

response = urllib3.request("GET", "http://localhost:9999/Product")
print(response.data)
