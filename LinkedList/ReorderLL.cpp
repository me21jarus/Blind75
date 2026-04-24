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
    void reorderList(ListNode* head) {
        // 1.using vector extra space
        // vector<ListNode*> nodes;

        // ListNode* curr = head;

        // while(curr){
        //     nodes.push_back(curr);
        //     curr=curr->next;
        // }
        // int n = nodes.size();
        // int i=0,j=n-1;

        // while(i<j){
        //     nodes[i++]->next = nodes[j];
        //     if(i>=j) break;
        //     nodes[j--]->next = nodes[i];
        // }
        // nodes[i]->next = NULL;

        // 2.using pointers
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = NULL;

        while(second){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        ListNode* first = head;
        second = prev;

        while(second){
            ListNode* fnext = first->next;
            ListNode* snext = second->next;

            first->next = second;
            second->next = fnext;
            first = fnext;
            second = snext;
        }

    }
};