/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start


int search(int* nums, int numsSize, int target){
        int left = 0;
        int right = numsSize-1;

        while ( left <= right ) {
                
                int mid = (left+right)/2;
                printf ("thao debug: left:%d,right:%d, mid:%d\n", left, right, mid);
                if ( target == nums[mid] ) {
                        return mid;
                } 
                if ( nums[mid] > nums[left] ) {
                        if ( (target<nums[mid]) && target>=nums[left] ) {
                                right = mid-1;
                        } else {
                                left = mid+1;
                        }
                } else if ( nums[mid] < nums[right] ) {
                        if ( (target>nums[mid]) && target<=nums[right]) {
                                left = mid+1;
                        } else {
                                right = mid-1;
                        }
                } else {
                        left++;
                }
        }

        return -1;
}
// @lc code=end

