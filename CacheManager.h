//
// Created by gal on 09/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <string>

using namespace std;
template <class Problem,class Solution>
class CacheManager {
public:
    //true if the cache manager has a solution to the problem, else false
    virtual bool containsSolution(Problem* problem) = 0;
    //solution the the problem
    virtual string getSolution(Problem* problem) = 0;
   //Save solution the problem
    virtual void saveSolution(Problem* problem,Solution* solution) = 0;
};


#endif //EX4_CACHEMANAGER_H
