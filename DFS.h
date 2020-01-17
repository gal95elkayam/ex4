//
// Created by gal on 12/01/2020.
//

#include <vector>
#include <stack>
#include <algorithm>

#ifndef EX4_DFS_H
#define EX4_DFS_H

#endif //EX4_DFS_H

using namespace std;
//#include "Searchable.h"
#include "Searcher.h"

template<class Problem>
class DFS : public Searcher<Problem> {
private:
    int nodesEvaluated = 0;
public:
    virtual std::vector<State<Problem> *> search(Searchable<Problem> *searchable) {

        // create stack and save the goal and initialize state
        std::stack<State<Problem> *> stack;
        searchable->getGoalState();
        State<Problem> *cur_state = searchable->getInitState();
        State<Problem> *goal = searchable->getGoalState();
        // push the first to stack
//        this->nodesEvaluated++;
        stack.push(cur_state);
        typename vector<State<Problem> *>::iterator it;

        while (!stack.empty()) {
            //pop a vertex from stack
            cur_state = stack.top();
            stack.pop();
            this->nodesEvaluated++;
            //if the cur_state not mark as visited already-mark as visited
            if (!cur_state->is_visited()) {
                cur_state->visit();
            }
            //if we reach the goal state -we done and exit
            if (cur_state == goal) {
                // we done
                break;
            }
            vector<State<Problem> *> adj = searchable->getAllPossibleStates(cur_state);
            it = adj.begin();
            //add the adj
            for (; it != adj.end(); ++it) {
                State<Problem> *temp = (*it);
                if (temp->getCost() < 0) {
                    continue;
                }
                State<Problem> *neighbor = (*it);
                if (!neighbor->is_visited()) {
                    neighbor->visit();
                    neighbor->setCameFrom(cur_state);
                    stack.push(neighbor);
                }
            }
        }
        this->nodesEvaluated--;//without the first node

        vector<State<Problem> *> path;
        State<Problem> *begin_state = searchable->getInitState();
        cur_state = goal;
        if (cur_state->getCameFrom() == NULL) {
            return path;
        }
        while (!(cur_state == begin_state)) {
            path.push_back(cur_state);
            cur_state = cur_state->getCameFrom();
        }
        path.push_back(searchable->getInitState());
        std::reverse(path.begin(), path.end());
        return path;

    }

    virtual int getNumOfNodesEvaluated() {
        return this->nodesEvaluated;
    }
};
