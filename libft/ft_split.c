/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:08:48 by cbelva            #+#    #+#             */
/*   Updated: 2021/04/09 14:08:22 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_tokens(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_get_token(const char **s, char c)
{
	char	*token;
	char	*iter;
	int		len;

	while (**s == c)
		(*s)++;
	len = 1;
	while ((*(*s + len) != c) && *(*s + len))
		len++;
	token = (char *)malloc((len + 1) * sizeof(char));
	iter = token;
	while ((**s != c) && **s)
		*(iter++) = *((*s)++);
	*iter = '\0';
	(*s)++;
	return (token);
}

char	**ft_split(char const *s, char c)
{
	char	**tokens;
	int		count;
	int		i;

	if (s == NULL)
		return (NULL);
	count = ft_count_tokens(s, c);
	tokens = (char **)malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		tokens[i] = ft_get_token(&s, c);
		if (tokens[i] == NULL)
		{
			ft_free_ntokens(tokens, i);
			return (NULL);
		}
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
