#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool happy_number(unsigned int n){
	int counter=0;
	int maxcount_of_interations=100;
	int* vector = (int*)calloc(sizeof(unsigned int), sizeof(int));
	int nextn=0;
	
	int buffern=0;
	int size_int =sizeof(int);
	int bits = size_int * 8;
	int bitclock =0;
	//int *buffer_vector = (int*)calloc(sizeof(unsigned int), sizeof(int));
	//unsigned int first4 = (num >> 28) & 0xF; bit shifting, (& and opperator), shift >>, 8bits in a byte, 32bits total, that why 28 to shift to last
	while(counter <= maxcount_of_interations){
		buffern=0;
		bitclock=0;
		nextn=0;
		while(n>0){
		buffern = vector[4-bitclock] = (n) % 10;//not work(n >> (bits-(8*(bitclock)))) & 0xF;
		printf("%d,", buffern);
		buffern*=buffern;
		nextn+=buffern;      
		n/=10;
		bitclock++;
		}
		printf("\n");
		if(n==nextn){
			free(vector);
			return false;
		}
		n=nextn;
		if(n==1){
			free(vector);
			return true;
		}
		counter++;
	}
	return false;       }
int main(int argc, char * argv){
	int inputn = 19;
	printf("output is \t%s\n", (happy_number(inputn)) ? "true" : "false");
	return 0;
}
