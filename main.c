#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N		5	//size of bingo (N*N)
#define M		3	//line that is a requirement for winning

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int initiate_bingo(table[][N])
{
}
/* make a initial bingotable. */

int print_bingo(table[][N])
{
}
/* print a present bingotable. */

int get_num_byMe(int Mychoice)
{
}
/* select my choice by hand. */ 

int get_num_byCom(int Comchoice)
{
}
/* select Com's choice by random. */

int process_bingo()
{
}
/* recieve my/Com's choice, fill a block of bingotable. */

int count_bingo()
{
}
/* count lines that are filled. */ 



int main(int argc, char *argv[]) {
	
	/* declare variables. */
	
	int i;
	int num_turn;
	char winner;
	
	
	
	/* initial preperation */

	initiate_bingo(Mybt[][N]);
	initiate_bingo(Combt[][N]);
	
	print_bingo(Mybt[][N]);
	
	
	
	/* game process */
	
	i=count_bingo();
	
	for (i=0; i<M; i++)
	{
		get_num_byMe();
		process_bingo();
		
		get_num_byCom();
		process_bingo();
	}
	
	
	
	/* ending */
	
	winner
	printf("Winner: %c", winner);
	
	num_turn
	printf("How many turns? %i turns.", num_turn);

	
	return 0;
}
