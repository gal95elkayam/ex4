//
// Created by gal on 09/01/2020.
//

#ifndef EX4_FILECACHEMANGER_H
#define EX4_FILECACHEMANGER_H

#define Max_m_hash_map_size 5
#include <fstream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <mutex>
#include <sstream>
#include "CacheManager.h"


template <class Problem,class Solution>

class FileCacheManger: public CacheManager<Problem,Solution>{
    fstream m_stream;
    int cacheSize=5;
    int listSize;
    list<pair<Problem, Solution> > itemList;
    unordered_map<Problem,typename list<pair<Problem, Solution> >::iterator> m_hash_map;


public:
    FileCacheManger(){
        int cacheSize=5;
        int listSize=0;
    }
    //string &filename
    bool fileExists(string &filename) {
        ifstream isfile(filename);
        return (bool) isfile;
    }
    bool containsSolution(Problem* problem) {
        mutex g_i_mutex;
        g_i_mutex.lock();
        auto got = m_hash_map.find ((*problem));
        //not in the map, check if we have file of that.
        //if we have file- insert to map
        if(got == m_hash_map.end()){
            this->loadFromFile(problem);
        }
        //now in the map- implement lru algorithm
        else{
            //Transfer only the element pointed by it->second from list itemList into the itemList.begin().
            itemList.splice(itemList.begin(),itemList,got->second);
            //change the place in the mapping
            this->m_hash_map.erase(got);
            m_hash_map.insert(make_pair(*problem,itemList.begin()));
        }
        bool answer = (m_hash_map.find(*problem) != m_hash_map.end());
        g_i_mutex.unlock();
        return answer;
        // This function accepts a single parameter key which is needed to be checked in the given unordered_map container.
        //This function returns 1 if there exists a value in the map with the given key, otherwise it returns 0.
//        if (m_hash_map.count((*problem)) != 0) {
//            return true;
//        } else {
//            return false;
//        }
    }
    string getSolution(Problem* problem){
        mutex g_i_mutex;
        g_i_mutex.lock();
        if (containsSolution(problem)) {
            auto it = m_hash_map.find(*problem);
            auto got=it->second->second;;
            g_i_mutex.unlock();
            return got;
        } else {
            g_i_mutex.unlock();
            return "";
        }
    }
    void saveSolution(Problem *problem, Solution *solution) {
        mutex g_i_mutex;
        g_i_mutex.lock();
        itemList.push_front(make_pair(*problem, *solution));
        ++ listSize;
        this->m_hash_map.insert(make_pair(*problem, itemList.begin()));
        if (listSize > cacheSize) {
            this->m_hash_map.erase(itemList.back().first);
            --listSize;
            itemList.pop_back();
        }
        writeToFile(problem, solution);
        g_i_mutex.unlock();
    }
    void writeToFile(Problem *problem, Solution *solution) {
        mutex g_i_mutex;
        g_i_mutex.lock();
        hash<Problem>myHash;
        int fileName=myHash(*problem);
        string hashProblemStr=to_string(fileName);
        this->m_stream.open(hashProblemStr, std::ofstream::out | std::ofstream::trunc);
        this->m_stream << (*solution) << endl;
        this->m_stream.close();
        g_i_mutex.unlock();
    }
    void loadFromFile(Problem* problem) {
        mutex g_i_mutex;
        g_i_mutex.lock();
        std::stringstream file;
        fstream outfile;
        hash<Problem>myHash;
        int fileName=myHash(*problem);
        string hashProblemStr=to_string(fileName);
        if (fileExists(hashProblemStr)) {
            outfile.open(hashProblemStr, std::ofstream::out | std::ofstream::trunc);
            string line;
            getline(outfile, line);
//            outfile.read((char *) &object, sizeof(object));
            itemList.push_front(make_pair(*problem, line));
            ++listSize;
            this->m_hash_map.insert(make_pair(*problem, itemList.begin()));
            outfile.close();
            ///////////////////////////////////////////////////////
            if (listSize > cacheSize) {
                this->m_hash_map.erase(itemList.back().first);
                --listSize;
                itemList.pop_back();
                /////////////////////////////////////////////////////
            }
        }
        g_i_mutex.unlock();
    }

};


#endif //EX4_FILECACHEMANGER_H
