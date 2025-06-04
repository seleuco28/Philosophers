/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:33:09 by alvelazq          #+#    #+#             */
/*   Updated: 2025/05/08 17:33:48 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h> //libreria especifica para hilos
# include <sys/time.h>
struct s_data;

typedef struct s_philo //data de cada filosofo en particular
{
	struct s_data *data; //PERMITE QUE CADA FILOSOFO ACCEDA A DATOS COMPARTIDOS
	pthread_t philo_thread;
	int id;
	int eating;
	int thinking;
	int sleeping;
	int alive;
} t_philo;

typedef struct s_data //data del programa en general
{
    int	philo_num;
	u_int64_t time_to_die;
	u_int64_t time_to_eat;
	u_int64_t time_to_sleep;
	int number_of_meals;
	u_int64_t start_time;
	t_philo *philos;
} t_data;



/////////////////////// FUNCIOENS UTILES ///////////////
int	ft_error_msg(char *message);
int	ft_atoi(const char *str);

void ft_arg_num_checker(char **av);
void ft_arg_count_checker(int ac);

void pruebas_printar_fecha(t_data *data);

#endif