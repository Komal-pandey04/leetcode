/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode d(0,head),*p=&d;
        while(p->next&&p->next->next){
            ListNode* a=p->next;
            ListNode* b=a->next;
            a->next=b->next;
            b->next=a;
            p->next=b;
            p=a;
        }
        return d.next;
    }
};