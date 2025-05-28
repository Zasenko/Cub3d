/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitryzasenko <dmitryzasenko@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:04:22 by dzasenko          #+#    #+#             */
/*   Updated: 2025/05/28 08:00:23 by dmitryzasen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "m_parser.h"

int	allocate_buf_str(char **buf, char **str)
{
	if (!buf || !str)
		return (ft_putstr_fd("Error\n", 2), 0);
	*buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (*buf == NULL)
		return (ft_putstr_fd("Error\nMalloc\n", 2), 0);
	*str = (char *)malloc(sizeof(char));
	if (*str == NULL)
		return (free_str(buf), ft_putstr_fd("Error\nMalloc\n", 2), 0);
	(*str)[0] = '\0';
	return (1);
}

int	check_file_name(char *file_name)
{
	size_t	len;

	if (!file_name)
		return (ft_putstr_fd("Error\n", 2), 0);
	len = ft_strlen(file_name);
	if (len < 4)
	{
		ft_putstr_fd("Error\nIcorrect file name (expected fileName.cub)\n", 2);
		return (0);
	}
	if (ft_strcmp(&file_name[len - 4], ".cub"))
	{
		ft_putstr_fd("Error\nInvalid file extension (expected .cub)\n", 2);
		return (0);
	}
	return (1);
}

char	*read_file(int fd)
{
	char	*str;
	char	*buf;
	char	*temp;
	int		buf_count;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (ft_putstr_fd("Error\n", 2), NULL);
	if (!allocate_buf_str(&buf, &str))
		return (NULL);
	buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
	while (buf_count > 0)
	{
		buf[buf_count] = '\0';
		temp = ft_strjoin(str, buf);
		if (!temp)
			return (free_str(&buf), free_str(&str), NULL);
		free_str(&str);
		str = temp;
		buf_count = read(fd, buf, sizeof(char) * BUFFER_SIZE);
	}
	if (buf_count < 0)
		return (free_str(&buf), free_str(&str), NULL);
	return (free_str(&buf), str);
}

char	*read_from_file(char *file_name)
{
	int		fd;
	char	*str;

	if (!check_file_name(file_name))
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCan't open the file\n", 2);
		return (NULL);
	}
	str = read_file(fd);
	close(fd);
	if (!str)
		return (NULL);
	return (str);
}
