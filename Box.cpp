#include <string>
#include <iostream>
#include "ostream"

struct IsEven {
    int &ref;

    explicit IsEven(int &ref) : ref(ref) {};

    IsEven &operator=(int other) {
        if (other % 2 == 1) throw std::runtime_error("bad");
        this->ref = other;
        return *this;
    }

    operator int() const {
        return ref;
    }
};

class BoxEven {
    int height;
    int width;

public:
    IsEven getHeight() {
        return IsEven{height};
    }

    IsEven getWidthh() {
        return IsEven{width};
    }
};


int main() {
    BoxEven box;
    box.getWidthh() = 6; // OK
    box.getHeight() = 20;
    std::cout << box.getHeight() << std::endl;
    std::cout << box.getWidthh() << std::endl;
//    box.getWidthh() = 5; // error
    box.getHeight() = 7;
}
