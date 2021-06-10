/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int bubble_sort(int* nums, int numsSize);
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
        int i = 0;
        int j = 0;
        int k = 0;
        
        int size = 0;

        printf ("numsSize:%d",numsSize);

        if ((nums==NULL) || (numsSize<3)) {
                *returnSize = 0;
                return NULL;
        }
        
        bubble_sort(nums, numsSize);

        int **ans = (int**)malloc((numsSize + 1) * 6 * sizeof(int *));
        *returnColumnSizes = malloc((numsSize + 1) * 6 * sizeof(int));


        for ( i=0; i<numsSize-2; i++ ) {
                if (nums[i] > 0) {
                        break;
                }
                if (i > 0 && nums[i] == nums[i - 1]) {
                        continue;
                }

                j = i+1;
                k = numsSize-1;
                while (j < k) {
                        int sum = nums[i]+nums[j]+nums[k];
                        

                        if (sum == 0){
                                
                                ans[size] = malloc(sizeof(int)*3);
                                ans[size][0] = nums[i];
                                ans[size][1] = nums[j];
                                ans[size][2] = nums[k];
                                
                                (*returnColumnSizes)[size] = 3;
                                size = size+1;
                                 
                                while ( (j<k) && (nums[j]==nums[++j]) );
                                while ( (j<k) && (nums[k]==nums[--k]) );
                                printf ("i:%d,j:%d,k:%d\n", i, j, k);
                               // break;
                                
                        } else if (sum > 0) {
                                k--;
                        } else if (sum < 0) {
                                j++;
                        }
                        
                  
                }
        }
        *returnSize = size;
        return ans;

        

}

int bubble_sort(int* nums, int numsSize){
        int i = 0;
        int j = 0;
        int tmp = 0;

        for ( i=0; i<numsSize-1; i++ ){
                for ( j=0; j<numsSize-i-1; j++ ){
                        if (nums[j] > nums[j+1]){
                               tmp = nums[j];
                               nums[j] = nums[j+1];
                               nums[j+1] = tmp;
                        }
                }
        }

        return 1;
}


// @lc code=end

