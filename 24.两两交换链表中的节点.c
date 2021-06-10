/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
        struct ListNode *tmp = head;
        struct ListNode left_head;
        struct ListNode *left = &left_head;
        left->next = head;

        while ( (tmp!=NULL) && (tmp->next!=NULL) ) {
                struct ListNode *a = tmp->next;
                tmp->next = a->next;
                a->next = tmp;
                left->next = a;
                left = tmp;
                tmp = tmp->next;
        }
        return left_head.next;
}
// @lc code=end

