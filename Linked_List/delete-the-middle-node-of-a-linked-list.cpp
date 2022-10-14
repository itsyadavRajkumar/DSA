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
    ListNode* deleteMiddle(ListNode* head) {
        // TC: O(N+N) , SC: O(1)
        if(head ==NULL)
        {
            return head;
        }
        if(head->next==NULL)
        {
            delete(head);
            return NULL;
        }
//         ListNode* ptr = head;
//         int c=0;
//         while(ptr!=NULL)
//         {
//             ptr = ptr->next;
//             c++;
//         }
//         ptr = head;
        
//         int half = c/2;
        
//         half--;
//         // cout<<half;
//         while(half--)
//         {
//             ptr=ptr->next;
//         }
        
//         ListNode* temp = ptr->next;
//         // cout<<temp->val;
//         ptr->next = ptr->next->next;
//         delete(temp);
        
//         return head;
        
        // Slow or fast pointer approach
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode *prev = NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete(slow);
        return head;
    }
};
