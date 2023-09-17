/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:43:51 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/17 13:31:56 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_data_initializer(t_data *data, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		data->number_of_meals = ft_atoi(av[5]);
		//printf("NUMERO DE COMIDAS: %d\n", data->number_of_meals);
	}
	else
		data->number_of_meals = -1;
	/*printf("el numero de filosofos es: %d\n", data->philo_num);
	printf("el time to die es: %d\n", data->time_to_die);
	printf("el time to eat es: %d\n", data->time_to_eat);
	printf("el time to sleep es: %d\n", data->time_to_sleep);
	printf("NUMERO DE COMIDAS: %d\n", data->number_of_meals);*/
}

void ft_philo_initializer(t_data *data)
{
	int i = 0;

	while (i < data->philo_num)
	{
		data->philos[i].id = i + 1; 
		i++;
	}
}

int main(int ac, char **av)
{
	t_data data;

	if (ac < 5 || ac > 6)
		ft_error_msg("Argumentos mal puestos, de mas o de menos");
	else
	{
		ft_arg_checker(av);
		ft_data_initializer(&data, av);
		
	}
	return 0;
}