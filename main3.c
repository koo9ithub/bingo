#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h>		//ǥ�� ���̺귯�� 
#include <time.h>		//�ð� ó�� (.h: ��� ����) 
/* �����Ϸ����� �����ϴ� �Լ����� �ҷ��´�. */ 

#define	N		5		//bingo table ������: N*N 
#define M		3		//bingo���� �̱�� ����
/* �ʿ信 ���� �ٲ� �� �ִ� ��ȣ��� ����. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. �ʿ��� �Լ����� ����. */
void start_bingo();
void initiate_bingo(int *);

void print_bingo(int *, int);

int get_number_byMe(int *);
int get_number_byCom(int *);

void process_bingo(int *);

int count_bingo();
		
 
/* 2. ���� �Լ� */
int main(int argc, char *argv[]) {
	
	while(1)		//�¸��ڰ� ���� ������ ���� �ݺ� 
	{
		int Mybt[N][N];
		int Combt[N][N]; 
		
		printf("***** BINGO GAME with your computer ******\n");
	
		start_bingo();
		initiate_bingo(Mybt);
		
		print_bingo(Mybt);
	
	}
	return 0;
}

/* 3. start_bingo: ���� ���� ���� */
void start_bingo() {
	
	int Bingotable[N][N];			//Bingotable ���� 
	int count; 						//����, ����, �밢���� ä���� �� �� 
	intitiate_bingo(Bingotable); 	//Bingotable �ʱ�ȭ 
	
	while(1)						//�¸��ڰ� ���� ������ �ݺ� 
	{
		count = count_bingo(Bingotable);
		print_bingo(Bingotable, count);
		
		if (count >= M) {
			break;
			get_number_byMe(Bingotable);
		}
		
	}
}

/* 4. initiate_bingo: ���� ���̺��� ó���� �������. */
void initiate_bingo(int *Bingotable) {
	
	srand((unsigned)time(NULL)); //���� �Լ� 
	
	int i;
	for (i=0; i<N*N; i++) {
		
		Bingotable[i] = i + 1;
	
	}
	for (i=0; i<100; i++) {
		
		int random1 = rand()%(N*N);
		int random2 = rand()%(N*N);
		
		int temp = Bingotable[random1];
		Bingotable[random1] = Bingotable[random2];
		Bingotable[random2] = temp;
		/* temp��� ������ ������ ������1�� �����ϰ�,
		   ������ ������1���� ������ ������2�� ������ ��,
		   temp�� ������ ������2�� ������ �ش�.
		   => ������ �迭�� ���� �ٲ��.               */
		
	}
}

/* 5. print_bingo: �������� ���� ��Ȳ�� ����ϴ� �Լ� */
void print_bingo(int *, int) {
	
	
	
}











