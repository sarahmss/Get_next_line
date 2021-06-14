/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:38:43 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/14 13:49:41 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/fcntl.h>

typedef struct s_positions
{
	char		*buffer;
	char		*stemp;
	int			len;
	int			len1;
	int			len2;
}	t_positions;

int		get_next_line(int fd, char **line);

char	*ft_strchr(const char *s, int c);

int		ft_strlen(const char *str, char n);

char	*ft_strdup(const char *src, char c);

char	*ft_strjoin(char const *s1, char const *s2);

void	ft_free(char **s_list);

#endif
