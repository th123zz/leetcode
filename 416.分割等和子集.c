/*
 * @lc app=leetcode.cn id=416 lang=c
 *
 * [416] 分割等和子集
 */

// @lc code=start
//dp[i][j] 表示前i个数任选，总和是否为j。
#define         MAX_NUM(x,y)         ((x)>(y)?(x):(y))

bool canPartition(int* nums, int numsSize){
        int sum = 0;
        int target = 0;
        int answer = 0;
        int max_num = 0;

        //求取和和最大值
        for (int i=0; i<numsSize; i++) {
                sum =sum+nums[i];
                max_num = MAX_NUM(nums[i], max_num);
        }
        target = sum/2;
        //如果和为奇数或者最大值比sum/2还要大，证明没有一个子集的和是另外一个子集
        if ( (sum%2) || (max_num>target) ) {
                return false;
        }

        //申请一个二维数组，并全部初始化为0
        int **ans = (int **)malloc(numsSize*sizeof(int *));
        for (int i=0; i<numsSize; i++) {
                *(ans+i) = (int *)malloc((target+1)*sizeof(int));
                for (int j=0; j<target+1; j++) {
                        ans[i][j] = 0;
                }
        }

        //初始化第一列数组，当j为0时，ans[i][0]全部初始化为1；
        for (int i=0; i<numsSize; i++) {
                ans[i][0] = 1;
        }
        //初始化第一行数组，当i为0时，nums[0] == i成立则ans[i][0]为1
        for (int i=0; i<=target; i++) {
                if (nums[0] == i) {
                        ans[0][i] = 1;
                }
        }

        for (int i=1; i<numsSize; i++) {
                for (int j=0; j<=target; j++) {
                        if ( j > nums[i] ) {
                                ans[i][j] = ans[i-1][j] | ans[i-1][j-nums[i]];
                        } else {
                                ans[i][j] = ans[i-1][j];
                        }     
                }
        }

        answer = ans[numsSize-1][target];
        for (int i=0; i<numsSize; i++) {
                free(*(ans+i));
        }

        free(ans);

        return answer;

}
// @lc code=end

