/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target){
        int i = 0;

        if ( (nums==NULL) || (numsSize<1) ) {
                return 0;
        }

        for ( i=0; i<numsSize; i++) {
                if ( nums[i] < target ) {
                        continue;
                } else if ( nums[i] == target ) {
                        return i;
                } else if ( nums[i] > target ) {
                        return i;
                }
        }

        if ( i == numsSize ) {
                return numsSize;
        }

        return 0;
}
// @lc code=end

