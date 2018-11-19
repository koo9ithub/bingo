#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h>		//ǥ�� ���̺귯�� 
#include <time.h>		//�ð� ó�� (.h: ��� ����) 
/* �����Ϸ����� �����ϴ� �Լ����� �ҷ��´�. */ 

#define	N		5		//bingo table ������: N*N 
#define M		3		//bingo���� �̱�� ����
/* �ʿ信 ���� �ٲ� �� �ִ� ��ȣ��� ����. */ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initiate_bingo(){ 

	int Bingotable[N][N]={{0},{0},{0},{0},{0}}; //bingo table �ʱ�ȭ
	
	int overlap[N*N] = {0}; //�ߺ� ������ Ȯ���ϱ� ���� �迭
	int top = 0;
	int i, j, k; 
	 
	
	srand((unsigned)time(NULL));
	
	while (top<25){
		
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


		
 

int main(int argc, char *argv[]) {
	
	printf("***** BINGO GAME with your computer ******\n");
	
	
	return 0;
}
