#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h>		//ǥ�� ���̺귯�� 
#include <time.h>		//�ð� ó�� (.h: ��� ����) 
/* �����Ϸ����� �����ϴ� �Լ����� �ҷ��´�. */ 

#define	N		5		//bingo table ������: N*N 
#define M		3		//bingo���� �̱�� ����
/* �ʿ信 ���� �ٲ� �� �ִ� ��ȣ��� ����. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. �ʿ��� �Լ����� ����. */
void initiate_bingo(int *);
void print_bingo();
int get_number_byMe();
int get_number_byCom();
void process_bingo();
int count_bingo();
		
 
/* 2. ���� �Լ� */
int main(int argc, char *argv[]) {
	
	while(1) 
	{
		int Mybt[N][N];
		int Combt[N][N]; 
		
		printf("***** BINGO GAME with your computer ******\n");
	
		initiate_bingo();
		print_bingo(Mybt);
	
	}
	return 0;
}
