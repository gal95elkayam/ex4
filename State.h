//
// Created by gal on 12/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

template<class T>
class State {
    T state;
    int m_cost;;
    State<T> *came_from;
    bool has_visited;
    int m_path_cost;
    double m_heuristicCost;
public:
    State(T stat, int cost) {
        state = stat;
        m_cost = cost;
        has_visited = false;
        m_path_cost = cost;
        came_from = nullptr;
        m_heuristicCost = 0;
    };

    // check if other state equal to this state.
    bool operator==(const State<T> *other) {
        return (this->state == other->state);
    }

//    State<T> &operator=(const State<T> *s) {
//        state = s->getState();
//        m_cost = s->getCost();
//        came_from = s->getCameFrom();
//        has_visited = s->isVisited();
//        return *this;
//    }
//
//    bool operator>(const State &st2) const {
//        return (m_cost > st2.getCost());
//    }
//
//    bool operator<(const State &st2) {
//        return (m_cost < st2.getCost());
//    }

    T getState() {
        return this->state;
    }

    void setCameFrom(State<T> *father) {
        this->came_from = father;
    }

    void visit() {
        this->has_visited = true;
    }

    bool is_visited() {
        return this->has_visited;
    }

    State<T> *getCameFrom() {
        return this->came_from;
    }

    void setCost(double c) {
        m_cost = c;
        m_path_cost = c;
    }

    int getCost() {
        return this->m_cost;
    }

    double getPathCost() const {
        return m_path_cost;
    }

    void setPathCost(double c) {
        m_path_cost = c;
    }

    void setHeuristicCost(double c) {
        m_heuristicCost = c;
    }

    double getHeuristicCost() const {
        return m_heuristicCost;
    }
    void addPathValue(int path) {
        this->m_path_cost += path;
    }



};


#endif //EX4_STATE_H
