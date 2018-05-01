#include <iostream>
#include <map>

using namespace std;

int main() {
    pair<char, int> x;
    multimap<char, int> m; //can store the pair with duplicate key

    for(char ch = 'a'; ch!='z'; ch++) {
        x.first = ch;
        x.second = (int)ch;

        m.insert(x);
    }

    multimap<char, int>::iterator itr = m.begin();
    for(itr = m.begin(); itr!=m.end();itr++) {
        cout << (*itr).first << " " << (*itr).second << endl;
    }

    x.first = 'j';
    x.second = 1000;

    m.insert(x);

    for(itr = m.begin(); itr!=m.end();itr++) {
        cout << (*itr).first << " " << (*itr).second << endl;
    }

    itr = m.find('j');
    cout << "Finding the value of J: " << (*itr).second << endl;
    itr++;
    cout << "Finding the value of J: " << (*itr).second << endl;

    return 0;
}