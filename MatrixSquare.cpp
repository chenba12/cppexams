#include <valarray>
#include "array"
#include "iostream"

using namespace std;

class intRef {
    int &ref;;
public:
    intRef &operator=(int val) {
        this->ref = (int) pow(val, 2);
        return *this;
    }

    explicit operator int() const {
        return ref;
    }

    explicit intRef(int &ref) : ref(ref) {}
};

class MatrixSquare {
    array<array<int, 5>, 5> arr;
public:
    MatrixSquare(int val) {
        for (size_t i; i < arr.size(); i++) {
            for (size_t j = 0; j < arr[i].size(); ++j) {
                arr[i][j] = val;
            }
        }
    }

    MatrixSquare(const MatrixSquare &other) : arr(other.arr) {};

    bool operator!=(const MatrixSquare &other) {
        if (this->arr != other.arr) return true;
        return false;
    }

    MatrixSquare &operator=(const MatrixSquare &other) {
        if (*this != other) {
            this->arr = other.arr;
        }
        return *this;
    }

    array<array<int, 5>, 5> &getArr() {
        return this->arr;
    }

    intRef operator[](pair<int, int> pair) {
        int a = pair.first;
        int b = pair.second;
        if (a < 0 && b < 0) {
            a = (int) pow(a, 2);
            b = (int) pow(b, 2);
        } else if (a < 0 && b >= 0) {
            a = (int) pow(a, 2);
        } else if (a >= 0 && b < 0) {
            b = (int) pow(b, 2);
        }
        return (arr[(size_t) a][(size_t) b]);
    }

    void print() {
        cout << "now printing: " << endl;
        for (size_t i = 0; i < arr.size(); i++) {
            for (size_t j = 0; j < arr[i].size(); j++) {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    // class mat{array<array<int, 5>, 5> arr;}
    MatrixSquare matrixSquare2(2); // ctr (int)
    matrixSquare2.print();
    MatrixSquare matrixSquare3 = matrixSquare2; // copy ctr
    matrixSquare3.print();
    MatrixSquare matrixSquare(1); // all values are 1
    matrixSquare.print();
    //mat[i][j]=5
    matrixSquare[{1, 2}] = 2; //mat[1,2]=4 //operator [] // operator = proxy
    cout << matrixSquare[{1, 2}] << endl;
    matrixSquare = matrixSquare2; //matrixSquare values are 2
    matrixSquare[{-2, -1}] = 5; // mat1[4,1]=25
    cout << matrixSquare[{-2, -1}] << endl;
}