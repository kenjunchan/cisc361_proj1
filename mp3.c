#include <stdio.h>
#include <string.h>
typedef struct mp3 {
	char *name;
	char *title;
	int year;
	int runtime;
	struct mp3* next;
	struct mp3* prev;
}mp3_t;

int main(){
	char n[3] = {'a','b','c'};
	char t[3] = {'d','e','f'};
	struct mp3 mp1 = {n,t,2019,500,NULL,NULL};
	printf("%s",mp1.name);
	printf("%s",mp1.title);
	printf("%d",mp1.year);
	printf("%d",mp1.runtime);
	printf(mp1.name,mp1.title,mp1.year,mp1.runtime);
	return 0;
}
	
