#include <stdio.h>
#include "tree.h"




int main() {

    Tree testTree;
    createTree(&testTree);
    int n;
    scanf("%d",&n);
    for(int i = 0; i != n; ++i)
    {
        int par;
        scanf("%d", &par);
        add(&testTree, par);
    }
    scanf("%d",&n);
    delElem(&testTree, n);
    //delNode(&testTree, testTree.head);
    //printTree(&testTree);
    //delNode(&testTree, testTree.head);
    //printTree(&testTree);
    //printf("%d\n", treePower(&testTree));
    //printf("%d\n",findNode(&testTree, 4)->elem);
    //printf("%d\n", maxHight(&testTree));
    //destrouTree(&testTree);
    //printf("%d\n",treePower(&testTree));
    printTree(&testTree);
}
