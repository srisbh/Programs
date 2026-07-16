//Floyd's  Algorithm
#include<stdio.h>
int a[10][10],n;
int main()
{
    int i,j,k;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost adjaceny matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
        scanf("%d",&a[i][j]);
        if(i!=j && a[i][j]==0)
            a[i][j]=999;
        }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k]+a[k][j]<a[i][j])
                    a[i][j]=a[i][k]+a[k][j];
    printf("\nAll Pairs Shortest Path Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}