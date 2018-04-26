#include <stdio.h>

int main() {
	//code
	int n;
	int arr[100];
	scanf("%d", &n);
	int i;
	for(i=0;i<100;i++) {
	    arr[i] = 0;
	}
	for(i=0;i<n;i++) {
	    int temp;
	    scanf("%d", &temp);
	    arr[temp-1]++;
	}
	
	
	int max = arr[0];
	int index = 0;

	for(i=1;i<100;i++) {
	    if(max < arr[i]) {
	        max = arr[i];
	        index = i+1;
	    }
	}
	printf("%d", index);
	return 0;
}