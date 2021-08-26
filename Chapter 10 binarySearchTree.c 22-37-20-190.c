/*
by GEEE3, August 25, 2021
Binary Search Tree is node-based binary tree which has the following properties:
1. The left subtree of a node contains only nodes with keys lesser than the node
2. The right subtree of a node contains only nodes with keys greater than the node
3. The left and right subtree each must also be a binary search tree
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* root, int key) {
    if(root == NULL)
        return newNode(key);
    if(key < root->key)
        root->left = insert(root->left, key);
    else if(key > root->key)
        root->right = insert(root->right, key);
    return root;
}

struct node* minNode(struct node* node) {
    struct node* current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* delete(struct node* root, int key) {
    if(root == NULL)
        return root;

    if(key < root->key)
        root->left = delete(root->left, key);
    else if(key > root->key)
        root->right = delete(root->right, key);
        
    else {
        if(root->left == NULL) {
            struct node* target = root->right;
            free(root);
            return target;
        }
        else if(root->right == NULL) {
            struct node* target = root->left;
            free(root);
            return target;
        }
        struct node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}

int main(void) {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("[Initialize Tree]\n");
    printf("Inorder Traversal of the Given Tree:\n");
    inorder(root);
    printf("\n\n");

    printf("[Delete 20]\n");
    delete(root, 20);
    printf("Inorder Traversal of the Modified Tree:\n");
    inorder(root);
    printf("\n\n");

    printf("[Insert 10]\n");
    insert(root, 10);
    printf("Inorder Traversal of the Modified Tree:\n");
    inorder(root);
    printf("\n\n");

    printf("[Delete 50]\n");
    delete(root, 50);
    printf("Inorder Traversal of the Modified Tree:\n");
    inorder(root);
    printf("\n");
    return 0;
}