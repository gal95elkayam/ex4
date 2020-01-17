//
// Created by gal on 12/01/2020.
//

#include <vector>

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "State.h"
#include "Searchable.h"


template<class T>
class Searcher {

public:
    // search method
    virtual std::vector<State<T>*> search(Searchable<T> *searchable) = 0;
    //  get how many nodes were evaluated by the algorithm
    virtual int getNumOfNodesEvaluated() = 0;

};
#endif //EX4_SEARCHABLE_H
