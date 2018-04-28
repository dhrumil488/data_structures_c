#include <iostream>
#include <set>

using namespace std;

int main() {

    //set stores data in BST
    //set stores ints in ascending order by default as sets are unordered
    //set ca not have duplicate values
    set<int> s;

    for(int i=0;i<10;i++) {
        s.insert(10-i);
    }

    set<int>::iterator itr;
    itr = s.find(6);
    // *itr = 8 : can not do this as sets are read only
    //delete 6 from set
    s.erase(itr);
    s.insert(1); //will not be added1 again as 1 is already present

    for(set<int>::iterator itr = s.begin(); itr!=s.end();itr++) {
        cout << *itr << endl;
    }

    return 0;
}
