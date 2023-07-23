#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    const int port = 12345; 

    // creating a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket.\n";
        return 1;
    }

    // preparing the sockaddr_in structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    // binding
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error binding to port.\n";
        return 1;
    }

    // listennn
    listen(serverSocket, 3);
    std::cout << "Server started. Listening for connections...\n";

    // accepting incoming connection
    sockaddr_in clientAddr;
    int addrLength = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, (socklen_t*)&addrLength);
    if (clientSocket < 0) {
        std::cerr << "Error accepting connection.\n";
        return 1;
    }

    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(clientAddr.sin_addr), clientIP, INET_ADDRSTRLEN);
    std::cout << "Connection accepted from " << clientIP << std::endl;

    // receiving a message from client
    char buffer[1024] = {0};
    int valread = read(clientSocket, buffer, 1024);
    std::cout << "Received: " << buffer << std::endl;

    // sending a message to client
    std::string message = "Hello from server!";
    send(clientSocket, message.c_str(), message.length(), 0);
    std::cout << "Message sent to client.\n";

    // closing the connection
    close(clientSocket);
    close(serverSocket);

    return 0;
}

