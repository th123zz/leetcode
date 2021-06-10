/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
        int len = 1;
        int time = 0;
        struct ListNode *left = head;
        struct ListNode *tail = head;
        struct ListNode *return_head = NULL;

        if ( (head==NULL) || (k==0) ) {
                return head;
        }

        while ( tail->next != NULL) {
                tail = tail->next;
                len++;
        }
        time = len-k%len;

        for (int i=0; i<time-1; i++) {
                left = left->next;
        }
        tail->next = head;
        return_head = left->next;
        left->next = NULL;
        
        return return_head;
}
// @lc code=end

