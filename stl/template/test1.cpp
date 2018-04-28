#include <iostream>


using namespace std;

/*function overloading
int add(int x, int y) {
    return x+y;
}

float add(float x, float y) {
    return x+y;
}
*/ 


template <typename T>
T add(T a, T b) {
    return a+b;
}


int main() {
    int x = 10;
    int y = 20;

    float a = 5.6;
    float b = 4.4;

    cout << add(x,y) << endl;
    cout << add(a,b) << endl;

    return 0;
}