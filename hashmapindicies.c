#include <stdio.h>
#include <stdlib.h>
int* findindiciesontarget(int target, int vector[], int max, int len){
	int i=0;
	int underfill[len];
	int *indicies = (int*)calloc( max*len, sizeof(int));
	int counter =0;
	int *untouchedmap = (int*)calloc(max*len, sizeof(int));
	for(i=0; i<=len; i++){
		if(target-vector[i] >= 0){
			underfill[counter] = target-vector[i];
			indicies[underfill[counter]] = i;
			untouchedmap[vector[counter]] = i;
			if(untouchedmap[underfill[counter]] !=0 && indicies[underfill[counter]] != 0 ){
				int* output = malloc(2 * sizeof(int));
				output[0] = untouchedmap[underfill[counter]];
				output[1] = indicies[underfill[counter]];
				return output;
			}
			counter++;
		}
	}
	
}
int main(){
	int vector[] = {3,2,4};
	int target = 6;
	int max = 4;
	int * out = findindiciesontarget(target, vector, max, 3);
	printf("output %d, %d",out[0], out[1]);
	return 0;
}
