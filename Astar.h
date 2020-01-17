//
// Created by gal on 13/01/2020.
//
#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H
#include "Searcher.h"
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include "State.h"
//#include "Searchable.h"


using namespace std;
template<class T>
class Astar : public Searcher<T> {
    enum Color {
        WHITE, GREY, BLACK
    };
    class CompareState {
    public:
        bool operator()(State<T> *first, State<T> *second) {
            return first->getPathCost() + first->getHeuristicCost() > second->getPathCost() + second->getHeuristicCost();
        }
    };

    //members
    std::priority_queue<State<T> *, std::vector<State<T> *>, CompareState> open_list;
    int evaluate_nodes;
    std::unordered_map<State<T> *, Color> state_to_color;

    std::vector<State<T> *> backTrace(State<T> *goal) {
        std::vector<State<T> *> path;
        State<T> *curr_state = goal;
        while (curr_state != nullptr) {
            path.push_back(curr_state);
            curr_state = curr_state->getCameFrom();
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    void initStatesColor(Searchable<T> *searchable) {
        std::vector<State<T> *> states = searchable->getAllStates();
        for (auto &s:states) {
            state_to_color[s] = WHITE;
        }
    }

public:

    virtual std::vector<State<T> *> search(Searchable<T> *searchable) {
        // init all states color to white
        initStatesColor(searchable);
        State<T> *first = searchable->getInitState();
        /**
         * init the start state with the hiuristic value(distance)
         */
        searchable->setHeuristic(first);
        //searchable->setDistance(first);
        state_to_color.at(first) = GREY;
        open_list.push(first);
        while (getOpenListSize() > 0) {
            State<T> *n = popOpenList();
            if (n == searchable->getGoalState()) {
                //this->solution_value = n->getPathValue();
                this->open_list = std::priority_queue<State<T> *, std::vector<State<T> *>, CompareState>();
                return backTrace(n);
            }
            else if(n->getCost()==-1){
                continue;
            }
            else {
                std::vector<State<T> *> succerssors = searchable->getAllPossibleStates(n);
                for (typename std::vector<State<T> *>::iterator it = succerssors.begin();
                     it != succerssors.end(); it++) {
                    // if not found in the open and in the close lists
                    State<T> *curr_state = (*it);
                    if (curr_state->getCost() == -1) {
                        continue;
                    } else if (state_to_color.at(curr_state) == WHITE) {
                        state_to_color[curr_state] = GREY; // update color
                        curr_state->setCameFrom(n); // set your dad
                        curr_state->addPathValue(n->getPathCost()); // add cost
                        searchable->setHeuristic(curr_state);
                        //searchable->setDistance(curr_state);
                        open_list.push(curr_state); // add succerssors to open list
                    } else {
                        int new_path_val = n->getPathCost() + curr_state->getCost();
                        if (new_path_val < curr_state->getPathCost()) {
                            // if new path is better than the prev one
                            curr_state->setCameFrom(n); // update dad
                            curr_state->setPathCost(new_path_val); // update path
                            // if not in open add it to open
                            if (state_to_color.at(curr_state) == BLACK) {
                                searchable->setHeuristic(curr_state);
                                open_list.push(curr_state);
                            }
                        }
                    }
                }
            }
        }
        //this->solution_value = -1;
        this->open_list = std::priority_queue<State<T> *, std::vector<State<T> *>, CompareState>();
        std::vector<State<T> *> empty;
        return empty;
    }


/**
 * get how many nodes were evaluated by the algorithm
 * @return
 */
    virtual int getNumOfNodesEvaluated() {
        return evaluate_nodes;
    }

    State<T> *popOpenList() {
        ++(this->evaluate_nodes);
        State<T> *temp_top = open_list.top();
        state_to_color.at(temp_top) = BLACK;
        open_list.pop();
        return temp_top;
    }

    int getOpenListSize() {
        return open_list.size();
    }

};

#endif //EX4_ASTAR_H
