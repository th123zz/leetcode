/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 */

// @lc code=start
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int cal_result (char *p, char a, char b, int *flag);

char * addBinary(char * a, char * b){
        int k = 0;
        int flag = 0;
        int a_len = strlen(a);
        int b_len = strlen(b);
        int r_len = MAX(a_len,b_len)+2;

        //这里申请比最大的数组长度还要+2是因为，有可能产生进位，长度+1.字符串末尾要添加\0,长度也要+1
        char  *result = (char*)malloc( r_len*sizeof(char) );
        
        memset( result, 0, r_len );
        //malloc申请的内存末尾不会自动添加\0 这里添加\0非常重要。否则返回会报错
        result[r_len-1] = '\0';
        
        k = r_len-1;
        while ( (a_len>0) && (b_len>0) ) {
                cal_result ( &result[--k], a[--a_len], b[--b_len], &flag);
        }
        while ( (a_len==0) && (b_len!=0) ) {
                cal_result ( &result[--k], '0', b[--b_len], &flag);
        }

        while ( (b_len==0) && (a_len!=0) ) {
                cal_result ( &result[--k], a[--a_len], '0', &flag);
        }

        if ( flag == 1 ) {              //有进位的情况
                result[--k] = '1';
                return result;
        } else {                        //没有进位的情况
                return result+1;
        }

        return NULL;
}

int cal_result (char *p, char a, char b, int *flag) {
        int sum = a + b - '0' - '0' + *flag;
        printf ("sum:%d\n", sum);
        if ( sum == 0 ) {
                *flag = 0;
                *p = '0';
        } else if ( sum == 1 ) {
                *flag = 0;
                *p = '1';
        } else if ( sum == 2 ) {
                *flag = 1;
                *p = '0';
        } else if ( sum == 3 ) {
                *flag = 1;
                *p = '1';
        }

        return 1;
}
// @lc code=end

