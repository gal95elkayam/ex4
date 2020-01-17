//
// Created by gal on 13/01/2020.
//
#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H
#include <unordered_set>
#include <algorithm>
#include "State.h"
#include "MyPriorityQueue.h"
#include "Searcher.h"
using namespace std;
template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    class CompareStates {
    public:
        bool operator()(const State<T>  *left, const State<T>  *right) {
            return left->getPathCost() > right->getPathCost();
        }
    };
    int m_numOfnodes;
    // priority queue
    MyPriorityQueue<T,CompareStates> *open;
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
public:
    BestFirstSearch() {
        open = new MyPriorityQueue<T,CompareStates>();
        m_numOfnodes = 0;
    }

    std::vector<State<T> *> search(Searchable<T> *searchable) {
        m_numOfnodes = 0;
        // set
        std::unordered_set<State<T> *> close;
        // insert the initial state to the priority queue
        open->push_Priority_Queue(searchable->getInitState());
        // goal state
        State<T> *goal = searchable->getGoalState();
        // tmp - to iterate the priority queue
        State<T> *father;

        while (!open->isEmpty_Priority_Queue()) {
            // take from the priority queue the min
            father = open->Pop_Priority_Queue();
            ++m_numOfnodes;
            // insert to the set the minimum
            close.insert(father);
            // if finds the goal - return and break.
            if (father == goal) {
                //need to save to a vector and to sum the shortest path
                open->clear_Priority_Queue();
                return backTrace(goal);
            }
            // the neighbors of each state
            State<T> *neigh;
            std::vector<State<T> *> neighbors = searchable->getAllPossibleStates(father);
            double pathCost;
            for (typename std::vector<State<T> *>::iterator it = neighbors.begin();
                 it != neighbors.end(); it++) {
                neigh = (*it);
                /**
                * for each neighbor that that not in open and not in close:
                * 1. update his father to tmp
                * 2. add the neighbor to "open" (MyPriorityQueue)
                */
                if (neigh->getCost() == -1) {
                    continue;
                }
                pathCost = father->getPathCost() + neigh->getCost();
                if (!open->isInPriorityQueue(neigh) && close.find(neigh) ==
                                                       close.end()) {
                    neigh->setCameFrom(father);
                    neigh->setPathCost(pathCost);
                    open->push_Priority_Queue(neigh);
                }
                    /**
                     * else:
                     * 1. if not in "open" (MyPriorityQueue) - add to open
                     *  else:
                     *    1.update the priority of neigh
                     */
                else if (pathCost < neigh->getPathCost()) {
                    // if its not in "open"
                    if (!open->isInPriorityQueue(neigh)) {
                        open->push_Priority_Queue(neigh);
                        // if it's in "open"
                    } else {
                        open->Update_Priority_Queue(neigh, father);
                    }
                }
            }
        }
        open->clear_Priority_Queue();
        std::vector<State<T> *> empty;
        return empty;
    }

    int getNumOfNodesEvaluated(){
        return m_numOfnodes;
    }

    ~BestFirstSearch() {
        delete (open);
    }
};
#endif //EX4_BESTFIRSTSEARCH_H