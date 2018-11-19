#include <stdio.h>		//표준 입출력 
#include <stdlib.h>		//표준 라이브러리 
#include <time.h>		//시간 처리 (.h: 헤더 파일) 
/* 컴파일러에서 제공하는 함수들을 불러온다. */ 

#define	N		5		//bingo table 사이즈: N*N 
#define M		3		//bingo에서 이기는 조건
/* 필요에 따라 바꿀 수 있는 기호상수 정의. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. initiate_bingo: 빙고 테이블을 초기에 만들어줌. */
void initiate_bingo(){ 

	int Bingotable[N][N]={{0},{0},{0},{0},{0}}; //bingo table 초기화
	
	int overlap[N*N] = {0}; //중복 난수를 확인하기 위한 배열
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


/* 2. print_bingo: 빙고 테이블 현재 상황을 화면에 출력 */
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
