

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void reverse(char *str, int i, int j) {
    printf("%s\n", str);
    printf("%d\n%d\n", i ,j);
    while(i<j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }    
}


int main() {
	int n;
	scanf("%d\n", &n);
	int i;
	char str_list[n][100];
	
	for(i=0;i<n;i++) {
	    gets(str_list[i]);
	}
	
	for(i=0;i<n;i++) {
	    int j;
	    int index_i = 0;
	    int index_j;
	    for(j=0;j<strlen(str_list[i])+1;j++) {
	        if(str_list[i][j] == ' ' || str_list[i][j] == '\0'){
	            index_j = j;
	            
	            reverse(str_list[i], index_i, index_j-1);
	            index_i = j+1;
	        }
	    }
	}
	
	for(i=0;i<n;i++) {
	    printf("%s\n", str_list[i]);
	}
	
	return 0;
}