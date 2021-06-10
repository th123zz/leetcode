/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){

        int *ans = (int *)malloc(2*sizeof(int));
        *returnSize = 2;

        ans[0] = -1;
        ans[1] = -1;

        int left = 0;
        int right = numsSize-1;

        while ( left <= right ) {
                int mid = (left+right)/2;

                if ( nums[mid] > target ) {
                        right = mid-1;
                } else if ( nums[mid] < target ) {
                        left = mid +1;
                } else if ( nums[mid] == target ) {
                        int l = mid;
                        int r = mid;
                        while ( (l>=left) && (nums[l]==target) ) {
                                ans[0] = l--;
                        }
                        while ( (r<=right) && (nums[r]==target) ) {
                                ans[1] = r++;
                        }
                        break;
                } 
        }
        return ans;

}
// @lc code=end

