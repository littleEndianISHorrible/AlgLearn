#include <stdio.h>
#include <stdlib.h>
int* findindiciesontarget(int target, int vector[], int max, int len){
	int i=0;
	int underfill[len];
	int *indicies = (int*)calloc( max*len, sizeof(int));
	int counter =0;
	int *full=(int*)calloc(2*max*len, sizeof(int));
	int *untouchedmap = (int*)calloc(max*len, sizeof(int));
	int *hashtable = (int*)calloc(2* max*len*len, sizeof(int));
	for(i=0; i<=len*2; i++){
		if(target-vector[i] >= 1){
			underfill[counter] = target-vector[i];
			indicies[underfill[counter]] = i;
			untouchedmap[vector[counter]] = i;
			counter++;
		}
		if(i<=len){
			full[i] = vector[i];
		}else{
			full[i] = underfill[i-len-1];
		}
	}
	for(i=0; i<=2*len; i++){
		if(hashtable[full[i]] == 0){
			  hashtable[full[i]] = 1;
		}else{
		     hashtable[full[i]] += 1;
		}
	}
	for(i=0; i<=2*len; i++){
		if(hashtable[full[i]]>1){
			int  output[3] = {untouchedmap[full[i]], indicies[full[i]]};
			return output;
		}
	}
	
}
int main(){
	int vector[] = {2,7,11,15};
	int target = 9;
	int max = 15;
	int * out = findindiciesontarget(target, vector, max, 4);
	printf("output %d, %d",out[0], out[1]);
	return 0;
}
