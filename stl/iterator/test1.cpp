#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    set<int> s;

    //insert 10 random ints in the range of 100
    for(int i=0;i<10;i++) {
        v.push_back(rand()%100);
    }

    cout << "vector:" << endl;
    for(vector<int>::iterator itr = v.begin(); itr!=v.end(); itr++) {
        cout << *itr << endl;
    }

    //copy vector elements to set

    copy(v.begin(), v.end(), inserter(s, s.begin()));

    cout << "set:" << endl;
    for(set<int>::iterator itr = s.begin(); itr!=s.end(); itr++) {
        cout << *itr << endl;
    }

    //sort the vector
    sort(v.begin(), v.end());
    cout << "sorted vector:" << endl;
    for(vector<int>::iterator itr = v.begin(); itr!=v.end(); itr++) {
        cout << *itr << endl;
    }

    vector<int>::iterator itr = v.begin();
    cout << "finding 77 by find algorithm in vector:" << endl;
    itr = find(v.begin(), v.end(), 77);
    cout << *itr << endl;

    return 0;
}