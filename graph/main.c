#include "main.h"

int main(void) {
    // 3 vertex
    // 2 edge; a - b, a - c
    AMGraph graph;
    graph_init(&graph);

    printf("%d\n", graph_v_degrees(&graph, 'A'));
    printf("%d\n", graph_v_degrees(&graph, 'B'));
    printf("%d\n", graph_v_degrees(&graph, 'C'));

    return 0;
}

void graph_init(AMGraph *graph) {
    graph->vexnum = 3;
    graph->arcnum = 4;

    char vexs[] = {'A', 'B', 'C'};
    for (int i = 0; i < graph->vexnum; i++) {
        graph->vexs[i] = vexs[i];
    }

    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {{0, 1, 1}, {1, 0, 0}, {1, 0, 0}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < graph->vexnum; j++) {
            graph->arcs[i][j] = arcs[i][j];
        }
    }
}

// 计算某个顶点的度数
// O(n*n)
int graph_v_degrees(AMGraph *graph, VertexType v) {
    int d = 0;
    int index = graph_v_index(graph, v);

    if (index == -1) {
        return d;
    }

    for (int i = 0; i < graph->vexnum; i++) {
        if (graph->arcs[index][i]) {
            d++;
        }
    }

    return d;
}

// O(n)
int graph_v_index(AMGraph *graph, VertexType v) {
    int index = -1;

    for (int i = 0; i < graph->vexnum; i++) {
        if (graph->vexs[i] == v) {
            index = i;
        }
    }

    return index;
}
