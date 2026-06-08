#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int a[6000],i,j,min,t,n;
    printf("Enter n value: ");
    scanf("%d",&n);
    srand(time(0));
    printf("\nRandom numbers for n = %d:\n",n);
    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
        printf("%d ",a[i]);
        if(i%20==0)
            printf("\n");
    }
    clock_t start=clock();
    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
            if(a[j]<a[min])
                min=j;
        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
    clock_t end=clock();
    printf("\n\nTime taken to sort for n = %d : %lf seconds\n",n,(double)(end-start)/CLOCKS_PER_SEC);
    printf("\nSorted numbers for n = %d:\n",n);

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);

        if(i%20==0)
            printf("\n");
    }
    return 0;
}
