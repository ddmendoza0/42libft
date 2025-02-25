/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:23:24 by dmendoza          #+#    #+#             */
/*   Updated: 2025/02/25 13:24:57 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * str 		= string to tokenize or NULL to continue with las string.
 * delimmiters 	= string containing the delim characters.
 * return	= pointer to the next token or NULL if no more tokens.
 */

#include "libft.h"

static int	is_delimiter(char c, const char *delimiters)
{
	while (*delimiters)
	{
		if (c == *delimiters)
			return (1);
		delimiters++;
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delimiters)
{
	static char	*next_token;
	char		*token_start;

	if (str)
		next_token = str;
	if (!next_token || !*next_token)
		return (NULL);
	while (*next_token && is_delimiter(*next_token, delimiters))
		next_token++;
	if (!*next_token)
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token;
	while (*next_token && !is_delimiter(*next_token, delimiters))
		next_token++;
	if (*next_token)
	{
		*next_token = '\0';
		next_token++;
	}
	return (token_start);
}
