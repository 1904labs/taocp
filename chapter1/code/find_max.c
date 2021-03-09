#include <stdio.h>

int main(){

  int X[] = {10,2,3,19,4,5,6};

  size_t n = sizeof(X)/sizeof(X[0]);

  int j = n-1;
  int k =  n - 2;
  int m  = X[n-1];
  while(k >= 0){
    if(X[k] <= m)
      k--;
    else{
      j = k;
      m = X[k];
    }
    
  }
  printf("index -> %d , max value -> %d \n", j, m);
  
}
