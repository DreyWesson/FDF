/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conyejib <conyejib@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:03:02 by conyejib          #+#    #+#             */
/*   Updated: 2022/08/28 01:03:02 by conyejib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_text(char *find)
{
	char	*text;

	text = ft_strchr2(find, '\n');
	if (!text)
	{
		free(find);
		return (0);
	}
	if (*(text + 1))
		text = ft_strdup2(text + 1);
	else
		text = NULL;
	free(find);
	return (text);
}

char	*get_next_line(int fd)
{
	static char		*statchar;
	char			*actualbyte;
	char			line[BUFFER_SIZE + 1];
	int				size;

	size = read(fd, line, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	line[size] = '\0';
	while (size > 0)
	{
		if (!statchar)
			statchar = ft_strdup2(line);
		else
			statchar = ft_strjoin2(statchar, line);
		if (ft_strchr2(line, '\n'))
			break ;
		size = read(fd, line, BUFFER_SIZE);
		line[size] = '\0';
	}
	actualbyte = ft_substr2(statchar, 0, ft_strchr2(statchar, '\n')
			- statchar + 1);
	statchar = find_text(statchar);
	return (actualbyte);
}
