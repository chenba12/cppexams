#include "iostream"
#include "vector"

using namespace std;

template<typename T>
class MyVec {
    vector<T> vec;
    int range;
    double x;
public:
    explicit MyVec(int range) : range(range) {
        for (int i = 1; i <= range; i++) {
            vec.emplace_back(i);
        }
    }

    ~MyVec() = default;

    class MyIterator {
        MyVec<T> &myVec;
        size_t index;
    public:
        MyIterator(MyVec<T> &myVec, size_t index) :
        myVec(myVec), index(index) {};

        T operator*() {
            return myVec.vec[index];
        }

        bool operator==(const MyIterator &other) const {
            return index == other.index;
        }

        bool operator!=(const MyIterator &other) const {
            return index != other.index;
        }

        MyIterator &operator++() {
            index += 2;
            return *this;
        }
    };

    MyIterator begin() {
        return MyIterator(*this, 0);
    }

    MyIterator end() {
        return MyIterator(*this, vec.size());
    }
};


//print the numbers at even indexes
int main() {
    MyVec<double> vec(10);
    // 1 2 3 4 5 6 7 8 9 10
    for (auto i: vec) {
        cout << i << endl;
    }
    // != begin end ++pre * ctr
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        auto i = *it;
        cout << i << endl;
    }

}
