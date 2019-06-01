#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int value;
    struct node* left;
    struct node* right;
}node;

node* createNode(int value) 
{
    node* yeni;
    yeni = malloc(sizeof(node));
    yeni->value = value;
    yeni->left = NULL;
    yeni->right = NULL;
    return yeni;
}

void addNode(int value, node* root) 
{
    if (root) 
    {
        if (root->value < value) 
	{
            if (root->right) 
                addNode(value, root->right);
            else 
	    {
                node* yeni = createNode(value);
                root->right = yeni;
            }
        } 
	else 
	{
            if (root->left) 
                addNode(value, root->left);
            else 
	    {
                node* yeni = createNode(value);
                root->left = yeni;
            }
        }
    } 
    else 
    {
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    }
}

void search(int value, node* root) 
{
    int flag = 1;
    if ( !root) 
    {
        printf("List is empty \n");
    } 
    else 
    {
        node* current = root;
        while ( (current) && (flag) ) 
	{
            if (current->value < value) 
                current = current-> right;
            else if ( current-> value > value)
                current = current->left;
            else if ( current-> value == value) 
	    {
                printf("Element found \n");
                flag = 0;
            }
        }
    }
    if (flag)
        printf("Element is not in the tree \n");
    
}

void preOrder (node* root) 
{
    if (root) 
    {
        printf("%d ", root-> value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node* root) 
{
    if (root) 
    {
        postOrder(root->left);
        printf("%d ", root->value);
        postOrder(root->right);
    }
}

void inOrder(node* root) 
{
    if (root) 
    {
        inOrder(root->left);
        inOrder(root->right);
        printf("%d ", root->value);
    }
}

int main(int argc, char **argv)
{
    node* root = createNode(9);
    
    addNode(5, root);
    addNode(12, root);
    addNode(1, root);
    addNode(10, root);
    addNode(7, root);
    addNode(4, root);
    
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    
    search(4, root);
    search(18, root);
    
	return 0;
}
