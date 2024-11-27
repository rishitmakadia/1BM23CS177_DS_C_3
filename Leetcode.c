#include <stdio.h>
#include <stdlib.h>


// Implementation of Queue using Stack (16/10/24)
// #define MAX 2  
// typedef struct 
// {
//     int s1[MAX];  
//     int s2[MAX];  
//     int top1;         
//     int top2;         
// } MyQueue;

// MyQueue myQueueCreate() {
//     MyQueue queue;
//     queue.top1 = -1;  
//     queue.top2 = -1;
//     return queue;
// }

// // Push in s1
// void myQueuePush(MyQueue* obj, int x) {
//     if ((*obj).top1 == MAX - 1) {
//         printf("Queue is full\n");
//         // return;
//     }
//     else
//         (*obj).s1[++((*obj).top1)] = x;  
// }

// int myQueuePop(MyQueue* obj) 
// {
//     int val;
//     // s1 to s2
//     if ((*obj).top2 == -1) 
//     {
//         while ((*obj).top1 != -1) 
//         {
//             (*obj).s2[++((*obj).top2)] = (*obj).s1[((*obj).top1)--];
//         }
//         (*obj).top1 = -1;
//     }

//     // Pop and S2 to back to s1
//     if ((*obj).top2 == -1) 
//     {
//         printf("Queue is empty\n");
//         return -1;
//     }
//     else
//     {
//         val = (*obj).s2[((*obj).top2)--];
//         while ((*obj).top2 != -1)
//         {
//             (*obj).s1[++((*obj).top1)] = (*obj).s2[((*obj).top2)--];
//         }
//         (*obj).top2 = -1;
//     }
//     return val;
// }

// // Displaying Queue
// void myQueuePeek(MyQueue* obj) 
// {
//     int i = (*obj).top1;
//     if ((*obj).top2 == -1)
//     {
//         while ((*obj).top1 != -1) 
//         {
//             (*obj).s2[++((*obj).top2)] = (*obj).s1[((*obj).top1)--];
//         }
//         (*obj).top1 = i;
//     }

//     if ((*obj).top2 == -1) 
//     {
//         printf("Queue is empty\n");
//     }
//     else
//     {
//         printf("Queue =  ");
//         while ((*obj).top2 != -1)
//         {
//             printf("%d\t", (*obj).s2[(*obj).top2--]);
//         }
//         (*obj).top2 = -1;
//     }
// }

// // int myQueueEmpty(MyQueue* obj) 
// // {
// //     printf("Queue is empty now");
// //     return ((*obj).top1 == -1 && (*obj).top2 == -1);
// // }

// // void myQueueFree(MyQueue* obj) {
// //     // No memory to free since we are not using dynamic allocation
// // }

// int main() {
//     MyQueue obj = myQueueCreate();   //Imp
//     int opt, in;
//     while (1)
//     {
//         printf("\n1=Push\t2=Pop\t3=Display\t4=Exit");
//         printf("\nSelect Option: ");
//         scanf("%d", &opt);
//         switch(opt)
//         {
//             case 1:
//             {
//                 printf("Enter Push Element: ");
//                 scanf("%d", &in);
//                 myQueuePush(&obj, in);  
//                 break;
//             }
//             case 2:
//             {
//                 myQueuePop(&obj);
//                 break;
//             }
//             case 3:
//             {
//                 myQueuePeek(&obj);
//                 break;
//             }
//             case 4:
//             {
//                 printf("Program Exited");
//                 return 0;
//             }
//             default:
//                 printf("Invalid Operations");
//         }
//     }
//     return 0;
// }


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