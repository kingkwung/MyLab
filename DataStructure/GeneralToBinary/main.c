/*
 This program is reads information about general tree and constructs a binary tree, using the leftmost-child-right-silbings representation.
 
 Left most child is my left child, sibling node of that node will be right node of that node.
 
 2014/03/28, Made by 우영남
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node node;
struct node{
    int level;
    int key;
    int child_key;
    
    node* left;
    node* right;
};

node* root = NULL; // Root node pointer
void insertNode(node* parent, int level, int key, int child_key); // function declaration of 'insertNode'
void preorder_trav(node* parent);//function declaration of 'preorder_trav'

int main(void)
{
    int level=0; // save the level of node
    int key=0; // save the key of node
    char child_key[10]; // save the child key of node
    int int_child_key=0; // save the child key of node (integer type)
    
    int i=0;
    int count=0;
    
    
    printf("Enter the number of node : ");
    scanf("%d", &count);
    printf("\n");
    
    for(i=0; i<count; i++){
        printf("Enter the LEVEL KEY CHILD_KEY : ");
        scanf("%d %d %s",&level, &key, child_key);
        
        //case of child_key is NULL
        if(strcmp(child_key,"NULL")==0 || strcmp(child_key,"null")==0 || strcmp(child_key,"Null")==0 ){
            int_child_key=NULL;
        }
        else{
            int_child_key = atoi(child_key);
        }
        
        //call insertNode funtion
        insertNode(root, level, key, int_child_key);
    }
    
    printf("\n[Preorder traversal]\n");
    preorder_trav(root);
}

/*
 It is insertNode function.
 
 Simple expression.
 
 if(visited node's level == my level)
    if (right node is null)
       right child of visited node <- my node, return
    else if right node is not null
       visit the right node
 
 else if(visited node's level != my level)
    if (child key of visited node == my key)
       left child of visited node <- my node, return
    else if child key of visited node != my key
       if left node of visited node is not null
          visit the left node
       else if left node of visited node is null
          visit the right node
 
 DA
 Input : root node pointer, level of node, key of node, child key of node
 Output : none
 */
void insertNode(node* parent, int level, int key, int child_key){
    if(parent==NULL){
        node* newNode = (node*)malloc(sizeof(node));
        
        newNode->left = NULL;
        newNode->right = NULL;
        
        newNode->level = level;
        newNode->key = key;
        newNode->child_key = child_key;
        
        root = newNode;
        return;
    }
    
    node* current = root;
    
    node* newNode = (node*)malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->level = level;
    newNode->key = key;
    newNode->child_key = child_key;
    
    while(current){
        if(current->level==newNode->level){
            if(current->right==NULL){
                current->right = newNode;
                return;
            }
            else{
                current=current->right;
            }
        }
        else{
            if(current->child_key==newNode->key){
                current->left = newNode;
                return;
            }
            else{
                if(current->left!=NULL){
                    current=current->left;
                }
                else{
                    current=current->right;
                }
            }
        }
    }
}

/*
 It is preorder_trav function.
 Print the key using preorder traveling.
 
 Input : root node pointer
 Output : none
 */
void preorder_trav(node* parent) {
    if(parent != NULL) {
        printf("%d\n",parent->key);
        preorder_trav(parent->left);
        preorder_trav(parent->right);
    }
}
