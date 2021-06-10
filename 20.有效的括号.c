/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start

bool isValid(char * s){
        
        char *str_head = s; 
        char *stack_head = s;

        if ((strlen(s) < 2) || (strlen(s)%2 != 0)){
                return false;
        }

        while (*s != '\0'){
                if ( (*s=='(') || (*s=='[') || (*s=='{') ) {
                        *stack_head = *s;
                        stack_head++;
                } else {  
                        if ( (stack_head == str_head) && ((*s == ')') || (*s == ']') || (*s == '}')) ) {
                                return false;
                        }

                        stack_head--;
                        
                        if (((*s == ')') && (*stack_head != '(')) ||
                            ((*s == ']') && (*stack_head != '[')) ||
                            ((*s == '}') && (*stack_head != '{')) ){
                                return false;
                        }
                }
                s++;
        }

        if (stack_head == str_head){
                return true;
        } else {
                return false;
        }

}
// @lc code=end

