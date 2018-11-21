#include <stdio.h>		//표준 입출력 
#include <stdlib.h>		//표준 라이브러리 
#include <time.h>		//시간 처리 (.h: 헤더 파일) 
/* 컴파일러에서 제공하는 함수들을 불러온다. */ 

#define	N		5		//bingo table 사이즈: N*N 
#define M		3		//bingo에서 이기는 조건
/* 필요에 따라 바꿀 수 있는 기호상수 정의. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. 필요한 함수들을 선언 */
int start_bingo();
int initiate_bingo(int Bingotable[][N]);

int print_bingo(int Bingotable[][N], int count);

int get_number_byMe(int Bingotable[][N]);
int get_number_byCom(int Bingotable[][N]);

int count_bingo(int Bingotable[][N]);
		
 
/* 2. 메인 함수 */
int main(int argc, char *argv[]) {

		int Mybt[N][N];			//배열 Mybingotable 정의 
		int Combt[N][N]; 		//배열 Combingotable 정의 
		int count;
		
		printf("***** BINGO GAME with your computer ******\n");
	
		start_bingo();
		initiate_bingo(Mybt);
		
		count = count_bingo(Mybt);
		print_bingo(Mybt, count);
		
		initiate_bingo(Combt);
		
		while(1)		//승리자가 나올 때까지 무한 반복
		{
			get_number_byMe(Mybt);
			process_bingo(Mybt);
			print_bingo(Mybt, count);
		
			get_number_byCom(Combt);
			process_bingo(Combt);
		
			if (count_bingo(Mybt) >= M || count_bingo(Combt) >= M)
			{
				if (count_bingo(Mybt) >= M && count_bingo(Combt) < M)
				{
					printf("Winner is YOU.");
					break;
				}
				else if (count_bingo(Mybt) < M && count_bingo(Combt) >= M)
				{
					printf("Winner is your COM.");
					break;
				}
				else
				{
					printf("TIE.");
					break;
				}
			}	
		}
	return 0;
}

/* 3. start_bingo: 빙고 게임 초기 설정 */
int start_bingo() {
	
	int Bingotable[N][N];			//Bingotable 정의 
	int count; 						//count: 가로, 세로, 대각선이 채워진 줄 수 
	intitiate_bingo(Bingotable); 	//Bingotable 초기화 
	
	while(1)						//승리자가 나올 때까지 반복 
	{
		count = count_bingo(Bingotable);
		print_bingo(Bingotable, count);	//count만큼을 적용한 Bingotable 출력 
		
		if (count >= M) 				//승리자 나옴! 
		{
			break;						//게임에서 빠져나온다. 
		}
		else							//count<M 이라면 다시 숫자를 입력 받음. 
		{
			get_number_byMe(Bingotable);
		}
	}
	return 0;
}

/* 4. initiate_bingo: 빙고 테이블을 처음에 만들어줌. */
/* 난수 함수를 이용하여 빙고판을 random으로 만들어 주되 그 숫자가 1~N*N 사이이고,
   숫자가 중복되어 표현되지 않도록 설정해 준다. */
int initiate_bingo(int Bingotable[N][N]) {
	
	srand((unsigned)time(NULL)); //난수 함수 
	
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0;j<N;j++) {
			Bingotable[i][j] = i + 1;
		}
	}
	for (i=0; i<100; i++) {
		
		int random1 = rand()%(N*N);
		int random2 = rand()%(N*N);
		
		int temp = Bingotable[random1/N][random1%N];
		Bingotable[random1/N][random1%N] = Bingotable[random2/N][random2%N];
		Bingotable[random2/N][random2%N] = temp;
		/* temp라는 변수에 임의의 빙고판1을 저장하고,
		   임의의 빙고판1에는 임의의 빙고판2를 저장한 후,
		   temp를 임의의 빙고판2에 저장해 준다.
		   => 숫자의 배열이 서로 바뀐다.               */
		
	}
	return 0;
}

/* 5. print_bingo: 빙고판의 현재 상황을 출력하는 함수 */
int print_bingo(int Bingotable[N][N], int count) {
	
	int i, j;
	for (i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if (Bingotable[i][j] != 0 )			//거의 대부분의 경우 출력되도록 설정 
			{
				printf("7d%", Bingotable[i][j]);
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

/* 6. get_number_byMe: 내가 빙고 번호의 입력을 선택하고, 선택한 것을 -1로 표시해줌. */
int get_number_byMe(int Bingotable[N][N]) {
	
	int num;
	int overlap;		//이미 입력되어 중복인지 확인할 변수 선언 
	int i, j;
	
	while (1)
	{
		overlap = 0;
		printf("Choose a number which you want to erase: ");
		scanf("%d", &num);
		
		if (num<1 || num>(N*N))
		{
			printf("ERROR: 1~N*N number, please.");
		} 
		else
		{
			for (i=0; i<N; i++) {
				for (j=0; j<N; j++) {
					if (Bingotable[i][j] == num)	//입력받은 수와 같은 수가 저장되어 있다면, 
					{
						Bingotable[i][j] = -1;		//-1을 출력
						overlap = 1;			//overlap에 중복임을 저장 
					}
				}
			}
			
			if (overlap == 1)				//중복임이 잘 저장되었다면, 
			{
				break;						//빠져나온다. 
			}
			else							//그렇지 않으면, 
			{
				prinf("ERROR: different number, please."); //메시지 출력 
			}
		
		}
	}
} 

/* 7. get_number_byCom: 컴퓨터가 임의로 빙고 번호 선택 */
int get_number_byCom(int Bingotable[N][N]) {
	
	int num;
	int overlap;		//이미 입력되어 중복인지 확인할 변수 선언 
	int i, j;
	
	while (1)
	{
		overlap = 0;
		srand((unsigned)time(NULL));
		num = rand()%(N*N);
		
			for (i=0; i<N; i++) {
				for (j=0; j<N; j++) {
					if (Bingotable[i][j] == num)	//입력받은 수와 같은 수가 저장되어 있다면, 
					{
						Bingotable[i][j] = -1;		//-1을 출력
						overlap = 1;			//overlap에 중복임을 저장 
					}
				}
			}
			
			if (overlap == 1)				//중복임이 잘 저장되었다면, 
			{
				break;						//빠져나온다. 
			}
			else							//그렇지 않으면, 
			{
				srand((unsigned)time(NULL));
				num = rand()%(N*N); 		//다시 난수를 받는다. 
			}
	}
} 


/* 8. count_bingo: 빙고테이블이 받은 가로, 세로, 대각선의 줄 수를 계산해서 반환 */
int count_bingo(int Bingotable[N][N]) {
	
	int Bingocount[N+N+2] = {0};		//최대 만들어질 수 있는 빙고수: 가로(N)+세로(N)+대각선(2) 
	int count = 0;						//빙고수를 저장할 변수 
	int i, j;
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[i][j] == -1)
			{
				Bingocount[i]++;
			}
		}
	}									//가로 N줄 확인 
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[j*N + i] == -1)
			{
				Bingocount[i+N]++;
			}
		}
	}									//세로 N줄 확인
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[i*N + j] == -1)
			{
				Bingocount[N+N]++;
			}
		}
	}									//대각선(왼쪽위 -> 오른쪽아래) 확인
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[j*N + i] == -1)
			{
				Bingocount[N+N+1]++;
			}
		} 
	}									//대각선(오른쪽위 -> 왼쪽아래) 확인
	
	for (i=0; i<(N+N+2); i++) {
		if (Bingocount[i] == M)
		{
			count++;
		}
	} 
	return count;
}





