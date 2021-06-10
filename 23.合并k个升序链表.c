/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

        if ( listsSize == 0 ) {
                return NULL;
        }
 
        while ((listsSize/2) != 0) {
                int i = 0;
                for (i=0; i<listsSize/2; i++) {
                        lists[i] = mergeTwoLists (lists[i*2], lists[i*2+1]);
                }
                if ( listsSize%2 == 1 ) {
                        lists[i] = lists[listsSize-1];
                        listsSize = listsSize/2+1;
                } else {
                        listsSize = listsSize/2;
                }
                
        }
        return (lists[0]);
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *tmp = head;
        
        if ( (!l1) || (!l2) ) {
                return (l1?l1:l2);
        }

        while ( (l1!=NULL) && (l2!=NULL) ) {
                if ( l1->val >= l2->val ) {
                        tmp->next = l2;
                        l2 = l2->next;
                } else {
                        tmp->next = l1;
                        l1 = l1->next;
                }
                tmp = tmp->next;
        }

        if ( (!l1) || (!l2) ) {
                tmp->next = (l1?l1:l2);
        }

        struct ListNode *return_head = head->next;
        free(head);
        return (return_head);

}
// @lc code=end

