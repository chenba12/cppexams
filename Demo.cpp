#include <iostream>
#include <fstream>
#include <utility>
#include "vector"
#include "algorithm"

using namespace std;

class Tday {
public:
    static std::string DayNames[7];

    Tday() : D("1") {};

    Tday(std::string day) : D(day) {};

    void setDay(std::string day) {
        bool flag = false;
        for (const auto &DayName: DayNames) {
            if (day == DayName) {
                flag = true;
                break;
            }
        }
        if (flag) this->D = day;
        else throw std::string("bla bla bla");
    }

    std::string getDay() const {
        return this->D;
    }

    Tday &operator=(const Tday &other) {
        if (*this != other) {
            this->D = other.D;
        }
        return *this;
    }

    Tday &operator+=(int numOfDays) {
        int index;
        int res = 0;
        for (int i = 0; i < 7; i++) {
            if (DayNames[i] == this->D) {
                index = i;
            }
        }
        res = ((index + numOfDays) % 7);
        this->D = DayNames[res];
        return *this;
    }

    Tday operator++(int) {
        Tday temp(*this);
        int index;
        int res = 0;
        for (int i = 0; i < 7; i++) {
            if (DayNames[i] == this->D) {
                index = i;
            }
        }
        res = ((index + 1) % 7);
        this->setDay(DayNames[res]);
        return temp;
    }

    Tday &operator++() {
        int index;
        int res = 0;
        for (int i = 0; i < 7; i++) {
            if (DayNames[i] == this->D) {
                index = i;
            }
        }
        res = ((index + 1) % 7);
        this->setDay(DayNames[res]);
        return *this;
    }

    bool operator!=(const Tday &other) const {
        if (this->D != other.D) return true;
        return false;
    }


    Tday operator+(int numOfDays) {
        int index;
        int res = 0;
        for (int i = 0; i < 7; i++) {
            if (DayNames[i] == this->D) {
                index = i;
            }
        }
        res = ((index + numOfDays) % 7);
        this->D = DayNames[res];
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Tday &day) {
        return out << "today is day number " << day.D << std::endl;
    }

    friend std::istream &operator>>(std::istream &in, Tday &day) {
        std::string today;
        in >> today;
        bool flag = false;
        for (const auto &DayName: DayNames) {
            if (today == DayName) {
                flag = true;
                break;
            }
        }
        if (flag) {
            day.setDay(today);
        } else {
            throw std::string("hatul sleepy");
        }
        return in;
    }

private:
    std::string D;
};

std::string Tday::DayNames[7] = {"1", "2", "3", "4", "5", "6", "7"};

template<class T, class V>
struct A {
    T s;
    V k;
    static int count;
};
template<class T, class V>
int A<T, V>::count = 0;

#include "maxxx.hpp"

struct oddEven {
    bool operator()(int x) {
        if (x % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }
};

#include <set>
#include <iostream>

struct customCompare {

    bool operator()(const int &lhs, const int &rhs) const {
        if (lhs % 2 != rhs % 2) // One is even, the other is odd
            return lhs % 2 == 0; // The even number comes first
        else // Both are even, or both are odd
            return lhs < rhs; // The smaller number comes first
    }
};

struct Compare {
    bool operator()(const int a, const int b) const {
        return a > b;
    }
};

struct Shape {
    virtual void draw() = 0;
    ~Shape() { cout << "Shape~\n"; }
};

struct Circle : public Shape {
    void draw() {
        cout << "Circle::draw\n";
    }

    ~Circle() { cout << "Circle~\n"; }
};

void drawSomething(Shape &s) {
    s.draw();
}

int main() {
    Circle c;
    drawSomething(c);
    return 0;
}
