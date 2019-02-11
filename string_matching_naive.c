#include "string_matching.h"
#include <string.h>

int string_matching_naive(char* text, int N, char* pattern, int M){
	int total = 0;
	for (int i = 0; i <= N-M; i++){
		int j = 0;		
		while(j<M){
			if (text[i+j] == pattern[j]){
				j++;
				if(j == M){
					total++;
				}
			}
			else{
				break;
			}
		}
	}
	return total;
}

/*int main(){
	char* str;
	str = "qwertyaauiopaaasdfghaajklaaz";
	char* pat;
	pat = "aa";
	int a = string_matching_naive(str, 28, pat, 2);
	printf("%d\n",a);
}
Used a main function to test different examples for my code*/


