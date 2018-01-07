//
//  main.cpp
//  LeetCode148_SortList
//
//  Created by Rui on 1/5/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
        
        
    }
    
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        if(l1)
            cur->next = l1;
        if(l2)
            cur->next = l2;
        
        return dummy->next;
    }
};
