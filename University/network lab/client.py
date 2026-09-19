import socket

HOST = "127.0.0.1"
PORT = 5000

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client_socket.connect((HOST, PORT))

print(f"Connected to server {HOST}:{PORT}")

while True:
    message = input("You: ")

    if message == "exit":
        break

    client_socket.send(message.encode())

client_socket.close()