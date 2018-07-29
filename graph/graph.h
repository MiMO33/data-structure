#ifndef DS_GRAPH_H__
#define DS_GRAPH_H__

#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

#define DS_GRAPH_INFINITY INT_MAX
#define DS_GRAPH_MAX_VERTEX_NUM 20

#ifndef DS_GRAPH_KIND
#define DS_GRAPH_KIND DG
#endif

#define VRType int
#define VertexType int

typedef enum {DG = 0, DN, UDG, UDN} GraphKind;

typedef struct{
    char vexs[DS_GRAPH_MAX_VERTEX_NUM];
    int arcs[DS_GRAPH_MAX_VERTEX_NUM][DS_GRAPH_MAX_VERTEX_NUM];
    int vex_num, arc_num;
    GraphKind kind;
}MGraph;

void graph_init(MGraph* g);
static void graph_init_DG(MGraph* g);
static void graph_init_DN(MGraph* g);
static void graph_init_UDG(MGraph* g);
static void graph_init_UDN(MGraph* g);

#endif //DS_GRAPH_H__