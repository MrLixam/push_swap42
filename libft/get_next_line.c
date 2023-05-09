/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:12:17 by lvincent          #+#    #+#             */
/*   Updated: 2022/12/29 17:31:39 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*rv;

	if (!s1)
	{
		rv = malloc(ft_strlen(s2) + 1);
		if (!rv)
			return (NULL);
		rv[ft_strlen(s2)] = '\0';
		ft_memcpy(rv, s2, ft_strlen(s2));
		return (rv);
	}
	if (!s2)
		return (s1);
	rv = malloc(1 + ft_strlen(s1) + ft_strlen(s2));
	if (!rv)
		return (NULL);
	ft_memcpy(rv, s1, ft_strlen(s1));
	ft_memcpy(rv + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	if (rv[ft_strlen(s1) + ft_strlen(s2)] != '\0')
		rv[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (rv);
}

static char	*read_mini_line(char *save, int fd)
{
	char	*tmp;
	int		b_read;

	b_read = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(save, '\n') && b_read != 0)
	{
		b_read = read(fd, tmp, BUFFER_SIZE);
		if (b_read == -1 || (b_read == 0 && ft_strlen(save) == 0))
		{
			free(tmp);
			free(save);
			return (NULL);
		}
		tmp[b_read] = '\0';
		save = ft_strjoin_gnl(save, tmp);
	}
	free(tmp);
	return (save);
}

static char	*get_curr_line(char *save)
{
	int		i;
	char	*rv;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	rv = malloc(i + 2);
	if (!rv)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		rv[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		rv[i] = save[i];
		i++;
	}
	rv[i] = '\0';
	return (rv);
}

static char	*new_save(char *save)
{
	char	*rv;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (ft_strlen(save) - i + 1 <= 1)
	{
		free(save);
		return (NULL);
	}
	rv = malloc(ft_strlen(save) - i + 1);
	if (!rv)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		rv[j++] = save[i++];
	rv[j] = '\0';
	free(save);
	return (rv);
}

char	*get_next_line(int fd)
{
	static char	*save[1024] = {NULL};
	char		*buffer;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	save[fd] = read_mini_line(save[fd], fd);
	if (!save[fd])
		return (NULL);
	buffer = get_curr_line(save[fd]);
	save[fd] = new_save(save[fd]);
	return (buffer);
}
