/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:18:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/08 21:27:34 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#define BUFFER_SIZE 1000

t_label	*read_dict(char *dict_name)
{
	int		fd;
	char	*content;
	int		nb_entries;
	t_label	*dict;

	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Not able to open the file.", 27);
		return (NULL);
	}
	content = read_file(fd);
	close(fd);
	nb_entries = get_nb_entries(content);
	if (nb_entries == -1)
		return (NULL);
	dict = malloc(sizeof(*dict) * (nb_entries + 1));
	if (!dict)
		return (NULL);
	add_label_to_dict(content, dict, 0);
	free(content);
	dict[nb_entries].key = NULL;
	dict[nb_entries].label = NULL;
	return (dict);
}

void	free_dict(t_label	*dict)
{
	int	i;

	i = 0;
	while (dict[i].key)
	{
		free(dict[i].key);
		free(dict[i].label);
		i++;
	}
	free(dict);
	return ;
}

void	add_label_to_dict(char *str, t_label *dict, int index)
{
	char	*end;

	if (!*str)
		return ;
	while (*str == '\n')
		str++;
	end = str;
	while (*end && !(is_space(*end) || *end == ':'))
		end++;
	dict[index].key = str_cut(str, end);
	str = end;
	while (*str && (is_space(*str) || *str == ':'))
		str++;
	end = str;
	while (*end && *end != '\n')
		end++;
	dict[index].label = str_cut(str, end);
	add_label_to_dict(end + 1, dict, index + 1);
}

int	get_nb_entries(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == '\n')
			str++;
		if (is_entrie(str))
			count++;
		else
			return (-1);
		while (*str != '\n')
			str++;
		str++;
	}
	return (count);
}

char	*read_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*content;
	char	*next_content;
	int		buffer_len;
	int		i;

	i = 0;
	content = malloc(sizeof(*content));
	if (!content)
		return (NULL);
	next_content = content;
	content[0] = '\0';
	buffer_len = 1;
	while (buffer_len != 0)
	{
		buffer_len = read(fd, buffer, BUFFER_SIZE);
		next_content = str_cat(content, buffer, buffer_len);
		free(content);
		content = next_content;
	}
	return (content);
}
