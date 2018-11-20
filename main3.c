#include <stdio.h>		//표준 입출력 
#include <stdlib.h>		//표준 라이브러리 
#include <time.h>		//시간 처리 (.h: 헤더 파일) 
/* 컴파일러에서 제공하는 함수들을 불러온다. */ 

#define	N		5		//bingo table 사이즈: N*N 
#define M		3		//bingo에서 이기는 조건
/* 필요에 따라 바꿀 수 있는 기호상수 정의. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. 필요한 함수들을 선언. */
void initiate_bingo(int *);
void print_bingo();
int get_number_byMe();
int get_number_byCom();
void process_bingo();
int count_bingo();
		
 
/* 2. 메인 함수 */
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
