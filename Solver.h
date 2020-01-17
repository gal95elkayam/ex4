//
// Created by gal on 09/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H



template<class Problem, class Solution>
class Solver {
public:
    virtual ~Solver() {}
    virtual Solution solve(Problem* problem) = 0;
};
#endif //EX4_SOLVER_H