#ifndef _FUNC_

extern int menu(void);

extern void chooseTeam(void);

extern void choosePitcher(int t1, int t2, int *p1, int *p2);

extern void loadTeam(int t1, int t2);

extern void start_sim(void);

extern void show_g(void);

extern void battle(int h, int t);

extern int sim_running(void);

extern void load_info(int m);

extern void show_inn(int a);

extern void show(void);

extern void show_s(void);

extern void baseload(int b_l_);

extern void show_text(int m);

extern void rule(void);

extern int quit(void);
#endif
