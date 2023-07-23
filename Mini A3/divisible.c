#include <stdio.h>

int main() {
	int n1, n2, n3;
	
	printf("Please input three numbers: ");
	scanf("%d %d %d", &n1, &n2, &n3);	// ask for user inputs
	
	if (n1<n2 && n1<n3 && n2<n3) {
		if (n1==0) { 	// edge case, n1 is zero
			printf("Not Divisible & Increasing\n");
            		return 1;
		}
		if (n2%n1==0 && n3%n1==0) {
			printf("Divisible & Increasing\n");
			return 0;
		} else {
			printf("Not Divisible & Increasing\n");
			return 1;
		}
	} else {
		if (n2%n1==0 && n3%n1==0) {
			printf("Divisible & Not Increasing\n");
			return 2;
		} else { 
			printf("Not Divisible & Not Increasing\n");
			return 3;
		}
	}
}


