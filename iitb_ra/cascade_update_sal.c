#include <stdio.h>

int main() {
	int rows;
	int cols = 3;
	scanf("%d", &rows);
	int arr[rows][3];
	int i,j;
	for(i=0;i<rows;i++) {
	    for(j=0;j<cols;j++) {
	        scanf("%d", &arr[i][j]);
	    }
	}
	
	int emp_id, inc;
	int boss, new_sal;
	scanf("%d", &emp_id);
	scanf("%d", &inc);
	
	for(i=0;i<rows;i++) {
	    if(arr[i][0] == emp_id){
	        arr[i][2] += inc;
	        boss = arr[i][1];
	        new_sal = arr[i][2];
	    }
	}
	
	for(i=0;i<rows;i++) {
	    if(arr[i][0] == boss) {
	        if(arr[i][2] < new_sal) {
	            arr[i][2] += 5000;
	            boss = arr[i][1];
	            new_sal = arr[1][2];
	        }
	    }
	}
	
	for(i=0;i<rows;i++) {
	    for(j=0;j<cols;j++) {
	        printf("%d ", arr[i][j]);
	    }
	    printf("\n");
	}
	return 0;
}