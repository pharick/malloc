/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:20:28 by cbelva            #+#    #+#             */
/*   Updated: 2020/12/21 17:20:45 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tokens_len(char **tokens)
{
	int	i;

	i = 0;
	while (*tokens)
	{
		i++;
		tokens++;
	}
	return (i);
}