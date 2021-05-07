#include <stdio.h>
#include "keresofa.h"

int main() {
    Node *root;
    root=NULL;
    insert(&root,27);
    insert(&root,14);
    insert(&root,35);
    insert(&root,10);
    insert(&root,19);
    insert(&root,31);
    insert(&root,42);
    inorder(root);
    printf("A legkisebb elem: %i\n",min(root));
    printf("A legnagyobb elem elem: %i\n",max(root));
    //root=deleteNode(root,14);
    printf("\n Inorder bejaras: \n");
    inorder(root);
    printf("\n Preoder bejaras: \n");
    preorder(root);
    printf("\n Postorder bejaras: \n");
    postorder(root);
    printf("\n %i ",prev(root,15));
    printf("\n %i ",next(root,15));






}
