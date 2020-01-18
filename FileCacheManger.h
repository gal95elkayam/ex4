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
    unordered_map<Problem,Solution> m_hash_map;


public:
    FileCacheManger(){
    }
    //string &filename
    bool fileExists(string &filename) {
        ifstream isfile(filename);
        return (bool) isfile;
    }
    bool containsSolution(Problem* problem) {
        auto got = m_hash_map.find ((*problem));
        //not in the map, check if we have file of that.
        //if we have file- insert to map
        if(got == m_hash_map.end()){
            this->loadFromFile(problem);
        }
        bool answer = (m_hash_map.find(*problem) != m_hash_map.end());
        return answer;
    }
    string getSolution(Problem* problem){

        if (containsSolution(problem)) {
            auto it = m_hash_map.find(*problem);
            return it->second;
        } else {
            return "";
        }
    }
    void saveSolution(Problem *problem, Solution *solution) {

        this->m_hash_map.insert(pair<Problem, Solution>(*problem, *solution));
        writeToFile(problem, solution);
    }
    void writeToFile(Problem *problem, Solution *solution) {
        fstream m_stream;
        hash<Problem>myHash;
        int fileName=myHash(*problem);
        string hashProblemStr=to_string(fileName);
        m_stream.open(hashProblemStr, std::ofstream::out | std::fstream::in);
        m_stream << (*solution) << endl;
        m_stream.close();
    }
    void loadFromFile(Problem* problem) {
        std::stringstream file;
        fstream outfile;
        hash<Problem>myHash;
        int fileName=myHash(*problem);
        string hashProblemStr=to_string(fileName);
        if (fileExists(hashProblemStr)) {
            outfile.open(hashProblemStr, std::ofstream::out | std::fstream::in);
            string line;
            getline(outfile, line);
            this->m_hash_map.insert(pair<Problem, Solution>(*problem, line));
            outfile.close();
        }
    }

};


#endif //EX4_FILECACHEMANGER_H
