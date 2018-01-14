//
// Created by 张威 on 2017/7/4.
//

#include <iostream>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ret = new ListNode(0);
    ListNode* cur = ret;
    int sum = 0;


    while(l1||l2){
        if(l1 != NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        cur->next = new ListNode(sum%10);
        sum=sum/10;
        cur=cur->next;
    }

    if (sum ==1){
        cur->next=new ListNode(1);
    }

        return  ret->next;

    }
};

int main() {
    ListNode *l1= new ListNode(2);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(4);
    ListNode *l2= new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);

    ListNode* l3 = Solution::addTwoNumbers(l1,l2);

    while (l3){
        std::cout << l3->val << std::endl;
        l3=l3->next;
    }
}