/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:09:31 by chughes           #+#    #+#             */
/*   Updated: 2022/09/10 14:13:09 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Allocates and zeros nitems * size bytes
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*rtnptr;

	rtnptr = malloc(nitems * size);
	if (rtnptr == NULL)
		return (NULL);
	memset(rtnptr, 0, (nitems * size));
	return (rtnptr);
}
