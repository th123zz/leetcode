/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 */

// @lc code=start

#define         MAX_NUM(x,y)         ((x)>(y)?(x):(y))

int maxSubArray(int* nums, int numsSize){
        int *dp = (int *)malloc(numsSize*sizeof(int));
        int max_num = nums[0];

        dp[0] = nums[0];

        for (int i=1; i<numsSize; i++) {
                dp[i] = MAX_NUM(dp[i-1]+nums[i], nums[i]);
                if ( dp[i] > max_num ) {
                        max_num = dp[i];
                }
        }

        return max_num;
}

// @lc code=end

