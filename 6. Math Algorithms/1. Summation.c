#include <stdio.h>
#include <stdlib.h>

int AlgoSummation(int ini, int fin, int skull)
{
	skull=(fin*(fin+1))/2-(ini*(ini-1))/2;
	return skull;
}

int main(int argc, char *argv[]) {
	while(3){
		system("TITLE AlgoSum");
		system("CLS");
		system("COLOR F0");
		
		int ini, fin, skull; 
		
		printf("\n Initialization: ");
		scanf("%d", &ini);
		printf("\n Finalization: ");
		scanf("%d", &fin);
		
		printf("\n Summation = %d", AlgoSummation(ini, fin, skull));
		printf("\n\n by Aldo Manco, Jr.");
		getch();
	}
	return 1;
}
