/*
 * @lc app=leetcode.cn id=69 lang=c
 *
 * [69] x 的平方根
 */

// @lc code=start


int mySqrt(int x){
        int left = 0;
        int right = x;
        int mid = 0;

        while ( 1 ) {
                mid = (left+right)/2;
                if ( ((long long)mid*mid) > x ) {
                        right = mid-1;
                } 
                if ( ((long long)mid*mid) < x ) {
                        left = mid+1;
                }
                
                if (((long long)mid*mid<=x) && ((long long)(mid+1)*(mid+1)>x)) {
                        return mid;
                }
        }
}
// @lc code=end

