#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<time.h>


struct arr
{
    int new[100][100];
};
struct arr form(int a[],int row, int column)
{
    struct arr final;
    int count=0;
    static int new[100][100];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            final.new[i][j]=a[count];
            count++;
        }

        printf("\n");
    }

    return(final);
}

int main()
{
    int n;
    printf("enter no. of elements you want to enter: ");
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int i=0,j=0;
    struct arr final;

    if(pow(sqrt(n),2)==n)
    {
        i=sqrt(n);
        j=sqrt(n);

        final=form(a,i,j);
    }
    else if(n%2==0)
    {
        i=n/2;
        j=2;

        final=form(a,i,j);
    }
    else
    {
        printf("not possible\n");
    }

    for(int m=0;m<i;m++)
    {
        for(int n=0;n<j;n++)
        {
            printf("%d ",final.new[m][n]);
        }

        printf("\n");
    }
    
    return(0);
}