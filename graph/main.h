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

void graph_init(AMGraph *graph);
int graph_v_degrees(AMGraph *graph, VertexType v);
int graph_v_index(AMGraph *graph, VertexType v);


#endif