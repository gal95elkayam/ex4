////
//// Created by gal on 09/01/2020.
////
//
//#include <string>
//#include <vector>
//#include <strings.h>
//#include <zconf.h>
//#include <cstring>
//#include "MyTestClientHandler.h"
//using namespace std;
//#define BUFFER_SIZE 1024
//
//void MyTestClientHandler::handleClient(int newsockfd){
//
//    char buffer[BUFFER_SIZE];
//    bzero(buffer, BUFFER_SIZE);
//    string line;
//    bool getOutOfLoop = true;
//    vector<string> vec;
//    read(newsockfd, buffer, BUFFER_SIZE);
//    while (getOutOfLoop) {
//        //stop condition
//        if (strstr(buffer,"end")!=NULL) {
//            getOutOfLoop = false;
//            break;
//        }
//        line = createLine(buffer, BUFFER_SIZE);
//        vec.emplace_back(line);
//        read(newsockfd, buffer, BUFFER_SIZE);
//    }
//
//
//
//
//
//
//
//}
//
//
////create vector with the line of the problem
//string MyTestClientHandler::createLine(char buffer[], int size) {
//    string line;
//    for (int i = 0; i < size; i++) {
//        if (buffer[i] == ' ') {
//            continue;
//        }
//        if (buffer[i] == '\0'||buffer[i] == '\n'|| buffer[i] == '\r') {
//            break;
//        }
//        line += buffer[i];
//    }
//    return line;
//}