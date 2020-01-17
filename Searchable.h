//
// Created by gal on 12/01/2020.
//



#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#endif //EX4_SEARCHABLE_H
template<class T>
class Searchable {
public:
    virtual State <T> *getInitState() = 0;
    virtual State <T> *getGoalState() = 0;
    virtual std::vector<State < T>*> getAllPossibleStates(State<T>*s) = 0;
    virtual void setHeuristic(State<T> * current)=0;
    virtual std::vector<State<T> *> getAllStates() = 0;

};
