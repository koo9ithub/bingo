#include <stdio.h>		//표준 입출력 
#include <stdlib.h>		//표준 라이브러리 
#include <time.h>		//시간 처리 (.h: 헤더 파일) 
/* 컴파일러에서 제공하는 함수들을 불러온다. */ 
#include "bingo.h" 

#define	N		5		//bingo table 사이즈: N*N 
#define M		2		//bingo에서 이기는 조건
/* 필요에 따라 바꿀 수 있는 기호상수 정의. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. 필요한 함수들을 선언 */
//헤더파일 

 
/* 2. 메인 함수 */
int main(int argc, char *argv[]) {

		int Mybt[N][N];			//배열 Mybingotable 정의 
		int Combt[N][N]; 		//배열 Combingotable 정의 
		int count;
		int numMe, numCom;
		
		printf("***** BINGO GAME with your computer ******\n");
	
		initiate_bingo(Mybt);
		initiate_bingo(Combt);
		
		print_bingo(Mybt, count_bingo(Mybt));
		
		while(1)		//승리자가 나올 때까지 무한 반복
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

/* 3. initiate_bingo: 빙고 테이블을 처음에 만들어줌. */
/* 난수 함수를 이용하여 빙고판을 random으로 만들어 주되 그 숫자가 1~N*N 사이이고,
   숫자가 중복되어 표현되지 않도록 설정해 준다. */
int initiate_bingo(int Bingotable[N][N]) {
	
	int cnt=1;
	srand((unsigned)time(NULL)); //난수 함수 
	
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
			/* temp라는 변수에 임의의 빙고판1을 저장하고,
		   임의의 빙고판1에는 임의의 빙고판2를 저장한 후,
		   temp를 임의의 빙고판2에 저장해 준다.
		   => 숫자의 배열이 서로 바뀐다.               */
		}
	}
	return 0;
}

/* 4. print_bingo: 빙고판의 현재 상황을 출력하는 함수 */
int print_bingo(int Bingotable[N][N], int count) {
	
	int i, j;
	for (i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if (Bingotable[i][j] != 0 )			//거의 대부분의 경우 출력되도록 설정 
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

/* 5. get_number_byMe: 내가 빙고 번호의 입력을 선택함. */
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
		
	

/* 6. process_bingo: 선택된 숫자를 입력받아서 빙고판 내에서 -1로 바꿈. */
int process_bingo(int Bingotable[N][N], int num) {
	
	int i, j;

		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
					if (Bingotable[i][j] == num)	//입력받은 수와 같은 수가 저장되어 있다면, 
					{
						Bingotable[i][j] = -1;		//-1을 출력
						 
					}
				}
			}
			
} 


/* 7. get_number_byCom: 컴퓨터가 임의로 빙고 번호 선택 */
int get_number_byCom() {
	
	int num; 
	int i, j;
	
		srand((unsigned)time(NULL));
		num = rand()%(N*N);
		
		return num;
}
			


/* 8. count_bingo: 빙고테이블이 받은 가로, 세로, 대각선의 줄 수를 계산해서 반환 */
int count_bingo(int Bingotable[N][N]) {
	
	int Bingocountrow[N] = {0};
	int Bingocountcol[N] = {0};
	int Bingocount1 = 0;
	int Bingocount2 = 0;		//최대 만들어질 수 있는 빙고수: 가로(N)+세로(N)+대각선(2) 
	int count = 0;						//빙고수를 저장할 변수 
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
	}									//가로 N줄 확인 
	
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
	}									//세로 N줄 확인
	
	for (i=0; i<N; i++) {
			if (Bingotable[i][i] == -1)
			{
				Bingocount1++;
				
				if (Bingocount1 == N) {
					count++;
				}
			}
	}									//대각선(왼쪽위 -> 오른쪽아래) 확인
	
	for (i=0; i<N; i++) {
			if (Bingotable[i][(N-1)-i] == -1)
			{
				Bingocount2++;
				
				if (Bingocount2 == N) {
					count++;
				}
			}
	}									//대각선(오른쪽위 -> 왼쪽아래) 확인
	
	return count;
}
