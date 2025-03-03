/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:33:25 by mmendiol          #+#    #+#             */
/*   Updated: 2024/04/25 14:20:38 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strchr_bool(const char *s, int c)
{
	size_t			i;
	unsigned char	character;

	i = 0;
	character = (unsigned char)c;
	if (character == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == character)
			return (1);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	*p;

// 	p = "Hola Mundo";
// 	printf("Funcion: %s", ft_strchr_bool(p, 'a'));
// 	return (0);
// }
