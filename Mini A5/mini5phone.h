#include<string.h>
#define MAX_RECORDS 10

struct PHONE_NODE {
	char name[50];
	char birthdate[12];
	char phone[15];
	struct PHONE_NODE *next;
};
extern struct PHONE_NODE *phonebook;
int loadCSV(char *filename);
int saveCSV(char *filename);
int addRecord(char name[], char birth[], char phone[]);
int deleteRecord(char name[]);
int clearRecord();
int findRecord(char name[]);
void printHeading();
void printContent(char *name, char *bith, char *phone);
int listRecords();
