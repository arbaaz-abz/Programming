/*
Given Preorder Traversal . Convert it to Inorder Traversal
o(n^2) Traversal
*/
#include <stdio.h> 
#include <stdlib.h> 
  
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
// Create a node 
struct node* newNode (int data) 
{ 
    struct node* temp = (struct node *) malloc( sizeof(struct node) ); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
// A recursive function to construct Full from pre[]. preIndex is used 
// to keep track of index in pre[]. 
struct node* constructTreeUtil (int pre[], int* preIndex, 
                                int low, int high, int size) 
{ 
    // Base case 
    if (*preIndex >= size || low > high) 
        return NULL; 
  
    // The first node in preorder traversal is root. So take the node at 
    // preIndex from pre[] and make it root, and increment preIndex 
    struct node* root = newNode ( pre[*preIndex] ); 
    *preIndex = *preIndex + 1; 
  
    // If the current subarry has only one element, no need to recur 
    if (low == high) 
        return root; 
  
    // Search for the first element greater than root 
    int i; 
    for ( i = low; i <= high; ++i ) 
        if ( pre[ i ] > root->data ) 
            break; 
  
    // Use the index of element found in preorder to divide preorder array in 
    // two parts. Left subtree and right subtree 
    root->left = constructTreeUtil ( pre, preIndex, *preIndex, i - 1, size ); 
    root->right = constructTreeUtil ( pre, preIndex, i, high, size ); 
  
    return root; 
} 
  
//print inorder traversal of a Binary Tree 
void printInorder (struct node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    printf("%d ", node->data); 
    printInorder(node->right); 
} 
  
// DRIVER
int main () 
{ 
    int pre[] = {10, 5, 1, 7, 40, 50}; 
    int size = sizeof( pre ) / sizeof( pre[0] ); 
    
    int preIndex = 0; 
    struct node *root = constructTreeUtil(pre,&preIndex,0,size - 1,size); 
  
    printf("Inorder traversal of the constructed tree: \n"); 
    printInorder(root); 
  
    return 0; 
} 