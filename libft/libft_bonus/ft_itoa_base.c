#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>


char		*ft_itoa_base(int num, int base)
{
	static char	*str;
    static char buffer[100];
	char    *ptr;

	str = "0123456789abcdef";
    ptr = &buffer[99];
    *ptr = '\0';
   if (num == 0)
		*ptr = str[num%base];
	while (num != 0)
	{
        ptr--;
		*ptr = str[num%base];
		num /= base;
	}
    if (num < 0 && base == 10)
        *ptr = '-';
	return (ptr);
}

int main (void)
{
    unsigned int ui = 540000;
    char *str;

    str = ft_itoa_base(ui, 16);
    printf("%s\n", str);
    printf("---\n");
    printf("%x\n", ui);
    
    return (0);
}