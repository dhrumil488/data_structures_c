#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str[100];
	int error = 0;
	scanf("%s", str);
	int i;
	char str_freq[26];
	for(i=0;i<strlen(str);i++) {
	    int temp = (str[i]);
	    if(temp >= 97 && temp <=122) {
	        str_freq[temp-97] = 1;
	    } else {
	        error = 1;
	    }
	         
	}
	
	for(i=0;i<26;i++) {
	    if(str_freq[i] == 1) {
	        printf("%c", (i+97));
	    }
	}
	if(error == 1) {
	    printf(" error");
	}
	
	return 0;
}