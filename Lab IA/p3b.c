//Warshall's algorithm
#include<stdio.h>
int main()
{
    int a[10][10],n,i,j,k;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjaceny matrix: \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);

    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
    printf("\nTransitive Closure Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}