#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> array;
    for(int i=0;i<5;i++){
         vector<int> temp;   
        for(int j=0;j<5;j++) {
            temp.push_back(j);
        }
        array.push_back(temp);
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}