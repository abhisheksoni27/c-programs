#include<stdio.h>
#include<math.h>

float f(float x){
  return log(x);
};

int main(){
  
  float x0, xn, h, y[20], x[20], ytimestwo, ans;
  
  int i, n;
  
  printf("Enter the value of x0, xn, and n. (Maximum value of n is 21.)\n");
  
  scanf("%f %f %d", &x0, &xn, &n);
  
  h = (xn-x0)/n;
  
  ytimestwo = 0.0;
  
  for(i=1; i<=n; i++){
    
    x[i] = x0 + i*h;
    
    y[i] = f(x[i]);
    
    printf("x: %8.5f, y: %8.5f\n", x[i], y[i]);
    
    ytimestwo = ytimestwo + 2*y[i];
  
  }
  
  ans = (h/2.0) * (y[0] + y[n] + ytimestwo);

  printf("\nThe value of integration is %f",ans);
  
}