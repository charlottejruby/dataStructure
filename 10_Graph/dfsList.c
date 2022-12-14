#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 200

int visited[MAX_VERTICES];

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType{
    int n;
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g){
    g->n=0;

    for(int i = 0 ; i <MAX_VERTICES;i++)
        g->adj_list[i]=NULL;
}
void insert_vertex(GraphType* g, int v){
    if((g->n)+1 > MAX_VERTICES){
        fprintf(stderr, "정점 개수 오류");
        return;
    }
    g->n++;
}
void insert_edge(GraphType* g, int start, int end){
    GraphNode* w;
    w=(GraphNode*)malloc(sizeof(GraphNode));
    w->vertex = end;
    w->link = g->adj_list[start];
    g->adj_list[start]=w;
}
void dfs_list(GraphType* g, int v){
    visited[v]=1;
    printf("정점: %d->", v);
    GraphNode* w;
    for(w=g->adj_list[v];w;w=w->link){
        if(!visited[w->vertex]){
            dfs_list(g, w->vertex);
        }
    }
}
int main(){
    GraphType *g;
    g= (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0; i<4;i++){
        insert_vertex(g, i);
    }
   insert_edge(g, 2, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 1);

    printf("DFS\n");
    dfs_list(g, 0);
    free(g);
    return 0;

}