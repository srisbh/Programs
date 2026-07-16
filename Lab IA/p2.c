#include<stdio.h>
int c[10][10],n;
int main()
{
    int i,j,a,b,min,mincost=0,ne=1,visited[10]={0};
    printf("****PRIM'S ALGORITHM****\n");
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter the cost matrix:");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
            if(c[i][j]==0)
            c[i][j]==999;
        }
        visited[1]=1;
        printf("The MST tree edges and costs are:\n");
        while(ne<n)
        {
            min=999;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(visited[i] && !visited[j] && c[i][j]<min)
                    {
                        min=c[i][j];
                        a=i;
                        b=j;
                    }
            printf("The minimum edge is %d -> %d \t cost=%d\n",a,b,min);
            mincost+=min;
            visited[b]=1;
            ne++;
        }
        printf("The minimum spanning tree cost is %d\n",mincost);
        return 0;
}