# Simple C++ Client-Server Program with Sockets
This repository contains a basic implementation of a client-server program in C++ using sockets. The program demonstrates how to create a simple server that listens for incoming connections and a client that connects to the server. The client and server can exchange messages over the network.ONLY WORKS FOR LINUX:]

# Introduction
This C++ client-server program illustrates the concept of socket programming, which enables communication between processes over the network. The program consists of two parts:

    Server: The server listens on a specified port for incoming connections from clients. Once a client connects, the server can receive and send messages to the client.

    Client: The client connects to the server using the server's IP address and port number. Once connected, the client can send messages to the server and receive messages from it

# Prerequisites
to run this program, you will need:
    1.C++ compiler (supporting C++11 or higher)
    2.Linux-based system
    
# How to Use

Clone this repository to your local machine:
 git clone https://github.com/elizamirzoyan/Task3.git
 cd Task3
 
 Compile the server and client files separately:
  g++ server.cpp -o server
  g++ client.cpp -o client

  
Run the server:
./server

In a separate terminal, run the client:
./client
