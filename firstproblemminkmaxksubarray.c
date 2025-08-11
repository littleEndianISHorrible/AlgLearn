//solution
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

/*

 
 */
int algmain(int *nums, int sizeofnums, int mink, int maxk){
	int totalbreaks[sizeofnums/sizeof(int)];
	int amoutofsubarrays =0; //which is our little system total 
	//key: -3 negative num break num too small, +3 num too big, -1 wall negative, _1 positive wall
	int i;
	int len = sizeofnums/sizeof(int);
	for(i=0; i<len; i++){
		if(nums[i] <= mink && i == 0){
			amoutofsubarrays += 1;
		}else if(nums[i] <= mink){
			amoutofsubarrays += 3;
		}
		if(nums[i] >= maxk && i == len){
			amoutofsubarrays += 1;
			
		}else if(nums[i] >= maxk){
			amoutofsubarrays += 3;
			
		}
	}
	int devine = amoutofsubarrays/ 3;
	return (devine)-(amoutofsubarrays% 3);
}
int main(){
	int nums[] = {1,1,1,1};
	int mink =2;
	int maxk = 3;
	printf("test: %d", algmain(nums, sizeof(nums), mink, maxk));
	return 0;
}
