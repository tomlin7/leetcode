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
        long long a=l1->val, b=l2->val, c=0, r=0;
        while(l1->next != NULL){
            a = a*10 + l1->next->val;
            l1->next = l1->next->next;
        }
        while(l2->next != NULL){
            b = b*10 + l2->next->val;
            l2->next = l2->next->next;
        }
        c = a + b;
        
        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;
        for(;c;c/=10){
            curr->next = new ListNode(c%10);
            curr = curr->next;
        }

        if(ans->next == NULL)
            return new ListNode(0);

        return ans->next;
    }
};