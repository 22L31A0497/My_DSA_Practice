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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int n=0;
        while(temp != nullptr){
            temp = temp->next;
            n++;
        }
        int ans=0;
        int power=n-1;
        temp = head;
        while(temp != nullptr){
            if(temp->val==1){
                ans+=(pow(2,power));
            }
            power--;
            temp= temp->next;

        }
        return ans;
        
    }
};