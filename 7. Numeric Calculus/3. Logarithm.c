#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

double Logarithm(double max, double number, double temp, double min, double amjr, double base, double delta)
{
	max=number;
	temp=0;
	min=1;
   
   while (8) {
      amjr=(min+max)/2;                 // il logaritmo iniziale e' uguale alla somma di min=0 + max=input tutto diviso 2 [2+0]/2=1
      delta=pow(base, amjr);           // il delta e' eguale alla base elevata al logaritmo iniziale [10^1]
      if(delta>number)                // se il delta e' maggiore di 2 (si) il massimo e' assegnato a log ini
         max=amjr;
      if(delta<number)
         min=amjr;
      if(temp==amjr)
         break;
      temp=amjr;
   }
   return amjr;
}

int main(int argc, char *argv[]) {
	while(8)
	{   system("TITLE Logarithms");
		system("CLS");
		system("COLOR F0");
	double num, base, max, temp=-1, min=0, amjr, delta;
	
	printf("\n Number: ");
	scanf("%lf", &num);
	printf("\n Base: ");
	scanf("%lf", &base);
	
	printf("\n Logarithm = %.17lf", Logarithm(max, num, temp, min, amjr, base, delta));
	printf("\n\n by Aldo Manco, Jr.");
	getch();
}
	return 1;
}
