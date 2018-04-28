#include <iostream>

using namespace std;


template <class T>
class addition {
    private:
        T a;
        T b;
    public:
        addition();
        T add();
};

template <class T>
addition<T>::addition() {
    cout << "Please enter two nums:";
    cin >> a >> b;
}

template <class T>
T addition<T>::add() {
    return a+b;
}


int main() {
    
    addition<float> add_obj;
    cout << add_obj.add() << endl;
}