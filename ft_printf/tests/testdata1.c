#include <stdio.h>
#include "ft_printf.h"
#include "inttypes.h"
#include <stdarg.h>
#include <limits.h>

int main()
{
	int i = -13345;
	printf("188-NOK|%.*s|\n", -3, "hello");
	ft_printf("188-NOK|%.*s|\n", -3, "hello");
	printf("\n");
	ft_printf("--------------\n");
	ft_printf("70B-NOK|%#*i\n",12, i);
	printf("70B-NOK|%#*i\n", 12, i);
	ft_printf("--------------\n");
	printf("\n");
	ft_printf("36|%40.20i|\n", i); 
	printf("36|%40.20i|\n", i);
	
	unsigned int ui = 424242;
	printf("7|%p|\n", (void*)ULONG_MAX + 1);
	ft_printf("7|%p|\n", (void*)ULONG_MAX + 1);
	printf("\n");
	ft_printf("--------------\n");
	ft_printf("64|%.20p|\n", &ui);
	printf("64|%.20p|\n", &ui);
	ft_printf("--------------\n");
	ft_printf("65|%*p|\n", -10, &ui);
	printf("65|%*p|\n", -10, &ui);
	ft_printf("--------------\n");
	ft_printf("66|%-015p|\n", &ui);
	printf("66|%-015p|\n", &ui);
	ft_printf("--------------\n");
	ft_printf("67|%-30p|\n", &ui);
	printf("67|%-30p|\n", &ui); 
	ft_printf("--------------\n");
	ft_printf("68|%-30.40p|\n", &ui);
	printf("68|%-30.40p|\n", &ui); 
	ft_printf("69|%p|\n", &ui);
	printf("69|%p|\n", &ui); 
	ft_printf("--------------\n");
	ft_printf("68|%-30.40p|\n", &ui);
	printf("68|%-30.40p|\n", &ui); 
	ft_printf("--------------\n");
	ft_printf("68|%30.40p|\n", &ui);
	printf("68|%30.40p|\n", &ui); 
	ft_printf("--------------\n");
	ft_printf("68|%-30.20p|\n", &ui);
	printf("68|%-30.20p|\n", &ui); 
	ft_printf("--------------\n");
	ft_printf("68|%30.20p|\n", &ui);
	printf("68|%30.20p|\n", &ui); 
	ft_printf("--------------\n");
	ft_printf("68|%*.*p|\n", -30, -40, &ui);
	printf("68|%*.*p|\n", -30, -40, &ui);
	ft_printf("--------------\n");
	ft_printf("68|%-*.*p|\n", 30, 40, &ui);
	printf("68|%-*.*p|\n", 30, 40, &ui);
	ft_printf("--------------\n");
	ft_printf("68|%-*.*p|\n", -30, -40, &ui);
	printf("68|%-*.*p|\n", -30, -40, &ui);
	ft_printf("--------------\n");
	
	return (0);
}  
