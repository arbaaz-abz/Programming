#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct node {
    int data;
    struct node * rlink;
    struct node * llink;
};
struct node * createBST(int a[],int start,int end) {
    if(start>end) return NULL;
    int mid = (start+end)/2;
    struct node * root = (struct node *)malloc(sizeof(struct node));
    root->data=a[mid];
    printf("%d CREATED\n",root->data);
    root->llink = createBST(a,start,mid-1);
    root->rlink = createBST(a,mid+1,end);
    
    return root;
}
void preorder(struct node * root) {
    if(root != NULL) {
        printf("%d  ",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) 
        scanf("%d",&a[i]);
    struct node * root = createBST(a,0,n-1);
    preorder(root);
    return 0;
}
