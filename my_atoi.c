// atoi user defined function

#include<stdio.h>
#include<limits.h>

int my_atoi(const char *);

int main(int argc , char **argv)
{
    int n ;

    if(argc != 2)
    {
        printf("usage: %s string \n\n",argv[0]);
        return 1;
    }

    n = my_atoi(argv[1]);

    printf("%d",n);

	printf("\n");
	return 0 ;
}

int my_atoi(const char *s)
{
    long long res = 0;
    int sign = 1;

    while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f' || *s == '\v')
        s++;

    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }

    while (*s >= '0' && *s <= '9')
    {
        res = res * 10 + (*s - '0');

        if (sign == 1 && res > INT_MAX)
            return INT_MAX;
        if (sign == -1 && -res < INT_MIN)
            return INT_MIN;

        s++;
    }

    return (int)(sign * res);
}
