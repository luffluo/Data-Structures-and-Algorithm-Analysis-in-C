#ifndef _MAIN_HEAD_H
#define _MAIN_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    const char *name;
} Element;

typedef struct TreeNode {
    Element elem;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} QueueLink, *QueueLinkList;

void divider();

void tree_node_init(TreeNode *node, const char *name, TreeNode *left, TreeNode *right);
void tree_fro_traversal(TreeNode *tree);
void tree_mid_traversal(TreeNode *tree);
void tree_rea_traversal(TreeNode *tree);
void tree_node_visity(TreeNode *node);

void queue_init(QueueLinkList *queue);
int queue_is_empty(QueueLinkList queue);
void queue_node_create(QueueNode **node, TreeNode *data);
void queue_send(QueueLinkList queue, TreeNode *tree_node);
int queue_pick(QueueLinkList queue, TreeNode **tree_node);
void tree_level_traversal(TreeNode *node);

#endif