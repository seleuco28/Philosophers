/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:53:08 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/17 11:21:44 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_arg_checker(char **av)
{
	int i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9')) //si en algun momento no es numero
				ft_error_msg("Invalid argv, please try again\n");
			j++;
		}
		i++;
	}
	return(0);
}

int	ft_error_msg(char *message)
{
	printf("%s", message);
	exit(0); //pongo algun otro numero??¿ O EXIT_FAILURE¿?¿?
}

int	ft_atoi(const char *str)
{
	long int	resultado;
	long int	signo;

	resultado = 0;
	signo = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signo *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (signo * resultado > 2147483647)
			return (-1);
		else if (signo * resultado < -2147483648)
			return (-2); //le he cambiado esto, antes ponia return(0)
		resultado = resultado * 10 + *str - '0';
		str++;
	}
	return (signo * resultado);
}