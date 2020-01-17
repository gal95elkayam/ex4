//
// Created by gal on 08/01/2020.
//

#include "ClientHandler.h"

#ifndef EX4_SERVER_H
#define EX4_SERVER_H


using namespace std;

namespace server_side{

    class Server {
    public:
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void stop(int sockfd) = 0;
        virtual ~Server() {}
    };
}
#endif //EX4_SERVER_H
