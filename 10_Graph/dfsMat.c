#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 50

typedef struct GraphType{
    int n;
    int adj_mat[MAX_ELEMENT][MAX_ELEMENT];
}GraphType;

void init(GraphType* g){
    int r, c;
    g->n = 0;
    for(r = 0 ; r<MAX_ELEMENT;r++){
        for(c=0;c<MAX_ELEMENT;c++)
            g->adj_mat[r][c]=0;
    }
}
void insert_vertex(GraphType* g, int v){
    if((g->n)+1 >MAX_ELEMENT){
        fprintf(stderr, "정점의 개수 초과");
        return;
    }
    g->n++;
}
void insert_edge(GraphType* g, int start, int end){
    if(start>=g->n || end >=g->n){
        fprintf(stderr, "정점 번호 오류");
        return;
    }
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;

}
void print_adj_mat(GraphType*g){
    for(int i =0;i<g->n;i++){
        for(int j = 0; j<g->n; j++){
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}
int visited[MAX_ELEMENT];

void dfs_mat(GraphType* g, int v){
    visited[v]=1;
    printf("정점 %d->", v);
    for(int w = 0 ; w<g->n; w++){
        if(g->adj_mat[v][w]&& !visited[w])
            dfs_mat(g, w);
    }
}
int main(){
    GraphType* g;
    g=(GraphType*)malloc(sizeof(GraphType));
    init(g);

    for(int i = 0 ; i <4;i++){
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    printf("깊이 우선 탐색\n");
    dfs_mat(g, 0);
    printf("\n");

    free(g);
    return 0;

}
