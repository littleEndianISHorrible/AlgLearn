#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
    int valid;
} HashEntry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // „V„„Š-„„„p„q„|„y„ˆ„p: „{„|„„‰ ? „‰„y„ƒ„|„€, „x„~„p„‰„u„~„y„u ? „y„~„t„u„{„ƒ
    HashEntry* hashTable = (HashEntry*)calloc(numsSize, sizeof(HashEntry));   //<- eto struct
    if (!hashTable) {
        *returnSize = 0;
        return NULL;
    }      //ne nado
	int i;
    for (i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
		int j;
        // „I„‹„u„} complement „r „„„p„q„|„y„ˆ„u
        for (j = 0; j < numsSize; j++) {
            if (hashTable[j].valid && hashTable[j].key == complement) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = hashTable[j].value;
                *returnSize = 2;

                free(hashTable);
                return result;
            }
        }

        // „D„€„q„p„r„|„‘„u„} „„„u„{„…„‹„u„u „‰„y„ƒ„|„€ „r „‡„„Š-„„„p„q„|„y„ˆ„…
        hashTable[i].key = nums[i];
        hashTable[i].value = i;
        hashTable[i].valid = 1;
    }

    free(hashTable);
    *returnSize = 0;
    return NULL;
}

int main() {
    int vector[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = 4;
    int returnSize;

    int* result = twoSum(vector, numsSize, target, &returnSize);

    if (result && returnSize == 2) {
        printf("„I„~„t„u„{„ƒ„: %d, %d\n", result[0], result[1]);
    } else {
        printf("„Q„u„Š„u„~„y„u „~„u „~„p„z„t„u„~„€.\n");
    }

    free(result);
    return 0;
}
