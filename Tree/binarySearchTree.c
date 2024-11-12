// Implementation of Binary Search Tree
/*
Name : Sumeet Sambhaji Bhosale
Roll No : 2021
Class : SY - A
Batch : S2
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node  // Structure definition for binary search tree node
{
    int val; // value stored in the node
    struct Node* left; // pointer pointing to left node
    struct Node* right; // pointer poining to right node
} TreeNode;

// Function to free the memory allocated to the tree
void freeTree(TreeNode* root)   
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


// prints the elements in the tree (inorder mode)
void inorder(TreeNode* root)
{
    if (!root) return; // if it is null, it simply returns
    inorder(root->left);  // then recurively calls itself
    printf("%d ", root->val);
    inorder(root->right);
}
// prints the elements in the tree (preorder mode)
void preorder(TreeNode* root)
{
    if (!root) return;
    printf("%d ", root->val);
    inorder(root->left);
    inorder(root->right);
}
// prints the elements in the tree (postorder mode)
void postorder(TreeNode* root)
{
    if (!root) return;
    inorder(root->left);
    inorder(root->right);
    printf("%d ", root->val);
}

// This function gives the user the option to choose between inorder, preorder and postorder
void printTree(TreeNode* root)
{
    if (!root) 
    {
        printf("Tree is empty!");
        return;
    }
    int c;
    printf("Choose the way to print the tree:\n");
    printf("1. Inorder\n");
    printf("2. Preorder\n");
    printf("3. Postorder\n");
    printf("Choose : ");
    scanf("%d", &c);
    printf("Elements in the Tree : ");
    switch (c)
    {
        case 1 : inorder(root); break;
        case 2 : preorder(root); break;
        case 3 : postorder(root); break;
        default : printf("Invalid choice \n");
    }
}

// This Function allocates memory for a node and returns the node
TreeNode* createNode(int data)
{
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// This function creates the node based on their values (Binary Search Tree)
void create(TreeNode** root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    else if (data  < (*root)->val)
    {
        create(&((*root)->left), data);
    }
    else 
    {
        create(&((*root)->right), data);
    }
}

// Function to search the element in the tree
bool Search(TreeNode* root, int data)
{
    if (!root) 
    {
        return false;
    }
    if (root->val == data)  // if the value is equal it returns true
    {
        return true;
    }
    else if (root->val > data)   
    {
        return Search(root->left, data); // Recursively calls the function for left node
    }
    else
    {
        return Search(root->right, data); // Recursively calls the function for right node
    }
}

int main()
{
    TreeNode* root = NULL;
    int ch;
    do
    {
        printf("\nMenu :\n");   // Gives option to the user 
        printf("1. Create\n2. Traverse\n3. Search\n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                printf("Enter data : ");
                int data;
                scanf("%d", &data);
                create(&root, data);
                break;
            case 2 : printTree(root); break;
            case 3 :
                printf("Enter the data you want to search : ");
                int key;
                scanf("%d", &key);
                if (Search(root, key))
                {
                    printf("%d is present in the Tree!\n", key);
                }
                else 
                {
                    printf("%d is not present in the Tree!\n", key);
                }
                break;
            case 4 :
                printf("Quiting...!!");
                break;
            default :  printf("Invalid choice!\n");
        }
    }while(ch != 4);
    freeTree(root); // Deallocates all the memory allocated for the tree
    return 0;
}