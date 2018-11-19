#include <stdio.h>		//표준 입출력 
#include <stdlib.h>		//표준 라이브러리 
#include <time.h>		//시간 처리 (.h: 헤더 파일) 
/* 컴파일러에서 제공하는 함수들을 불러온다. */ 

#define	N		5		//bingo table 사이즈: N*N 
#define M		3		//bingo에서 이기는 조건
/* 필요에 따라 바꿀 수 있는 기호상수 정의. */ 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* This is a program for BINGO GAME with your computer! */


	/* 필요한 함수들을 선언. */
	
	void initate_bingo();
	void random_bingo(int *table);
	
	int get_number_byMe(int me);
	void process_bingo(int bt[N][N], int choice);	// bt: bingo table
	void print_bingo(int bt[N][N]);
	
	int get_number_byCom(int com);
	void process_bingo(int bt[N][N], int choice);
	
	int count_bingo();

	
/* 메인 함수 */ 
	
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


/* initiate_bingo: 빙고 테이블을 초기에 만들어 줌. */ 
	
void initiate_bingo(){
	srand((unsigned int)time(NULL));
	random_bingo(Mybt);
	random_bingo(Combt);
}	


/* random_bingo: 1~N*N 사이의 숫자로 빙고판을 채움.(겹치지 않게) */

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
	

/* get_number_byMe: 내가 빙고 번호 입력 선택 */

int get_number(int who){
	int number;
	
	if (who == me){
		printf("숫자를 선택하세요. (1~%i): ", N*N);
		scanf("%i", &number);
		if (number >= 1 && number <= N*N);
		number
	}
} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
