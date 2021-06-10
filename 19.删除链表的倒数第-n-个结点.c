/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int i;
int recursive_call ( struct ListNode* node, int n );
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
        int result = recursive_call (head, n);

        if ( result == n ){
                head = head->next;
        }
        i = 0;
        return head;
}

int recursive_call ( struct ListNode* node, int n ) {
        
        if ( node->next != NULL) {
                recursive_call (node->next, n);
        }
        if ( i == n ) {
                node->next = node->next->next;
        }
        return i++;
}
// @lc code=end

