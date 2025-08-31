#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int notsodynamic(char*s1, char*s2, char*base, char**outputt, int sharedsize){           \
	int b=10; //? it should equal to total num chars
	int combodict1[sharedsize][sharedsize+b];
	int i;
	int n  = sharedsize;
	sharedsize+=2;
	char S1[sharedsize];
	char S2[sharedsize];
	char BASE[sharedsize];
	char output[sharedsize]; 
	char S1B[sharedsize];
	char S2B[sharedsize];
	char BASEB[sharedsize];
	int c=3;
	int p=0;
	bool ran = false; 
	bool halfran = false; 
	for(i=0; i<sharedsize-1; i++){
		if(c>n-1){
			c=0;
		}
		if(c==0){
			S1[i] = s1[n-1];
			S2[i] = s2[n];
			BASE[i] = base[c];
		}else if(c==1){
			S1[i] = s1[n];
			S2[i] = s2[c-1];
			BASE[i] = base[c];
		}else{
			S1[i] = s1[c-2];
			S2[i] = s2[c-1];
			BASE[i] = base[c];
		}
		
		if(S1[i] == S2[i] && S1 == BASE[i]){
            if(S2[i] != BASE[i]){ //a!=b but b==c
            	combodict1[i][1] = S2[i];
				combodict1[i][0] = BASE[i];
				halfran = true; 
			}
		}else{                // a==b==c
			combodict1[i][2] = S1[i];
			combodict1[i][1] = S2[i];
			combodict1[i][0] = BASE[i];
			ran = true;
		}
		
		if(p>n-1){
			p=0;
		}
		S1B[i] = s1[p];
		S2B[i] = s2[p];
		BASEB[i] = base[p];
		if(S1B[i] == S2B[i] && S1B == BASEB[i]){
            if(S2B[i] != BASEB[i]){ //a!=b but b==c
 			    if(halfran){
 			    	combodict1[i][0+3] = S2B[i];
					combodict1[i][1+3] = BASEB[i];
				 }else{
				 	combodict1[i][0] = S2B[i];
					combodict1[i][1] = BASEB[i];
				 }
			}
		}else{                // a==b==c
  		    if(ran){
  		    	combodict1[i][5] = S1B[i];
				combodict1[i][4] = S2B[i];
				combodict1[i][3] = BASEB[i];
			  }else{
			  	combodict1[i][0] = S1B[i];
				combodict1[i][1] = S2B[i];
				combodict1[i][2] = BASEB[i];
			  }
		}
		p++;
		c++;
		output[i] = (combodict1[i][1] >= 0? combodict1[i][1] : combodict1[i][0]); // make it so that all fthe thngs are thinngs that thing that thing thtatnig htih ombine twith on e anohter to tforma a new r32 list 
	}
	*outputt = &output;
	return 0;
	
}

int main(){
	char s1[] = "parker";
	char s2[] = "parser";
	char basestr[] = "morris";
//	for(i=0; i<roundedsize; i++){
//		if(s1[i] == 0)
//	}
	char *stringout;
	notsodynamic(s1,s2,basestr, &stringout, sizeof(s1));
	printf("string out: \t%s", stringout);
	return 0;
}
