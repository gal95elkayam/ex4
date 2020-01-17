//
// Created by gal on 13/01/2020.
//

#include <iostream>
#include <queue>

#include "State.h"

#ifndef EX4_MYPRIORITYQUEUE_H
#define EX4_MYPRIORITYQUEUE_H
#endif //EX4_MYPRIORITYQUEUE_H
template<class T,class Compare>
class MyPriorityQueue {
private:

    std::priority_queue<State<T> *, std::vector<State<T> *>, Compare>
    m_priorityQueue;
public:

    MyPriorityQueue() = default;

    unsigned long QueueSize() {
        return m_priorityQueue.size();
    }

    State<T>  *Pop_Priority_Queue() {
        State<T>  *tmpState = m_priorityQueue.top();
        m_priorityQueue.pop();
        return tmpState;
    }

    void push_Priority_Queue(State<T>  *newSt) {
        m_priorityQueue.push(newSt);
    }

    State<T>  *top_Priority_Queue() {
        return m_priorityQueue.top();
    }

    bool isEmpty_Priority_Queue() {
        return m_priorityQueue.empty();
    }

    bool isInPriorityQueue(State<T>  *st) {
        std::vector<State<T>  *> tmpVec;
        State<T>  *top;
        bool ret = false;
        while (!isEmpty_Priority_Queue()) {
            top = Pop_Priority_Queue();
            tmpVec.push_back(top);
            // found the state
            if (top==st) {
                ret = true;
            }
        }
        // return the states to the priority queue
        unsigned int vecSize= tmpVec.size();
        for (unsigned int i = 0; i < vecSize; ++i) {
            push_Priority_Queue(tmpVec[i]);
        }
        return ret;
    }


    void Update_Priority_Queue(State<T>  *oldSt, State<T>  *newSt) {
        std::vector<State<T>  *> tmpVec;
        State<T>  *top;
        while (!isEmpty_Priority_Queue()) {
            // take the top and pop out from queue
            top = Pop_Priority_Queue();
            tmpVec.push_back(top);
            /**
             *if old is equals to  the current top, we set that top came from
             * the updated state and update the cost of the path to the state
             */
            if (oldSt==top) {
                top->setCameFrom(newSt);
                top->setPathCost(newSt->getPathCost() + oldSt->getPathCost());
                break;
            }
        }
        // return the states to the priority queue
        for (int i = 0; i < tmpVec.size(); ++i) {
            push_Priority_Queue(tmpVec[i]);
        }
    }

    void print_Priority_Queue() {
        std::vector<State<T>  *> tmpVec;
        State<T>  *top;
        while (!isEmpty_Priority_Queue()) {
            top = Pop_Priority_Queue();
            std::cout << top->getPathCost() << std::endl;
        }
        // return the states to the priority queue
        unsigned int vecSize = tmpVec.size();
        for (unsigned int i = 0; i < vecSize; ++i) {
            push_Priority_Queue(tmpVec[i]);
        }
    }

    void clear_Priority_Queue() {
        m_priorityQueue = std::priority_queue<State<T>  *, std::vector<State<T>  *>, Compare>();

    }


};