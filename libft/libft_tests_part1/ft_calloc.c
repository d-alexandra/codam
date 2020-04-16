/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:27:07 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/16 14:11:50 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
	void *new_arr;

	new_arr = malloc(count*size);
	if (new_arr == NULL)
		return (NULL);
	else
		bzero(new_arr, (count*size));
	return (new_arr);
}

int main()
{
	int i, n;
	int *a;

	printf("Number of elements to be entered:");
	scanf("%d", &n);

	a = (int *)ft_calloc(n, sizeof(int));
	printf("Enter %d numbers: \n", n);
	i = 0;
   	while (i < n)
	{
		scanf("%d", &a[i]);
		i++;
	}
	printf("The numbers entered are: ");
	i = 0; 
	while (i < n)
	{
		printf("%d\n", a[i]);
		i++;
	}	
	free(a);
	return (0);
}
