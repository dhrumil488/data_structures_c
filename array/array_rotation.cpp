#include <iostream>
#include <stdio.h>

using namespace std;

/*Function to left rotate arr[] by 1 of size n*/
void left_rotate_by_one(int arr[], int n) {
    int temp = arr[0];
    for(int i=0;i<n;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

/*Function to left rotate arr[] by d of size n*/
void left_rotate(int arr[], int d, int n) {
    for(int i=0;i<d;i++){
        left_rotate_by_one(arr, n);
    }
}

/*Print the array*/
void display(int arr[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n,i,d;
    printf("Array Left Rotation!\n");
    printf("Please enter array size:");
    cin >> n;
    int arr[n];
    for(i=0;i<n;i++){
        cout << "Please enter arr[" << i << "]: ";
        cin >> arr[i]; 
    }
    cout << "Please enter rotation index:";
    cin >> d;

    left_rotate(arr, d, n);

    display(arr, n);

    return 0;
}