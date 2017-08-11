#include <stdio.h>
#include <math.h>
void main()
{
	int n, i;
	double fact(int x);
    float x, sign = -1, sinx = 1;

    printf("Enter the length of the series\n");
    scanf("%d", &n);

    printf("Enter the value of x\n");
    scanf("%f", &x);
    sinx = x;

	for(i=2; i<n; i+=2){
		sinx += (pow(x,i+1)/fact(i+1))*sign;
		sign=-1*sign;
	}

	printf("Value of sin(x): %f\n",sinx);
	printf("Value of sin(x) using math.h: %f\n", sin(x));

}

double fact(int x){
	
	int i=1;
	double sum=1;
	for(i;i<x+1;i++){
		sum=sum*i;
	}
	return sum;
}