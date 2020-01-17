//
// Created by gal on 08/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H


#include "Server.h"
#include "StringReverser.h"

class MySerialServer : public server_side::Server{
public:
    int sockfd;
    virtual void open(int port, ClientHandler* ch);
    virtual void stop(int sockfd);
    void Start(int port,ClientHandler* clientHandler);

};


#endif //EX4_MYSERIALSERVER_H
