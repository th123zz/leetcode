/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int bubble_sort(int* nums, int numsSize);
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
        int i = 0;
        int j = 0;
        int left = 0;
        int right = 0;
        int times = 0;
        *returnSize = 0;

        if ( (nums==NULL) || (numsSize<4) ) {
                return NULL;
        }
        bubble_sort(nums, numsSize);

        int **answer = (int **)malloc(numsSize*6*sizeof(int**));
        *returnColumnSizes = malloc(numsSize*6*sizeof(int));

        for ( i=0; i<numsSize-3; i++) {
                if ( (i>0) && (nums[i]==nums[i-1]) ) {
                        continue;
                }
                for ( j=i+1; j<numsSize-2; j++) {
                        if ( (j>1+i) && (nums[j]==nums[j-1]) ) {
                                continue;
                        }
                        
                        left = j+1;
                        right = numsSize-1;
                        while ( left<right ) {
                                int sum = nums[i]+nums[j]+nums[left]+nums[right];
                                if (sum == target) {
                                        answer[times] = malloc(sizeof(int)*4);
                                        answer[times][0] = nums[i];
                                        answer[times][1] = nums[j];
                                        answer[times][2] = nums[left];
                                        answer[times][3] = nums[right];
                                        (*returnColumnSizes)[times] = 4;
                                        times++;
                                        while ( (left<right) && (nums[left]==nums[++left]) );
                                        while ( (left<right) && (nums[right]==nums[--right]) );
                                } else if (sum < target) {
                                        left++;
                                } else if (sum > target) {
                                        right--;
                                }
                        }

                }
        }
        *returnSize = times;
        return answer;
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

