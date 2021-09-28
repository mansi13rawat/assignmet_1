#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char a[100];
    int dot=0;
    int e=0;
    printf("enter your number: ");
    scanf("%s",&a);

    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {

        }
        else if(a[i]=='.')
        {
            if(e!=0)
            {
                dot=-1;
                break;
            }
            else
            {
                if(dot==0 && i>0)
                {
                    dot=i;
                }
                else
                {
                    dot=-1;
                    break;
                }
            }
        }
        else if(a[i]='e')
        {
            e=i;
            if(i==strlen(a)-1 || i==0)
            {
                dot=-1;
                break;
            }
        }
        else
        {
            dot=-1;
            break;
        }
    }
    
    if(e==0 && dot==0)
    {
        printf("not valid\n");
    }
    else if(dot==-1)
    {
        printf("not valid\n");
    }
    else
    {
        printf("valid\n");
    }

    
    return(0);
}