#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h> 	//ǥ�� ���̺귯�� 
#include <time.h>		//�ð� ó�� (.h: ��� ����) 

#define N		5	//size of bingo (N*N)
#define M		3	//line that is a requirement for winning

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int initiate_bingo()
{
		int i, j;
		int max = N*N-1;
		int rand_choice;	//���� ���տ��� ������ �� (���� ���õǾ� �̹� ����.) 
		int Rand_choice;	//��� �ؼ� �ٲ�� ���� ���� 
		
		srand((unsigned)time(NULL)); 
		
		for (i=0; i<N; i++){
			for (j=0; j<N; j++){
				
				rand_choice = 1+rand()%max;
				Rand_choice = 1+rand()%max - rand_choice;
				
				if (j == 0)
				printf("%d", rand_choice);
				else
				printf("%d", Rand_choice);
					
			}
		}
		
		return 0; 
	
}
/* make a initial bingotable. */

int print_bingo(int table[N][N])
{
	
}
/* print a present bingotable. */

int get_num_byMe(int Mychoice)
{
}
/* select my choice by hand. */ 

int get_num_byCom(int Comchoice)
{
}
/* select Com's choice by random. */

int process_bingo()
{
}
/* recieve my/Com's choice, fill a block of bingotable. */

int count_bingo()
{
}
/* count lines that are filled. */ 



int main(int argc, char *argv[]) {
	
	/* declare variables. */
	
	int i;
	int num_turn;
	int Mybt[N][N];
	int Combt[N][N];
	char winner;
	
	
	
	/* initial preperation */

	initiate_bingo(Mybt[N][N]);
	initiate_bingo(Combt[N][N]);
	
	print_bingo(Mybt[N][N]);
	
	
	
	/* game process */
	
	i=count_bingo();
	
	for (i=0; i<M; i++)
	{
		get_num_byMe();
		process_bingo();
		
		get_num_byCom();
		process_bingo();
	}
	
	
	
	/* ending */
	
	winner
	printf("Winner: %c", winner);
	
	num_turn
	printf("How many turns? %i turns.", num_turn);

	
	return 0;
}
