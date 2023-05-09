/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:09:06 by cacarval          #+#    #+#             */
/*   Updated: 2023/05/08 16:35:00 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *temp, int line_break)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i] != '\0')
	{
		if (temp[i] == (char)line_break)
			return ((char *)&temp[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *temp, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	i = -1;
	j = 0;
	if (!temp)
	{
		temp = (char *)malloc(1 * sizeof(char));
		temp[0] = '\0';
	}
	if (!temp || !buffer)
		return (NULL);
	strjoin = malloc((ft_strlen(temp) + ft_strlen(buffer)) + 1);
	if (!strjoin)
		return (NULL);
	while (temp[++i])
			strjoin[i] = temp[i];
	while (buffer[j])
		strjoin[i++] = buffer[j++];
	strjoin[i] = '\0';
	free(temp);
	return (strjoin);
}

char	*ft_get_line(char *temp)
{
	int		i;
	char	*str;

	i = 0;
	if (temp[i] == 0)
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
		str = malloc(sizeof(char) * (i + 1));
	else
		str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_new_temp(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (temp[i])
		str[j++] = temp[i++];
	str[j] = '\0';
	free(temp);
	return (str);
}
