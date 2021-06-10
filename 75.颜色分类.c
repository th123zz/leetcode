/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 */

// @lc code=start


void sortColors(int* nums, int numsSize){
        int left = 0;
        int right = numsSize-1;
        int i = 0;
        while ( i <= right ){
                switch (nums[i]) {
                        case 0: if ( i == left ){
                                        i++;
                                        left++;
                                } else {
                                        nums[i] = nums[left];
                                        nums[left] = 0;
                                        left++;   
                                }
                                break;
                        case 1: i++;
                                break;
                        case 2: 
                                nums[i] = nums[right];
                                nums[right] = 2;
                                right--;
                                break;
                        default:
                                break;
                }
        }
}
// @lc code=end

