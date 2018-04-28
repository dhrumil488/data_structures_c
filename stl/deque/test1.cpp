#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> queue;

    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);

    queue.push_front(0);


    for(int i=0;i<queue.size();i++) {
        cout << queue.at(i) << endl;
    }

    cout << "The queue is empty: " << queue.empty() << endl;

    return 0;
}