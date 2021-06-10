/*
 * @lc app=leetcode.cn id=38 lang=c
 *
 * [38] 外观数列
 */

// @lc code=start

#define         MAX_LEN         10000

int cal (char *s);

char * countAndSay(int n){
        char tmp[MAX_LEN];
        char *result = (char *)malloc(MAX_LEN*sizeof(char));
        strcpy(tmp, "1");
        strcpy(result, "1");
        for (int i=0; i<n-1; i++) {
                int num = 0;
                int len = 0;
                for (int j=0; j<strlen(tmp); j=j+len) {
                        len = cal(&tmp[j]);
                        result[num] = len+'0';
                        result[num+1] = tmp[j];
                        num = num+2;
                }
                result[num] = '\0';
                strcpy(tmp, result);
        }
        return result;
}

//计算开头相同数连续的个数
int cal (char *s) {
        int i=0;
        for (i=1; i<strlen(s); i++) {
                if ( s[i] == s[i-1] ) {
                        continue;
                } else {
                        break;
                }
        }
        return i;
}
// @lc code=end

