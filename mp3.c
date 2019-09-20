#include <stdio.h>
#include <string.h>
#include "mp3.h"
#include <stdlib.h>
#include <ctype.h>

typedef struct mp3 {
	char *name;
	char *title;
	int year;
	int runtime;
	struct mp3* next;
	struct mp3* prev;
}mp3;

void printHelp(){
  printf("LIST OF COMMANDS AND THEIR DESCRIPTION (COMMAND - DESCRIPTION)\n\"Add\" - Adds an Mp3 to the end of the list\n\"PrintB\" - Prints the list from the beginning\n\"PrintE\" - Prints the list from the end\n\"Delete\" - Deletes all Mp3s from the list with the given Artist's name and frees up their memories\n\"Exit\" - Terminates the program and frees up all memory\n-------------------------------------------------------------------------------\n");
}

int isNumber(char* str){
  for(int i = 0; i< strlen(str); i++){
    if(!isdigit(str[i])){
      return 0;
    }
  }
  return 1;
}

void printMp3(mp3* mp3){
	printf("*********************************************** \n");
	printf("Artist Name of Mp3: %s \n", mp3->name);
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
  printf("Memory Address of Mp3: %p \n", mp3);
}



void printMp3ListFromBeginning(mp3** head){
	printf(">>Start of List \n");
  if(*head == NULL){
    printf(">>Empty list\n");
  }
  else{
	  mp3* current = *head;
	  while(current != NULL){
	  	printMp3(current);
	  	current = current->next;
	  }
  }
}

void printMp3ListFromEnd(mp3** tail){
  printf(">>End of List\n");
  if(*tail == NULL){
    printf(">>Empty list\n");
  }
  else{
	  mp3* current = *tail;
	  while(current != NULL){
  		printMp3(current);
	  	current = current->prev;
	  }
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
  char* input = (char*)malloc(sizeof(char));
	int year = -1;
  int runtime = -1;
  mp3* next = NULL;
	mp3* prev = NULL;
	printf(">>Please enter Artist's Name\n");
	fgets(name,256,stdin);
	printf(">>Please enter Song Title\n");
	fgets(title,256,stdin);
	printf(">>Please enter Song Year\n");
  scanf("%s", input);
  while(!isNumber(input)){
    printf(">>Please enter Year as an Integer\n");
    scanf("%s", input);
  }
  year = atoi(input);
	printf(">>Plese enter Song Runtime\n");
  scanf("%s", input);
  while(!isNumber(input)){
    printf(">>Please enter Runtime as an Integer\n");
    scanf("%s", input);
  }
  runtime = atoi(input);
  free(input);
	return createMp3(strtok(name, "\n"), strtok(title, "\n"), year, runtime, next, prev);
}

void append(mp3** head, mp3** tail){
	mp3* new = createMp3FromInput();
	if(*head == NULL){
    *head = new;
		*tail = new;
	}
	else{
    mp3* lastnext = *tail;
		lastnext->next = new;
		new->prev = *tail;
		*tail = new;
	}
}

int compareMp3(mp3* mp3_1, mp3* mp3_2){
  return(mp3_1->name == mp3_2->name && mp3_1->title == mp3_2->title && mp3_1->year == mp3_2->year && mp3_1->runtime == mp3_2->runtime && mp3_1->next == mp3_2->next && mp3_1->prev == mp3_2->prev);
}

void deleteMp3(mp3* del){
  free(del->name);
  free(del->title);
  free(del);
}

void deleteMp3FromList(mp3** head, mp3** tail, char* del_name){
  mp3* current = *head;
	while(current != NULL){
		mp3* del_mp3 = NULL;
    if(strcmp(current->name,del_name) == 0){
      del_mp3 = current;
      if(*head == del_mp3){
        if(current->next != NULL){
          *head = current->next;
          current->next->prev = NULL;
        }
        else{
          *head = NULL;
          *tail = NULL;
        }
      }
      else if(*tail == del_mp3){
        if(current->prev != NULL){
          *tail = current->prev;
          current->prev->next = NULL;
        }
        else{
          *tail = NULL;
          *head = NULL;
        }
      }
      else{
        current->prev->next = current->next;
        current->next->prev = current->prev;
      }
      current = del_mp3->next;
      deleteMp3(del_mp3);
    }
    else{
		  current = current->next;
    }
	}
}

void deleteProgram(mp3** head, mp3** tail){
  printf("Freeing up ALL memory\n");
	mp3* current = *head;
	while(current != NULL){
		deleteMp3(current);
		current = current->next;
  }
  free(head);
  free(tail);
}

int main(){
	mp3 *head = (mp3*)malloc(sizeof(mp3));
  mp3 *tail = (mp3*)malloc(sizeof(mp3));
  head = NULL;
	tail = NULL;
	char* input = (char*)malloc(256*sizeof(char));
  char* buffer = (char*)malloc(256*sizeof(char));
  printHelp();
  do{
    scanf("%s", input);
    fgets(buffer, 256, stdin);
    input = strtok(input,"\n");
    if(strcmp(input, "Add") == 0){
			append(&head, &tail);
      printf(">>Mp3 Added!\n");
		}
		else if(strcmp(input, "PrintB") == 0){
			printMp3ListFromBeginning(&head);
      printf(">>List Printed!\n");
		}
    else if(strcmp(input, "PrintE") == 0){
			printMp3ListFromEnd(&tail);
      printf(">>List Printed!\n");
		}
    else if(strcmp(input, "Delete") == 0){
      printf(">>Enter the Name of the Artist to Delete\n");
      fgets(input, 256, stdin);
      deleteMp3FromList(&head, &tail, strtok(input,"\n"));
      printf(">>Mp3(s) Deleted\n");
    }
    else if(strcmp(input, "Help") == 0){
      printHelp();
    }
    else{
      printf(">>Invalid Command, type \"Help\" to get a list of Commands\n");
    }
  }while((strcmp(strtok(input, "\n"), "Exit") != 0));
  deleteProgram(&head,&tail);
  free(input);
  free(buffer);
	return 0;
}
	

