#include <iostream>
#include "multisetclass.hpp"

int main() {
    Multiset_class<int> m;

    m.insert(1);
    m.insert(1);
    m.insert(2);
    m.insert(3);
    m.insert(4);
    m.insert(4);

    std::cout << m.find(1) << std::endl;

    m.erase(4);

    std::cout << m;
}
