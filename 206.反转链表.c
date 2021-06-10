/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
#if 0
        struct ListNode* pre = NULL;
        struct ListNode* curr = head;
        while ( curr ) {
                struct ListNode* next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
        }
        return pre;
#endif

        if (( head==NULL ) || ( head->next==NULL )) {
                return head;
        }

        struct ListNode* pre = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return pre;
}
// @lc code=end

