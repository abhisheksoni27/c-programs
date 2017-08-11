#include <stdio.h>
void main()
{
    int n,i,a[100],j;

    printf("Enter decimal number: \n");
    
    scanf("%d",&n);

    i=0;

    while(n>0){
        a[i]=n%2;
        n=n/2;
        i++;
    }

    
    printf("The binary number is: ");
    
    for(j=i-1; j>-1; j--){
        printf("%d", a[j]);
    }
    
    printf("\n");
}
