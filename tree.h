//
// Created by Ilya on 3/19/2021.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <stdbool.h>


typedef struct Node
{
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int elem;
}Node;

typedef struct Tree
{
    Node* head;
}Tree;

void createTree(Tree* tree);

void addNode(Tree* tree, Node* newNode);
void add(Tree* tree, int elem);

void addNodeToNode(Node* head, Node* newNode);

void printTree(Tree* tree);

void printNodes(Node* node);

Node* findNode(Tree* tree, int elem);

Node* findNodeByNode(Node* node, int elem);



void printTree(Tree* tree);

void delNode(Tree* tree, Node* node);

void switchValue(Node* a, Node* b);

int treePower(Tree* tree);

int nodePower(Node* node);

int maxHight(Tree* tree);

int nodeHight(Node* node, int baseHight);

bool delElem(Tree* tree,int elem);

void destrouTree(Tree* tree);

void destroyNode(Node* node);

void makeParentNull(Node* child);









#endif //TREE_TREE_H
