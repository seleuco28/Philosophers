/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:41:56 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/17 13:41:11 by alvelazq         ###   ########.fr       */
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
# include <pthread.h>

struct s_data;

typedef struct s_philo
{
	struct s_data *data; //PERMITE QUE CADA FILOSOFO ACCEDA A DATOS COMPARTIDOS
	int id;
} t_philo;

typedef struct s_data
{
    int	philo_num;
	int time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int number_of_meals;
	t_philo *philos;
} t_data;



/////////////////////// FUNCIOENS UTILES ///////////////
int	ft_error_msg(char *message);
int ft_arg_checker(char **av);
int	ft_atoi(const char *str);

#endif