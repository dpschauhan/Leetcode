/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//  approach 2 hashmap
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> hm;
        while(head!=NULL){
            hm[head]++;
            if(hm[head]==2)return 1;
            head=head->next;
        }
        return 0;
    }
};
//  approach 1 Slow and fast pointer
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        auto slow=head;
        auto fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)return 1;
        }
        return 0;
    }
};


class Solution3 {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while (head!=nullptr) //until head is null
        {
            if (set.count(head)==0) //check for repetition
            {
                set.insert(head); //if not, add reference to set
            }
            else //if repetition is found
            {
                return true;
            }
            head=head->next; //go next node
        }
        //if we can reach here, means that there is no cycle
        return false;
    }
};
