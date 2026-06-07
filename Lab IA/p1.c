#include<stdio.h>
int n,cost[10][10],parent[10];
int find(int x) {
    while(parent[x])
    x=parent[x];
    return x;
}
int main() {
    int i,j,a,b,u,v,min,mincost=0,ne=1;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter cost matrix: \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) {
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
        cost[i][j]=999;
}
    printf("\n Edges in MST: \n");
    while(ne<n) {
    min=999;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j]<min) {
            min=cost[i][j];
            a=u=i;
            b=v=j;

        }
        while(parent[u])
        u=parent[u];
        while(parent[v])
        v=parent[v];
        if(u !=v)  { 
            parent[v]=u;
            printf("%d edge(%d,%d)=%d \n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\n Minimum cost =%d",mincost);
    return 0;
}
