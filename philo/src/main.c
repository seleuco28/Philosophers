/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:43:51 by alvelazq          #+#    #+#             */
/*   Updated: 2024/01/26 13:09:54 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_data_initializer(t_data *data, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	if (data->philo_num < 1 || data->philo_num > 200) //checkear lo de +200 el tutorial dice que no puede haber mas, el subject no lo dice
		ft_error_msg("Invalid number of philosophers\n");
	data->time_to_die = ft_atoi(av[2]); //los errores están controlados si pongo negativo
	if (data->time_to_die == 0)
		ft_error_msg("Time_to_die can't be 0\n");
	data->time_to_eat = ft_atoi(av[3]); //los errores están controlados si pongo negativo
	if (data->time_to_eat == 0)
		ft_error_msg("Time_to_eat can't be 0\n");
	data->time_to_sleep = ft_atoi(av[4]); //los errores están controlados si pongo negativo
	if (data->time_to_sleep == 0)
		ft_error_msg("Time_to_sleep can't be 0\n");	
	if (av[5])
		data->number_of_meals = ft_atoi(av[5]);
	else
		data->number_of_meals = -1;// controlar este fallo
}

void ft_philo_initializer(t_data *data) //falta ponerlo en el main
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

		ft_arg_num_checker(av); //checkear que el argumento es un numero
		ft_arg_count_checker(ac); //checkear que los args son 5 o 6
		ft_data_initializer(&data, av);
		//pruebas_printar_fecha(&data);
	return (0);
}