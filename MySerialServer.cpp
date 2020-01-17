//
// Created by gal on 08/01/2020.
//

#include <string>
#include <netinet/in.h>
#include <iostream>
#include <strings.h>
#include <thread>
#include <cstring>
#include <zconf.h>
#include "MySerialServer.h"


void Start(int port, ClientHandler *pHandler);

using namespace std;
void MySerialServer:: open(int port, ClientHandler* clientHandler) {
    int newsockfd = -1;

    struct sockaddr_in serv_addr{}, client_addr{};
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        cerr << "Error opening socket" << endl;
        exit(-1);
    }
    // Bind IP_address to socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Error binding to address" << endl;
        this->stop(sockfd);
        exit(-2);
    }
    // only one can conncet.
    listen(sockfd, 1);
    thread t([clientHandler,port, this] { Start(port,clientHandler); });
    t.join();

}

void MySerialServer::Start(int port,ClientHandler* clientHandler) {
    struct sockaddr_in cli_addr;
    int newsockfd,clilen;
    clilen = sizeof(cli_addr);
    struct timeval tv;
    tv.tv_sec = 120;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    /* Accept actual connection from the client */
    while(true) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        if (newsockfd < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                break;
            }
            else {
                cerr << "Error accepting connection" << endl;
                cout << strerror(errno);
                break;
            }
        }
        clientHandler->handleClient(newsockfd);
    }
    // Close socket
    this->stop(sockfd);
    if (newsockfd != -1) {
        this->stop(newsockfd);
    }
}
/**
 * Close the server
 */
void MySerialServer:: stop(int sockfd) {
//    openCustumer = false;
    close(this->sockfd);
}
