int cal_palindrome (char *left, char *right, char *head);

char * longestPalindrome(char * s){
        int max_len = 0;
        char *result = (char *)malloc(1001*sizeof(char));
        char *tmp = s+1;
        char *result_left = NULL;


        if ( (strlen(s) < 2) ){
                return s;
        }

        while ( tmp < (s+strlen(s)-1) )
        {       
                int len = 0;      
                if ( *tmp == *(tmp-1) ) {
                        len=cal_palindrome(tmp-1, tmp, s);
                        if (len > max_len) {
                                max_len = len;
                                result_left = tmp-max_len/2;
                        }
                } else if ( *tmp == *(tmp+1) ){
                        len=cal_palindrome(tmp, tmp+1, s);
                        if (len > max_len) {
                                max_len = len;
                                result_left = tmp-max_len/2+1;
                        }
                }
                if ( *(tmp-1) == *(tmp+1) ) {
                        len=cal_palindrome(tmp, tmp, s);
                        if (len > max_len) {
                                max_len = len;
                                result_left = tmp-max_len/2;
                        }
                } 
                tmp++;
        }

        if ( max_len == 0 ) {
                if ( *s == *(s+1) ){
                        return s;
                } else {
                        *(s+1) = '\0';
                        return s;
                }
        }

        strncpy (result, result_left, max_len);
        result[max_len] = '\0';
        return result;
}
int cal_palindrome (char *left, char *right, char *head) {
        
        while ( (left>head) && (right<(head+strlen(head))) && (*left == *right) ) {
                left--;
                right++;
        }

        if (*left == *right) {
                return (right-left)-1+2;
        }

        return (right-left)-1;

}