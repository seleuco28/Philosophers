/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:53:08 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/21 19:16:57 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_arg_num_checker(char **av)
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
				ft_error_msg("ERROR: Invalid argv, please try again\n");
			j++;
		}
		i++;
	}
}

void ft_arg_count_checker(int ac)
{
	if (ac < 5)
		ft_error_msg("ERROR: Too few arguments\n");
	else if (ac > 6)
		ft_error_msg("ERROR: Too many arguments\n");
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

u_int64_t	get_time(void) //TE DEVUELVE EL TIEMPO ACTUAL EN MILISEGUNDOS
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ft_error_msg("Error getting the time\n"));
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void pruebas_printar_fecha(t_data *data)
{
	int time;
    data->start_time = get_time();
	time = data->start_time - get_time();
    printf("La hora que printa es: %d", time);
}