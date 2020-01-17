//
// Created by gal on 15/01/2020.
//



#ifndef EX4_SEARCHSOLUTION_H
#define EX4_SEARCHSOLUTION_H

#include <vector>
#include <string>
#include "Solver.h"
#include "Matrix.h"
#include "State.h"
#include "Searcher.h"
using namespace std;
template<class T, class Solution>
class SearchSolution :public Solver<vector<vector<string>>, Solution> {
    Searcher<T> *searcher;
    int cost=0;
public:
    SearchSolution(Searcher<T> *searcher) {
        this->searcher = searcher;
    }

     Solution solve(vector<vector<string>>* lines) {
        // init matrix into searchable
        Searchable<T> *matrix = new Matrix(*lines);
        // find path- from start to goal state
        vector<State<pair<int, int>> *> path = searcher->search(matrix);
        // return the result in string of directions
//        MatrixResult matrixResult;
        string solution = getSolution(path);
        delete (matrix); // free
        return solution;
    }
    string getSolution(vector<State<pair<int, int>> *> solution) {
        string result = "";
        int sol_size=solution.size();
        //TODO check about size-1
        if (sol_size == 0) {
            return "No possible solution";
        }
        cout<<"pathcost:  " <<solution[sol_size - 1]->getPathCost()<<endl;
        for (int i = 0; i < sol_size - 1; ++i) {

            if (solution[i]->getState().second == solution[i + 1]->getState().second) {
                if (solution[i]->getState().first > solution[i + 1]->getState().first) {
                    result = result + "Up,";
                    this->cost+=solution[i]->getCost();
                } else {
                    result = result + "Down,";
                    this->cost+=solution[i+1]->getCost();
                }
            } else if (solution[i]->getState().first == solution[i + 1]->getState().first) {
                if (solution[i]->getState().second > solution[i + 1]->getState().second) {
                    result = result + "Left,";
                    this->cost+=solution[i]->getCost();

                } else {
                    result = result + "Right,";
                    this->cost+=solution[i+1]->getCost();
                }

            }
        }
        cout<<"number of node:  " <<searcher->getNumOfNodesEvaluated()<<endl;

        // delete the extra ","
        string final_result = result.substr(0, result.size() - 1);
        cout<<final_result<<endl;
        return final_result;
    }

};
#endif //EX4_SEARCHSOLUTION_H