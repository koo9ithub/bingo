#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h>		//ǥ�� ���̺귯�� 
#include <time.h>		//�ð� ó�� (.h: ��� ����) 
/* �����Ϸ����� �����ϴ� �Լ����� �ҷ��´�. */ 

#define	N		5		//bingo table ������: N*N 
#define M		3		//bingo���� �̱�� ����
/* �ʿ信 ���� �ٲ� �� �ִ� ��ȣ��� ����. */ 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* This is a program for BINGO GAME with your computer! */


	/* �ʿ��� �Լ����� ����. */
	
	void initate_bingo();
	void random_bingo(int *table);
	
	int get_number_byMe(int me);
	void process_bingo(int bt[N][N], int choice);	// bt: bingo table
	void print_bingo(int bt[N][N]);
	
	int get_number_byCom(int com);
	void process_bingo(int bt[N][N], int choice);
	
	int count_bingo();
	
/* ���� �Լ� */ 
	
int main(int argc, char *argv[]) {
	
	int i;
	int me, com;
	int Mychoice, Comchoice;
	int Mybt[N][N], Combt[N][N];
	
	int winner;
	int num_turn; 
	
	i=count_bingo();
	
	for (i=0; i<M; i++)
	{
		get_num_byMe(me);
		process_bingo(&Mybt[N][N], Mychoice);
		print_bingo(&Mybt[N][N]);
		
		get_num_byCom(com);
		process_bingo(&Combt[N][N], Comchoice);
	}
	
	printf("Winner: %c", winner);
	
	printf("How many turns? %i turns.", num_turn);

	return 0;

}

/* initiate_bingo: ���� ���̺��� �ʱ⿡ ����� ��. */ 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
