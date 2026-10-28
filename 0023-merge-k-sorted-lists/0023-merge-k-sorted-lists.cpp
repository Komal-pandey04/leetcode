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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](ListNode* a,ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        for(auto l:lists)
            if(l) pq.push(l);
        ListNode d(0),*t=&d;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            t->next=p;
            t=p;
            if(p->next) pq.push(p->next);
        }
        return d.next;
    }
};