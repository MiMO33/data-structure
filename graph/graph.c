#include"graph.h"

void graph_init(MGraph* g){

    g = (MGraph*)malloc(sizeof(MGraph));
    g->arc_num = 0;
    g->vex_num = 0;
    g->kind = DS_GRAPH_KIND;
    switch(g->kind){
        case DG: graph_init_DG(g); break;
        case DN: graph_init_DN(g); break;
        case UDG: graph_init_UDG(g); break;
        case UDN: graph_init_UDN(g); break;
        default: perror("illegal graph kind value.");
                 exit(0);
    }
}

static void find_pos()

static void graph_init_DG(MGraph* g){
    int pos1, pos2;
    char a, b;
    printf("input the vexs: \n");
    for(size_t i = 0; i < 5; i++){
        scanf("%c", &g->arcs[i]);
        g->vex_num++;
    }
    printf("input the edges \n");
    for(size_t i = 0; i < 5; i++){
        scanf("%c->%c", &a, &b);

    }
    
}
static void graph_init_DN(MGraph* g);
static void graph_init_UDG(MGraph* g);
static void graph_init_UDN(MGraph* g);