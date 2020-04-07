/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:57:23 by asolopov          #+#    #+#             */
/*   Updated: 2020/04/06 07:32:13 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void	err_exit(char *msg)
{
	perror(msg);
	exit(0);
}

void	del_char_array(char **array)
{
	int cnt;
	
	cnt = 0;
	while (array[cnt])
	{
		ft_strdel(&(array[cnt]));
		cnt += 1;
	}
}
