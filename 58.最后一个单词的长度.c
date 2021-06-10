/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start


int lengthOfLastWord(char * s){
        int len = strlen(s);
        int left = 0;
        int right = 0;

        if ( s == NULL ) {
                return 0;
        }

        while ( (len>0) && (s[--len]==' ') );
        right = len;

        while ( (len>=0) && (s[len]!=' ') ) {
                len--;
        }
        left = len;

        return right-left;

        
}
// @lc code=end

