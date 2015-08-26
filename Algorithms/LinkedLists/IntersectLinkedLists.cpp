/*
 * IntersectLinkedLists.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
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

        if(headA == nullptr or headB == nullptr){
            return nullptr;
        }

        unsigned lengthA = 0;
        unsigned lengthB = 0;

        auto calc_length = [](ListNode* tmp, unsigned & length) -> void{

            while(tmp not_eq nullptr){
                ++length;
                tmp = tmp->next;
            }
        };
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        calc_length(tmpA,lengthA);
        calc_length(tmpB, lengthB);

        unsigned shift_amount(0);
        ListNode* ptr;

        if(lengthA not_eq lengthB){
            if(lengthA < lengthB){
                shift_amount = lengthB - lengthA;
                ptr = headB;
            }
            else{
                shift_amount = lengthA - lengthB;
                ptr = headA;
            }
            for(unsigned i = 0; i < shift_amount; ++i){
                ptr = ptr->next;
            }
             if(lengthA < lengthB){
                 tmpB = ptr;
                 tmpA = headA;
             }
             else{
                 tmpA = ptr;
                 tmpB = headB;
             }
        }


        while(tmpB not_eq nullptr or tmpA not_eq nullptr){
                if(tmpB->val == tmpA->val){
                    return tmpB;
                }
                tmpB = tmpB->next;
                tmpA = tmpA->next;

        }

        return nullptr;
    }
};



