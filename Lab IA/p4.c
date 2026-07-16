//Dijkstra Algorithm
#include<stdio.h>
int c[10][10],d[10],v[10],n;
int main()
{
    int i,j,u,w,min,s;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost adjaceny matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
            if(c[i][j]==0 && i!=j)
                c[i][j]=999;
        }
    printf("Enter the source node: ");
    scanf("%d",&s);
    for(i=1;i<=n;i++)
    {
        d[i]=c[s][i];
        v[i]=0;
    }
    d[s]=0;
    v[s]=1;
    for(i=1;i<+n;i++)
    {
        min=999;
    for(j=1;j<=n;j++)
        if(!v[j]&&d[j]<min)
        {
            min=d[j];
            u=j;
        }
    v[u]=1;
    for(w=1;w<=n;w++)
        if(!v[w] && d[w]>d[u]+c[u][w])
            d[w]=d[u]+c[u][w];
    }
    for(i=1;i<=n;i++)
        if(i!=s)
            printf("\nShortest path from %d to %d is %d",s,i,d[i]);
    return 0;
}

