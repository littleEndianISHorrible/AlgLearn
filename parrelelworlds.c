/*„B„r„€„t: scores = [1,3,5,10,15], ages = [1,2,3,4,5] 
„B„„r„€„t: 34 
„B„r„€„t: scores = [4,5,6,5], ages = [2,1,2,1] 
„B„„r„€„t: 16*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int incorrectsort(int *input, int sizeofthing, int **output){
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
int parrelworldsteams(int *inputlista, int *inputlistb, int sizea, int sizeb){
	
	incorrectsort(inputlista, (sizea), &inputlista);
	incorrectsort(inputlista, (sizeb), &inputlistb);
	int *lista = inputlista;
	int *listb = inputlistb;
	sizea /= sizeof(int);
	sizeb /=sizeof(int);   
	int buffercaner1=0;
	if(sizea == sizeb){
		//do nothing 
		1+1;
	}else if(sizea > sizeb){
		buffercaner1 = sizea-sizeb;
		int j=0;
		for(j=0; j<buffercaner1; j++){
			listb[sizeb+j] = (int)malloc(sizeof(int));
			listb[sizeb+j] = 1; 
		}
	}else if(sizea < sizeb){
		  buffercaner1 = sizeb-sizea;
		int j=0;
		for(j=0; j<buffercaner1; j++){
			lista[sizea+j] = (int)malloc(sizeof(int));
			lista[sizea+j] = 1; 
		}
	}else{
		return 0;
	}
	int i=0;
	int convelutedlist[sizea];
	int sum =0;
	for(i=0; i<sizea; i++){
		sum += (listb[i]);
	}
	printf("sum: \t %d\n", sum);
	int meansum = 0;
	for(i=0; i<sizea; i++){
		convelutedlist[i] =  sum*(lista[i]);
		convelutedlist[i] -= (lista[i]);
		printf("ab: \t %d\n", convelutedlist[i]);
		meansum += convelutedlist[i];
		printf("mesum: \t %d\n", meansum);
	}
	unsigned long long factorial = 1;  
	for (i = 1; i <= sizea; ++i) {
            factorial *= i;
	}
	int a = (int)(meansum/(sizea*sizea*0.5));
	int b = (int)(meansum/(sizea));
	int c = (int)(meansum/(factorial ));   //+(c*c)
	//return ((c*c)*(a*a)*(b*b))/(meansum*meansum);
	return meansum/sum;

}
int main(){
	int inputlistage[] = {4,5,6,5};
	//int inputlistage[] = {1,3,5,10,15};
	int inputlistscore[] = {2,1,2,1};
	//int inputlistscore[] = {1,2,3,4,5};
	int finalvalue =0;
	finalvalue = parrelworldsteams(inputlistage, inputlistscore, sizeof(inputlistage), sizeof(inputlistscore));
	printf("finalvalue:\t%d\n", finalvalue);
	return 0; 
}


//code review tommoro 
