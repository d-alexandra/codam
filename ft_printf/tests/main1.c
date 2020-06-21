#include <stdio.h>
#include "ft_printf.h"
#include "inttypes.h"
#include <stdarg.h>
#include <limits.h>

int main(void)
{
	int ptr = 1200;

	unsigned int ui = 424242;

	printf("24|%*.*d|\n", -12, -20, -3402);
    ft_printf ("24|%*.*d|\n", -12, -20, -3402);
    printf("\n");

    printf("25|%*.*d|\n", -12, -9, 3402);
    ft_printf ("25|%*.*d|\n", -12, -9, 3402);
    printf("\n");

	printf("26|%-*.*d|\n", -12, -20, 3402);
    ft_printf ("26|%-*.*d|\n", -12, -20, 3402);
    printf("\n");

    printf("27|%-*.*d|\n", -12, -9, 3402);
    ft_printf ("27|%-*.*d|\n", -12, -9, 3402);
    printf("\n");

	printf("11|%-*.*s|\n", -12, -9, "work");
    ft_printf ("11|%-*.*s|\n", -12, -9, "work");
    printf("\n");

	printf("12|%-*.*s|\n", -12, -20, "work");
    ft_printf ("12|%-*.*s|\n", -12, -20, "work");
    printf("\n");

	printf("13|%*.s|\n", -3, "hello");
    ft_printf("13|%*.s|\n", -3, "hello");
    printf("\n");

    printf("14|%*.s|\n", 3, "hello");
    ft_printf("14|%*.s|\n", 3, "hello");
    printf("\n");

    printf("15|%.*s|\n", -3, "hello");
    ft_printf("15|%.*s|\n", -3, "hello");
    printf("\n");
    
    printf("16|%.*s|\n", -7, "hello");
    ft_printf("16|%.*s|\n", -7, "hello");
    printf("\n");

	printf("17|%-8.3d|\n", -2464);
    ft_printf ("17|%-8.3d|\n", -2464);
    printf("\n");

	printf("18|%-*.*p|\n", -32, -29, &"work");
    ft_printf ("18|%-*.*p|\n", -32, -29, &"work");
    printf("\n");

	printf("19|%-*.*p|\n", -32, -60, &"work");
    ft_printf ("19|%-*.*p|\n", -32, -60, &"work");
    printf("\n");

	printf("20|%-*.*s|\n", -12, -9, "work");
    ft_printf ("20|%-*.*s|\n", -12, -9, "work");
    printf("\n");

	printf("21|%-*.*s|\n", -12, -20, "work");
    ft_printf ("21|%-*.*s|\n", -12, -20, "work");
    printf("\n");

	printf("22|%-*.*u|\n", -12, -9, 3402);
    ft_printf ("22|%-*.*u|\n", -12, -9, 3402);
    printf("\n");

	printf("23|%-*.*u|\n", -12, -20, 3402);
    ft_printf ("23|%-*.*u|\n", -12, -20, 3402);
    printf("\n");

	printf("24|%-*.*x|\n", -12, -9, 3402);
    ft_printf ("24|%-*.*x|\n", -12, -9, 3402);
    printf("\n");

	printf("25|%-*.*x|\n", -12, -20, 3402);
    ft_printf ("25|%-*.*x|\n", -12, -20, 3402);
    printf("\n");

    printf("26|%-*.*d|\n", -12, -20, 3402);
    ft_printf ("26|%-*.*d|\n", -12, -20, 3402);
    printf("\n");

    printf("27|%-*.*d|\n", -12, -9, 3402);
    ft_printf ("27|%-*.*d|\n", -12, -9, 3402);
    printf("\n");

	printf("1|%-*.c|\n", -3, 'c');
    ft_printf("1|%-*.c|\n", -3, 'c');
    printf("\n");

    printf("1|%-.*c|\n", -3, 'c');
    ft_printf("1|%-.*c|\n", -3, 'c');
    printf("\n");

    printf("1|%-*.c|\n", -3, 'c');
    ft_printf("1|%-*.c|\n", -3, 'c');
    printf("\n");

    printf("1|%-.*c|\n", -3, 'c');
    ft_printf("1|%-.*c|\n", -3, 'c');
    printf("\n");

	printf("14|%*.*c|\n", 1, -29, 'C');
    ft_printf ("14|%*.*c|\n", 1, -29, 'C');
    printf("\n");

	printf("15|%*.*c|\n", 10, -16, 'C');
    ft_printf ("15|%*.*c|\n", 10, -16, 'C');
    printf("\n");

	printf("16|%*.*c|\n", -32, -29, 'C');
    ft_printf ("16|%*.*c|\n", -32, -29, 'C');
    printf("\n");

	printf("17|%*.*c|\n", -32, -60, 'C');
    ft_printf ("17|%*.*c|\n", -32, -60, 'C');
    printf("\n");

	printf("18|%*.*p|\n", -32, -29, &"work");
    ft_printf ("18|%*.*p|\n", -32, -29, &"work");
    printf("\n");

	printf("19|%*.*p|\n", -32, -60, &"work");
    ft_printf ("19|%*.*p|\n", -32, -60, &"work");
    printf("\n");

	printf("20|%*.*s|\n", -12, -9, "work");
    ft_printf ("20|%*.*s|\n", -12, -9, "work");
    printf("\n");

	printf("21|%*.*s|\n", -12, -20, "work");
    ft_printf ("21|%*.*s|\n", -12, -20, "work");
    printf("\n");

	printf("22|%*.*u|\n", -12, -9, 3402);
    ft_printf ("22|%*.*u|\n", -12, -9, 3402);
    printf("\n");

	printf("23|%*.*u|\n", -12, -20, 3402);
    ft_printf ("23|%*.*u|\n", -12, -20, 3402);
    printf("\n");

	printf("24|%*.*x|\n", -12, -9, 3402);
    ft_printf ("24|%*.*x|\n", -12, -9, 3402);
    printf("\n");

	printf("25|%*.*x|\n", -12, -20, 3402);
    ft_printf ("25|%*.*x|\n", -12, -20, 3402);
    printf("\n");

    printf("26|%*.*d|\n", -12, -20, 3402);
    ft_printf ("26|%*.*d|\n", -12, -20, 3402);
    printf("\n");

	printf("0|%020x|\n", ui);
    ft_printf("0|%020x|\n", ui);
    printf("\n");

    printf("|%8.5x|\n", 34);
    ft_printf("|%8.5x|\n", 34);
    printf("\n");
     printf("|%8.5x|\n", 0);
    ft_printf("|%8.5x|\n", 0);
    printf("\n");
    printf("|%2.7x|\n", 3267);
    ft_printf("|%2.7x|\n", 3267);
    printf("\n");
    printf("|%-8.5x|\n", 34);
    ft_printf("|%-8.5x|\n", 34);
    printf("\n");
    printf("|%-2.7x|\n", 3267);
    ft_printf("|%-2.7x|\n", 3267);
    printf("\n");
    printf("|%08.5x|\n", 0);
    ft_printf("|%08.5x|\n", 0);
    printf("\n");
    printf("|%08.3x|\n", 8375);
    ft_printf("|%08.3x|\n", 8375);
    printf("\n");
    printf("|%02.7x|\n", 3267);
    ft_printf("|%02.7x|\n", 3267);
    printf("\n");
    printf("|%0-8.5x|\n", 34);
    ft_printf("|%0-8.5x|\n", 34);
    printf("\n");
    printf("|%0-8.5x|\n", 0);
    ft_printf("|%0-8.5x|\n", 0);
    printf("\n");
    printf("|%0-2.7x|\n", 3267);
    ft_printf("|%0-2.7x|\n", 3267);
    printf("\n");
    printf("|%.0x|\n", 0);
    ft_printf("|%.0x|\n", 0);
    printf("\n");
    printf("|%.x|\n", 0);
    ft_printf("|%.x|\n", 0);
    printf("\n");
    printf("|%5.0x|\n", 0);
    ft_printf("|%5.0x|\n", 0);
    printf("\n");
    printf("|%5.x|\n", 0);
    ft_printf("|%5.x|\n", 0);
    printf("\n");
    printf("|%-5.x|\n", 0);
    ft_printf("|%-5.x|\n", 0);
    printf("\n");
    printf("|%8.5x|\n", 34);
    ft_printf("|%8.5x|\n", 34);
    printf("\n");
    printf("|%2.7x|\n", 3267);
    ft_printf("|%2.7x|\n", 3267);
    printf("\n");
    printf("|%-8.5x|\n", 0);
    ft_printf("|%-8.5x|\n", 0);
    printf("\n");
     printf("|%-2.7x|\n", 3267);
    ft_printf("|%-2.7x|\n", 3267);
    printf("\n");
    printf("|%08.5x|\n", 34);
    ft_printf("|%08.5x|\n", 34);
    printf("\n");
    printf("|%08.5x|\n", 34);
    ft_printf("|%08.5x|\n", 34);
    printf("\n");
    printf("|%08.3x|\n", 8375);
    ft_printf("|%08.3x|\n", 8375);
    printf("\n");
    printf("|%02.7X|\n", 3267);
    ft_printf("|%02.7X|\n", 3267);
    printf("\n");
    printf("|%0-8.5X|\n", 34);
    ft_printf("|%0-8.5X|\n", 34);
    printf("\n");
    printf("|%0-8.5X|\n", 0);
    ft_printf("|%0-8.5X|\n",0);
    printf("\n");
    printf("|%0-2.7X|\n", 3267);
    ft_printf("|%0-2.7X|\n", 3267);
    printf("\n");
    printf("|%.0X|\n", 0);
    ft_printf("|%.0X|\n", 0);
    printf("\n");
    printf("|%.X|\n", 0);
    ft_printf("|%.X|\n", 0);
    printf("\n");
     printf("|%5.0X|\n", 0);
    ft_printf("|%5.0X|\n", 0);
    printf("\n");
    printf("|%5.X|\n", 0);
    ft_printf("|%5.X|\n", 0);
    printf("\n");
    printf("|%-5.X|\n", 0);
    ft_printf("|%-5.X|\n", 0);
    printf("\n");
    printf("|%-5.0X|\n", 0);
    ft_printf("|%-5.0X|\n", 0);
    printf("\n");

	printf("0|%-30.10i|\n", -12345);
    ft_printf("0|%-30.10i|\n", -12345);
    printf("\n");

    printf("0|%30.10i|\n", -12345);
    ft_printf("0|%30.10i|\n", -12345);
    printf("\n");

	printf("0|%021s|\n", NULL);
    ft_printf("0|%021s|\n", NULL);
    printf("\n");

    printf("26|%*.*d|\n", 12, 20, 3402);
    ft_printf ("26|%*.*d|\n", 12, 20, 3402);

    printf("26|%*.*d|\n", 20, 12, 3402);
    ft_printf ("26|%*.*d|\n", 20, 12, 3402);

    printf("26|%-8.3d|\n", -2464);
    ft_printf ("26|%-8.3d|\n", -2464);

	printf("0|%*c|\n", 0, 'c');
    ft_printf("0|%*c|\n", 0, 'c');
    printf("\n");

    printf("0|%-*c|\n", 3, 'c');
    ft_printf("0|%-*c|\n", 3, 'c');
    printf("\n");

	printf("0|%*c|\n", -10, 'c');
    ft_printf("0|%*c|\n", -10, 'c');
    printf("\n");

    printf("1|%*.c|\n", -3, 'c');
    ft_printf("1|%*.c|\n", -3, 'c');
    printf("\n");

    printf("1|%.*c|\n", -3, 'c');
    ft_printf("1|%.*c|\n", -3, 'c');
    printf("\n");

    printf("\n");

    printf("0|%8.5x|\n", 0);
    ft_printf("0|%8.5x|\n", 0);
    printf("\n");

    printf("0|%08.5x|\n", 0);
    ft_printf("0|%08.5x|\n", 0);
    printf("\n");

    printf("0|%-8.5x|\n", 0);
    ft_printf("0|%-8.5x|\n", 0);
    printf("\n");

    printf("0|%*p|\n", -32, &ptr);
    ft_printf("0|%*p|\n", -32, &ptr);
    printf("\n");

    printf("0|%-*p|\n", -32, &ptr);
    ft_printf("0|%-*p|\n", -32, &ptr);
    printf("\n");
    
    printf("1|%*.p|\n", -3, &ptr);
    ft_printf("1|%*.p|\n", -3, &ptr);
    printf("\n");
    
    printf("2|%.*p|\n", -7, &ptr);
    ft_printf("2|%.*p|\n", -7, &ptr);
    printf("\n");
    
    printf("3|%*p|\n", -3, &ptr);
    ft_printf("3|%*p|\n", -3, &ptr);
    printf("\n");
    
    printf("4|%-*.*p|\n", -7, -3, &ptr);
    ft_printf("4|%-*.*p|\n", -7, -3, &ptr);
    printf("\n");

    printf("5|%-*.*p|\n", -3, -7, &ptr);
    ft_printf("5|%-*.*p|\n", -3, -7, &ptr);
    printf("\n");
    
    printf("6|%*p|\n", -14, &ptr);
    ft_printf("6|%*p|\n", -14, &ptr);
    printf("\n");
    
    printf("7|%0*p|\n", -7, &ptr);
    ft_printf("7|%0*p|\n", -7, &ptr);
    printf("\n");

    printf("8|%-*.*p|\n", -7, -3, &ptr);
    ft_printf("8|%-*.*p|\n", -7, -3, &ptr);
    printf("\n");

    printf("9|%-*.*p|\n", -3, -7, &ptr);
    ft_printf("9|%-*.*p|\n", -3, -7, &ptr);
    printf("\n");
    
    printf("10|%*p|\n", -14, &ptr);
    ft_printf("10|%*p|\n", -14, &ptr);
    printf("\n");
    
    printf("11|%*.*p|\n", 0, 0, &ptr);
    ft_printf("11|%*.*p|\n", 0, 0, &ptr);

	return (0);
}
