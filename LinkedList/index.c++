// 141. Linked List Cycle
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};

// 876. Middle of the Linked List
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL &&  fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr=head;
        ListNode* nxt=curr->next;
        while(nxt!=NULL){
            if(curr->val==nxt->val){
                curr->next=nxt->next;
                nxt=nxt->next;
            }else{
                curr=nxt;
                nxt=nxt->next;
            }
        }
        return head;
    }
};



// 21. Merge Two Sorted Lists
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
         ListNode* newhead=NULL;
         ListNode* newtail=NULL;
        if(list1->val<list2->val){
            newhead=list1;
            newtail=list1;
            list1=list1->next;
        }else{
            newhead=list2;
            newtail=list2;
            list2=list2->next;
        }
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
               newtail->next=list1;
               newtail=newtail->next;
               list1=list1->next;
            }else{
               newtail->next=list2;
               newtail=newtail->next;
               list2=list2->next;
            }
        }
        if(list1!=NULL){
            newtail->next=list1;
        }
        else if(list2!=NULL){//mistake make here not earlier wright while(list2!=NULL)
            newtail->next=list2;
        }
        return newhead;
    }
};