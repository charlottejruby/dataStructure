#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

int visited[MAX_VERTICES];

typedef struct GraphNode{
    int vertex; //인접 정점
    struct GraphNode *link; //인접 정점 노드를 가리키는 포인터 
}GraphNode;

typedef struct GraphType{
    int n;//정점의 개수 
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;


void init(GraphType * g){
    int v;
    g->n=0;
    for(v=0;v<MAX_VERTICES;v++){
        g->adj_list[v]=NULL;
    }
}
void insert_vertex(GraphType* g, int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "overflow");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v){
    GraphNode * node;
    node=(GraphNode*)malloc(sizeof(GraphNode));
    node->vertex=v;
    node->link=g->adj_list[u]; //노드를 앞에 삽입하기에 원래의 링크를 노드 링크랑 연결
    g->adj_list[u]=node; //원래 가리키는 링크에 노드를 가리키도록 변경
}

void dfs_list(GraphType* g, int v){
    GraphNode *w;
    visited[v]=1;
    printf("정점 : %d-> ", v);
    for(w=g->adj_list[v];w;w=w->link){
        if(!visited[w->vertex])
            dfs_list(g, w->vertex);
    }
}
int main(){
    GraphType* g;
    g=(GraphType*)malloc(sizeof(GraphType));

    init(g);
    for(int i = 0 ; i<4;i++){
        insert_vertex(g, i);
    }

    insert_edge(g, 2, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 1);

    printf("dfs\n");
    dfs_list(g, 0);
    printf("\n"); 
    free(g);
    return 0;
}