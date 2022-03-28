#include "main.h"

int main(void) {
    // 3 vertex
    // 2 edge; a - b, a - c
    AMGraph graph;
    graph_init(&graph);

    printf("%d\n", graph_v_degrees(&graph, 'A'));
    printf("%d\n", graph_v_degrees(&graph, 'B'));
    printf("%d\n", graph_v_degrees(&graph, 'C'));

    /**
    ALGraph algraph;
    algraph.vex_num = 5;
    algraph.arc_num = 6;
    algraph.vexs[0].vex = 'A';
    algraph.vexs[1].vex = 'B';
    algraph.vexs[2].vex = 'C';
    algraph.vexs[3].vex = 'D';
    algraph.vexs[4].vex = 'E';

    GraphLinkArc a_b = {1, NULL};
    GraphLinkArc a_d = {3, NULL};
    a_b.next_arc = &a_d;
    algraph.vexs[0].first_arc = &a_b;

    GraphLinkArc b_a = {0, NULL};
    GraphLinkArc b_c = {2, NULL};
    GraphLinkArc b_e = {4, NULL};
    b_a.next_arc = &b_c;
    b_c.next_arc = &b_e;
    algraph.vexs[1].first_arc = &b_a;
    */

    return 0;
}

void graph_init(AMGraph *graph) {
    printf("Enter vex num: ");
    scanf("%d", &graph->vexnum);
    printf("vex num %d\n", graph->vexnum);

    printf("Enter arc num: ");
    scanf("%d", &graph->arcnum);
    printf("arc num %d\n", graph->arcnum);

    char vex;
    for (int i = 0; ;) {
        printf("Enter vex: ");
        vex = getchar();
        if (vex >= 65 && vex <= 90) {
            graph->vexs[i] = vex;
            printf("%d index vex is %c\n", i, graph->vexs[i]);
            i++;
        }
        
        if (i == graph->vexnum) {
            break;
        }
    }

    char a, b;
    int x, y;
    for (int i = 0; ;) {
        printf("Enter arc: ");
        scanf("%c%c", &a, &b);
        if (a >= 65 && a <= 90 && b >= 65 && b <= 90) {
            x = graph_v_index(graph, a);
            y = graph_v_index(graph, b);
            printf("%c index is %d, %c index is %d\n", a, x, b, y);
            graph->arcs[x][y] = 1;
            i++;
        }

        if (i == graph->arcnum) {
            break;
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
