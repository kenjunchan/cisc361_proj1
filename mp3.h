#ifndef mp3_H_
#define mp3_H_
typedef struct mp3 mp3;
void printHelp();
int isNumber(char* str);
void printMp3(mp3* mp3);
void printMp3ListFromBeginning(mp3** head);
void printMp3ListFromEnd(mp3** tail);
mp3* createMp3(char* n, char* t, int y, int rt, mp3* nxt, mp3* prv);
mp3* createMp3FromInput();
void append(mp3** head, mp3** tail);
int compareMp3(mp3* mp3_1, mp3* mp3_2);
void deleteMp3(mp3* del);
void deleteMp3FromList(mp3** head, mp3** tail, char* del_name);
void deleteProgram(mp3** head, mp3** tail);
#endif

