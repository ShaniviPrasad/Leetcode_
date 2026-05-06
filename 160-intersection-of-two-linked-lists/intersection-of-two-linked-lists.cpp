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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL){
            lenA++;
            tempA=tempA->next;
        }
        while(tempB!=NULL){
            lenB++;
            tempB=tempB->next;
        }
         tempA = headA;
        tempB = headB;
        int dif = abs(lenA - lenB);
        if(lenA>lenB){
            for(int i=1; i<=dif; i++)
                tempA=tempA->next;
        }
        else {
            for(int i=1; i<=dif; i++)
                tempB=tempB->next;
        }
        
        while(tempA!=tempB){
             tempA=tempA->next;
              tempB=tempB->next;
        }
        return tempA;
    }  
};