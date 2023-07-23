#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char* firstWord = argv[1];
	char* secondWord = argv[2];
	
	if(firstWord==NULL||secondWord==NULL) {
		return 1;
	}
	// Compare the length of the two words 
	if (strlen(firstWord)!=strlen(secondWord)) {
		printf("Not an anagram\n");
		return 1;
	}

	// Convert to lower case for both arrays
	for (int i=0; i<strlen(firstWord); i++) {
		if (firstWord[i] > 'A' && firstWord[i] < 'Z') {
			firstWord[i] = firstWord[i] + 32;
		}
		if (secondWord[i] > 'A' && secondWord[i] < 'Z') {
			secondWord[i] = secondWord[i] + 32;
		}
	}
	// Sort the two arrays 
	for (int i=0; i<strlen(firstWord)-1; i++) {
		for (int j=i+1; j<strlen(firstWord); j++) {
			if (firstWord[i]>firstWord[j]) {
				int temp = firstWord[j];    // Swap
				firstWord[j] = firstWord[i];
				firstWord[i] = temp;
			}
			if (secondWord[i]>secondWord[j]) {
				int temp = secondWord[j];
				secondWord[j] = secondWord[i];
				secondWord[i] = temp;
			}
		}
	}
	// Compare the two words 
	for (int i=0; i<strlen(firstWord); i++) {
		if (firstWord[i] != secondWord[i]) {
			printf("Not an anagram\n");
			return 1;
		}
	}
	printf("Anagram\n");
	return 0;
}
