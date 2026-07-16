//sum subset
#include<stdio.h>
int a[10],x[10],n,sum,count=0;
void sub(int s,int k)
{
    int i;
    x[k]=1;
    if(s+a[k]==sum)
    {
        printf("\nSubset %d:\n",++count);
        for(i=0;i<=k;i++)
            if(x[i])
                printf("%d\t",a[i]);
    }
    else if(s+a[k]<sum && k+1<n)
        sub(s+a[k],k+1);
    x[k]=0;
    if(k+1<n)
        sub(s,k+1);
}
int main()
{
    int i,total=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        total+=a[i];
    }
    printf("Enter the sum: ");
    scanf("%d",&sum);
    if(total<sum)
    {
        printf("No solution");
        return 0;
    }
    sub(0,0);
    if(!count)
        printf("No solution");
    return 0;
}