/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iterative_factorial.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 17:15:47 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/11 17:56:14 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int nb;
	int i;
	
	if (nb < 0)
		return 0;
	if (nb == 0)
		return 1;
	else
	{  
		int i = 0;
		int f = 1;
		while (i < nb)
		{
			
			i = i + 1;
			f = f * i;
		} 
		return f;
	}
}

int main (void)
{
	ft_iterative_factorial(6);
	return (0);
}
