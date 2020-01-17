//
// Created by gal on 15/01/2020.
//

#include <algorithm>
#include <cstring>
#include <zconf.h>
#include <regex>
#include "MyClientHandler.h"

vector<vector<string>> MyClientHandler::lexer(string input) {
    vector<vector<string >> after_lex;
    vector<string> vec_lex;
    string temp;
    regex number("[0-9.]*");
    smatch match_results;
    while (input.size() > 0) {
        if (input[0] == '\n') {
            input = input.substr(1, input.size());
            after_lex.push_back(vec_lex);
            temp = ""; // clear to list
            vec_lex.clear();
        } else if ((input[0] >= 48 && input[0] < 58)) {
            // if valid number or minus
            regex_search(input, match_results, number);
            for (unsigned i = 0; i < match_results.size(); ++i) {
                // TODO check the +=
                temp += temp + match_results.str(i);
            }
            vec_lex.push_back(temp);
            input = input.substr(temp.size(), input.size());
            temp = ""; // clear to list
        } else if ((input[0] >= 65 && input[0] <= 90) || (input[0] >= 97 && input[0] <= 122)) {
            // if a char- "end" - return and finish
            return after_lex;
        } else if (input[0] == 45) {

            temp = "-1";
            vec_lex.push_back(temp);
            input = input.substr(temp.size(), input.size());
            temp = "";

        } else {
            temp = ""; // clear to list
            input = input.substr(1, input.size());
        }
    }
    return after_lex;
}


//check if we have the problem in cache if not solved and save
void MyClientHandler::handleClient(int sock_id) {
    string solution;
    string problem;
    vector<vector<string>> data;
    problem = getData(sock_id);
    ///////////////////////////////
//    string problem_to_lexer = problem;
    // arrange the string problem
//    replace(problem.begin(), problem.end(), '\n', '%');
//    if (problem.back() == '%') {
//        problem.pop_back();
//    }
////////////////////////////////////
    // have problem
    if (this->cache_Manager->containsSolution(&problem)) {
        // write the solution and return
        solution = this->cache_Manager->getSolution(&problem);
        writeToServer(solution, sock_id);
        return;
    }
    // else - find solution
    /////////////////////////////////
    data = this->lexer(problem);
    ///////////////////////////////////
    solution = solver->solve(&data);
    // the solution isn't saved already- save, write and return
    this->cache_Manager->saveSolution(&problem, &solution);
    writeToServer(solution, sock_id);
}


void MyClientHandler::writeToServer(string sol, int sock_id) {
    const char *solution = sol.c_str();
    int n = write(sock_id, solution, strlen(solution));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}
bool MyClientHandler::getOut(const string &line) {
    if (line.substr(0).find("end") < line.size()) {
        this->toStop = false;
        return true;

    } else {
        return false;
    }
}
string MyClientHandler::getData(int sock_id) {
    string curr_line;
    string problem;
    while (true) { // condition to stop- inside
        curr_line = getLineFromSocket(sock_id);
        problem += curr_line;
        if (curr_line.find("end") != std::string::npos) {
            break;
        }
    }
    return problem;
}
string MyClientHandler::getLineFromSocket(int sock_id) {
    char buf[CHARS_TO_BUFFER];
    ssize_t readen_bytes;
    readen_bytes = read(sock_id, buf, CHARS_TO_BUFFER - 1);
    if (readen_bytes < 0) {
        __throw_bad_exception();
    } else if (readen_bytes == 0) {
        //connection closed
    } else {
        buf[readen_bytes] = NULL;
    }
    return buf;
}

////read from file
//string MyClientHandler::getData(int socketId) {
//    vector<string> v;
//    std::string lineData;
//    std::stringstream ss;
//    char buffer[1024];
//    string line;
//    string problem;
//    while (true) {
//        bzero(buffer, 1024);
//        read(socketId, buffer, 1023);
//        ss << buffer;
//        if (this->getOut(ss.str())) {
//            break;
//        }
//    }
//    while (std::getline(ss,lineData)) {
//        lineData.erase(std::remove(lineData.begin(),lineData.end(),' '),lineData.end());
//        problem += lineData;
//    }
//    return problem;
//}
