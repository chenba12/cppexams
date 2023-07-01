#include <valarray>
#include <iostream>
#include "algorithm"
#include "vector"
#include "set"

using namespace std;

//print only full square number 4 is a full square of 2
//find_if and vector
//set all negative at the end asc order

struct SortNegative {
    //true a,b
    //false b,a
    bool operator()(int a, int b) {
        if (a >= 0 && b < 0) return true;
        else if (a < 0 && b >= 0) return false;
        else if (a > 0 && b > 0) return a > b;
        else return a < b;
    }
};


int main() {
    vector<int> vec;
    std::sort(vec.begin(), vec.end(), SortNegative());
    set<int, SortNegative> container;
    container.insert(2);
    container.insert(-4);
    container.insert(6);
    container.insert(-8);
    container.insert(36);
    container.insert(49);
    container.insert(-1);
    //2 6 3;6 49 -8 -4 -1
    for (auto it: container) {
        cout << it << " ";
    }
}


