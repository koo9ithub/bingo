#include <stdio.h>		//표준 입출력 
#include <stdlib.h>		//표준 라이브러리 
#include <time.h>		//시간 처리 (.h: 헤더 파일) 
/* 컴파일러에서 제공하는 함수들을 불러온다. */ 

#define	N		5		//bingo table 사이즈: N*N 
#define M		3		//bingo에서 이기는 조건
/* 필요에 따라 바꿀 수 있는 기호상수 정의. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. 필요한 함수들을 선언. */
void start_bingo();
void initiate_bingo(int *);

void print_bingo(int *, int);

int get_number_byMe(int *);
int get_number_byCom(int *);

void process_bingo(int *);

int count_bingo();
		
 
/* 2. 메인 함수 */
int main(int argc, char *argv[]) {
	
	while(1)		//승리자가 나올 때까지 무한 반복 
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

/* 3. start_bingo: 빙고 게임 과정 */
void start_bingo() {
	
	int Bingotable[N][N];			//Bingotable 정의 
	int count; 						//가로, 세로, 대각선이 채워진 줄 수 
	intitiate_bingo(Bingotable); 	//Bingotable 초기화 
	
	while(1)						//승리자가 나올 때까지 반복 
	{
		count = count_bingo(Bingotable);
		print_bingo(Bingotable, count);
		
		if (count >= M) {
			break;
			get_number_byMe(Bingotable);
		}
		
	}
}

/* 4. initiate_bingo: 빙고 테이블을 처음에 만들어줌. */
void initiate_bingo(int *Bingotable) {
	
	srand((unsigned)time(NULL)); //난수 함수 
	
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
		/* temp라는 변수에 임의의 빙고판1을 저장하고,
		   임의의 빙고판1에는 임의의 빙고판2를 저장한 후,
		   temp를 임의의 빙고판2에 저장해 준다.
		   => 숫자의 배열이 서로 바뀐다.               */
		
	}
}

/* 5. print_bingo: 빙고판의 현재 상황을 출력하는 함수 */
void print_bingo(int *, int) {
	
	
	
}











