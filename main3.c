#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h>		//ǥ�� ���̺귯�� 
#include <time.h>		//�ð� ó�� (.h: ��� ����) 
/* �����Ϸ����� �����ϴ� �Լ����� �ҷ��´�. */ 

#define	N		5		//bingo table ������: N*N 
#define M		3		//bingo���� �̱�� ����
/* �ʿ信 ���� �ٲ� �� �ִ� ��ȣ��� ����. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. initiate_bingo: ���� ���̺��� �ʱ⿡ �������. */
void initiate_bingo(){ 

	int Bingotable[N][N]={{0},{0},{0},{0},{0}}; //bingo table �ʱ�ȭ
	
	int overlap[N*N] = {0}; //�ߺ� ������ Ȯ���ϱ� ���� �迭
	int top = 0;
	int i, j, k; 
	 
	
	srand((unsigned)time(NULL));
	
	while (top < N*N){
		
		overlap[top] = 1 + rand()%(N*N);
		
		for (i=0; i<top; i++){
			
			if (overlap[top] == overlap[i]) {
				top--;
			}
		}
		top++;
	}
	top = 0; //�ߺ� ������ ������ üũ �� �����ǿ� �ۼ�. 

	for (j=0; j<N; j++){
		for (k=0; k<N; k++){
			
			Bingotable[j][k] = overlap[top];
			top++;
		}
	}
	
	char check [N][N] = {
	{'X', 'X', 'X', 'X', 'X'},
	{'X', 'X', 'X', 'X', 'X'},
	{'X', 'X', 'X', 'X', 'X'},
	{'X', 'X', 'X', 'X', 'X'},
	{'X', 'X', 'X', 'X', 'X'}
	} ; //Ȯ�� 
}


/* 2. print_bingo: ���� ���̺� ���� ��Ȳ�� ȭ�鿡 ��� */
void print_bingo(int Bingotable[][N], char check[][N]){
	
	int j, k;
	char left0 = '(';
	char right0 = ')';
	
	for (j=0; j<N; j++){
		for (k=0; k<N; k++){
			
			if (check[j][k] == '0'){
				
				printf("%c%2d%c", left0, Bingotable[j][k], right0);
			}
			else{
				printf("%2d", Bingotable[j][k]);
			}
		}
		printf("\n");
	}
	printf("\n");
}


		
 

int main(int argc, char *argv[]) {
	
	int Mybt[N][N];
	char check[N][N];
	
	printf("***** BINGO GAME with your computer ******\n");
	
	initiate_bingo();
	print_bingo(Mybt, check);
	
	return 0;
}
