
//Created:2023/04/13
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PHONE_NODE {
	char name[50];
	char birthdate[12];
	char phone[15];
	struct PHONE_NODE *next;
};

int nextIndex = 0; // assumes phonebook is empty
int isEmptyCSV = 1; // assume empty
struct PHONE_NODE *head = NULL;

// func prototype
void printHeading();
void printContent(char *name, char *bith, char *phone);
//The loadCSV function loads the contents of a CSV file into a linked list for the phonebook application.
int loadCSV(char *filename) {
	FILE *p = fopen(filename, "rt");
	char buffer[1000];
	int i,j;

	if (p == NULL) {
		isEmptyCSV = 1; // make true
		return 1; // error code
	}

	// otherwise, the file is open, read CSV
	
	fgets(buffer,999,p); // to read the CSV header (we discard it)
	isEmptyCSV = 0; // it is not empty

	nextIndex = 0;
	fgets(buffer,999,p);
	while(!feof(p)) {
		// parse the CSV record
		struct PHONE_NODE *temp = (struct PHONE_NODE *) malloc(sizeof(struct PHONE_NODE));
		if (temp == NULL) return 2;

		for(j=0,i=0;i<999&&buffer[i]!='\0'&&buffer[i]!=',';i++,j++)
			temp->name[j] = buffer[i];

		temp->name[j]='\0';
		i++;

		for(j=0;i<999&&buffer[i]!='\0'&&buffer[i]!=',';i++,j++)
			temp->birthdate[j]=buffer[i];

		temp->birthdate[j]='\0';
		i++;

		for(j=0;i<999&&buffer[i]!='\0'&&buffer[i]!='\n';i++,j++)
			temp->phone[j]=buffer[i];

		temp->phone[j]='\0';

		if (nextIndex == 0) {
			head = temp;
		} else {
			temp->next = head;
			head = temp;
		}
		// Get the next record
		fgets(buffer,999,p);
		nextIndex++;
	}

	fclose(p);

	return 0;
}
//The saveCSV function is responsible for saving the phonebook data stored in the linked list to a CSV file.
int saveCSV(char *filename) {
	FILE *p = fopen(filename,"wt");
	struct PHONE_NODE *current = head;
	int i;
	struct PHONE_NODE *ptr = head;

	if (p == NULL) return 1; // error code

	if (nextIndex <= 0) return 2; // error code

	if (ptr == NULL) return 3;

	fprintf(p,"name,birthdate,phone\n");

	while (current != NULL) {
		fprintf(p, "%s,%s,%s\n", current->name, current->birthdate, current->phone);
		current = current->next;
	}

	fclose(p);

	return 0;
}
//The addRecord function is responsible for adding a new record to the phonebook, which is a linked list of PHONE_NODE structs.

int addRecord(char name[], char birth[], char phone[]) {
	struct PHONE_NODE *temp = (struct PHONE_NODE *)malloc(sizeof(struct PHONE_NODE));

	strcpy(temp->name, name);
	strcpy(temp->birthdate, birth);
	strcpy(temp->phone, phone);
	
	temp->next = head;
	head = temp;


	nextIndex++;
	isEmptyCSV = 0;

	return 0;
}
//The deleteRecord function is responsible for deleting a record from the phonebook by the given name. 
int deleteRecord(char name[]) {
    struct PHONE_NODE *current = head;
    struct PHONE_NODE *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            nextIndex--;
            return 0; // Success
        }
        prev = current;
        current = current->next;
    }

    return 1; // Not found
}
//The clearRecord function is responsible for clearing all records from the phonebook, effectively deleting the entire linked list.
int clearRecord() {
    struct PHONE_NODE *current = head;
    struct PHONE_NODE *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    nextIndex = 0;
    isEmptyCSV = 1;

    return 0; // Success
}

//The findRecord function searches for a record in the phonebook linked list based on the provided name. 
int findRecord(char name[]) {
	int i;
	int found = 0;
	struct PHONE_NODE *current = head;
	while (current != NULL) {
    		if (strcmp(current->name, name) == 0) {
			printHeading();
			printContent(current->name, current->birthdate, current->phone);
			found = 1;
			break;
		}
		current = current->next;
	}
	if (!found) {
		return -1;
	}
	return 0;
}
//this methid is to print the header 
void printHeading() {
	 printf("---- NAME ---- ---- BIRTH DATE ---- ---- PHONE ----\n");
}
// this method is to adjuest the header  based on required 
void printContent(char *name, char *bith, char *phone) {
	printf("%-14s %-20s %-10s\n", name, bith, phone);
}
//The listRecords function is responsible for displaying all the records in the phonebook linked list.
int listRecords() {
	struct PHONE_NODE *current = head;

	if (nextIndex == 0 || isEmptyCSV) return -1;
	
	if (current == NULL) {
		printf("Phonebook is empty.\n");
		return 1;
	}
	printHeading();

	while (current != NULL) {
		printContent(current->name, current->birthdate, current->phone);
		current = current->next;
	}

	return 0;	
}

