
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "func.h"



void clear (void) { while ( getchar() != '\n' ); } 
int quit_ = 0;
int input;
char input_c; 
int team1, team2, p1, p2;//p1, p2 => pitcher

int menu(void) {
	srand(time(NULL));
	printf("�w����{����¾��110�~ �����ɨ�\n");
	printf("1.�}�l 2.�d�ݹC���]�w 3.���}\n");
	printf("��J: ");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 3)) {
		clear();
		printf("��J���~�A�ЦA��J�@��!!");
		printf("��J: ");
	} clear();

	switch (input) {
		case 1:
			system("cls");
			chooseTeam();
			if (quit_ == 0) {
			system("cls");
			choosePitcher(team1, team2, &p1, &p2);	
			}
			break;
		case 2:
			system("cls");
			rule();
			break;
		case 3:
			quit();
			break;
	}
	if (quit_ == 0) return 0;
	else return 666;
}

void rule(void) {
	printf("1.�@���u��3���C\n2.�p�G3����������A�Y���M���C\n3.���|�X�{�O�e�C\n4.�w���u��2�S�w���P1�S�w���C\n5.���Ҽ{�ӽ������]�S�P�_:\n  ���S�W���H: �@�S�w��: �Ҧ��]�̬ҩ��e���i�@���S�]\n	      �G�S�w��: �Ҧ��]�̬ҩ��e���i����S�]\n6.���u�T�w�A���}���ԥ��o���u�A����󴫥���\n7.���o�󴫧��");
	printf("\n\n--��Jy��^--\n��J:");
	while ((scanf("%c", &input_c) != 1) || (input_c != 'Y' && input_c != 'y')) {
		clear();
		printf("\n--��Jy��^--\n��J:");
	} clear();
	system("cls");
	menu();
}


int quit(void) {
	printf("----����----");
	quit_ = 1;
	return 0;
}


char team_list[5][9] = {"���H�S��", "�Τ@��", "�����s", "�I�����N", "�֤Ѯ��"};


void chooseTeam(void) {
	int i;
	for (i=0; i<5; i++) {
		printf("%d. %s \n", i+1, team_list[i]);
	}
	printf("\n��ܥ���y��(��J�s��):");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 5)) {
		clear();
		printf("��J���~�A�ЦA��J�@��!!");
		printf("��ܥ���y��(��J�s��): ");
	} clear();
	team1 = input-1;
	printf("��ܥ��u�y��(��J�s��):");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 5)) {
		clear();
		printf("��J���~�A�ЦA��J�@��!!");
		printf("��ܥ��u�y��(��J�s��): ");
	} clear();
	team2 = input-1;
	system("cls");
	printf("����:%s VS ���u:%s \n", team_list[team1], team_list[team2]);
	printf("�H�W���z��ܪ��y���A��y�~��A��r���s��ܡA��q���}");
	printf("��J: ");
	while ((scanf("%c", &input_c) != 1) || (input_c != 'q' && 
	input_c != 'Q' && input_c != 'r' && input_c != 'R' && 
	input_c != 'Y' && input_c != 'y')) {
		clear();
		printf("��J���~�A�ЦA��J�@��!!");
		printf("��J: ");
	} clear();
	system("cls");
	switch (input_c) {
		case 'y':
		case 'Y':
			loadTeam(team1, team2);
			break;
		case 'r':
		case 'R':
			chooseTeam();
			break;
		case 'q':
		case 'Q':
			quit();
			break;	 
	}
	return;
}

typedef struct {
	int index;
    int vsR;
    int vsL;
    int power;
    char LR;
} Hitter;

typedef struct {
	int index;
    int vsR;
    int vsL;
    int Kkk;
    double goao;
    char LR;
} Pitcher;

Hitter team1_hitter[9];
Pitcher team1_pitcher[5];
Hitter team2_hitter[9];
Pitcher team2_pitcher[5];




void loadTeam(int t1, int t2) {
	int i = 0;
	FILE  *fin;
	 
	while (i<2) {
		
		switch (t1) {
			case 0:
				fin = fopen("���H�S�̿����.txt", "r");
				break;
			case 1:
				fin = fopen("�Τ@������.txt", "r");
				break;
			case 2:
				fin = fopen("�����s�����.txt", "r");
				break;
			case 3:
				fin = fopen("�I�����N�����.txt", "r");
				break;
			case 4:
				fin = fopen("�֤Ѯ������.txt", "r");
				break;
		}
		int j;
		
		switch (i) {
			case 0:
				for (j=0; j<9; j++) {
					fscanf(fin, "%d", &team1_hitter[j].index);
					//printf("%d\n", team1_hitter[j].index);
					fscanf(fin, "%d", &team1_hitter[j].vsR);
					//printf("%d\n", team1_hitter[j].vsR);
					fscanf(fin, "%d", &team1_hitter[j].vsL);
					//printf("%d\n", team1_hitter[j].vsL);
					fscanf(fin, "%d", &team1_hitter[j].power);
					//printf("%d\n", team1_hitter[j].power);
					fscanf(fin, " %c", &team1_hitter[j].LR);
					//printf("%c\n\n", team1_hitter[j].LR);
				}
				for (j=0; j<5; j++) {
					fscanf(fin, "%d", &team1_pitcher[j].index);
					printf("%d\n", team1_pitcher[j].index);
					fscanf(fin, "%d", &team1_pitcher[j].vsR);
					printf("%d\n", team1_pitcher[j].vsR);
					fscanf(fin, "%d", &team1_pitcher[j].vsL);
					printf("%d\n", team1_pitcher[j].vsL);
					fscanf(fin, "%d", &team1_pitcher[j].Kkk);
					printf("%d\n", team1_pitcher[j].Kkk);
					fscanf(fin, "%lf", &team1_pitcher[j].goao);
					printf("%f\n", team1_pitcher[j].goao);
					fscanf(fin, " %c", &team1_pitcher[j].LR);
					printf("%c\n\n", team1_pitcher[j].LR);
				}
				break;
			case 1:
				for (j=0; j<9; j++) {
					fscanf(fin, "%d", &team2_hitter[j].index);
					fscanf(fin, "%d", &team2_hitter[j].vsR);
					fscanf(fin, "%d", &team2_hitter[j].vsL);
					fscanf(fin, "%d", &team2_hitter[j].power);
					fscanf(fin, " %c", &team2_hitter[j].LR);
				}
				for (j=0; j<5; j++) {
					fscanf(fin, "%d", &team2_pitcher[j].index);
					fscanf(fin, "%d", &team2_pitcher[j].vsR);
					fscanf(fin, "%d", &team2_pitcher[j].vsL);
					fscanf(fin, "%d", &team2_pitcher[j].Kkk);
					fscanf(fin, "%lf", &team2_pitcher[j].goao);
					fscanf(fin, " %c", &team2_pitcher[j].LR);
				}
				break;
		}
		fclose(fin);
		i++;
		t1 = t2;
	}
	
	return;
	
}

//�ѩ�bŪ�ɼg�J�ɡA����W�rŪ�J���X�Ҭ��ýX�A�ҥH�b���ѨM�覡�e�A�u������@�Ӳy���W��A�Q�νs���d��
char playerList[70][9] = {"���±�","���[�t","�i�ӻ�","��l��","�\\��","�P���","���l��","���t�N","Ĭ�n�F","�w�O��","�G�ͤ�","�[�ʧQ","�֤ܺO","���A��", "���Ǿ�","�L�t��","���`��","�L�w�i","�����L","Ĭ����","�I�a�t","�L����","�L���w","���p�J","�r�º�","�j�L�ͷ�","���}","������", "���Ǫ@","���p��","���ͫ�","�B���E","������","���~��","�L����","�B�ɻ�","�d�F��","�}�Y��","������","�L�l�R","������","���M", "���v��","������","�L�q��","�����","������","������","�ӵq޳","�L��ޱ","�L�ɿo","���F","ù�O","����","�Ǵ�","���h�B", "��ģ��","�L��","�űG��","���T�q","���|��","�L�l�|","���Y��","�L�ӭ�","�ⴼ��","�Q�L��","�i�߳�","���l�P","��޳��","������"};  


void choosePitcher(int t1, int t2, int *p1, int *p2) {
	int i ,j;

	printf("%s �����o���p�U:\n", team_list[t1]);
	for (i=0; i<5; i++) {
		j = team1_pitcher[i].index;
		printf("%d. %s\n", i+1, playerList[j]);
	}
	printf("�п�ܥ��o���(��J�s��):");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 5)) {
		clear();
		printf("��J���~�A�ЦA��J�@��!!");
		printf("�п�ܥ��o���(��J�s��): ");
	} clear();
	*p1 = input -1;
	
	printf("\n%s �����o���p�U:\n", team_list[t2]);
	for (i=0; i<5; i++) {
		j = team2_pitcher[i].index;
		printf("%d. %s\n", i+1, playerList[j]);
	}
	printf("�п�ܥ��o���(��J�s��):");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 5)) {
		clear();
		printf("��J���~�A�ЦA��J�@��!!");
		printf("�п�ܥ��o���(��J�s��): ");
	} clear();
	*p2 = input -1;
	
	return;
}  


int inning = 1;// inning 1�@���W 2�@���U 3�G���W 4 �G���U.... 
int h1 = 0;//���̴Φ� 
int h2 = 0;
int result;
int base_live;
int out = 0;
int t1_run, t2_run;
int inn_count[7];//�����C�������u 


void start_sim(void) {
	
	
	int newRun, count=0;
	FILE  *fout;
	fout = fopen("record.txt", "w");
	
	while (1) {
		
		out = 0;
		base_live = 9;
		fprintf(fout, "%d\n", inning);
		while (1) {
			newRun = 0;
			battle(h1, 0);//�|����out �B result �B base_live
			if (result == 0 || result == 1 || result == 2) out++;
			newRun = sim_running();
			t1_run += newRun;
			fprintf(fout, "%d %d %d %d %d\n", h1, result, newRun, base_live, out);
			count ++;
			h1 = (h1+1)%9;
			if (out == 3) break;
			
			
		}
		switch (inning) {
			case 1:
				//printf("%d\n", count);
				inn_count[1] = count;
				break;
			case 3:
				//printf("%d\n", count);
				inn_count[3] = count;
				break;
			case 5:
				//printf("%d\n", count);
				inn_count[5] = count;
				break;
		}
		inning ++;
		
		
		
		out = 0;
		base_live = 9;
		fprintf(fout, "%d\n", inning);
		while (1) {
			newRun = 0;
			battle(h2, 1);//�|����out �B result �B base_live 
			if (result == 0 || result == 1 || result == 2) out++;
			newRun = sim_running();
			t2_run += newRun;
			fprintf(fout, "%d %d %d %d %d\n", h2, result, newRun, base_live, out);
			count ++;
			h2 = (h2+1)%9;
			if (out == 3) break;
			
			
		}
		switch (inning) {
			case 2:
				//printf("%d\n", count);
				inn_count[2] = count;
				break;
			case 4:
				//printf("%d\n", count);
				inn_count[4] = count;
				break;
			case 6:
				//printf("%d\n", count);
				inn_count[6] = count;
				break;
		}
		
		if (inning >= 5) break;
		inning ++;		
	}
	fclose(fout);
}
//base_live 0:�@�S���H�A1:�G�S���H�A2:�T�S���H�A3:�@�B�G�S���H�A 
//4:�G�B�T�S���H�A5:�@�B�T�S���H�A6:���S���A7:�S�W�ثe�S�H�A
//8:���b�������A9:������}�l  
int sim_running(void) {
	if (out == 3) base_live = 8; //out <- �X���� 
	switch (base_live) {  
		case 0:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 3;
					return 0;
					break;
				case 4:
					base_live = 4;
					return 0;
					break;
			}
			break;
		case 1:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 5;
					return 0;
					break;
				case 4:
					base_live = 1;
					return 1;
					break;
			}
			break;
		case 2:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 0;
					return 1;
					break;
				case 4:
					base_live = 1;
					return 1;
					break;
			}
			break;
		case 3:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 6;
					return 0;
					break;
				case 4:
					base_live = 4;
					return 1;
				}
			break;
		case 4:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 3;
					return 1;
					break;
				case 4:
					base_live = 1;
					return 2;
				}
			break;
		case 5:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 3;
					return 1;
					break;
				case 4:
					base_live = 4;
					return 1;
				}
			break;	
		case 6:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 6;
					return 1;
					break;
				case 4:
					base_live = 4;
					return 2;
				}
			break;
		case 7:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 0;
					return 0;
					break;
				case 4:
					base_live = 1;
					return 0;
				}
			break;	
		case 8:
			return 0;
			break;
		case 9:
			switch (result) {
				case 0:
					return 0;
					break;
				case 1:
					return 0;
					break;
				case 2:
					return 0;
					break;
				case 3:
					base_live = 0;
					return 0;
					break;
				case 4:
					base_live = 1;
					return 0;
				}
			break;
	}
}



void battle(int h, int t) {
	int random; 
	int result_i;//�X�� 0 �B�w�� 1 �uor��2  
	int d;
	int pr;
	int s = 0;
	switch (t) {
		case 0:
			switch (team2_pitcher[p2].LR) {
				case 'L':
					switch (team1_hitter[h].LR) {
						case 'L':
							//pL vs hL
							//1000 = 1�� 
							random = (rand()%100)+1;
							d = abs(team2_pitcher[p2].vsL - team1_hitter[h].vsL);
							pr = d/2+50;
							if (team2_pitcher[p2].vsL > team1_hitter[h].vsL) {
								if (random < pr) result_i = 0; 
								else if (random > pr) result_i = 1;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
								}
							} else if (team2_pitcher[p2].vsL < team1_hitter[h].vsL) {
								if (random < pr) result_i = 0; 
								else if (random > pr) result_i = 1;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
								}
							} else {	
								random = (rand()%100)+1;
								if (random > 50) result_i = 0;	
								else result_i = 1;
								}
							if (result_i == 1) {
								random = (rand()%100)+1;
								if (random < team1_hitter[h].power) result = 4;
								else if (random > team1_hitter[h].power) result = 3;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 4;	
									else result = 3;
								}	
							} else if (result_i == 0) {	
								random = (rand()%100)+1;
								if (random < team2_pitcher[p2].Kkk) result = 2;
								else if (random > team2_pitcher[p2].Kkk) result_i = 2;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 2;	
									else result_i = 2;
								}
							} else if (result_i == 2) {	
								random = (rand()%100)+1;
								d = abs(team2_pitcher[p2].goao-1)*100;
								pr = (int)d+40;
								if (random < pr) {
									if (team2_pitcher[p2].goao > 1)	result = 1;
									else if (team2_pitcher[p2].goao < 1) result = 0;
									else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else if (random > pr) {
									if (team2_pitcher[p2].goao > 1)	result = 0;
									else if (team2_pitcher[p2].goao < 1) result = 1;
									else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									} 
							}
							break;
						case 'R':
							//pL vs hR
							random = (rand()%100)+1;
							d = abs(team2_pitcher[p2].vsR - team1_hitter[h].vsL);
							pr = d/2+50;
							if (team2_pitcher[p2].vsR > team1_hitter[h].vsL) {
								if (random < pr) result_i = 0; 
								else if (random > pr) result_i = 1;
								else {		
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
									}
							} else if (team2_pitcher[p2].vsR < team1_hitter[h].vsL) {
								if (random < pr) result_i = 0; 
								else if (random > pr) result_i = 1;
								else {		
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
									}
							} else {	
								random = (rand()%100)+1;
								if (random > 50) result_i = 0;	
								else result_i = 1;
							}
							if (result_i == 1) {
								random = (rand()%100)+1;
								if (random < team1_hitter[h].power) result = 4;
								else if (random > team1_hitter[h].power) result = 3;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 4;	
									else result = 3;
								}	
							} else if (result_i == 0) {	
								random = (rand()%100)+1;
								if (random < team2_pitcher[p2].Kkk) result = 2;
								else if (random > team2_pitcher[p2].Kkk) result_i = 2;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 2;	
									else result_i = 2;
								}
							} else if (result_i == 2) {
								random = (rand()%100)+1;
								d = abs(team2_pitcher[p2].goao-1)*100;
								pr = (int)d+40;
								if (random < pr) {
									if (team2_pitcher[p2].goao > 1)	result = 1;
									else if (team2_pitcher[p2].goao < 1) result = 0;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else if (random > pr) {
									if (team2_pitcher[p2].goao > 1)	result = 0;
									else if (team2_pitcher[p2].goao < 1) result = 1;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									} 
							}
							break;
					}
					break;
				case 'R':
					switch (team1_hitter[h].LR) {
						case 'L':
							//pR vs hL
							random = (rand()%100)+1;
							d = abs(team2_pitcher[p2].vsL - team1_hitter[h].vsR);
							pr = d/2+50;
							if (team2_pitcher[p2].vsL > team1_hitter[h].vsR) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
								}
							} else if (team2_pitcher[p2].vsL < team1_hitter[h].vsR) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
								}
							} else {
								random = (rand()%100)+1;
								if (random > 50) result_i = 0;	
								else result_i = 1;
								}
							if (result_i == 1) {
								random = (rand()%100)+1;
								if (random < team1_hitter[h].power) result = 4;
								else if (random > team1_hitter[h].power) result = 3;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 4;	
									else result = 3;
								}	
							} else if (result_i == 0) {
								random = (rand()%100)+1;
								if (random < team2_pitcher[p2].Kkk) result = 2;
								else if (random > team2_pitcher[p2].Kkk) result_i = 2;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 2;	
									else result_i = 2;
								}
							} else if (result_i == 2) {
								random = (rand()%100)+1;
								d = abs(team2_pitcher[p2].goao-1)*100;
								pr = (int)d+40;
								if (random < pr) {
									if (team2_pitcher[p2].goao > 1)	result = 1;
									else if (team2_pitcher[p2].goao < 1) result = 0;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else if (random > pr) {
									if (team2_pitcher[p2].goao > 1)	result = 0;
									else if (team2_pitcher[p2].goao < 1) result = 1;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									} 
							}	
							break;
						case 'R':
							//pR vs hR	
							random = (rand()%100)+1;
							d = abs(team2_pitcher[p2].vsR - team1_hitter[h].vsR);
							pr = d/2+50;
							if (team2_pitcher[p2].vsR > team1_hitter[h].vsR) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
									}
							} else if (team2_pitcher[p2].vsR < team1_hitter[h].vsR) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {		
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
									}
							} else {		
								random = (rand()%100)+1;
								if (random > 50) result_i = 0;	
								else result_i = 1;
							}
							if (result_i == 1) {	
								random = (rand()%100)+1;
								if (random < team1_hitter[h].power) result = 4;
								else if (random > team1_hitter[h].power) result = 3;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 4;	
									else result = 3;
								}	
							} else if (result_i == 0) {	
								random = (rand()%100)+1;
								if (random < team2_pitcher[p2].Kkk) result = 2;
								else if (random > team2_pitcher[p2].Kkk) result_i = 2;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 2;	
									else result_i = 2;
								}
							} else if (result_i == 2) {	
								random = (rand()%100)+1;
								d = abs(team2_pitcher[p2].goao-1)*100;
								pr = (int)d+40;
								if (random < pr) {
									if (team2_pitcher[p2].goao > 1)	result = 1;
									else if (team2_pitcher[p2].goao < 1) result = 0;
									else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else if (random > pr) {
									if (team2_pitcher[p2].goao > 1)	result = 0;
									else if (team2_pitcher[p2].goao < 1) result = 1;
									else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									} 
							}
							break;
				}	}
			break;
		case 1:
			switch (team1_pitcher[p2].LR) {
				case 'L':
					switch (team2_hitter[h].LR) {
						case 'L':
							//pL vs hL
							random = (rand()%100)+1;
							d = abs(team1_pitcher[p2].vsL - team2_hitter[h].vsL);
							pr = d/2+50;
							if (team1_pitcher[p2].vsL > team2_hitter[h].vsL) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
								}
							} else if (team1_pitcher[p2].vsL < team2_hitter[h].vsL) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
								}
							} else {	
								random = (rand()%100)+1;
								if (random > 50) result_i = 0;	
								else result_i = 1;
							}
							if (result_i == 1) {
								random = (rand()%100)+1;
								if (random < team2_hitter[h].power) result = 4;
								else if (random > team2_hitter[h].power) result = 3;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 4;	
									else result = 3;
								}	
							} else if (result_i == 0) {
								random = (rand()%100)+1;
								if (random < team1_pitcher[p2].Kkk) result = 2;
								else if (random > team1_pitcher[p2].Kkk) result_i = 2;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 2;	
									else result_i = 2;
								}
							} else if (result_i == 2) {
								random = (rand()%100)+1;
								d = abs(team1_pitcher[p2].goao-1)*100;
								pr = (int)d+40;
								if (random < pr) {
									if (team1_pitcher[p2].goao > 1)	result = 1;
									else if (team1_pitcher[p2].goao < 1) result = 0;
									else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else if (random > pr) {
									if (team1_pitcher[p2].goao > 1)	result = 0;
									else if (team1_pitcher[p2].goao < 1) result = 1;
									else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									} 
							}
							break;
						case 'R':
							//pL vs hR
							random = (rand()%100)+1;
							d = abs(team1_pitcher[p2].vsR - team2_hitter[h].vsL);
							pr = d/2+50;
							if (team1_pitcher[p2].vsR > team2_hitter[h].vsL) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
									}
							} else if (team1_pitcher[p2].vsR < team2_hitter[h].vsL) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {		
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
									}
							} else {
								random = (rand()%100)+1;
								if (random > 50) result_i = 0;	
								else result_i = 1;
							}
							if (result_i == 1) {
								random = (rand()%100)+1;
								if (random < team2_hitter[h].power) result = 4;
								else if (random > team2_hitter[h].power) result = 3;
								else {
									Sleep(500);
									srand(time(NULL));
									random = (rand()%100)+1;
									if (random > 50) result = 4;	
									else result = 3;
								}	
							} else if (result_i == 0) {
								random = (rand()%100)+1;
								if (random < team1_pitcher[p2].Kkk) result = 2;
								else if (random > team1_pitcher[p2].Kkk) result_i = 2;
								else {
									random = (rand()%100)+1;
									if (random > 50) result = 2;	
									else result_i = 2;
								}
							} else if (result_i == 2) {
								random = (rand()%100)+1;
								d = abs(team1_pitcher[p2].goao-1)*100;
								pr = (int)d+40;
								if (random < pr) {
									if (team1_pitcher[p2].goao > 1)	result = 1;
									else if (team1_pitcher[p2].goao < 1) result = 0;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else if (random > pr) {
									if (team1_pitcher[p2].goao > 1)	result = 0;
									else if (team1_pitcher[p2].goao < 1) result = 1;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									} 
							}
							break;
					}
					break;
				case 'R':
					switch (team2_hitter[h].LR) {
						case 'L':
							//pR vs hL
							random = (rand()%100)+1;
							d = abs(team1_pitcher[p2].vsL - team2_hitter[h].vsR);
							pr = d/2+50;
							if (team1_pitcher[p2].vsL > team2_hitter[h].vsR) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
								}
							} else if (team1_pitcher[p2].vsL < team2_hitter[h].vsR) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {	
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
								}
							} else {
								random = (rand()%100)+1;
								if (random > 50) result_i = 0;	
								else result_i = 1;
								}
								if (result_i == 1) {
								random = (rand()%100)+1;
								if (random < team2_hitter[h].power) result = 4;
								else if (random > team2_hitter[h].power) result = 3;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 4;	
									else result = 3;
								}	
							} else if (result_i == 0) {
								random = (rand()%100)+1;
								if (random < team1_pitcher[p2].Kkk) result = 2;
								else if (random > team1_pitcher[p2].Kkk) result_i = 2;
								else {	
									random = (rand()%100)+1;
									if (random > 50) result = 2;	
									else result_i = 2;
								}
							} else if (result_i == 2) {
								random = (rand()%100)+1;
								d = abs(team1_pitcher[p2].goao-1)*100;
								pr = (int)d+40;
								if (random < pr) {
									if (team1_pitcher[p2].goao > 1)	result = 1;
									else if (team1_pitcher[p2].goao < 1) result = 0;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else if (random > pr) {
									if (team1_pitcher[p2].goao > 1)	result = 0;
									else if (team1_pitcher[p2].goao < 1) result = 1;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									} 
							}
							break;
						case 'R':
							//pR vs hR
							random = (rand()%100)+1;
							d = abs(team2_pitcher[p2].vsR - team1_hitter[h].vsR);
							pr = d/2+50;
							if (team1_pitcher[p2].vsR > team2_hitter[h].vsR) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
									}
							} else if (team1_pitcher[p2].vsR < team2_hitter[h].vsR) {
								if (random < pr) {
									result_i = 0; 
								} else if (random > pr) {
									result_i = 1;
								} else {
									random = (rand()%100)+1;
									if (random > 50) result_i = 0;	
									else result_i = 1;
									}
							} else {
								random = (rand()%100)+1;
								if (random > 50) result_i = 0;	
								else result_i = 1;
							}
							if (result_i == 1) {
								random = (rand()%100)+1;
								if (random < team2_hitter[h].power) result = 4;
								else if (random > team2_hitter[h].power) result = 3;
								else {
									random = (rand()%100)+1;
									if (random > 50) result = 4;	
									else result = 3;
								}	
							} else if (result_i == 0) {
								
								random = (rand()%100)+1;
								if (random < team1_pitcher[p2].Kkk) result = 2;
								else if (random > team1_pitcher[p2].Kkk) result_i = 2;
								else {
									random = (rand()%100)+1;
									if (random > 50) result = 2;	
									else result_i = 2;
								}
							} else if (result_i == 2) {
								
								random = (rand()%100)+1;
								d = abs(team1_pitcher[p2].goao-1)*100;
								pr = (int)d+40;
								if (random < pr) {
									if (team1_pitcher[p2].goao > 1)	result = 1;
									else if (team1_pitcher[p2].goao < 1) result = 0;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else if (random > pr) {
									if (team1_pitcher[p2].goao > 1)	result = 0;
									else if (team1_pitcher[p2].goao < 1) result = 1;
									else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									}
								} else {
									random = (rand()%100)+1;
									if (random > 50) result = 1;	
									else result = 0;
									} 
							}
							break;
			}
			break;
	}break;
}
	
	//srand(time(NULL));
	//random = (rand()%100)+1;
	
}

int base_live_ = 9,out_live_ = 0;
int run1_live[5] = {0};
int run2_live[5] = {0};
char base[4];
int show_p;

void show(void) {
	int i,j;
	
	for (i=1; i<inn_count[6] +2; i++) {
		if (i > inn_count[5]) {
			if (run2_live[4] > run1_live[4]) {
				printf("....");
				Sleep(500);    
				show_g();
				show_text(i-1);
				printf("\n���ɵ���\n------------------\n%s ���", team_list[team2]);
				break;
			}
		}
		printf("....");
		Sleep(500);    
		show_g();
		if (i>1) show_text(i-1);
		if (i<inn_count[6] +1) load_info(i);
		Sleep(500);
	}
	if (run2_live[4] < run1_live[4]) {
		printf("\n���ɵ���\n------------------\n%s ���", team_list[team1]);
	} else if (run2_live[4] == run1_live[4]) {
		printf("\n���ɵ���\n------------------\n�ⶤ����");
	}
	
	
}


void show_g(void) {
	
	
	baseload(base_live_);
	run1_live[4] = run1_live[1]+run1_live[2]+run1_live[3];
	run2_live[4] = run2_live[1]+run2_live[2]+run2_live[3];
	system("cls");

	switch (show_p) {
		case 1:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |     |     ||%3d  |      �@���W\n", team_list[team1], run1_live[1], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |     |     |     ||     |\n", team_list[team2]);
			printf("------------------------------------\n");
			break;
		case 2:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |     |     ||%3d  |      �@���U\n", team_list[team1], run1_live[1], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |     |     ||%3d  |\n", team_list[team2], run2_live[1], run2_live[4]);
			printf("------------------------------------\n");
			break;
		case 3:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |%3d  |     ||%3d  |      �G���W\n", team_list[team1], run1_live[1], run1_live[2], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |     |     ||%3d  |\n", team_list[team2], run2_live[1], run2_live[4]);
			printf("------------------------------------\n");
			break;
		case 4:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |%3d  |     ||%3d  |      �G���U\n", team_list[team1], run1_live[1], run1_live[2], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |%3d  |     ||%3d  |\n", team_list[team2], run2_live[1], run2_live[2], run2_live[4]);
			printf("------------------------------------\n");
			break;
		case 5:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |%3d  |%3d  ||%3d  |      �T���W\n", team_list[team1], run1_live[1], run1_live[2], run1_live[3], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |%3d  |     ||%3d  |\n", team_list[team2], run2_live[1], run2_live[2], run2_live[4]);
			printf("------------------------------------\n");
			break;
		case 6:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |%3d  |%3d  ||%3d  |      �T���U\n", team_list[team1], run1_live[1], run1_live[2], run1_live[3], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |%3d  |%3d  ||%3d  |\n", team_list[team2], run2_live[1], run2_live[2], run2_live[3], run2_live[4]);
			printf("------------------------------------\n");
			break;
	}

	
	
}

void baseload(int b_l_) {
	base[1] = ' ';
	base[2] = ' ';
	base[3] = ' ';
	switch (b_l_) {
		case 0:
			base[1] = '@';
			break;
		case 1:
			base[2] = '@';
			break;
		case 2:
			base[3] = '@';
			break;
		case 3:
			base[1] = '@';
			base[2] = '@';
			break;
		case 4:
			base[2] = '@';
			base[3] = '@';
			break;
		case 5:
			base[1] = '@';
			base[3] = '@';
			break;
		case 6:
			base[1] = '@';
			base[2] = '@';
			base[3] = '@';
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break; 
	}
}

void load_info(int m) {
	//system("cls");
	FILE  *fin;
	fin = fopen("record.txt", "r");
	int s_inning;
	int h_no, h_result, h_run, h_base, h_out;
	int i;
	
	if (m<inn_count[1]+1) {
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<m; i++)	fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		show_p = 1;
		run1_live[1] += h_run;
		base_live_ = h_base;
		out_live_ = h_out;
	} else if (m<inn_count[2]+1) {
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[1]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<m - inn_count[1]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		show_p = 2;
		run2_live[1] += h_run;
		base_live_ = h_base;
		out_live_ = h_out;
	} else if (m<inn_count[3]+1) {
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[1]; i++)	fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++)	fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<m - inn_count[2]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		show_p = 3;
		run1_live[2] += h_run;
		base_live_ = h_base;
		out_live_ = h_out;
	} else if (m<inn_count[4]+1) {
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[1]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<m - inn_count[3]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		show_p = 4;
		run2_live[2] += h_run;
		base_live_ = h_base;
		out_live_ = h_out;
	} else if (m<inn_count[5]+1) {
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[1]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[4]-inn_count[3]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<m - inn_count[4]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		show_p = 5;
		run1_live[3] += h_run;
		base_live_ = h_base;
		out_live_ = h_out;	
	} else if (m<inn_count[6]+1) {
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[1]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[4]-inn_count[3]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<inn_count[5]-inn_count[4]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		fscanf(fin, "%d", &s_inning);
		for (i=0; i<m - inn_count[5]; i++) fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		show_p = 6;
		run2_live[3] += h_run;
		base_live_ = h_base;
		out_live_ = h_out;
	}
	
	
	//fscanf(fin, "%d", &s_inning);
	//show_inn(s_inning);
	
	/*
	for (i=0; i<m; i++) {
		
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("%d %d %d %d %d\n", h_no, h_result, h_run, h_base, h_out);
		ncount ++;
	}*/	

	fclose(fin);
	
}

void show_inn(int a) {
	switch (a) {
		case 1:
			printf("\n�@���W\n");
			break;
		case 2:
			printf("\n�@���U\n");
			break;
		case 3:
			printf("\n�G���W\n");
			break;
		case 4:
			printf("\n�G���U\n");
			break;
		case 5:
			printf("\n�T���W\n");
			break;
		case 6:
			printf("\n�T���U\n");
			break;
	}
	printf("------------------\n");
}




void show_text(int m) {
	//system("cls");
	FILE  *fin;
	fin = fopen("record.txt", "r");
	int s_inning;
	int h_no, h_result, h_run, h_base, h_out;
	
	
	
	int i;
	char result_out[5][30] = {"���X�����y�A�Q�����X���C", "���X�����u�a�y�A�X���C", 
	"���θ��šA�T���X���C", "���X�����y�A�@�S�w���C", "���X�����y�A�G�S�w���C"};
	char run_out[3][20] = {"", "�@�W�]�̶]�^�o���C", "��W�]�̶]�^�o���C"};
	char base_out[10][20] = {"�@�S���H�C", "�G�S���H�C", "�T�S���H�C", "�@�B�G�S���H�C",
	 "�G�B�T�S���H�C", "�@�B�T�S���H�C", "���S���C", "�S�W�ثe�S���H�C", "���b�������C", "������}�l�C"}; 
	char out_out[4][21] = {"", "�@�H�X���C", "�G�H�X���C", "�T�H�X���A���������C"};
	
	
	
	if (m<inn_count[1]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
	} else if (m<inn_count[2]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
	} else if (m<inn_count[3]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[2]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
	} else if (m<inn_count[4]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[3]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}	
	} else if (m<inn_count[5]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[4]-inn_count[3]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[4]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
	} else if (m<inn_count[6]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[4]-inn_count[3]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[5]-inn_count[4]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[5]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("��%d�� %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}	
	}
	fclose(fin);
	
}
