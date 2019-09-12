#include <stdio.h>
#include "mp3.h"
#include <string.h>
#include <stdlib.h>
typedef struct mp3 {
	char *name;
	char *title;
	int year;
	int runtime;
	struct mp3* next;
	struct mp3* prev;
}mp3_t;

void printMp3(struct mp3* mp3){
	printf("***********************************************");
	printf("Name of Mp3: %s \n", mp3->name);
	printf("Title of Mp3: %s \n", mp3->title);
	printf("Year of Release: %d \n", mp3->year);
	printf("Runtime of Mp3: %d \n", mp3->runtime);
	if(mp3.next != NULL){
		printf("Next Mp3: %s \n", mp3->next->name);
	}
	else{
		printf("No Next Song \n");
	}
	if(mp3.prev != NULL){
		printf("Previous Mp3: %s \n", mp3->prev->name);
	}
	else{
		printf("No Previous Song \n");
	}
}
void printMp3List(struct mp3* head){
	printf("Start of List");
	struct mp3* current = head;
	while(current != NULL){
		printMp3(current);
		current = current->next;
	}
}
int main(){
	char *a = (char*)malloc(5* sizeof(char));
	if(a == NULL){
		printf("Memory NOT allocated \n");
	}
	else{
		a[0] = 'a';
		a[1] = 'b';
		a[2] = 'c';
	}
	char *b = (char*)malloc(5* sizeof(char));
	b[0] = 'd';
	b[1] = 'e';
	b[2] = 'f';
	char n[3] = {'a','b','c'};
	char t[3] = {'d','e','f'};
	struct mp3 mp1 = {a,b,2019,500,NULL,NULL};
	struct mp3 mp2 = {t, n, 2020, 100, NULL, &mp1};
	mp1.next = &mp2;
	printMp3(mp1);
	printf(mp1.name,mp1.title,mp1.year,mp1.runtime);
	return 0;
}
	

