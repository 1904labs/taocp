#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

int gcd(int m, int n){
  int r = m % n;
  if(r == 0)
    return n;
  else
    return gcd(n,r);
}

int main(int argc, const char* argv[]){
  char *p ;
  errno = 0;
  
  
  if (argc != 3){
    printf("Please provide two positive numbers\n");
    return 1;
  }else{
    int m = 0;
    int n = 0;
    long conv = strtol(argv[1],&p, 10);
    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv <= 0){
      printf("bad number\n");
      return 1;
    }else {
      m = conv;
    }
    conv = strtol(argv[2],&p, 10);
    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv <= 0){
      printf("bad number\n");
      return 1;
    }else {
      n = conv;
    }
    
    printf("inputs are %d , %d\n", m, n);
    int result  = gcd(m,n);
    printf("GCD is %d\n", result);
    return 0;
  }
}
