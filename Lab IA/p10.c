//Quick Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quick(int a[],int l,int r)
{
    int i,j,p,t;
    if(l<r)
    {
        p=a[r];
        i=l-1;
        for(j=1;j<r;j++)
            if(a[j]<p)
            {
                i++;
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        t=a[i+1];
        a[i+1]=a[r];
        a[r]=t;
        quick(a,l,i);
        quick(a,i+2,r);
    }
}
int main()
{
    int a[6000],i,n;
    printf("Enter n value: ");
    scanf("%d",&n);
    srand(time(0));
    printf("Random numbers for n = %d;\n",n);
    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
        printf("%d ",a[i]);
    }
    clock_t start =clock();
    quick(a,0,n-1);
    clock_t end=clock();
    printf("\n\nTime taken to sort for n = %d : %1f seconds\n",n,(double)(end-start)/CLOCKS_PER_SEC);
    printf("\nSorted numbers for n = %d:\n",n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}