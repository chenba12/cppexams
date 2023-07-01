#ifndef CPPEXAMS_BOX_HPP
#define CPPEXAMS_BOX_HPP

class Box {
    int length;
    int breadth;
    int height;
public:
    Box(int length, int breadth, int height) : length(length), breadth(breadth), height(height) {};

    bool operator<(const Box &other) {
        if (this->length < other.length) return true;
        else if (this->length == other.length) {
            if (this->breadth < other.breadth) return true;
            else if (this->breadth == other.breadth) {
                if (this->height < other.height) return true;
                else return false;
            }
        }
        return false;
    }
};
#endif
