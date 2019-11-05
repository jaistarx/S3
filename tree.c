#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int data;
    struct node *ll,*rl;
};
node * getnew(int data){
    node *newnode=malloc(1 * sizeof(struct node));
    newnode->data=data;
    newnode->ll=newnode->rl=NULL;
    return newnode;
}
node * insert(node *root,int data){
    if(root==NULL){
        root=getnew(data);
    }
    else if (data<=root->data){
        root->ll=insert(root->ll,data);
    }
    else{
        root->rl=insert(root->rl,data);
    }
    return root;
}
int search(node * root,int data){
    if(root==NULL)
        return 0;
    else if(root->data== data)
        return 1;
    else if (root->data>=data)
        return search(root->ll,data);
    else
        return search(root->rl,data);
}
void inorder(node *ptr){
    if(ptr==NULL)
        return;
    else{
        inorder(ptr->ll);
        printf(" %d ",ptr->data);
        inorder(ptr->rl);
    }    
}
void preorder(node *ptr){
    if(ptr==NULL)
        return;
    else{
        printf(" %d ",ptr->data);
        preorder(ptr->ll);
        preorder(ptr->rl);
    }    
}
void postorder(node *ptr){
    if(ptr==NULL)
        return;
    else{
        postorder(ptr->ll);
        postorder(ptr->rl);
        printf(" %d ",ptr->data);
    }    
}
int max(node *root){
    if(root==NULL){
        printf("Tree is empty...");
        return -1;
    }
    else{
        if(root->rl==NULL)
            return root->data;
        else{
            return max(root->rl);
        }    
    }
}
int main(){
    int a,i,s,ch,order;
    node *root=NULL,*p;
    for(i=0;i<5;i++){
    printf("Enter %d: ",i+1);
    scanf("%d",&a);
    root=insert(root,a);}
    while(1){
    printf("\n1.traversal\n2.search\n3.delete\n4.largest element\n");
    scanf("%d",&ch);
    if(ch==2){
    printf("Enter number : ");
    scanf("%d",&s);
    if(search(root,s)==0)
        printf("Not found...\n");
    else
        printf("found...\n");
    }
    else if(ch==1){
        printf("\n1.Preorder\n2.Inorder\n3.Postorder\n");
        scanf("%d",&order);
        if(order==1){
            printf("\n");
            preorder(root);
        }
        else if(order==2){
            printf("\n");
            inorder(root);
        }
        else if(order==3){
            printf("\n");
            postorder(root);
        }
    }
    else if(ch==4){
        printf("%d",max(root));
    }
    }
}