#include <stdio.h>
#include <math.h>
void main()
{
	int n, i;
	double fact(int x);
    float x, sign = -1, cosx = 1;

    printf("Enter the length of the series\n");
    scanf("%d", &n);

    printf("Enter the value of x\n");
    scanf("%f", &x);

	for(i=2; i<n; i+=2){
		cosx += (pow(x,i)/fact(i))*sign;
		sign=-1*sign;
	}

	printf("Value of cos(x): %f\n",cosx);
	printf("Value of cos(x) using math.h: %f\n", cos(x));

}

double fact(int x){
	
	int i=1;
	double sum=1;
	for(i;i<x+1;i++){
		sum=sum*i;
	}
	return sum;
}