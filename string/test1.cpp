#include <iostream>
#include <string>

using namespace std;

int main() {
     // Declaring string
    string str;
 
    // Taking string input using getline()
    // "geeksforgeek" in givin output
    getline(cin,str);
 
    // Displaying string
    cout << "The initial string is : ";
    cout << str << endl;
 
    // Using push_back() to insert a character
    // at end
    // pushes 's' in this case
    str.push_back('s');
 
    // Displaying string
    cout << "The string after push_back operation is : ";
    cout << str << endl;
 
    // Using pop_back() to delete a character
    // from end
    // pops 's' in this case
    str.pop_back();
 
    // Displaying string
    cout << "The string after pop_back operation is : ";
    cout << str << endl;

    //displaying string char by char
    cout << "displaying string char by char:" << endl;
    for(int i=0;i<str.size();i++) {
        cout << str[i];
    }

    cout << endl;
 
    return 0;
}

