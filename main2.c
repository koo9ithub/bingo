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
		process_bingo(Mybt[N][N], Mychoice);
		print_bingo(Mybt[N][N]);
		
		get_num_byCom(com);
		process_bingo(Combt[N][N], Comchoice);
	}
	
	printf("Winner: %c", winner);
	
	printf("How many turns? %i turns.", num_turn);

	initiate_bingo();
	
	return 0;

}


/* initiate_bingo: ���� ���̺��� �ʱ⿡ ����� ��. */ 
	
void initiate_bingo(){
	srand((unsigned int)time(NULL));
	random_bingo(Mybt);
	random_bingo(Combt);
}	


/* random_bingo: 1~N*N ������ ���ڷ� �������� ä��.(��ġ�� �ʰ�) */

void random_bingo(int *table){
	
	int i, j;
	int max;
	int rand_choice;
	int Rand_choice;
	
	for (j=0; j<N; j++){
		for (i=0; i<N; i++){
			max=N*N;
			rand_choice = 1+rand()%max;
			Rand_choice = 1+rand()%max - rand_choice;
			
			if (i == 0)
			{ printf("%d", rand_choice); }
			else
			{ printf("%d", Rand_choice); }
		}
	}
	
	return 0;
} 
	

/* get_number_byMe: ���� ���� ��ȣ �Է� ���� */

int get_number(int who){
	int number;
	
	if (who == me){
		printf("���ڸ� �����ϼ���. (1~%i): ", N*N);
		scanf("%i", &number);
		if (number >= 1 && number <= N*N);
		number
	}
} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
