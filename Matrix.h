//
// Created by gal on 14/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include <utility>
#include <vector>
#include <string>
#include "Searcher.h"
//#include "SearchSolution.h"
#include "State.h"


using namespace std;
    typedef pair<int, int> point;
    class Matrix : public Searchable<point> {
    private:
        State <point> *begin;
        State <point> *end;
        vector<vector < State < point> *>>matrix;
        void createMatrix(vector <vector<string>> &lines);

    public:
        Matrix(vector <vector<string>> lines);
        virtual State <point> *getInitState() {
            return this->begin;
        }
        virtual State <point> *getGoalState() {
            return this->end;
        }
        virtual vector<State < point> *>getAllPossibleStates(State<point>*state);

        virtual void setHeuristic(State<point> * current);

        bool checkIfValidNeighbor(int col, int row);
        virtual vector<State<point> *> getAllStates();
    };


#endif //EX4_MATRIX_H
