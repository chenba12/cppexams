#ifndef CPPEXAMS_MAXXX_HPP
#define CPPEXAMS_MAXXX_HPP

template<typename T>
T max1(T x, T y) {
    return (x > y) ? x : y;
}

int max1(int x, int y) {
    return (x > y) ? x : y;
}

template<typename T>
void f(T x,T y){
    std::cout<<"Template"<<std::endl;
}

void f(int x,int y){
    std::cout<<"non Template"<<std::endl;
}


#endif //CPPEXAMS_MAXXX_HPP
