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

    tree_fro_traversal(&root);
    divider();
    tree_mid_traversal(&root);
    divider();
    tree_rea_traversal(&root);
    divider();
    tree_level_traversal(&root);

    return 0;
}

void divider() {
    printf("========================\n");
}

void tree_node_init(TreeNode *node, const char *name, TreeNode *left, TreeNode *right) {
    Element elem = {name};
    node->elem = elem;
    node->left = left;
    node->right = right;
}

void tree_node_visity(TreeNode *node) {
    if (node == NULL) return;

    printf("%s\n", node->elem.name);
}

void tree_fro_traversal(TreeNode *tree) {
    if (tree != NULL) {
        tree_node_visity(tree);
        tree_fro_traversal(tree->left);
        tree_fro_traversal(tree->right);
    }
}

void tree_mid_traversal(TreeNode *tree) {
    if (tree == NULL) {
        return;
    }

    tree_mid_traversal(tree->left);
    tree_node_visity(tree);
    tree_mid_traversal(tree->right);
}

void tree_rea_traversal(TreeNode *tree) {
    if (tree == NULL) return;

    tree_rea_traversal(tree->left);
    tree_rea_traversal(tree->right);
    tree_node_visity(tree);
}

void queue_init(QueueLinkList *queue) {
    *queue = (QueueLinkList) malloc(sizeof(QueueLink));
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
}

void queue_node_create(QueueNode **node, TreeNode *data) {
    *node = (QueueNode *) malloc(sizeof(QueueNode));
    (*node)->data = data;
    (*node)->next = NULL;
}

void queue_send(QueueLinkList queue, TreeNode *tree_node) {

    QueueNode *node = NULL;
    queue_node_create(&node, tree_node);

    if (queue_is_empty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

int queue_pick(QueueLinkList queue, TreeNode **tree_node) {
    if (queue_is_empty(queue)) {
        return 0;
    }

    QueueNode *node = queue->front;
    *tree_node = node->data;

    if (queue->front->next == NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    } else{
        queue->front = node->next;
    }

    free(node);

    return 1;
}

void tree_level_traversal(TreeNode *tree) {
    QueueLinkList queue;
    queue_init(&queue);
    queue_send(queue, tree);
    TreeNode *tree_node = NULL;

    while (!queue_is_empty(queue)) {

        if (!queue_pick(queue, &tree_node)) {
            break;
        }

        if (tree_node == NULL) {
            break;
        }

        tree_node_visity(tree_node);

        if (tree_node->left != NULL) {
            queue_send(queue, tree_node->left);
        }

        if (tree_node->right != NULL) {
            queue_send(queue, tree_node->right);
        }

        tree_node = NULL;
    }
}

int queue_is_empty(QueueLinkList queue) {
    return (queue->front == NULL);
}
