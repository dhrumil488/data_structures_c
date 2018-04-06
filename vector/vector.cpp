#include <iostream>
#include <vector>

using namespace std;


int sum(vector<int> &a) {
    int sum = 0;
    for(int i=0;i<a.size();i++){
        sum = sum + a[i];
    }
    printf("Total sum = %d", sum);
}


int main()
{

    vector<int> list1;

    for (int i = 0; i < 5; i++)
    {
        list1.push_back(i);
    }

    printf("The list contains:\n");

    //both for loop are same
    for (int i = 0; i < list1.size(); i++)
    {
        printf("%d\n", list1.at(i));
    }

    for (int i = 0; i < list1.size(); i++)
    {
        printf("%d\n", list1[i]);
    }

    printf("The list in reverse order:\n");
    for(int i=list1.size()-1;i>=0;i--){
        printf("%d", list1[i]);
    }

    sum(list1);

    std::vector<int> array; // create an empty vector
    array.reserve(3);       // make room for 3 elements
                            // at this point, capacity() is 3
                            // and size() is 0
    array.push_back(999);   // append an element
    array.resize(5);        // resize the vector
                            // at this point, the vector contains
                            // 999, 0, 0, 0, 0
    array.push_back(333);   // append another element into the vector
                            // at this point, the vector contains
                            // 999, 0, 0, 0, 0, 333
    array.reserve(1);       // will do nothing, as capacity() > 1
    array.resize(3);        // at this point, the vector contains
                            // 999, 0, 0
                            // capacity() remains 6
                            // size() is 3
    array.resize(6, 1);     // resize again, fill up with ones
                            // at this point the vector contains
                            // 999, 0, 0, 1, 1, 1

    return 0;
}