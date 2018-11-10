#include <stdio.h>
#include <stdlib.h>

#define N		5	//size of bingo
#define M		3	//line that is a requirement for winning

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo()
{
}

int print_bingo()
{
}

int get_num_byMe()
{
}

int get_num_byCom()
{
}



int main(int argc, char *argv[]) {
	
	int i;
	int BingoTable1[N]; //make one bingotable.
	int BingoTable2[N]; //make the other bingotable.
	
	initiate_bingo();
	/* make a bingotable by random */
	
	print_bingo();
	/* show a bingotable that made by random */
	
	for (i=0; i<N; i++)
	{
		get_num_byMe();
		get_num_byCom();
	}

	
	
	
	
	return 0;
}
