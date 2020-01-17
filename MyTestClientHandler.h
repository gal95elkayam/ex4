//
// Created by gal on 09/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#define BUFFER_SIZE 1024

#include <strings.h>
#include <zconf.h>
#include <cstring>
#include <iostream>
#include "CacheManager.h"
#include "Solver.h"
#include "ClientHandler.h"
//#include "Solver.h"


template <class Problem,class Solution>
class MyTestClientHandler: public ClientHandler {
private:
    Solver<Problem, Solution> *_solver;
    CacheManager<Problem, Solution> *_manager;
public:
    virtual ~MyTestClientHandler() {}
    MyTestClientHandler(Solver<Problem, Solution> *solver, CacheManager<Problem, Solution> *manager) {
        _solver = solver;
        _manager = manager;
    }
    void handleClient(int socketId) {
        string line = "";
        string solutionFromFile;
        string solutionFromSolve;
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);
        while (true) {
            //read from socket until you you get "end"
            line = readFromSocket(socketId, buffer, BUFFER_SIZE);
            if (line.find("end") != string::npos) {
                return;
            }
            bzero(buffer, BUFFER_SIZE);
            //check if we have a solution
            if (_manager->containsSolution(&line)) {
                solutionFromFile = _manager->getSolution(&line);
            } else {
                string temp = line;
                //solve the problem
                solutionFromSolve = _solver->solve(&line);
                //update the cache and the file
                _manager->saveSolution(&temp, solutionFromSolve);
            }
            //write Solution To Socket
            const char *solution = solutionFromFile.c_str();
            int n = write(socketId, solution, strlen(solution));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            bzero(buffer, BUFFER_SIZE);
        }
    }
    string readFromSocket(int socketId, char *buffer, int size) {
        string line;
        auto n = read(socketId, buffer, size);
        if (n < 0) {
            cout << strerror(errno);
        }
        line = buffer;
        return line;
    }

};


#endif //EX4_MYTESTCLIENTHANDLER_H
