#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool findcharinstring(char car, char*string, int sizestring){
	int i;
	int index=0;
	for(i=0; i<sizestring-1; i++){
		if(string[i] == car){
			index =i;
			printf("breaking out: index\t %d\n", i);
			return true; 
		}
	}
	return false;
}
int firstinstancefindfunction(char*inputstringsub, char* inputmainstring, int sizesub, int sizeoverall, int*indexstart, int* indexend){
	sizeoverall --;
	sizesub--;
	
	double devistordouble = sizeoverall/sizesub;
	int devistorint = (int)devistordouble;
	int i;
	int j=0;
	bool lockedontarget = false;
	for(i=0, j=0; i< sizeoverall; i++){
		if(j>sizesub){
			j=0; 
			printf("J is now zero since bigger than sizesub\n");
		}
		
		if(inputstringsub[j] !=  inputmainstring[i] && lockedontarget && j<1){
			lockedontarget = false;
			//*indexstart = i;
			printf("lockedontarget = false, indexstart =i = %d\n", i);
		}else if(inputstringsub[j] == inputmainstring[i] && lockedontarget){
			*indexstart = i-1;
		}else if(inputstringsub[j] == inputmainstring[i]){
			lockedontarget = true;
			printf("defult lockedtarget = true, started picking i=%d\n", i);
		}
		
		if(lockedontarget && inputstringsub[j] != inputmainstring[i] && j>0){
			*indexend=i+1;
			printf("breaking out \n");
			break;
		}
		
		if(!lockedontarget && !findcharinstring(inputmainstring[i+sizesub], inputstringsub, sizeof(inputstringsub))){
			i+=sizesub-1;
			printf("jumped i by len j\n");
		}else if(lockedontarget){
			j++;
			printf("append j\n");
		}
	}
	return 0; 
}

int main(){
	char string[] = "hello world thier is a cat here";
	char stringfind[] = "cat";
	int returnindexstart =0;
	int returnindexend =0;
	firstinstancefindfunction(stringfind, string, sizeof(stringfind), sizeof(string), &returnindexstart, &returnindexend);
	printf("%s\n", string);
	printf("string:\t%s, is found on index from:\t%d, to \t %d\n", stringfind, returnindexstart, returnindexend);
	//prinitng the indexes
	int i = 0;
	for(i=returnindexstart-1; i<returnindexend; i++){
		printf("%c", string[i]);
	}
	printf("\n");
	return 0; 
}
