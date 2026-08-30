// atof user defined function

#include<stdio.h>

double my_atof(const char *);

int main(int argc , char **argv)
{
    double n ;

    if(argc != 2)
    {
        printf("usage: %s  string \n\n",argv[0]);
        return 1;
    }

    n = my_atof(argv[1]);

    printf("%f",n);

	printf("\n");
	return 0 ;
}

double my_atof(const char *s)
{
    double res = 0.0, power = 1.0 ; 
    int exp_sign = 1;
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
        s++;
    }

    if(*s == '.')
    {
        s++;

        while(*s >='0' && *s<='9')
        {
            res = res * 10.0 + (*s - '0');
            power = power * 10.0 ;

            s++ ;
        }

        res = res / power ;
    }

    return (double)(sign * res);
}
