//
// Created by Ilya on 3/31/2021.
//

#include "input.h"
#include <stdio.h>
#include "tree.h"

void getComand() {
    char command;
    Tree tree;
    createTree(&tree);
    printf("%s", "add - add node\n print - print tree\n power - show power\n delite\n hight\n");
    do {
        //fgets(command, 31, stdin);
        scanf("%c", &command);
        //printf("%s\n", command);
        if(command == 'a') {
            int elem;
            printf("%s\n", "value");
            scanf("%d", &elem);
            add(&tree, elem);
            printTree(&tree);
            continue;
        }
        if(command == 'd')
        {
            int elem;
            printf("%s\n", "elem");
            scanf("%d", &elem);
            delElem(&tree,elem);
            printTree(&tree);
            continue;
        }
        if(command == 'p')
        {
            printTree(&tree);
            continue;
        }
        if(command == 'h')
        {
            printf("%d\n", maxHight(&tree));
            continue;
        }
        if(command == 's')
        {
            printf("%d\n", treePower(&tree));
            continue;
        }
        //if(command == "help")
        //{
        //    printf("%s", "add - add node\n print - print tree\n power - show power\n delite\n hight\n");
        //}


    }while(command != 'e');
    destrouTree(&tree);
}

