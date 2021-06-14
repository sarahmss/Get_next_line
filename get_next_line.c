/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:37:27 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/14 16:32:02 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extra_strdup(const char *src, char c, int src_len)
{
	char	*new_str;
	int		i;

	new_str = malloc((sizeof (char)) * src_len + 1 );
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != c)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static int	ft_return(char **s_lines, char **line, ssize_t ret)
{
	t_positions	pos;

	if (ret < 0)
		return (-1);
	else if (ret == 0 && *s_lines == NULL)
		return (0);
	pos.len = 0;
	while ((*s_lines)[pos.len] != '\n' && (*s_lines)[pos.len] != '\0')
		pos.len++;
	if ((*s_lines)[pos.len] == '\n')
	{
		*line = ft_extra_strdup(*s_lines, '\n', pos.len);
		pos.stemp = ft_strdup(&((*s_lines)[pos.len + 1]), '\0');
		free(*s_lines);
		*s_lines = pos.stemp;
		if ((*s_lines)[0] == '\0')
			ft_free(s_lines);
	}
	else
	{
		*line = ft_strdup(*s_lines, '\0');
		ft_free(s_lines);
		return (0);
	}
	return (1);
}

ssize_t	ft_helper(int fd, char *buffer)
{
	ssize_t	i;

	i = 0;
	i = read(fd, buffer, BUFFER_SIZE);
	if (i < 0)
	{
		free(buffer);
		return (-1);
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{
	t_positions	pos;
	static char	*s_lines;
	ssize_t		ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	pos.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ret = 1;
	while (ret > 0)
	{
		ret = ft_helper(fd, pos.buffer);
		pos.buffer[ret] = '\0';
		if (s_lines == NULL)
			s_lines = ft_extra_strdup(pos.buffer, '\0', (BUFFER_SIZE + 1));
		else
		{
			pos.stemp = ft_strjoin(s_lines, pos.buffer);
			free(s_lines);
			s_lines = pos.stemp;
		}
		if (ft_strchr(pos.buffer, '\n'))
			break ;
	}
	free (pos.buffer);
	return (ft_return(&s_lines, line, ret));
}
