#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> l;

    l.push_back(1);

    for(int i=2;i<10;i++) {
        l.push_back(i);
    }

    l.push_front(0);

    for(list<int>::iterator itr = l.begin(); itr!=l.end();itr++) {
        cout << *itr <<endl;
    }

    //add 15 before 7
    list<int> ::iterator itr = find(l.begin(), l.end(), 7);
    itr++;
    l.insert(itr, 15);

    cout << "Print list after add 15 before 7:" << endl;
    for(list<int>::iterator itr = l.begin(); itr!=l.end();itr++) {
        cout << *itr <<endl;
    }

    //delete 8 from the list
    itr = find(l.begin(), l.end(), 8);
    l.erase(itr);

    cout << "Print list after delete 8:" << endl;
    for(list<int>::iterator itr = l.begin(); itr!=l.end();itr++) {
        cout << *itr <<endl;
    }

    return 0;
}