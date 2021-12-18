#ifndef _MAIN_HEAD_H
#define _MAIN_HEAD_H

#include <stdio.h>

typedef struct Element {
    const char *name;
} Element;

typedef struct TreeNode {
    Element elem;
    struct TreeNode *left, *right;
    int ltag, rtag;
} TreeNode;

void divider();

void tree_node_init(TreeNode *node, const char *name, TreeNode *left, TreeNode *right);
void tree_node_visit(TreeNode *node);

void tree_fro_thread_create(TreeNode *tree);
void tree_fro_traversal(TreeNode *tree, TreeNode **prev);
void tree_fro_order_print(TreeNode *node);
TreeNode *tree_fro_thread_next(TreeNode *tree);

void tree_mid_thread_create(TreeNode *tree);
void tree_mid_traversal(TreeNode *tree, TreeNode **prev);
void tree_mid_order_print(TreeNode *node);
void tree_mid_reverse_order_print(TreeNode *tree);
TreeNode *tree_mid_thread_front(TreeNode *tree);
TreeNode *tree_mid_thread_next(TreeNode *tree);
TreeNode *tree_mid_thread_rear(TreeNode *tree);
TreeNode *tree_mid_thread_prev(TreeNode *tree);

void tree_rea_thread_create(TreeNode *tree);
void tree_rea_traversal(TreeNode *tree, TreeNode **prev);
void tree_rea_reverse_order_print(TreeNode *tree);
TreeNode *tree_rea_thread_prev(TreeNode *tree);

#endif