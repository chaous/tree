//
// Created by Ilya on 3/19/2021.
//

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void createTree(Tree *tree) {
    tree->head = 0;
}

void addNode(Tree *tree, Node *newNode) {
    if (tree->head == 0)
    {
        tree->head = newNode;
        newNode->left = 0;
        newNode->right = 0;
        newNode->parent = 0;
        return;
    }
    addNodeToNode(tree->head, newNode);

}

void addNodeToNode(Node *head, Node *newNode) {
    if (head->elem > newNode->elem)
    {
        if (head->left == 0)
        {
            head->left = newNode;
            newNode->left = 0;
            newNode->right = 0;
            newNode->parent = head;
            return;
        }
        addNodeToNode(head->left, newNode);
    }
    else
    {
        if (head->right == 0)
        {
            head->right = newNode;
            newNode->left = 0;
            newNode->right = 0;
            newNode->parent = head;
            return;
        }
        addNodeToNode(head->right, newNode);
    }

}

void add(Tree *tree, int elem) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->elem = elem;
    newNode->left = 0;
    newNode->right = 0;
    newNode->parent = 0;
    addNode(tree, newNode);
}

void printTree(Tree *tree) {
    if(tree == NULL || tree->head == NULL)
    {
        puts("empty");
        return;
    }
    printNodes(tree->head->left);
    printf("%d\n", tree->head->elem);
    printNodes(tree->head->right);

}

void printNodes(Node *node) {
    if(node == 0)
        return;
    printNodes(node->left);
    printf("%d\n", node->elem);
    printNodes(node->right);

}

void delNode(Tree *tree, Node *node) {


    if(node->left == 0 && node->right == 0)
    {
        if(tree->head == node)
        {
            free(node);
            tree->head = NULL;
            return;
        }
        makeParentNull(node);
        free(node);
        return;
    }

    if(node->left == 0)
    {
        if(node == tree->head)
        {
            tree->head = node->right;
            node->right->parent = 0;
            free(node);
            return;
        }
        if(node->parent->left == node)
        {
            node->parent->left = node->right;
            node->right->parent = node->parent;
        }
        else{
            node->parent->right = node->right;
            node->right->parent = node->parent;
        }
        //node->parent = node->right;
        //node->right->parent = node->parent;
        free(node);
        return;
    }
    if (node->right == 0)
    {
        if(tree->head == node)
        {
            tree->head = node->left;
            node->left->parent = NULL;
            free(node);
            return;
        }
        if(node->parent->left == node)
        {
            node->parent->left = node->left;
            node->left->parent = node->parent;
        }
        else{
            node->parent->right = node->left;
            node->left->parent = node->parent;
        }
        //node->parent = node->left;
        free(node);
        return;
    }
    else
    {
        Node* replacement = node->right;
        if(replacement->left == 0)
        {
            node->elem = replacement->elem;
            replacement->parent->right = replacement->right;
            if(replacement->right != NULL)
                replacement->right->parent = replacement->parent;
            free(replacement);
            return;
        }
        while(replacement->left != 0)
        {
            replacement = replacement->left;
        }
        if (replacement->right == 0)
        {
            node->elem = replacement->elem;
            free(replacement);
            return;
        }
        //printf("%d\n", replacement->right->elem);
        node->elem = replacement->elem;
        replacement->parent->left = replacement->right;
        replacement->right->parent = replacement->parent;
        free(replacement);
        return;




    }

}

void switchValue(Node *a, Node *b) {
    Node val = *a;
    *a = *b;
    *b = val;

}

int treePower(Tree *tree)
{
    return nodePower(tree->head);

}



int nodePower(Node *node) {

    if(node == 0)
        return 0;
    int maxPower = 0;
    if(node->left != 0)
        ++maxPower;
    if(node->right != 0)
        ++maxPower;

    if(maxPower == 2)
        return maxPower;

    int maxLeft = nodePower(node->left);
    if (maxLeft > maxPower)
        maxPower = maxLeft;

    int maxRight = nodePower(node->right);
    if(maxRight > maxPower)
        maxPower = maxRight;
    return maxPower;


}

int maxHight(Tree *tree) {
    if (tree->head == 0)
        return 0;
    return nodeHight(tree->head, 0);

}

int nodeHight(Node* node, int baseHight) {
    if(node == 0)
        return baseHight;
    ++baseHight;
    int leftHight = nodeHight(node->left, baseHight);
    int rightHight = nodeHight(node->right, baseHight);
    if(leftHight > rightHight)
        return leftHight;
    return rightHight;
}

Node* findNode(Tree* tree, int elem) {
    if(tree->head == 0)
        return NULL;
    //if(tree->head->elem == elem)
    //    return tree->head;

    return findNodeByNode(tree->head, elem);


}

Node* findNodeByNode(Node* node, int elem) {
    if(node == 0)
        return NULL;
    if(node->elem == elem)
        return node;

    if(node->elem > elem)
        return findNodeByNode(node->left, elem);
    return findNodeByNode(node->right, elem);
}

bool delElem(Tree *tree, int elem) {
    Node* node = findNode(tree, elem);
    if(node == NULL)
        return false;
    delNode(tree, node);
    return true;
}

void destrouTree(Tree *tree) {

    if(tree == NULL)
    {
        return;
    }

    destroyNode(tree->head);


}

void destroyNode(Node *node) {

    if(node == NULL)
    {
        return;
    }
    destroyNode(node->left);
    destroyNode(node->right);
    free(node);
}

void makeParentNull(Node *child) {
    if(child == NULL)
        return;

    if(child->parent == NULL)
        return;

    Node* parent = child->parent;


    if(parent->left == child)
        parent->left = NULL;

    if(parent->right == child)
        parent->right = NULL;


}







