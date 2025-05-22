/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalnaani <yalnaani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:01:45 by yalnaani          #+#    #+#             */
/*   Updated: 2024/12/06 15:42:50 by yalnaani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(const char *s, char c, size_t len)
{
	size_t	counter;
	size_t	i;
	size_t	j;

	counter = 0;
	i = 0;
	while (i < len)
	{
		while (i < len && s[i] == c)
			i++;
		j = i;
		while (i < len && s[i] != c)
			i++;
		if (i > j)
			counter++;
	}
	return (counter);
}

static void	free_split_strings(char **ptr, size_t count)
{
	while (count > 0)
		free(ptr[--count]);
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;
	size_t	x;

	x = 0;
	i = 0;
	ptr = ft_calloc((word_counter(s, c, ft_strlen(s)) + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(s))
	{
		while (i < ft_strlen(s) && s[i] == c)
			i++;
		j = i;
		while (i < ft_strlen(s) && s[i] != c)
			i++;
		if (i > j)
		{
			ptr[x++] = ft_substr(s, j, (i - j));
			if (!ptr[x - 1])
				return (free_split_strings(ptr, x - 1), NULL);
		}
	}
	return (ptr[x] = NULL, ptr);
}

/*#include <string.h>

void	print_array_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	main(void)
{
	char	*string;
	char	charset;
	char	**array;

	string = "^^^1^^2a,^^^^3^^^^--h^^^^";
	charset = '^';
	array = ft_split(string, charset);
	print_array_str(array);
	return (0);
}
*/