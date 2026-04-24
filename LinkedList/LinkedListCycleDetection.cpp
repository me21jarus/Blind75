/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        //1. using set
        // ListNode* curr = head;
        // unordered_set<ListNode*> mp;
        // while(curr){
        //     if(mp.find(curr)!= mp.end()){
        //         return true;
        //     }
        //     mp.insert(curr);
        //     curr=curr->next;
        // }
        // return false;

        // 2. using fast and slow

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow=slow->next;

            if(fast == slow) return true;
        }
        return false;
    }
};