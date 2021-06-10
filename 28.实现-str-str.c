/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 */

// @lc code=start

int thaostrcmp (char *str1, char *str2);
int strStr(char * haystack, char * needle){
        int i = 0;

        if (*needle == '\0') {
                return 0;
        }
        if (*haystack == '\0') {
                return -1;
        }
        if (strlen(haystack) < strlen(needle)){
                return -1;
        }

        for (i=0; i<strlen(haystack)-strlen(needle)+1; i++) {
                if (*(haystack+i) != *needle){
                        continue;
                } else {
                        if (thaostrcmp(haystack+i, needle) == 1) {
                                return i;
                        }
                }
        }

        return -1;

}

int thaostrcmp (char *str1, char *str2){
        char *tmp1 = str1;
        char *tmp2 = str2;

       // printf ("thao debug: str1:%s, str2:%s\n", str1, str2);
        while ( (*tmp1!='\0') && (*tmp2!='\0') ) {
                //printf ("thao debug: tmp1:%c, tmp2:%c\n", *tmp1, *tmp2);
                if (*tmp1 == *tmp2){
                        tmp1++;
                        tmp2++;
                } else {
                        return 0;
                }
        }

        if (*tmp2 == '\0') {
                return 1;
        } else {
                return 0;
        }
}
// @lc code=end

