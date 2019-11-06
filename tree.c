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
    if(root->rl==NULL)
        return root->data;
    else{
        max(root->rl);
    }
}
node * delete(node *root,int da){
    int temp;
    node *ptr;
    if(da > root->data)
        root->rl=delete(root->rl,da);
    else if(da < root->data)
        root->ll=delete(root->ll,da);
    else{
        if(root->ll==NULL && root->rl==NULL){
            free(root);
            return NULL;
        }
        else if(root->ll==NULL){
            ptr=root->rl;
            free(root);
            return ptr;
        }
        else if(root->rl==NULL){
            ptr=root->ll;
            free(root);
            return ptr;
        }
        else{
            temp=max(root->ll);
            root->ll=delete(root->ll,temp);
            root->data=temp;
        }
    }
    return root;
}
int main(){
    int a,i=1,s,ch,del,order;
    node *root=NULL,*p;
     while(1){
    printf("\n1.Insertion\n2.traversal\n3.search\n4.deletion\n5.largest element\n");
    scanf("%d",&ch);
    
    if(ch==1){
        printf("Enter the %d number : ",i);
        i=i+1;
        scanf("%d",&a);
        root=insert(root,a);
    }
    else if(root==NULL)
        printf("-->Tree is empty...");
    else if(ch==3){
    printf("Enter number : ");
    scanf("%d",&s);
    if(search(root,s)==0)
        printf("-->Not found...\n");
    else
        printf("-->Found...\n");
    }
    else if(ch==2){
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
    else if(ch==5){
        printf("-->%d",max(root));
    }
    else if(ch==4){
        printf("Enter the element : ");
        scanf("%d",&del);
        root=delete(root,del);
    }
    }
}
