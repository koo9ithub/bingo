#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h>		//ǥ�� ���̺귯�� 

#define	N		5		//bingo table ������: N*N 
#define M		2		//bingo���� �̱�� ����

int initiate_bingo(int Bingotable[][N]);

int print_bingo(int Bingotable[][N], int count);

int get_number_byMe();
int get_number_byCom();

int process_bingo(int Bingotable[][N], int num);

int count_bingo(int Bingotable[][N]);
		
int tries = 0;
