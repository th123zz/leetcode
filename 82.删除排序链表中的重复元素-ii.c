/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
        struct ListNode *hair = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode *tail = head;
        struct ListNode *pre = hair;
        hair->next = head;
        int flag = 0;

        if ( head == NULL ) {
                return NULL;
        }

        while ( tail->next != NULL ) {
                if ( tail->val == tail->next->val ) {
                        flag = 1;
                        tail->next = tail->next->next;      
                }else {
                        tail = tail->next;
                        if ( flag == 1 ) {
                                flag = 0;
                                pre->next = tail;
                        }else {
                                pre = pre->next;
                        }
                }
        }
        if ( flag == 1 ) {
                pre->next = NULL;
        }
        struct ListNode *return_head = hair->next;
        free (hair);
        return (return_head);
}
// @lc code=end

