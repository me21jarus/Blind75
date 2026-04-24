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
    int len(ListNode* root){
        int n = 0;
        ListNode* curr = root;
        while(curr){
            n++;
            curr = curr->next;
        }
        return n;
    }
    ListNode* rec(ListNode* head, int& n){
        if(head== NULL) return NULL;

        head->next = rec(head->next, n);
        n--;

        if(n==0){
            return head->next;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = len(head);
        //1. using brute force
        // vector<ListNode*> nodes;
        // ListNode* curr = head;

        // while(curr){
        //     nodes.push_back(curr);
        //     curr = curr->next;
        // }
        // int indexEle = N-n;
        // if(indexEle == 0){
        //     return head->next;
        // }
        // nodes[indexEle - 1]->next = nodes[indexEle]->next;
        // return head;


        // 2. using iteration
        // ListNode* curr = head;
        // for(int i=0;i<N-1;i++){
        //     if((i+1) == indexEle){
        //         curr->next = curr->next->next;
        //         break;
        //     }
        //     curr=curr->next;
        // }
        // return head;

        // 3. using 2 pointer

        // ListNode* dummy = new ListNode(0,head);
        // ListNode* left = dummy;
        // ListNode* right = head;

        // while(n>0){
        //     right = right->next;
        //     n--;
        // }

        // while(right!=NULL){
        //     right = right->next;
        //     left = left->next;
        // }

        // left->next = left->next->next;
        // return dummy->next;

        return rec(head,n);
    }
};