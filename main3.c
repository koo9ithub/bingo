#include <stdio.h>		//표준 입출력 
#include <stdlib.h>		//표준 라이브러리 
#include <time.h>		//시간 처리 (.h: 헤더 파일) 
/* 컴파일러에서 제공하는 함수들을 불러온다. */ 

#define	N		5		//bingo table 사이즈: N*N 
#define M		3		//bingo에서 이기는 조건
/* 필요에 따라 바꿀 수 있는 기호상수 정의. */ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initiate_bingo(){ 

	int Bingotable[N][N]={{0},{0},{0},{0},{0}}; //bingo table 초기화
	
	int overlap[N*N] = {0}; //중복 난수를 확인하기 위한 배열
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
	top = 0; //중복 난수가 없음을 체크 후 빙고판에 작성. 

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
	} ; //확인 
}


		
 

int main(int argc, char *argv[]) {
	
	printf("***** BINGO GAME with your computer ******\n");
	
	
	return 0;
}
