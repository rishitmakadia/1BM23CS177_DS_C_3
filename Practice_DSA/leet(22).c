
// Valid Parentheses
// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>

// #define MAX 100 // Maximum size of the stack

// // Function to check if a string of parentheses is valid
// bool isValid(char str[])
// {
//     char stack[MAX]; // Stack to store opening parentheses
//     int top = -1;    // Stack top pointer

//     for (int i = 0; i < strlen(str); i++)
//     {
//         char ch = str[i];

//         // If it's an opening parenthesis, push it to the stack
//         if (ch == '(' || ch == '{' || ch == '[')
//         {
//             push(stack, &top, ch);
//         }
//         // If it's a closing parenthesis, check for matching pair
//         else if (ch == ')' || ch == '}' || ch == ']')
//         {
//             // If stack is empty or the top doesn't match, it's invalid
//             if (top == -1 || !isMatchingPair(pop(stack, &top), ch))
//             {
//                 return false;
//             }
//         }
//     }
//     // If stack is empty, it's a valid string, otherwise invalid
//     return (top == -1);
// }

// Function to push an element to the stack
// void push(char stack[], int *top, char ch)
// {
//     if (*top < MAX - 1)
//     {
//         (*top)++;
//         stack[*top] = ch;
//     }
// }

// // Function to pop an element from the stack
// char pop(char stack[], int *top)
// {
//     if (*top >= 0)
//     {
//         return stack[(*top)--];
//     }
//     return '\0'; // Return null character if stack is empty
// }

// // Function to check if a pair of parentheses match
// bool isMatchingPair(char open, char close)
// {
//     if (open == '(' && close == ')')
//         return true;
//     if (open == '{' && close == '}')
//         return true;
//     if (open == '[' && close == ']')
//         return true;
//     return false;
// }

// int main()
// {
//     char str[MAX];

//     printf("Enter the string of parentheses: ");
//     scanf("%s", str);

//     if (isValid(str))
//     {
//         printf("The string is valid.\n");
//     }
//     else
//     {
//         printf("The string is invalid.\n");
//     }

//     return 0;
// }



// Minimum Time to Revert Word to Initial State I
// #include <stdio.h>
// #include <string.h>

// #define MAX_SIZE 100

// // Function to calculate minimum time to revert word to its initial state
// int minTimeToRevert(char *word, char operations[][MAX_SIZE], int operationCount, int time[])
// {
//     int stack[MAX_SIZE]; // Stack to track the state of the word
//     int top = -1;        // Initialize stack pointer
//     int totalTime = 0;

//     // Process each operation
//     for (int i = 0; i < operationCount; i++)
//     {
//         if (strcmp(operations[i], "REVERT") == 0)
//         {
//             // If the operation is REVERT, pop from stack
//             if (top >= 0)
//             {
//                 top--;
//                 totalTime += time[i]; // Add the time for revert operation
//             }
//             else
//             {
//                 printf("Cannot revert, no previous state available.\n");
//             }
//         }
//         else
//         {
//             // Otherwise, push the operation onto the stack
//             if (top < MAX_SIZE - 1)
//             {
//                 stack[++top] = i;     // Push the index of the operation
//                 totalTime += time[i]; // Add the time for this operation
//             }
//             else
//             {
//                 printf("Stack overflow! Cannot perform operation: %s\n", operations[i]);
//             }
//         }
//     }
//     return totalTime;
// }

// int main()
// {
//     char word[MAX_SIZE];
//     int operationCount;

//     // Input the word
//     printf("Enter the word: ");
//     scanf("%s", word);

//     // Input number of operations
//     printf("Enter the number of operations: ");
//     scanf("%d", &operationCount);

//     char operations[MAX_SIZE][MAX_SIZE]; // Array to hold operation names
//     int time[MAX_SIZE];                  // Array to hold operation times

//     // Input the operations and their corresponding times
//     for (int i = 0; i < operationCount; i++)
//     {
//         printf("Enter operation %d (e.g., REVERT or some other operation): ", i + 1);
//         scanf("%s", operations[i]);
//         printf("Enter time for operation %d: ", i + 1);
//         scanf("%d", &time[i]);
//     }

//     // Calculate minimum time to revert
//     int result = minTimeToRevert(word, operations, operationCount, time);
//     printf("Total time to revert the word to its initial state: %d\n", result);

//     return 0;
// }



// 19/11/24
// 328. Odd Even Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* oddEvenList(struct ListNode* head) {
//     if (head == NULL || head->next == NULL) {
//         // If there are 0 or 1 nodes, no reordering is needed.
//         return head;
//     }

//     // Pointers to odd and even nodes
//     struct ListNode *odd = head;
//     struct ListNode *even = head->next;
//     struct ListNode *evenHead = even; // Save the head of the even list

//     while (even != NULL && even->next != NULL) {
//         odd->next = even->next; // Link odd nodes together
//         odd = odd->next;        // Move odd pointer forward
//         even->next = odd->next; // Link even nodes together
//         even = even->next;      // Move even pointer forward
//     }

//     // Attach the even list to the end of the odd list
//     odd->next = evenHead;

//     return head;
// }


// 234. Palindrome Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// bool isPalindrome(struct ListNode* head) {
//     if (head == NULL || head->next == NULL) {
//         return true; // Empty list or single element list is a palindrome
//     }

//     // Step 1: Find the middle of the list using slow and fast pointers
//     struct ListNode *slow = head, *fast = head;
    
//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // Step 2: Reverse the second half of the list
//     struct ListNode *prev = NULL, *current = slow, *next = NULL;
    
//     while (current != NULL) {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }

//     // Step 3: Compare the two halves
//     struct ListNode *firstHalf = head, *secondHalf = prev;
    
//     while (secondHalf != NULL) {
//         if (firstHalf->val != secondHalf->val) {
//             return false; // Not a palindrome
//         }
//         firstHalf = firstHalf->next;
//         secondHalf = secondHalf->next;
//     }

//     return true; // It's a palindrome
// }


// 1721. Swapping Nodes in a Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* swapNodes(struct ListNode* head, int k) {
//     if (head == NULL || head->next == NULL) {
//         return head; // If the list has only one node, return the head
//     }

//     // Step 1: Find the length of the list
//     struct ListNode *temp = head;
//     int length = 0;
    
//     while (temp != NULL) {
//         length++;
//         temp = temp->next;
//     }

//     // Step 2: Find the k-th node from the beginning
//     struct ListNode *first = head;
//     for (int i = 1; i < k; i++) {
//         first = first->next;
//     }

//     // Step 3: Find the k-th node from the end
//     struct ListNode *second = head;
//     for (int i = 1; i < length - k + 1; i++) {
//         second = second->next;
//     }

//     // Step 4: Swap the values of the k-th node from the beginning and the k-th node from the end
//     int tempVal = first->val;
//     first->val = second->val;
//     second->val = tempVal;

//     return head;
// }

// 700. Search in a Binary Search
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// struct TreeNode* searchBST(struct TreeNode* root, int val) {
//     if (root == NULL || root->val == val) {
//         return root; // Return the node if found or NULL if not found
//     }
//     if (val < root->val) {
//         return searchBST(root->left, val); // Search in the left subtree
//     } else {
//         return searchBST(root->right, val); // Search in the right subtree
//     }
// }

// 226. Invert Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// struct TreeNode* invertTree(struct TreeNode* root) {
//     if (root == NULL) {
//         return NULL; // Base case: If the tree is empty, return NULL
//     }

//     // Swap the left and right children
//     struct TreeNode* temp = root->left;
//     root->left = root->right;
//     root->right = temp;

//     // Recursively invert the left and right subtrees
//     invertTree(root->left);
//     invertTree(root->right);

//     return root; // Return the root of the inverted tree
// }

// 993. Cousins in Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// void dfs(struct TreeNode* node, int target, int parent, int depth, int* foundParent, int* foundDepth) {
//     if (node == NULL) {
//         return;
//     }
//     if (node->val == target) {
//         *foundParent = parent;
//         *foundDepth = depth;
//         return;
//     }
//     dfs(node->left, target, node->val, depth + 1, foundParent, foundDepth);
//     dfs(node->right, target, node->val, depth + 1, foundParent, foundDepth);
// }

// bool isCousins(struct TreeNode* root, int x, int y) {
//     if (root == NULL) {
//         return false;
//     }

//     int xParent = -1, xDepth = -1;
//     int yParent = -1, yDepth = -1;

//     // Perform DFS to find parent and depth for x and y
//     dfs(root, x, -1, 0, &xParent, &xDepth);
//     dfs(root, y, -1, 0, &yParent, &yDepth);

//     // Two nodes are cousins if they have the same depth but different parents
//     return (xDepth == yDepth && xParent != yParent);
// }

// Design Front Middle Back Queue

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100 // Maximum size of the queue

// // Initialize the queue
// void initializeQueue(int *left_half, int *right_half, int *left_size, int *right_size)
// {
//     *left_size = 0;
//     *right_size = 0;
// }

// // Insert at the front
// void insertFront(int *left_half, int *right_half, int *left_size, int *right_size, int value)
// {
//     // Shift all elements in left_half to the right
//     for (int i = *left_size; i > 0; i--)
//     {
//         left_half[i] = left_half[i - 1];
//     }
//     left_half[0] = value; // Insert at the front
//     (*left_size)++;

//     // Balance the halves if needed
//     if (*left_size > *right_size + 1)
//     {
//         right_half[*right_size] = left_half[*left_size - 1];
//         (*right_size)++;
//         (*left_size)--;
//     }
// }

// // Insert at the middle
// void insertMiddle(int *left_half, int *right_half, int *left_size, int *right_size, int value)
// {
//     if (*left_size > *right_size)
//     {
//         // Insert at the end of left_half
//         left_half[*left_size] = value;
//         (*left_size)++;
//     }
//     else
//     {
//         // Shift all elements in right_half to the right and insert at the front
//         for (int i = *right_size; i > 0; i--)
//         {
//             right_half[i] = right_half[i - 1];
//         }
//         right_half[0] = value;
//         (*right_size)++;
//     }
// }

// // Insert at the back
// void insertBack(int *left_half, int *right_half, int *left_size, int *right_size, int value)
// {
//     right_half[*right_size] = value; // Insert at the back of right_half
//     (*right_size)++;

//     // Balance the halves if needed
//     if (*right_size > *left_size)
//     {
//         left_half[*left_size] = right_half[0];
//         (*left_size)++;
//         // Shift right_half to the left
//         for (int i = 0; i < *right_size - 1; i++)
//         {
//             right_half[i] = right_half[i + 1];
//         }
//         (*right_size)--;
//     }
// }

// // Delete from the front
// int deleteFront(int *left_half, int *right_half, int *left_size, int *right_size)
// {
//     if (*left_size == 0 && *right_size == 0)
//     {
//         printf("Queue is empty!\n");
//         return -1;
//     }

//     int value = left_half[0]; // Value to delete

//     // Shift left_half to the left
//     for (int i = 0; i < *left_size - 1; i++)
//     {
//         left_half[i] = left_half[i + 1];
//     }
//     (*left_size)--;

//     // Balance the halves if needed
//     if (*left_size < *right_size)
//     {
//         for (int i = *left_size; i > 0; i--)
//         {
//             left_half[i] = left_half[i - 1];
//         }
//         left_half[0] = right_half[0];
//         // Shift right_half to the left
//         for (int i = 0; i < *right_size - 1; i++)
//         {
//             right_half[i] = right_half[i + 1];
//         }
//         (*left_size)++;
//         (*right_size)--;
//     }

//     return value;
// }

// // Delete from the middle
// int deleteMiddle(int *left_half, int *right_half, int *left_size, int *right_size)
// {
//     if (*left_size == 0 && *right_size == 0)
//     {
//         printf("Queue is empty!\n");
//         return -1;
//     }

//     int value;
//     if (*left_size > *right_size)
//     {
//         value = left_half[*left_size - 1]; // Middle is at the end of left_half
//         (*left_size)--;
//     }
//     else
//     {
//         value = right_half[0]; // Middle is at the start of right_half
//         // Shift right_half to the left
//         for (int i = 0; i < *right_size - 1; i++)
//         {
//             right_half[i] = right_half[i + 1];
//         }
//         (*right_size)--;
//     }

//     return value;
// }

// // Delete from the back
// int deleteBack(int *left_half, int *right_half, int *left_size, int *right_size)
// {
//     if (*left_size == 0 && *right_size == 0)
//     {
//         printf("Queue is empty!\n");
//         return -1;
//     }

//     int value;
//     if (*right_size > 0)
//     {
//         value = right_half[*right_size - 1]; // Back element in right_half
//         (*right_size)--;
//     }
//     else
//     {
//         value = left_half[*left_size - 1]; // Back element in left_half
//         (*left_size)--;
//     }

//     return value;
// }

// // Display the queue
// void displayQueue(int *left_half, int *right_half, int left_size, int right_size)
// {
//     if (left_size == 0 && right_size == 0)
//     {
//         printf("Queue is empty!\n");
//         return;
//     }

//     printf("Queue elements: ");
//     for (int i = 0; i < left_size; i++)
//     {
//         printf("%d ", left_half[i]);
//     }
//     for (int i = 0; i < right_size; i++)
//     {
//         printf("%d ", right_half[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int left_half[MAX_SIZE], right_half[MAX_SIZE]; // Fixed-size arrays
//     int left_size = 0, right_size = 0;             // Size trackers for both halves
//     int choice, value;

//     initializeQueue(left_half, right_half, &left_size, &right_size);

//     while (1)
//     {
//         printf("\n--- Front Middle Back Queue Menu ---\n");
//         printf("1. Insert at Front\n");
//         printf("2. Insert at Middle\n");
//         printf("3. Insert at Back\n");
//         printf("4. Delete from Front\n");
//         printf("5. Delete from Middle\n");
//         printf("6. Delete from Back\n");
//         printf("7. Display Queue\n");
//         printf("8. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter value to insert at Front: ");
//             scanf("%d", &value);
//             insertFront(left_half, right_half, &left_size, &right_size, value);
//             break;
//         case 2:
//             printf("Enter value to insert at Middle: ");
//             scanf("%d", &value);
//             insertMiddle(left_half, right_half, &left_size, &right_size, value);
//             break;
//         case 3:
//             printf("Enter value to insert at Back: ");
//             scanf("%d", &value);
//             insertBack(left_half, right_half, &left_size, &right_size, value);
//             break;
//         case 4:
//             printf("Deleted from Front: %d\n", deleteFront(left_half, right_half, &left_size, &right_size));
//             break;
//         case 5:
//             printf("Deleted from Middle: %d\n", deleteMiddle(left_half, right_half, &left_size, &right_size));
//             break;
//         case 6:
//             printf("Deleted from Back: %d\n", deleteBack(left_half, right_half, &left_size, &right_size));
//             break;
//         case 7:
//             displayQueue(left_half, right_half, left_size, right_size);
//             break;
//         case 8:
//             printf("Exiting...\n");
//             return 0;
//         default:
//             printf("Invalid choice!\n");
//         }
//     }

//     return 0;
// }
