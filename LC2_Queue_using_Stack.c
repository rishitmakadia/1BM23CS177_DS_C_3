#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int s1[MAX];
    int s2[MAX];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->top1 == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    obj->s1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++(obj->top2)] = obj->s1[(obj->top1)--];
        }
    }
    if (obj->top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return obj->s2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++(obj->top2)] = obj->s1[(obj->top1)--];
        }
    }
    if (obj->top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */




//Valid Parenthesis (23/10/24)
// bool isValid(char* s) {
//     char stack[50000];
//     int top=-1;
//     for (int i=0; i<strlen(s);i++){
//         char ch=s[i];
//         if (ch == '(' || ch == '{' || ch == '['){
//             stack[++top]=ch;
//         }
//         else if (ch == ')' || ch == '}' || ch == ']'){
//             if (top == -1){
//                 return 0;
//             }
//             char val = stack[top];
//             if ((ch == ')' && val == '(') || (ch == '}' && val == '{') || (ch == ']' && val == '[')){
//                 top--;
//             }
//             else{
//                 return 0;
//             }
//         }
//         else{
//             return 0;
//         }
//     }
//     if (top != -1){
//         return 0;
//     }
//     else{
//         top = -1;
//         return 1;
//     }
// }



// Middle element of the Linked List (20/11/24)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* middleNode(struct ListNode* head) {
//     struct ListNode *fast=head, *slow=head;
//     while(fast!=NULL && fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     return slow;
// }



//Search in Binary Search Tree (27/11/24)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// struct TreeNode* searchBST(struct TreeNode* root, int val) {
//     if (root==NULL || root->val == val)
//         return root;
//     if (val < (root->val))
//         return searchBST(root->left, val);
//     else
//         return searchBST(root->right, val);
// }