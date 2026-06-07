#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick(int a[],int l,int h)
{
    int i,j,pivot,temp;

    if(l<h)
    {
        pivot=a[h];
        i=l-1;

        for(j=l;j<h;j++)
            if(a[j]<pivot)
            {
                i++;

                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        temp=a[i+1];
        a[i+1]=a[h];
        a[h]=temp;

        int p=i+1;

        quick(a,l,p-1);
        quick(a,p+1,h);
    }
}

int main()
{
    int a[6000],i,n=6000;

    srand(time(0));

    printf("Random numbers for n = %d:\n",n);

    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
        printf("%d ",a[i]);
    }

    clock_t start=clock();

    quick(a,0,n-1);

    clock_t end=clock();

    printf("\nTime taken to sort for n = %d: %lf seconds\n",
            n,(double)(end-start)/CLOCKS_PER_SEC);

    printf("\nSorted numbers for n = %d:\n",n);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}