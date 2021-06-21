#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <string>
#define tt "±i§Ó»¨"
using namespace std;
char hhh[10][7] = {"12","123","123","111","555","±i§Ó»¨"};
typedef struct {
    int index;
    int vsR;
    int vsL;
    int power;
    char LR;
} Hitter;

typedef struct {
    char name[10];
    int vsR;
    int vsL;
    int Kkk;
    double goao;
    char LR;
} Pitcher;

Hitter team1_hitter[9];
Pitcher team1_pitcher[5];
int main(void) {
	FILE  *fin;
	int a;
	fin = fopen("test.txt", "r");
	int line[255];
	
	fscanf(fin, "%s", &line);
	//fgets(line, 255, fin);
	printf("%d", line);
	
	//fscanf(fin, "%s", team1_pitcher[0].name); 
	//team1_pitcher[0].name[0]*256+team1_pitcher[0].name[1];
	
        
		
	return 0;
}



