#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h>		//ǥ�� ���̺귯�� 
#include <time.h>		//�ð� ó�� (.h: ��� ����) 
/* �����Ϸ����� �����ϴ� �Լ����� �ҷ��´�. */ 
#include "bingo.h" 

#define	N		5		//bingo table ������: N*N 
#define M		2		//bingo���� �̱�� ����
/* �ʿ信 ���� �ٲ� �� �ִ� ��ȣ��� ����. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. �ʿ��� �Լ����� ���� */
//������� 

 
/* 2. ���� �Լ� */
int main(int argc, char *argv[]) {

		int Mybt[N][N];			//�迭 Mybingotable ���� 
		int Combt[N][N]; 		//�迭 Combingotable ���� 
		int count;
		int numMe, numCom;
		
		printf("***** BINGO GAME with your computer ******\n");
	
		initiate_bingo(Mybt);
		initiate_bingo(Combt);
		
		print_bingo(Mybt, count_bingo(Mybt));
		
		while(1)		//�¸��ڰ� ���� ������ ���� �ݺ�
		{
			numMe = get_number_byMe();
			process_bingo(Mybt, numMe);
			process_bingo(Combt, numMe);
			
			printf("My Pick!\n");
			print_bingo(Mybt, count_bingo(Mybt));
			
			numCom = get_number_byCom();
			process_bingo(Mybt, numCom);
			process_bingo(Combt, numCom);
			
			printf("Computer's Pick!\n");
			print_bingo(Mybt, count_bingo(Mybt));
			
			if (count_bingo(Mybt) >= M || count_bingo(Combt) >= M)
			{
				if (count_bingo(Mybt) >= M && count_bingo(Combt) < M)
				{
					printf("Winner is YOU.");
					printf("tries: %i", tries);
					break;
				}
				else if (count_bingo(Mybt) < M && count_bingo(Combt) >= M)
				{
					printf("Winner is your COM.");
					printf("tries: %i", tries);
					break;
				}
				else
				{
					printf("TIE.");
					printf("tries: %i\n", tries);
					break;
					
				}
			}	
		}
	return 0;
}

/* 3. initiate_bingo: ���� ���̺��� ó���� �������. */
/* ���� �Լ��� �̿��Ͽ� �������� random���� ����� �ֵ� �� ���ڰ� 1~N*N �����̰�,
   ���ڰ� �ߺ��Ǿ� ǥ������ �ʵ��� ������ �ش�. */
int initiate_bingo(int Bingotable[N][N]) {
	
	int cnt=1;
	srand((unsigned)time(NULL)); //���� �Լ� 
	
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			Bingotable[i][j] = cnt++;
		}
	}
	for (i=0; i<N; i++) {
		for(j=0; j<N; j++) {
		
			int random = rand()%(N*N);
		
			int temp = Bingotable[i][j];
			Bingotable[i][j] = Bingotable[random/N][random%N];
			Bingotable[random/N][random%N] = temp;
			/* temp��� ������ ������ ������1�� �����ϰ�,
		   ������ ������1���� ������ ������2�� ������ ��,
		   temp�� ������ ������2�� ������ �ش�.
		   => ������ �迭�� ���� �ٲ��.               */
		}
	}
	return 0;
}

/* 4. print_bingo: �������� ���� ��Ȳ�� ����ϴ� �Լ� */
int print_bingo(int Bingotable[N][N], int count) {
	
	int i, j;
	for (i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if (Bingotable[i][j] != 0 )			//���� ��κ��� ��� ��µǵ��� ���� 
			{
				printf("%d ", Bingotable[i][j]);
			}	
			else 
			{
				printf("ERROR");
			}
		}
		printf("\n\n");
	}
	return 0;
}

/* 5. get_number_byMe: ���� ���� ��ȣ�� �Է��� ������. */
int get_number_byMe() {
	
	int num;
	int i;
	//int out=0;
	int overlap[100];
	
	while(1) {
		
		printf("Choose a number which you want to erase: ");
		scanf("%d", &num);
		overlap[tries] = num;
		
		if (num<1 || num>N*N) {
			printf("ERROR: different number, please.\n");
		}
		else {
			for (i=0; i<tries; i++) 
			{
				if (num == overlap[i]) {
					printf("ERROR-OVERLAP: different number, please.\n");
					break;
				}
			}
		}
		if (i == tries) break;
	}
	tries++;
	return num;
}
		
	

/* 6. process_bingo: ���õ� ���ڸ� �Է¹޾Ƽ� ������ ������ -1�� �ٲ�. */
int process_bingo(int Bingotable[N][N], int num) {
	
	int i, j;

		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
					if (Bingotable[i][j] == num)	//�Է¹��� ���� ���� ���� ����Ǿ� �ִٸ�, 
					{
						Bingotable[i][j] = -1;		//-1�� ���
						 
					}
				}
			}
			
} 


/* 7. get_number_byCom: ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� */
int get_number_byCom() {
	
	int num; 
	int i, j;
	
		srand((unsigned)time(NULL));
		num = rand()%(N*N);
		
		return num;
}
			


/* 8. count_bingo: �������̺��� ���� ����, ����, �밢���� �� ���� ����ؼ� ��ȯ */
int count_bingo(int Bingotable[N][N]) {
	
	int Bingocountrow[N] = {0};
	int Bingocountcol[N] = {0};
	int Bingocount1 = 0;
	int Bingocount2 = 0;		//�ִ� ������� �� �ִ� �����: ����(N)+����(N)+�밢��(2) 
	int count = 0;						//������� ������ ���� 
	int i, j;	
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[i][j] == -1)
			{
				Bingocountrow[i]++;
				
				if (Bingocountrow[i] == N) {
					count++;
				}
			}
		}
	}									//���� N�� Ȯ�� 
	
	for (j=0; j<N; j++) {
		for (i=0; i<N; i++) {
			if (Bingotable[i][j] == -1)
			{
				Bingocountcol[j]++;
				
				if (Bingocountcol[j] == N) {
					count++;
				}
			}
		}
	}									//���� N�� Ȯ��
	
	for (i=0; i<N; i++) {
			if (Bingotable[i][i] == -1)
			{
				Bingocount1++;
				
				if (Bingocount1 == N) {
					count++;
				}
			}
	}									//�밢��(������ -> �����ʾƷ�) Ȯ��
	
	for (i=0; i<N; i++) {
			if (Bingotable[i][(N-1)-i] == -1)
			{
				Bingocount2++;
				
				if (Bingocount2 == N) {
					count++;
				}
			}
	}									//�밢��(�������� -> ���ʾƷ�) Ȯ��
	
	return count;
}
