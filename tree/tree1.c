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

node* find(bst *tree, int data) {
    node *result = NULL;
    node* temp = tree->root;
    if(tree->root) {
        while(1) {
            if(temp) {
                if(data < temp->data) {
                    temp = temp->left;    
                } else if(data > temp->data) {
                    temp = temp->right;
                } else {
                    result = temp;
                    break;
                }
            } else {
                break;
            }
        }
    } else {
        printf("Tree is empty!\n");
    }
    return result;
}

node* find_parent(bst *tree, int data) {
    node *result = NULL;
    node *pnode = NULL;
    node* temp = tree->root;
    if(tree->root) {
        if(data == tree->root->data) {
            return NULL;
        }
        while(1) {
            if(temp) {
                if(data < temp->data) {
                    pnode = temp;
                    temp = temp->left;    
                } else if(data > temp->data) {
                    pnode = temp;
                    temp = temp->right;
                } else {
                    result = temp;
                    break;
                }
            } else {
                break;
            }
        }
    } else {
        printf("Tree is empty!\n");
    }
    return pnode;
}

node* find_max(node* root) {
    node *temp = root;
    while(temp->right) {
        temp = temp->right;
    }
    return temp;
}

node* find_min(node* root) {
    node *temp = root;
    while(temp->left) {
        temp = temp->left;
    }
    return temp;
}

bst* delete(bst* tree,  int data) {
    node *dnode = find(tree, data);
    node *pnode = find_parent(tree, data);
    if(dnode && pnode) {
        if(dnode->left && dnode->right) {
            node *rnode = find_min(dnode);
            printf("rnofre is : %d\n", rnode->data);
            if(pnode->left == dnode) {
                pnode->left = rnode;
                rnode->left = dnode->left;
                rnode->right = dnode->right;
                free(dnode);
            } else {
                pnode->right = rnode;
                rnode->left = dnode->left;
                rnode->right = dnode->right;
                free(dnode);
            }
        } else if(!dnode->left && !dnode->right) {
            free(dnode);
        } else if(dnode->left && !dnode->right) {
            if(pnode->left == dnode) {
                pnode->left = dnode->left;
                free(dnode);
            } else {
                pnode->right = dnode->left;
                free(dnode);
            }
        } else if(dnode->right && !dnode->left) {
            if(pnode->left == dnode) {
                pnode->left = dnode->right;
                free(dnode);
            } else {
                pnode->right = dnode->right;
                free(dnode);
            }
        }
    } else {
        printf("Node or pnode is not present in tree or tree in empty!\n");
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
    tree = insert(tree, 60);

    inorder(tree->root);
    printf("\n");
    preorder(tree->root);
    printf("\n");
    postorder(tree->root);
    printf("\n");
    printf("Finding node having data 00:\n");
    if(find(tree, 0)){
        printf("Found!\n");
    } else {
        printf("Not Found!\n");
    }

    printf("Finding node having data 10:\n");
    if(find(tree, 10)){
        printf("Found!\n");
    } else {
        printf("Not Found!\n");
    }

    printf("Max element from the tree:%d\n", find_max(tree->root)->data);
    printf("Min element from the tree:%d\n", find_min(tree->root)->data);

    printf("The parent node of 50 is : %d\n", find_parent(tree, 50)->data);

    tree = delete(tree, 50);
    printf("Inorder after delete :\n");
    //inorder(tree->root);
    printf("\n");
    return 0;
}