#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "string_matching.h"
#include "string_matching_naive.c"
#include "string_matching_kmp.c"
#include "time.h"

void performance_test(int N, int M){
  int i;
  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  srand(time(NULL));   // Initialization, should only be called once.
  
    int n = N;
    int m = M; 
    
    char *text = malloc(n+1);
    for (i=0; i<n; i++){
	  int pos = rand() % (int)(sizeof(charset) -1);
          text[i] = charset[pos];      
    }
    text[i] = '\0';
	  
    char *pattern = malloc(m +1);
    for (i=0; i<m; i++){
	  int pos = rand() % (int)(sizeof(charset) - 1);
          pattern[i] = charset[pos];      
    }
    pattern[i] = '\0';
	  
    //printf("text='%s', pattern='%s'\n", text, pattern);
    clock_t t; 
    t = clock();
    int result1 = string_matching_naive(text, n, pattern, m);
    t = clock() - t; 
    double time_taken_naive = ((double)t)/CLOCKS_PER_SEC;
    t = clock(); 
    int result2 = string_matching_kmp(text, n, pattern, m);
    t = clock() - t;
    double time_taken_kmp = ((double)t)/CLOCKS_PER_SEC;
    
    if (result1==result2)
      	printf("naive = %f s, kmp = %f s\n", time_taken_naive, time_taken_kmp);
    else {
      	printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
	exit(0);
    }
    free(text);
    free(pattern);  
}

int main(){
   int max = 10000000;
   for(int N = 10000; N<= max; N+=50000){
   	performance_test(N, 400);
   }
   return 0;
  
}
