#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    const std::string serverIP = "10.0.2.15"; 
    const int port = 12345;

    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket.\n";
        return 1;
    }

    // Prepare the sockaddr_in structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid address/Address not supported.\n";
        return 1;
    }

    // Connect to server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection failed.\n";
        return 1;
    }

    std::cout << "Connected to server.\n";

    // Send message to server
    std::string message = "Hello from client!";
    send(clientSocket, message.c_str(), message.length(), 0);
    std::cout << "Message sent to server.\n";

    // Receive message from server
    char buffer[1024] = {0};
    int valread = read(clientSocket, buffer, 1024);
    std::cout << "Received: " << buffer << std::endl;

    // Close connection
    close(clientSocket);

    return 0;
}

