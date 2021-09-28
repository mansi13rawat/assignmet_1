#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isalp(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int isdig(char c)
{
    if (c >= '0' && c <= '9')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int charpre(char c)
{
    if (c == '!' || c == '#' || c == '$' || c == '%' || c == '^' || c == '/' || c == '&' || c == '*' || c == '+' || c == '-' || c == '_' || c == '{' || c == '}' || c == '?' || c == '=' || c == '`' || c == '~' || c == '|')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void check(char e[])
{
    int at = -1;
    if (isalp(e[0]) == 0 && e[0]!='"' && isdig(e[0])==0)
    {
        printf("not valid");
    }
    else
    {
        int dot = -1;
        int q = -1;
        int count = 0;

        for (int i = 0; i < strlen(e); i++)
        {
            if (at == -1)
            {
                count++;
            }

            if (e[i] == '@')
            {
                if(count>64)
                {
                    at=-1;
                    break;
                }
                else if (at == -1)
                {
                    at = i;
                }
                else
                {
                    at = -1;
                    break;
                }
            }
            else if (e[i] == '.')
            {
                if (q == -1)
                {
                    if (e[i + 1] == '@' || e[i + 1] == '.')
                    {
                        at = -1;
                        break;
                    }
                }
                else
                {
                    if (q == 1 && at == -1)
                    {
                        dot = i;
                    }
                    else if (at != -1)
                    {
                        if (dot < at)
                        {
                            dot = i;
                        }
                        else if (dot > at && i > dot)
                        {
                            at = -1;
                            break;
                        }
                    }
                }
            }
            else if (e[i] == '"')
            {
                if (i == 0)
                {
                    q = 1;
                }
                else if (q == 1)
                {
                    if (dot == -1)
                    {
                        at = -1;
                        break;
                    }
                    else
                    {
                        dot = -1;
                    }
                }
                else
                {
                    if (e[i-1] != '/')
                    {
                        at = -1;
                        break;
                    }
                    else
                    {
                        q = 1;
                    }
                }
            }
            else
            {
                if (q == -1 && at == -1)
                {
                    if (isalp(e[i]) == 1 || isdig(e[i]) == 1 || charpre(e[i]) == 1)
                    {
                    }
                    else
                    {
                        at = -1;
                        break;
                    }
                }
                else if (at != -1)
                {
                    if (isalp(e[i]) == 1 || isdig(e[i]) == 1 || e[i] == '-')
                    {
                    }
                    else
                    {
                        at = -1;
                        break;
                    }
                }
            }
        }

        if (at == -1)
        {
            printf("not valid\n");
        }
        else
        {
            printf("valid\n");
        }
    }
}

int main()
{
    char a[100];
    printf("enter your email: ");
    scanf("%s", &a);

    check(a);
    return (0);
}