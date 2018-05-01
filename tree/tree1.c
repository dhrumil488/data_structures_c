#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct bst {
    node *root;
} bst;


node* create_node(int data) {
    node* newnode = (node *) malloc(sizeof(node));
    if(newnode) {
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    return newnode;
}

bst* create_tree() {
    bst* newtree = (bst *) malloc(sizeof(bst));
    if(newtree) {
        newtree->root = NULL;
    }
    return newtree;
}

bst* insert(bst *tree, int data) {
    node* newnode = create_node(data);
    //node has been created or not
    if(newnode) {
        //tree is empty or not
        if(tree->root) {
            node* temp = tree->root;
            while(1) {

                if(data < temp->data) {
                    if(temp->left) {
                         temp = temp->left;
                    } else {
                        temp->left = newnode;
                        break;
                    }  
                }  else if(data >= temp->data) {
                    if(temp->right) {
                        temp = temp->right;
                    } else {
                        temp->right = newnode;
                        break;
                    }
                }
            }
        } else {
            tree->root = newnode;
        }

    } else {
        printf("Some error occured on creating a node!\n");
    }
    return tree; 
}

void inorder(node* root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root) {
    if(root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    bst *tree;
    tree = create_tree();
    tree = insert(tree, 30);
    tree = insert(tree, 10);
    tree = insert(tree, 20);
    tree = insert(tree, 50);
    tree = insert(tree, 40);
    inorder(tree->root);
    printf("\n");
    preorder(tree->root);
    printf("\n");
    postorder(tree->root);
    printf("\n");
    return 0;
}