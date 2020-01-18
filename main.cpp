

#include "FileCacheManger.h"
#include "MySerialServer.h"
#include "BestFirstSearch.h"
#include "SearchSolution.h"
#include "MyClientHandler.h"
#include "Astar.h"
#include "DFS.h"
#include "MyParallelServer.h"

using namespace std;

int main() {
//    TestMatrices empiricalExperiment;
//    empiricalExperiment.testAndWriteToFiles();
//    Solver<string, string>*solv=new StringReverser();
//    CacheManager<string, string> *fcm = new FileCacheManger<string, string>;
//    auto *serv = new MySerialServer();
//    ClientHandler *m=new MyTestClientHandler<string, string>(solv,fcm);
    int port=5600;
//    serv->open(port,m);
    auto * server = new MyParallelServer(); // server
    auto * cm = new FileCacheManger<string,string>(); // inside- load the solution
    auto *searcher = new DFS<pair<int, int>>();
    auto *searchSolver = new SearchSolution<pair<int, int>, string>(searcher);
    auto *client = new MyClientHandler(searchSolver, cm);
    server->open(port, client);
    delete(cm);
    delete (server);
    delete(searcher);
    delete(searchSolver);
    delete(client);
}