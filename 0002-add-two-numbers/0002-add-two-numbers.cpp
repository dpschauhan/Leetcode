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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *curr= head;
        ListNode *temp= head;
        int carry = 0;
        int a=0;
        while(l1 != NULL || l2 != NULL) {
            int p = l1 != NULL ? l1->val : 0;
            int q = l2 != NULL ? l2->val : 0;
            int sum = p + q + carry;
            carry= sum/10;
            ListNode *node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;
            l1 = l1 != NULL ? l1->next: NULL;
            l2 = l2 != NULL ? l2->next: NULL;
            a = carry;
        }
        cout<< a;
        curr=head;
        if (a!=0){
            while(curr->next!=NULL){
                curr=curr->next;
            }
            ListNode *node = new ListNode(a);
            curr->next = node;
        }
        return head->next;
    }
};