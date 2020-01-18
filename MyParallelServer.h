//
// Created by gal on 17/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H


#include <vector>
#include <thread>
#include "Server.h"

class MyParallelServer: public server_side::Server{
vector<thread> m_threads;
ClientHandler* m_handler;

private:
static void clientHandlerObjectFunctionAdapter(ClientHandler* ch, int sockfd);

public:
MyParallelServer();
virtual ~MyParallelServer();

virtual void open(int port, ClientHandler* ch);
virtual void stop(int sockfd);


};


#endif //EX4_MYPARALLELSERVER_H
