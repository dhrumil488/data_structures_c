
#include <stdio.h>

int main() {
	int x11, y11, x12, y12;
	scanf("%d %d\n%d %d\n", &x11, &y11, &x12, &y12);
	
	int x21, y21, x22, y22;
	scanf("%d %d\n%d %d\n", &x21, &y21, &x22, &y22);
	
	int slope1, slope2;
	
	if((x12-x11) != 0) {
	    slope1 = (y12-y11)/(x12-x11);
	}
	if((x12-x11) != 0) {
	    slope2 = (y22-y21)/(x22-x21);
	}
	
	if(slope2 == slope1) {
	    printf("0\n");
	} else {
	    printf("1\n");
	}
	
	return 0;
}