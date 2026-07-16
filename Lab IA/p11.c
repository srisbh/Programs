#include<stdio.h>
void merge(int a[],int l,int m,int r)
{
    int i=l,j=m+1,k=0,b[100];
    while(i<=m && j<=r)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)
        b[k++]=a[i++];
    while(j<=r)
        b[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)
        a[i]=b[k++];
}
void sort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        sort(a,l,m);
        sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    int a[100],n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,0,n-1);
        printf("Sorted array:\n");
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        return 0;
}