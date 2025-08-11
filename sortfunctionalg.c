#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//ok so just redo ig

int correctsort(int *input, int sizeofthing, int **output){
	int i;
	int len = sizeofthing /sizeof(int);
	int buffersmallest = (input)[0];
	int indexofsmallest = 0;
	int buffer  = 1;
	for(i=0; i< len-1; i++){
		if(input[i+1] < input[i]){
			buffer = input[i+1];
			input[i+1] = input[i];
			input[i] = buffer;
			if(buffersmallest>input[i]){
				buffer = (input)[indexofsmallest];
				(input)[indexofsmallest] = (input)[i];
				(input)[i] = buffer;
				indexofsmallest = i; 
				buffersmallest = (input)[i];
			}
			
		}
		if(input[i-1] > input[i] && i!=0){
			buffer = input[i-1];
			input[i-1] = input[i];
			input[i] = buffer;
			if(buffersmallest>input[i]){
				buffer = (input)[indexofsmallest];
				(input)[indexofsmallest] = (input)[i];
				(input)[i] = buffer;
				indexofsmallest = i; 
				buffersmallest = (input)[i];
			}
			
		}
		
	}
	output  = &input; 
}
int main(){
	int inputlist[] = {15, 3, 7, 19, 8, 3, 1, 6};
	correctsort(inputlist, sizeof(inputlist), &inputlist);
	correctsort(inputlist, sizeof(inputlist), &inputlist);
	
	
	int i ;
	printf("sort:\t");
	for(i=0; i<= sizeof(inputlist ) /sizeof(int) -1; i++){
		printf(", %d" , inputlist[i]);
	}
	return 0;
}
