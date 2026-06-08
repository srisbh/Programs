#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quick(int a[],int l,int h)
{
    int i,j,p,t;
    if(l<h)
    {
        p=a[h];
        i=l-1;
        for(j=l;j<h;j++)
        if(a[j]<p)
        {
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    t=a[i+1];
    a[i+1]=a[h];
    a[h]=t;
    int k=i+1;
    quick(a,l,k-1);
    quick(a,k+1,h);
    }
}
int main()
{
    int a[6000],i,n;
    print("Enter n value: ");
    scanf("%d",&n);
    srand(time(0));
    printf("\n Random number for n=%d:\n",n);
    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
        printf("%d",a[i]);
        if(i%20==0)
        printf("\n");
    }
    clock_t start=clock();
    quick(a,0,n-1);
    clock_t end=clock();

    printf("\n\nTime taken to sort for n = %d : %lf seconds\n",
            n,(double)(end-start)/CLOCKS_PER_SEC);
    printf("\nSorted numbers for n = %d:\n",n);

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);

        if(i%20==0)
            printf("\n");
    }

    return 0;
}
}
