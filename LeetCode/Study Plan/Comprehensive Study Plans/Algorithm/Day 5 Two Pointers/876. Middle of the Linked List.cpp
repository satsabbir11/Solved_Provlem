class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* step1 = head;
        ListNode* step2 = head;
        
        while(step2!=NULL && step2->next!=NULL){
            step1 = step1->next;
            step2 = step2->next->next;
        }
        
        return step1;
    }
};

