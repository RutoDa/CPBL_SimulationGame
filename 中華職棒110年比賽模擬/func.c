
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
	printf("歡迎光臨中華職棒110年 模擬賽事\n");
	printf("1.開始 2.查看遊戲設定 3.離開\n");
	printf("輸入: ");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 3)) {
		clear();
		printf("輸入錯誤，請再輸入一次!!");
		printf("輸入: ");
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
	printf("1.一場只有3局。\n2.如果3局結束平手，即為和局。\n3.不會出現保送。\n4.安打只有2壘安打與1壘安打。\n5.不考慮太複雜的跑壘判斷:\n  當壘上有人: 一壘安打: 所有跑者皆往前推進一個壘包\n	      二壘安打: 所有跑者皆往前推進兩個壘包\n6.打線固定，為開幕戰先發打線，不能更換打者\n7.不得更換投手");
	printf("\n\n--輸入y返回--\n輸入:");
	while ((scanf("%c", &input_c) != 1) || (input_c != 'Y' && input_c != 'y')) {
		clear();
		printf("\n--輸入y返回--\n輸入:");
	} clear();
	system("cls");
	menu();
}


int quit(void) {
	printf("----結束----");
	quit_ = 1;
	return 0;
}


char team_list[5][9] = {"中信兄弟", "統一獅", "味全龍", "富邦悍將", "樂天桃猿"};


void chooseTeam(void) {
	int i;
	for (i=0; i<5; i++) {
		printf("%d. %s \n", i+1, team_list[i]);
	}
	printf("\n選擇先攻球隊(輸入編號):");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 5)) {
		clear();
		printf("輸入錯誤，請再輸入一次!!");
		printf("選擇先攻球隊(輸入編號): ");
	} clear();
	team1 = input-1;
	printf("選擇先守球隊(輸入編號):");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 5)) {
		clear();
		printf("輸入錯誤，請再輸入一次!!");
		printf("選擇先守球隊(輸入編號): ");
	} clear();
	team2 = input-1;
	system("cls");
	printf("先攻:%s VS 先守:%s \n", team_list[team1], team_list[team2]);
	printf("以上為您選擇的球隊，按y繼續，按r重新選擇，按q離開");
	printf("輸入: ");
	while ((scanf("%c", &input_c) != 1) || (input_c != 'q' && 
	input_c != 'Q' && input_c != 'r' && input_c != 'R' && 
	input_c != 'Y' && input_c != 'y')) {
		clear();
		printf("輸入錯誤，請再輸入一次!!");
		printf("輸入: ");
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
				fin = fopen("中信兄弟選手資料.txt", "r");
				break;
			case 1:
				fin = fopen("統一獅選手資料.txt", "r");
				break;
			case 2:
				fin = fopen("味全龍選手資料.txt", "r");
				break;
			case 3:
				fin = fopen("富邦悍將選手資料.txt", "r");
				break;
			case 4:
				fin = fopen("樂天桃猿選手資料.txt", "r");
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

//由於在讀檔寫入時，中文名字讀入後輸出皆為亂碼，所以在找到解決方式前，只能先做一個球員名單，利用編號查詢
char playerList[70][9] = {"王威晨","江坤宇","張志豪","詹子賢","許\基宏","周思齊","陳子豪","高宇杰","蘇緯達","德保拉","鄭凱文","加百利","萊福力","廖乙忠", "陳傑憲","林靖凱","陳鏞基","林安可","郭阜林","蘇智傑","施冠宇","林祖傑","林岱安","布雷克","猛威爾","古林睿煬","泰迪","江辰晏", "曾傳昇","赫雷拉","李凱威","劉基鴻","曾陶鎔","陳品捷","林旺衛","劉時豪","吳東融","徐若熙","布里悍","林子昱","王維中","伍鐸", "李宗賢","王正棠","林益全","高國輝","高國麟","辛元旭","申皓瑋","林哲瑄","林宥穎","索沙","羅力","邦威","傑斯","陳士朋", "陽耀勳","林立","藍寅倫","陳俊秀","朱育賢","林泓育","郭嚴文","林承飛","詹智堯","霸林爵","張喜凱","黃子鵬","翁瑋均","王溢正"};  


void choosePitcher(int t1, int t2, int *p1, int *p2) {
	int i ,j;

	printf("%s 的先發投手如下:\n", team_list[t1]);
	for (i=0; i<5; i++) {
		j = team1_pitcher[i].index;
		printf("%d. %s\n", i+1, playerList[j]);
	}
	printf("請選擇先發投手(輸入編號):");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 5)) {
		clear();
		printf("輸入錯誤，請再輸入一次!!");
		printf("請選擇先發投手(輸入編號): ");
	} clear();
	*p1 = input -1;
	
	printf("\n%s 的先發投手如下:\n", team_list[t2]);
	for (i=0; i<5; i++) {
		j = team2_pitcher[i].index;
		printf("%d. %s\n", i+1, playerList[j]);
	}
	printf("請選擇先發投手(輸入編號):");
	while (scanf("%d", &input) != 1 || !(input >= 1 && input <= 5)) {
		clear();
		printf("輸入錯誤，請再輸入一次!!");
		printf("請選擇先發投手(輸入編號): ");
	} clear();
	*p2 = input -1;
	
	return;
}  


int inning = 1;// inning 1一局上 2一局下 3二局上 4 二局下.... 
int h1 = 0;//打者棒次 
int h2 = 0;
int result;
int base_live;
int out = 0;
int t1_run, t2_run;
int inn_count[7];//紀錄每局的打席 


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
			battle(h1, 0);//會改變out 、 result 、 base_live
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
			battle(h2, 1);//會改變out 、 result 、 base_live 
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
//base_live 0:一壘有人，1:二壘有人，2:三壘有人，3:一、二壘有人， 
//4:二、三壘有人，5:一、三壘有人，6:滿壘中，7:壘上目前沒人，
//8:本半局結束，9:本局剛開始  
int sim_running(void) {
	if (out == 3) base_live = 8; //out <- 出局數 
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
	int result_i;//出局 0 、安打 1 滾or飛2  
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
							//1000 = 1秒 
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
				printf("\n比賽結束\n------------------\n%s 獲勝", team_list[team2]);
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
		printf("\n比賽結束\n------------------\n%s 獲勝", team_list[team1]);
	} else if (run2_live[4] == run1_live[4]) {
		printf("\n比賽結束\n------------------\n兩隊平手");
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
			printf("|%-8s |%3d  |     |     ||%3d  |      一局上\n", team_list[team1], run1_live[1], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |     |     |     ||     |\n", team_list[team2]);
			printf("------------------------------------\n");
			break;
		case 2:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |     |     ||%3d  |      一局下\n", team_list[team1], run1_live[1], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |     |     ||%3d  |\n", team_list[team2], run2_live[1], run2_live[4]);
			printf("------------------------------------\n");
			break;
		case 3:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |%3d  |     ||%3d  |      二局上\n", team_list[team1], run1_live[1], run1_live[2], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |     |     ||%3d  |\n", team_list[team2], run2_live[1], run2_live[4]);
			printf("------------------------------------\n");
			break;
		case 4:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |%3d  |     ||%3d  |      二局下\n", team_list[team1], run1_live[1], run1_live[2], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |%3d  |     ||%3d  |\n", team_list[team2], run2_live[1], run2_live[2], run2_live[4]);
			printf("------------------------------------\n");
			break;
		case 5:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |%3d  |%3d  ||%3d  |      三局上\n", team_list[team1], run1_live[1], run1_live[2], run1_live[3], run1_live[4]);
			printf("------------------------------------      OUT: %d \n", out_live_);
			printf("|%-8s |%3d  |%3d  |     ||%3d  |\n", team_list[team2], run2_live[1], run2_live[2], run2_live[4]);
			printf("------------------------------------\n");
			break;
		case 6:
			printf("          --------------------------\n ");
			printf("         |  1  |  2  |  3  ||  R  |       ( %c )\n", base[2]    );
			printf("------------------------------------    ( %c ) ( %c )\n", base[3], base[1]);
			printf("|%-8s |%3d  |%3d  |%3d  ||%3d  |      三局下\n", team_list[team1], run1_live[1], run1_live[2], run1_live[3], run1_live[4]);
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
			printf("\n一局上\n");
			break;
		case 2:
			printf("\n一局下\n");
			break;
		case 3:
			printf("\n二局上\n");
			break;
		case 4:
			printf("\n二局下\n");
			break;
		case 5:
			printf("\n三局上\n");
			break;
		case 6:
			printf("\n三局下\n");
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
	char result_out[5][30] = {"擊出高飛球，被接殺出局。", "擊出內野滾地球，出局。", 
	"揮棒落空，三振出局。", "擊出平飛球，一壘安打。", "擊出高飛球，二壘安打。"};
	char run_out[3][20] = {"", "一名跑者跑回得分。", "兩名跑者跑回得分。"};
	char base_out[10][20] = {"一壘有人。", "二壘有人。", "三壘有人。", "一、二壘有人。",
	 "二、三壘有人。", "一、三壘有人。", "滿壘中。", "壘上目前沒有人。", "本半局結束。", "本局剛開始。"}; 
	char out_out[4][21] = {"", "一人出局。", "二人出局。", "三人出局，本局結束。"};
	
	
	
	if (m<inn_count[1]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
	} else if (m<inn_count[2]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
	} else if (m<inn_count[3]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[2]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
	} else if (m<inn_count[4]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[3]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}	
	} else if (m<inn_count[5]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[4]-inn_count[3]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[4]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
	} else if (m<inn_count[6]+1) {
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[2]-inn_count[1]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[3]-inn_count[2]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[4]-inn_count[3]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<inn_count[5]-inn_count[4]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team1_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}
		
		fscanf(fin, "%d", &s_inning);
		show_inn(s_inning);
		for (i=0; i<m - inn_count[5]; i++) {
		fscanf(fin, "%d %d %d %d %d", &h_no, &h_result, &h_run, &h_base, &h_out);
		printf("第%d棒 %s: %s%s%s%s\n", h_no+1, playerList[team2_hitter[h_no].index], result_out[h_result], run_out[h_run], base_out[h_base], out_out[h_out]);
		}	
	}
	fclose(fin);
	
}
