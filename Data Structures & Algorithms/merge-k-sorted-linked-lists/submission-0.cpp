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
        auto cmp=[](const ListNode* a,const ListNode* b){return a->val>b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>pq(cmp);
        for(ListNode* head:lists)if(head!=NULL)pq.push(head);

        ListNode* dummy_node=new ListNode(-1);
        ListNode* temp=dummy_node;
        while(!pq.empty()){
            temp->next=pq.top();
            ListNode* next_node=pq.top()->next;
            pq.pop();
            if(next_node!=NULL)pq.push(next_node);
            temp=temp->next;
        }
        return dummy_node->next;
    }
};
