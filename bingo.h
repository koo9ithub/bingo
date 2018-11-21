#include <stdio.h>		//표준 입출력 
#include <stdlib.h>		//표준 라이브러리 

#define	N		5		//bingo table 사이즈: N*N 
#define M		2		//bingo에서 이기는 조건

int initiate_bingo(int Bingotable[][N]);

int print_bingo(int Bingotable[][N], int count);

int get_number_byMe();
int get_number_byCom();

int process_bingo(int Bingotable[][N], int num);

int count_bingo(int Bingotable[][N]);
		
int tries = 0;
