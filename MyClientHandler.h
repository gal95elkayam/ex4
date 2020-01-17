//
// Created by gal on 15/01/2020.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H


//#include <vector>
//#include "CacheManager.h"
//#include "Solver.h"
//#include "ClientHandler.h"


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

#define CHARS_TO_WRITE 10000000000
#define CHARS_TO_BUFFER 100
class MyClientHandler: public ClientHandler {
    bool toStop;
    Solver<vector<vector<string>>, string> *solver;
    CacheManager<string, string> *cache_Manager;
    bool getOut(const string &line);
    void writeToServer(string sol, int sock_id);
    string getLineFromSocket(int sock_id);

public:
    MyClientHandler(Solver<vector<vector<string>>, string> *solver,
    CacheManager<string, string> *cache_Manager)
    : solver(solver), cache_Manager(cache_Manager) {
        this->toStop = true;
    };

    string getData(int sock_id);

    virtual void handleClient(int sock_id);

    vector<vector<string>> lexer(string input);
};


#endif //EX4_MYCLIENTHANDLER_H
