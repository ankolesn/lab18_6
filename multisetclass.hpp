//
// Created by ankolesn on 25.07.22.
//
#ifndef MULTISET_HPP
#define MULTISET_HPP

#include <set>
#include <list>
#include <iterator>

template<typename T>
class Multiset_class {
private:
    std::list<std::list<T>> st;
public:
    bool insert(T value);

    int find(T value);

    void erase(T value);

    friend std::ostream &operator<<(std::ostream &out, const Multiset_class<T> &nt) {
        for (auto &i: nt.st) {
            for (auto &j: i) {
                out << "Value: " << j << std::endl;
            }
        }
        return out;
    }
};


template<typename T>
bool Multiset_class<T>::insert(T value) {
    for(auto it = st.begin(); it!=st.end();++it){
        if(it->front() == value){
            it->push_back(value);
            return true;
        }
    }
    auto it = st.insert(st.end(),std::list<T>());
    it->push_back(value);
    st.sort();
    return false;
}

template<typename T>
int Multiset_class<T>::find(T value) {
    int count = 0;
    for(auto &it: st){
        if(it.front() == value){
            count = it.size();
        }
    }
    return count;
}

template<typename T>
void Multiset_class<T>::erase(T value) {
    for(auto &it: st){
        if(it.front() == value){
            it.pop_front();
        }
    }
}
#endif //LAB18_6_MULTISETCLASS_HPP
