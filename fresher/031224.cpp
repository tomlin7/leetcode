class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prefix = dummy;
        map<int, ListNode*> prefixSum;
        int sum = 0;

        while (prefix) {
            sum += prefix->val;
            if (prefixSum.find(sum) != prefixSum.end()) {
                ListNode* start = prefixSum[sum]->next;
                int tempSum = sum + start->val;
                while (start != prefix) {
                    prefixSum.erase(tempSum);
                    start = start->next;
                    tempSum += start->val;
                }
                prefixSum[sum]->next = prefix->next;
            } else {
                prefixSum[sum] = prefix;
            }
            prefix = prefix->next;
        }

        return dummy->next;
    }
};
