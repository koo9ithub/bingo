#include <stdio.h>		//ǥ�� ����� 
#include <stdlib.h>		//ǥ�� ���̺귯�� 
#include <time.h>		//�ð� ó�� (.h: ��� ����) 
/* �����Ϸ����� �����ϴ� �Լ����� �ҷ��´�. */ 

#define	N		5		//bingo table ������: N*N 
#define M		3		//bingo���� �̱�� ����
/* �ʿ信 ���� �ٲ� �� �ִ� ��ȣ��� ����. */ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



/* 1. �ʿ��� �Լ����� ���� */
int start_bingo();
int initiate_bingo(int Bingotable[][N]);

int print_bingo(int Bingotable[][N], int count);

int get_number_byMe(int Bingotable[][N]);
int get_number_byCom(int Bingotable[][N]);

int count_bingo(int Bingotable[][N]);
		
 
/* 2. ���� �Լ� */
int main(int argc, char *argv[]) {

		int Mybt[N][N];			//�迭 Mybingotable ���� 
		int Combt[N][N]; 		//�迭 Combingotable ���� 
		int count;
		
		printf("***** BINGO GAME with your computer ******\n");
	
		start_bingo();
		initiate_bingo(Mybt);
		
		count = count_bingo(Mybt);
		print_bingo(Mybt, count);
		
		initiate_bingo(Combt);
		
		while(1)		//�¸��ڰ� ���� ������ ���� �ݺ�
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

/* 3. start_bingo: ���� ���� �ʱ� ���� */
int start_bingo() {
	
	int Bingotable[N][N];			//Bingotable ���� 
	int count; 						//count: ����, ����, �밢���� ä���� �� �� 
	intitiate_bingo(Bingotable); 	//Bingotable �ʱ�ȭ 
	
	while(1)						//�¸��ڰ� ���� ������ �ݺ� 
	{
		count = count_bingo(Bingotable);
		print_bingo(Bingotable, count);	//count��ŭ�� ������ Bingotable ��� 
		
		if (count >= M) 				//�¸��� ����! 
		{
			break;						//���ӿ��� �������´�. 
		}
		else							//count<M �̶�� �ٽ� ���ڸ� �Է� ����. 
		{
			get_number_byMe(Bingotable);
		}
	}
	return 0;
}

/* 4. initiate_bingo: ���� ���̺��� ó���� �������. */
/* ���� �Լ��� �̿��Ͽ� �������� random���� ����� �ֵ� �� ���ڰ� 1~N*N �����̰�,
   ���ڰ� �ߺ��Ǿ� ǥ������ �ʵ��� ������ �ش�. */
int initiate_bingo(int Bingotable[N][N]) {
	
	srand((unsigned)time(NULL)); //���� �Լ� 
	
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
		/* temp��� ������ ������ ������1�� �����ϰ�,
		   ������ ������1���� ������ ������2�� ������ ��,
		   temp�� ������ ������2�� ������ �ش�.
		   => ������ �迭�� ���� �ٲ��.               */
		
	}
	return 0;
}

/* 5. print_bingo: �������� ���� ��Ȳ�� ����ϴ� �Լ� */
int print_bingo(int Bingotable[N][N], int count) {
	
	int i, j;
	for (i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if (Bingotable[i][j] != 0 )			//���� ��κ��� ��� ��µǵ��� ���� 
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

/* 6. get_number_byMe: ���� ���� ��ȣ�� �Է��� �����ϰ�, ������ ���� -1�� ǥ������. */
int get_number_byMe(int Bingotable[N][N]) {
	
	int num;
	int overlap;		//�̹� �ԷµǾ� �ߺ����� Ȯ���� ���� ���� 
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
					if (Bingotable[i][j] == num)	//�Է¹��� ���� ���� ���� ����Ǿ� �ִٸ�, 
					{
						Bingotable[i][j] = -1;		//-1�� ���
						overlap = 1;			//overlap�� �ߺ����� ���� 
					}
				}
			}
			
			if (overlap == 1)				//�ߺ����� �� ����Ǿ��ٸ�, 
			{
				break;						//�������´�. 
			}
			else							//�׷��� ������, 
			{
				prinf("ERROR: different number, please."); //�޽��� ��� 
			}
		
		}
	}
} 

/* 7. get_number_byCom: ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� */
int get_number_byCom(int Bingotable[N][N]) {
	
	int num;
	int overlap;		//�̹� �ԷµǾ� �ߺ����� Ȯ���� ���� ���� 
	int i, j;
	
	while (1)
	{
		overlap = 0;
		srand((unsigned)time(NULL));
		num = rand()%(N*N);
		
			for (i=0; i<N; i++) {
				for (j=0; j<N; j++) {
					if (Bingotable[i][j] == num)	//�Է¹��� ���� ���� ���� ����Ǿ� �ִٸ�, 
					{
						Bingotable[i][j] = -1;		//-1�� ���
						overlap = 1;			//overlap�� �ߺ����� ���� 
					}
				}
			}
			
			if (overlap == 1)				//�ߺ����� �� ����Ǿ��ٸ�, 
			{
				break;						//�������´�. 
			}
			else							//�׷��� ������, 
			{
				srand((unsigned)time(NULL));
				num = rand()%(N*N); 		//�ٽ� ������ �޴´�. 
			}
	}
} 


/* 8. count_bingo: �������̺��� ���� ����, ����, �밢���� �� ���� ����ؼ� ��ȯ */
int count_bingo(int Bingotable[N][N]) {
	
	int Bingocount[N+N+2] = {0};		//�ִ� ������� �� �ִ� �����: ����(N)+����(N)+�밢��(2) 
	int count = 0;						//������� ������ ���� 
	int i, j;
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[i][j] == -1)
			{
				Bingocount[i]++;
			}
		}
	}									//���� N�� Ȯ�� 
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[j*N + i] == -1)
			{
				Bingocount[i+N]++;
			}
		}
	}									//���� N�� Ȯ��
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[i*N + j] == -1)
			{
				Bingocount[N+N]++;
			}
		}
	}									//�밢��(������ -> �����ʾƷ�) Ȯ��
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (Bingotable[j*N + i] == -1)
			{
				Bingocount[N+N+1]++;
			}
		} 
	}									//�밢��(�������� -> ���ʾƷ�) Ȯ��
	
	for (i=0; i<(N+N+2); i++) {
		if (Bingocount[i] == M)
		{
			count++;
		}
	} 
	return count;
}





