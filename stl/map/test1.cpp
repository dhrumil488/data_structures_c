#include <iostream>
#include <map>

using namespace std;

int main() {

    //map stores the value in BST in <key, value> pair
    // have O(logn) complexity for find, insert
    //can not update the value, have to erase it and reinsert it
    //map sorts the value by key, like sets
    //map is unordered like set
    pair<char, int> p;
    map<char, int> m;

    for(char ch = 'a'; ch <= 'z'; ch++) {
        p.first = ch;
        p.second = (int)ch;

        m.insert(p);
    }

    map<char, int>::iterator itr = m.begin();

    for(itr = m.begin(); itr != m.end(); itr++) {
        cout << (*itr).first << " " << (*itr).second << endl;
    }

    itr = m.find('j');
    cout << "Finding the value of J:" << endl;
    cout << (*itr).second << endl;


    return 0;
}