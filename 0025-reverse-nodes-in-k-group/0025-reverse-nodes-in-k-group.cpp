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
    pair<ListNode*,ListNode*> reverseList(ListNode* head , int k) {
        auto cnt=head;
        ListNode* p=NULL;
        auto nxt=head;
        while(k!=0){
            cnt=head->next;
            head->next=p;
            p=head;
            head=cnt;
            k--;
        }
        nxt->next=head;
        return make_pair(p,nxt);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto t=head;
        int c=0;
        while(head!=NULL){
            c++;
            head=head->next;
        }
        head=t;
        int d=c/k;
        auto b= reverseList(head,k);
        auto nh=b.second;
        while(d-1!=0){
            auto e= reverseList(nh->next,k);
            nh->next=e.first;
            nh=e.second;
            d--;
        }
        return b.first;
    }
};