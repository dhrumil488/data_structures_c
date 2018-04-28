#include <iostream>

using namespace std;


template <class T>
class addition {
    private:
        T a;
        T b;
    public:
        addition(T a, T b);
        T add();
};

template <class T>
addition<T>::addition(T a, T b) {
    this->a = a;
    this->b = b;
}

template <class T>
T addition<T>::add() {
    return a+b;
}


int main() {
    
    addition<float> add_obj(4.4, 5.6);
    cout << add_obj.add() << endl;
}