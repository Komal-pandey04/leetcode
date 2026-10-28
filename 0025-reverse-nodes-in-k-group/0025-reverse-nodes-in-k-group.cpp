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
    ListNode* reverseKGroup(ListNode* head,int k) {
        ListNode d(0,head),*p=&d;
        while(true){
            ListNode* e=p;
            for(int i=0;i<k&&e;i++) e=e->next;
            if(!e) break;
            ListNode* a=p->next,*cur=a->next;
            for(int i=1;i<k;i++){
                a->next=cur->next;
                cur->next=p->next;
                p->next=cur;
                cur=a->next;
            }
            p=a;
        }
        return d.next;
    }
};