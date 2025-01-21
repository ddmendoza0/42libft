/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:11:19 by dmendoza          #+#    #+#             */
/*   Updated: 2025/01/21 11:04:43 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_joinfree(char *stack, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stack, buffer);
	free(stack);
	return (tmp);
}

static char	*ft_next_line(char *stack)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(stack) - i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (stack[i])
		line[j++] = stack[i++];
	line [j] = '\0';
	free(stack);
	return (line);
}

static char	*ft_new_line(char *stack)
{
	char	*line;
	int		i;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *stack)
{
	char	*buffer;
	int		byte_read;

	if (!stack)
		stack = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			free(stack);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		stack = ft_joinfree(stack, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack[fd] = ft_read(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);
	line = ft_new_line(stack[fd]);
	stack[fd] = ft_next_line(stack[fd]);
	return (line);
}
