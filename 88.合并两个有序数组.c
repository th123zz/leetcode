/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

// @lc code=start


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
        int i = m-1;
        int j = n-1;

        while ( (i>=0) && (j>=0) ) {
                if ( nums1[i] > nums2[j] ) {
                        nums1[--nums1Size] = nums1[i];
                        i--;
                } else {
                        nums1[--nums1Size] = nums2[j];
                        j--;
                }
        }

        if ( i < 0 ) {
                while ( j >= 0) {
                        nums1[--nums1Size] = nums2[j--];
                }
        }

}
// @lc code=end