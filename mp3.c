#include <stdio.h>
#include <string.h>
#include "mp3.h"
#include <stdlib.h>

typedef struct mp3 {
	char *name;
	char *title;
	int year;
	int runtime;
	struct mp3* next;
	struct mp3* prev;
}mp3;

void printMp3(mp3* mp3){
	printf("*********************************************** \n");
	printf("Name of Mp3: %s \n", mp3->name);
	printf("Title of Mp3: %s \n", mp3->title);
	printf("Year of Release: %d \n", mp3->year);
	printf("Runtime of Mp3: %d \n", mp3->runtime);
	if(mp3->next != NULL){
		printf("Next Mp3: %s \n", mp3->next->name);
	}
	else{
		printf("No Next Song \n");
	}
	if(mp3->prev != NULL){
		printf("Previous Mp3: %s \n", mp3->prev->name);
	}
	else{
		printf("No Previous Song \n");
	}
}

void printMp3List(mp3* head){
	printf("Start of List \n");
	struct mp3* current = head;
	while(current != NULL){
		printMp3(current);
		current = current->next;
	}
}

mp3* createMp3(char* n, char* t, int y, int rt, mp3* nxt, mp3* prv){
	mp3* returnMp3 = (mp3*)malloc(sizeof(mp3));
	returnMp3->name = n;
	returnMp3->title = t;
	returnMp3->year = y;
	returnMp3->runtime = rt;
	returnMp3->next = nxt;
	returnMp3->prev = prv;
	return returnMp3;
}	

mp3* createMp3FromInput(){
	char* name = (char*)malloc(sizeof(char));
	char* title = (char*)malloc(sizeof(char));
	//int* year = (int*)malloc(sizeof(int));
	//int* runtime = malloc(sizeof(int));;
	int year;
	int runtime;
	mp3* next = NULL;
	mp3* prev = NULL;
	printf("Please enter Song Name \n");
	fgets(name,256,stdin);
	printf("Please enter Song Title \n");
	fgets(title,256,stdin);
	printf("Please enter Song Year \n");
	//fgets(year,256,stdin);
	scanf("%d", &year);
	printf("Plese enter Song Runtime \n");
	//fgets(runtime,256,stdin);
	scanf("%d", &runtime);
	return createMp3(name, title, year, runtime, next, prev);
}

void append(mp3* head, mp3* tail){
	mp3* new = createMp3FromInput();
	if(head == NULL && tail == NULL){
		head = new;
		tail = new;
	}
	else{
		tail->next = new;
		new->prev = tail;
		tail = new;
	}
}

int main(){
	/*
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
	mp3* t1 = (struct mp3*)malloc(sizeof(struct mp3));
	mp3* t2 = (mp3*)malloc(sizeof(mp3));
	t1->name = a;
	t1->title = b;
	t1->year = 2019;
	t1->runtime = 500;
	t1->next = NULL;
	t1->prev = NULL;
	t2->name = b;
	t2->title = a;
	t2->year = 2020;
	t2->runtime = 200;
	t2->next = NULL;
	t2->prev = t1;
	t1->next = t2;
	struct mp3 mp1 = {a,b,2019,500,NULL,NULL};
	struct mp3 mp2 = {t, n, 2020, 100, NULL, &mp1};
	*/
	//printMp3List(t1);
	char* a = (char*)malloc(sizeof(char));
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';
	char* b = (char*)malloc(sizeof(char));
	b[0] = 'z';
	b[1] = 'x';
	b[2] = 'y';
	//printMp3(createMp3(a,b,2019,5232310,NULL,NULL));
	mp3* t1 = createMp3(a,b,2019,500,NULL,NULL);
	mp3* t2 = createMp3(b,a,2019,500,NULL,NULL);
	t1->next = t2;
	t2->prev = t1;
	//printMp3List(t1);
	//printf("enter test string \n");
	char* c = (char*)malloc(sizeof(char));
	//scanf("%s", c);
	//fgets(c, 256, stdin);
	//printf("%s", c);
	//mp1.next = &mp2;
	//printMp3(mp1);
	//printf(mp1.name,mp1.title,mp1.year,mp1.runtime);
	printMp3(createMp3FromInput());
	return 0;
}
	

