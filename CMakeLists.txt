cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex4 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h FileCacheManger.h Solver.h StringReverser.h Searcher.h Searchable.h State.h BFS.h DFS.h MyPriorityQueue.h BestFirstSearch.h Astar.h Matrix.cpp Matrix.h TestMatrices.h MyClientHandler.cpp MyClientHandler.h SearchSolution.h MyParallelServer.h MyParallelServer.cpp)