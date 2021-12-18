#include "main.h"

int main(void) {
    TreeNode left_left;
    tree_node_init(&left_left, "left-left", NULL, NULL);

    TreeNode left_right;
    tree_node_init(&left_right, "left-right", NULL, NULL);

    TreeNode left;
    tree_node_init(&left, "left", &left_left, &left_right);

    TreeNode right_left;
    tree_node_init(&right_left, "right-left", NULL, NULL);

    TreeNode right_right;
    tree_node_init(&right_right, "right-right", NULL, NULL);

    TreeNode right;
    tree_node_init(&right, "right", &right_left, &right_right);

    TreeNode root;
    tree_node_init(&root, "root", &left, &right);

    // tree_fro_thread_create(&root);
    // divider();
    // tree_fro_order_print(&root);

    // tree_mid_thread_create(&root);
    // divider();
    // tree_mid_order_print(&root);
    // divider();
    // tree_mid_reverse_order_print(&root);

    tree_rea_thread_create(&root);
    divider();
    tree_rea_reverse_order_print(&root);

    return 0;
}

void divider() {
    printf("=====================\n");
}

void tree_node_init(TreeNode *node, const char *name, TreeNode *left, TreeNode *right) {
    Element elem = {name};
    node->elem = elem;
    node->left = left;
    node->right = right;
    node->ltag = 0;
    node->rtag = 0;
}

void tree_node_visit(TreeNode *node) {
    if (node == NULL) return;

    printf("%s\n", node->elem.name);
}

void tree_fro_thread_create(TreeNode *tree) {
    if (tree == NULL) return;

    TreeNode *prev = NULL;

    tree_fro_traversal(tree, &prev);

    prev->right = NULL;
    prev->rtag = 1;
}

void tree_fro_traversal(TreeNode *tree, TreeNode **prev) {
    if (tree == NULL) return;

    tree_node_visit(tree);

    if (tree->left == NULL) {
        tree->left = *prev;
        tree->ltag = 1;
    }

    if (*prev != NULL && (*prev)->right == NULL) {
        (*prev)->right = tree;
        (*prev)->rtag = 1;
    }

    *prev = tree;

    if (tree->ltag == 0) {
        tree_fro_traversal(tree->left, prev);
    }

    tree_fro_traversal(tree->right, prev);
}

void tree_fro_order_print(TreeNode *tree) {
    TreeNode *next = tree;

    while (next != NULL) {
        tree_node_visit(next);
        next = tree_fro_thread_next(next);
    }
}

TreeNode *tree_fro_thread_next(TreeNode *tree) {
    if (tree->rtag == 1) {
        return tree->right;
    }

    if (tree->left != NULL) {
        return tree->left;
    }

    return tree->right;
}

void tree_mid_thread_create(TreeNode *tree) {
    if (tree == NULL) return;

    TreeNode *prev = NULL;

    tree_mid_traversal(tree, &prev);

    prev->right = NULL;
    prev->rtag = 1;
}

void tree_mid_traversal(TreeNode *tree, TreeNode **prev) {
    if (tree == NULL) return;

    tree_mid_traversal(tree->left, prev);

    tree_node_visit(tree);

    if (tree->left == NULL) {
        tree->left = *prev;
        tree->ltag = 1;
    }

    if (*prev != NULL && (*prev)->right == NULL) {
        (*prev)->right = tree;
        (*prev)->rtag = 1;
    }

    *prev = tree;

    tree_mid_traversal(tree->right, prev);
}

void tree_mid_order_print(TreeNode *tree) {
    TreeNode *next = tree_mid_thread_front(tree);

    while (next != NULL) {
        tree_node_visit(next);
        next = tree_mid_thread_next(next);
    }
}

void tree_mid_reverse_order_print(TreeNode *tree) {
    TreeNode *prev = tree_mid_thread_rear(tree);

    while (prev != NULL) {
        tree_node_visit(prev);
        prev = tree_mid_thread_prev(prev);
    }
}

TreeNode *tree_mid_thread_front(TreeNode *tree) {
    while (tree->ltag == 0) {
        tree = tree->left;
    }
    
    return tree;
}

TreeNode *tree_mid_thread_next(TreeNode *tree) {
    if (tree->rtag == 1) {
        return tree->right;
    }

    return tree_mid_thread_front(tree->right);
}

TreeNode *tree_mid_thread_prev(TreeNode *tree) {
    if (tree->ltag == 1) {
        return tree->left;
    }

    return tree_mid_thread_rear(tree->left);
}

TreeNode *tree_mid_thread_rear(TreeNode *tree) {
    while (tree->rtag == 0) {
        tree = tree->right;
    }

    return tree;
}

void tree_rea_thread_create(TreeNode *tree) {
    if (tree == NULL) return;

    TreeNode *prev = NULL;

    tree_rea_traversal(tree, &prev);

    if (prev->right == NULL) {
        prev->rtag = 1;
    }
}

void tree_rea_traversal(TreeNode *tree, TreeNode **prev) {
    if (tree == NULL) return;

    tree_rea_traversal(tree->left, prev);
    tree_rea_traversal(tree->right, prev);

    tree_node_visit(tree);

    if (tree->left == NULL) {
        tree->left = *prev;
        tree->ltag = 1;
    }

    if (*prev != NULL && (*prev)->right == NULL) {
        (*prev)->right = tree;
        (*prev)->rtag = 1;
    }

    *prev = tree;
}

void tree_rea_reverse_order_print(TreeNode *tree) {
    TreeNode *prev = tree;

    while (prev != NULL) {
        tree_node_visit(prev);
        prev = tree_rea_thread_prev(prev);
    }
}

TreeNode *tree_rea_thread_prev(TreeNode *tree) {
    if (tree->ltag == 1) {
        return tree->left;
    }

    if (tree->right != NULL) {
        return tree->right;
    }

    return tree->left;
}
