#include <iostream>
#include <vector>

struct node{
    int key;
    node *left,*right;
};

node* createNode(int value){
    node* newNode = new node;
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node* successor(node* root){
    if(root->right == NULL){
        return root;
    }else{
        return successor(root->right);
    }
}

node* insertNode(node* root,int value){
    if(root == NULL){
        root = createNode(value);
    }else if(root->key > value){
        root->left = insertNode(root->left,value);
    }else{
        root->right = insertNode(root->right,value);
    }
    return root;
}

node* deleteNode(node* root, int value){
    if(root == NULL){
        return root;
    }
    if(root->key > value){
        root->left = deleteNode(root->left,value);
    }else if(root->key < value){
        root->right = deleteNode(root->right,value);
    }else{
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = successor(root->left);
        root->key = temp->key;
        root->left = deleteNode(root->left,temp->key);
    }
    return root;
}

bool search(node* root, int value){
    if(root != NULL){
        if(root->key == value){
            return true;
        }
        if(root->key > value){
            return search(root->left,value);
        }else{
            return search(root->right,value);
        }
    }
    return false;
}

int findMin(node* root){
    if(root->left == NULL){
        return root->key;
    }else{
        return findMin(root->left);
    }
}

int findMax(node* root){
    if(root->right == NULL){
        return root->key;
    }else{
        return findMax(root->right);
    }
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        std::cout<<root->key<<"->";
        inorder(root->right);
    }   
}

int main(){
    struct node *root = NULL;
    root = insertNode(root,43);
    insertNode(root,20);
    insertNode(root,64);
    insertNode(root,10);
    insertNode(root,61);
    insertNode(root,74);
    insertNode(root,51);
    insertNode(root,62);
    inorder(root);

    std::cout<<std::endl;

    deleteNode(root,64);
    inorder(root);
    return 0;
}