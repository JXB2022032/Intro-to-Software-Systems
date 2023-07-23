
//Programmer: Yueqiao Zhang
//Date: 2023/4/10

#include<stdio.h>
#include "mini5phone.h"


int menu() {
	int selection;
	char garbage[5];

	printf("Phonebook Menu: (1)Add, (2)Delete/Clear, (3)Find, (4)List, (5)Quit > "); //changed menu options
	scanf("%d", &selection);
	fgets(garbage,4,stdin);

	return selection;
}

int main() {
	int choice, record;
	char choice2, garbage[5], name[50], birth[50], phone[50];

	loadCSV("phonebook.csv");

	do {
		choice = menu();

		switch(choice) {
			case 1:
				printf("Name: ");  fgets(name,49,stdin);  name[strlen(name)-1]   = '\0';
				printf("Birth: "); fgets(birth,12,stdin); birth[strlen(birth)-1] = '\0';
				printf("Phone: "); fgets(phone,14,stdin); phone[strlen(phone)-1] = '\0';

				record = addRecord(name, birth, phone);
				if (record != 0) printf("CSV if out of space\n");

				break;

			case 2:
		                //Programmer:Huanzhi Wang
				//Created :2023/03/10	

				printf("(D)elete/(C)lear > ");
				scanf("%c", &choice2);
				fgets(garbage,4,stdin);

				switch(choice2) {
					case 'D':
						printf("Name to delete: ");
						fgets(name,49,stdin);
						name[strlen(name)-1]='\0';
						record=deleteRecord(name);
						if (record==1)printf("Sorry not found\n");
						break;
					
					case 'C':
						// todo Clear
						// Programmer:Huanzhi Wang
						// Created:2023/03/10
						printf("Are you sure (Y/N)>");
						scanf("%c",&choice2);
						fgets(garbage,4,stdin);
						if (choice2 == 'Y'){
						
							clearRecord();
						
						}
						break;

					default:
						printf("Invalid input");
						break;
				}
				break;

			case 3:
				printf("Find name: "); fgets(name,49,stdin); name[strlen(name)-1] = '\0';
				
				record = findRecord(name);

				if (record == -1) printf("Does not exist\n");
				
					
				break;

			case 4:
				record = listRecords();

				if (record == -1) printf("Phonebook.csv does not exist\n");
				break;

			case 5:
				break;

			default:
				printf("Invalid menu selection\n");
		}
	} while(choice != 5);

	saveCSV("phonebook.csv");

	printf("End of phonebook program\n");

	return 0;
}

