/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
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
        struct ListNode *temp = head;

        if ( head == NULL ) {
                return NULL;
        }
        
        while ( temp->next != NULL ) {
                if ( temp->val == temp->next->val ) {
                        temp->next = temp->next->next;
                } else {
                        temp = temp->next;
                }
        }
        return head;
}
// @lc code=end

