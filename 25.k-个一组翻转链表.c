/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head, int k);
struct ListNode* reverseKGroup(struct ListNode* head, int k){
        struct ListNode* hair  = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* pre = hair;
        struct ListNode* test = head;
        hair->next = head;

        while ( 1 ) {
                test = head;
                for (int i=0; i<k; i++) {
                        if (test == NULL) {
                                return hair ->next;
                        }
                        test = test->next;
                }
                pre->next = reverseList(head, k);
                head->next = test;
                pre = head;
                head = test;
        }
}

struct ListNode* reverseList(struct ListNode* head, int k) {
        struct ListNode* pre = NULL;
        struct ListNode* curr = head;

        for (int i=0; i<k; i++) {
             struct ListNode* next = curr->next;
             curr->next = pre;
             pre = curr;
             curr = next;
        }
        return pre;
}
// @lc code=end

