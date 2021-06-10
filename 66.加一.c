/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
        int i = 0;
        int flag = 1;
        int *result = malloc( (digitsSize+1)*sizeof(int) );

        memset(result, 0, (digitsSize+1)*sizeof(int));

        for ( i=digitsSize-1; i>=0; i-- ) {
                if (flag != 1){
                        *(result+i+1) = *(digits+i);
                } else {
                        if ((*(digits+i)+1) == 10){
                                flag == 1;
                                *(result+i+1) = 0;
                        } else {
                                flag = 0;
                                *(result+i+1) = *(digits+i)+1;
                        }
                }
        }

        if (flag == 1){
                *result = 1;
                *returnSize = digitsSize+1;
                return result;
        } else {
                *returnSize = digitsSize;
                return (result+1);
        }

}
// @lc code=end

