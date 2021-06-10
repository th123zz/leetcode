/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

int bubble_sort (int* nums, int numsSize);
int threeSumClosest(int* nums, int numsSize, int target){
        int i = 0;
        int left = 0;
        int right = 0;
        int result = 0;

        bubble_sort( nums, numsSize );
 
        result = nums[0]+nums[1]+nums[2];

        for ( i=0; i<numsSize-2; i++ ) {

                left = i+1;
                right = numsSize-1;

                while ( left < right ) {
                        int sum = nums[i]+nums[left]+nums[right];
                        if ( sum > target ) {
                                right--;
                        } else if ( sum < target ) {
                                left++;
                        } else if ( sum == target ) {
                                return sum;
                        }
                        
                        if ( abs(result-target) > abs(sum-target) ){
                                result = sum;
                        }
                }
        }

        return result;

}


int bubble_sort (int* nums, int numsSize) {
        int i = 0;
        int j = 0;

        for ( i=0; i<numsSize-1; i++ ) {
                for ( j=0; j<numsSize-i-1; j++ ) {
                        if ( nums[j] > nums[j+1] ) {
                                int tmp = nums[j];
                                nums[j] = nums[j+1];
                                nums[j+1] = tmp;
                        }
                }
        }

        return 0;
} 
// @lc code=end

