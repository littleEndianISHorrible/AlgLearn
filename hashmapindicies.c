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

//or 
/*#include <stdio.h>
#include <stdlib.h>
int* findindiciesontarget(int target, int vector[], int max, int len){
 int i=0;
 int underfill = (int*)calloc( len, sizeof(int));
 int *indicies = (int*)calloc( max*len, sizeof(int));
 int counter =0;
 int *full=(int*)calloc(2*max*len, sizeof(int));
 int *untouchedmap = (int*)calloc(max*len, sizeof(int));
 int *hashtable = (int*)calloc(2* max*len*len, sizeof(int));
 for(i=0; i<=len*2; i++){
  if(target-vector[counter] >= 1){
   underfill[counter] = target-vector[counter];
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
   int* output = malloc(2 * sizeof(int));
   output[0] = untouchedmap[full[i]];
   output[1] = indicies[full[i]];
   free(indicies);
   free(untcouhedmap);
   free(full);
   free(hashtable);
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
 return 0;*/
