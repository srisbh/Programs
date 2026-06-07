#include<stdio.h>
int main()
{
    float w[10],p[10],r[10];
    float cap,val=0,temp;
    int i,j,n;
    printf("Enter the number of items:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Weight and Profit for item[%d]:\n",i);
        scanf("%f%f",&w[i],&p[i]);
        r[i]=p[i]/w[i];
    }
    printf("Enter the knapsack capacity:\n");
    scanf("%f",&cap);
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(r[i]<r[j])
            {
                temp=r[i];
                r[i]=r[j];
                r[j]=temp;

                temp=w[i];
                w[i]=w[j];
                w[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
    printf("\n Knapsack problem using Greedy Algorithm:\n");
    for(i=0;i<n && cap>0;i++)
    {
        if(w[i]<=cap)
        {
            val+=p[i];
            cap-=w[i];
        }
        else
        {
            val+=r[i]*cap;
            break;
        }
    }
    printf("\n The maximum value is :%f\n",val);
    return 0;
}