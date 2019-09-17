#ifndef mp3_H_
#define mp3_H_
typedef struct mp3 mp3;
void printMp3(mp3* mp3);
void printMp3List(mp3* head);
mp3* createMp3(char* n, char* t, int y, int rt, mp3* nxt, mp3* prv);
mp3* createMp3FromInput();
#endif

