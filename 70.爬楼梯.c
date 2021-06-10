/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start


int climbStairs(int n){
        int i = 0;
        int *dp = malloc(sizeof(int)*(n+1));
        dp[0] = 1;
        dp[1] = 2;

        for ( i=2; i<n; i++) {
                dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n-1];
}
// @lc code=end

