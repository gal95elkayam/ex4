//
// Created by gal on 10/01/2020.
//

#include <string>
#include <algorithm>

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#endif //EX4_STRINGREVERSER_H

#include "Solver.h"
using namespace std;

class StringReverser : public Solver<string, string> {

public:
    StringReverser() {}

    ~StringReverser() {}

    string  solve(string * p) {
        reverse(p->begin(), p->end());
        return *p;
    }


};