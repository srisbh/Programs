#include<stdio.h>
int p[10],w[10],n;
int ks(int i,int m)
{
    if(i>n)
    return 0;
    if(w[i]>m)
    return ks(i+1,m);
    int a=ks(i+1,m);
    int b=ks(i+1,m-w[i])+p[i];
    return (a>b)?a:b;
}
int main()
{
    int i,m;
    printf("Enter the no. of objects: ");
    scanf("%d",&n);
    printf("Enter the weights:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("Enter the profits:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("Enter the knapsack capacity:\n");
    scanf("%d",&m);
    printf("The optimal solution is %d\n",ks(1,m));
    return 0;
}