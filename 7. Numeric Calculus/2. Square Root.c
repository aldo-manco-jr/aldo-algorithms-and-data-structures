#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

double SquareRoot(double beta, double alpha, double x)
{
	beta=alpha/2; // 4.5
    
    do{   
	    x=beta; // 3.25
	    beta=(beta+(alpha/beta))/2;
    }while(x!=beta); // 4.5 3.25
    return beta;
}

int main(int argc, char *argv[]) {
	while(2) {
	
	system("TITLE AlgoRoot");
	system("CLS");
	system("COLOR f0");
	
	double alpha, beta, x=0;
	
	printf("\n Enter A Number: ");
	scanf("%lf", &alpha);
	
	printf("\n Square Root = %.17lf", SquareRoot(beta, alpha, x));
	printf("\n\n by Aldo Manco & Domenico Tortiglione...");
	getch();
}
	return 1;
}
