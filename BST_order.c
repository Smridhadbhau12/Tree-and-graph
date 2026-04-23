#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* root,int data){
    if(root==NULL)
        return createNode(data);
    else if(data < root->data)
        root->left = insert(root->left,data);
    else{
            root->right = insert(root->right,data);
        }
    }
void preOrder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
struct Node* search(struct Node* root,int val){
    if(root == NULL|| root->data ==val)
    return root;
    if(val < root->data)
    return search(root->left ,val);
    else
    return search(root->right,val);
}
struct Node* findMin(struct Node* root){
    while(root->left !=NULL){
        root = root->left;
    }
    return root;
}
struct Node* delete(struct Node* root,int val){
    if(root ==NULL)
    return NULL;
    else if(val <root->data)
    root->left = delete(root->left,val);
    else if(val > root->data)
    root->right =delete(root->right,val);
    else{
        if(root->left ==NULL && root->right ==NULL)
        return NULL;
        //One child
        if(root->left == NULL)
        return root->right;
        else if(root->right == NULL)
        return root->left;
        //two child
        else{
            struct Node* temp = fidMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}
int main() {
    int choice, value;
    struct Node* root = NULL;

    while (1) {
        printf("\n***** Binary Tree Menu *****\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                preOrder(root);
                printf("\n");
                break;

            case 3:
                inOrder(root);
                printf("\n");
                break;

            case 4:
                postOrder(root); // fixed function name
                printf("\n");
                break;

            case 5:
            printf("Enter value :");
            scanf("%d",&value);
            if(search(root,value)==NULL)
                printf("Element Not Found!!!\n");
            else{
                printf("Element Found!!!\n");
                break;
            }
            case 6:
                printf("Enter Element to delete: ");
                scanf("%d",&value);
                delete(root,value);
                break;
            case 7:
                exit(0);
                default:
                printf("Invalid Choice\n");
        }
    }
}
