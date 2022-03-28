#ifndef _MAIN_HEAD_H

#define _MAIN_HEAD_H

#include <stdio.h>

#define MAX_VERTEX_NUM 3

typedef char VertexType;
typedef int ArcType;

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; // Vertex
    ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // Edge
    int vexnum, arcnum;
} AMGraph;

// 链表图的边
typedef struct GraphLinkArc {
    int adj_vex_i;
    struct GraphLinkArc *next_arc;
} GraphLinkArc;

// 链表图的头节点
typedef struct {
    VertexType vex;
    GraphLinkArc *first_arc;
} GraphLinkHead, GraphLink[MAX_VERTEX_NUM];

// link graph
typedef struct {
    GraphLink vexs;
    int vex_num, arc_num;
} ALGraph;

void graph_init(AMGraph *graph);
int graph_v_degrees(AMGraph *graph, VertexType v);
int graph_v_index(AMGraph *graph, VertexType v);


#endif