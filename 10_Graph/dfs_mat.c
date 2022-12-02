#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

int visited[MAX_VERTICES];

typedef struct GraphType{
    int n; //정점의 개수 
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init (GraphType *g){
    g->n=0;
    int r, c;
    for(r=0;r<MAX_VERTICES;r++){
        for(c=0;c<MAX_VERTICES;c++){
            g->adj_mat[r][c]=0;
        }
    }
}

void insert_vertex(GraphType *g, int v){
    //만약, 그래프의 정점 개수가 MAX_VERTICE 초과할 경우
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "그래프 정점 개수 초과");
        return;
    }
    g->n++;
}
void insert_edge(GraphType *g, int start, int end){
    //그래프 정점 번호 체크 
    if(start>=g->n||end>=g->n){
        fprintf(stderr, "그래프 정점 번호 오류");
    }
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;
}
void dfs_mat(GraphType* g, int v){
    int w;
    visited[v]=1;
    //visited vertex print
    printf("정점 %d->", v);
    for(w=0;w<g->n;w++){
        if(g->adj_mat[v][w] && !visited[w]){
            dfs_mat(g, w);
        }
    }
}

int main(){
    GraphType* g;
    g=(GraphType*)malloc(sizeof(GraphType));

    init(g);
    for(int i = 0 ; i<4;i++){
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("dfs\n");
    dfs_mat(g, 0);
    printf("\n");
    free(g);
    return 0;
}
