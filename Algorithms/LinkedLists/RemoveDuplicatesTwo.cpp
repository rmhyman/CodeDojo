/*
 * RemoveDuplicatesTwo.cpp
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
    ListNode *deleteDuplicates(ListNode *head) {
       if(head == nullptr){
			            return nullptr;
			  }
			  if(head->next == nullptr){
			      return head;
			  }
		        std::vector<int> list;

		        for(ListNode* tmp = head; tmp not_eq nullptr; tmp=tmp->next){
		            list.push_back(tmp->val);
		        }
		        ListNode* final;
		        ListNode* tail;
		        bool is_first(true);

		        auto add_to_list = [&](int& num) -> void{

		              if(is_first){
		            	  final = new ListNode(num);
		            	  final->next = new ListNode(0);
		            	  tail = final->next;
		            	  is_first = false;
		              }
		              else {
		            	  tail->val = num;
		            	  tail->next = new ListNode(num);
		            	  tail = tail->next;
		              }

		        };



		        	 auto is_duplicate = [&](int& num) {return std::count(list.begin(),list.end(),num) > 1;};

		        	 list.erase(std::remove_if(list.begin(),list.end(),is_duplicate),list.end());

		        	 if(list.size() == 0){
		        		 return nullptr;
		        	 }

		        std::for_each(list.begin(),list.end(),add_to_list);
		        for(ListNode* tmp = final;tmp->next!= nullptr; tmp= tmp->next){
		        	if(tmp->next->next == nullptr){
		        		tmp->next = nullptr;
		        		break;
		        	}
		        }
		        return final;
    }
};



