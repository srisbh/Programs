#include<stdio.h>
#include<stdlib.h>
int x[10],n;
int place(int r,int c)
{
    int j;
    for(j=1;j<r;j++)
        if(x[j]==c || abs(x[j]-c)==abs(j-r))
            return 0;
    return 1;
}
void queen(int r)
{
    int c,i,j;
    for(c=1;c<=n;c++)
    {
        if(place(r,c))
        {
            x[r]=c;
            if(r==n)
            {
                printf("\nSolution:\n");
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                    {
                        if(x[i]==j)
                            printf("Q ");
                        else
                            printf(". ");
                    }
                    printf("\n");
                }
            }
            else
                queen(r+1);
        }
    }
}
int main()
{
    printf("Enter the value of N: ");
    scanf("%d",&n);
    queen(1);
    return 0;
}