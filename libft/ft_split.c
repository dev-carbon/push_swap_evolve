/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:13:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 14:41:32 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	len;
	int	nb;
	int	is_word;

	i = 0;
	nb = 0;
	len = ft_strlen((char *)s);
	while (i < len && s[i] != '\0')
	{
		is_word = 0;
		while (s[i] != c && i < len)
		{
			is_word = 1;
			i++;
		}
		nb += is_word;
		i++;
	}
	return (nb);
}

static char	*copy_word(char *dst, char *src, char c)
{
	int	i;

	i = 0;
	while (*src != c && *src != '\0')
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char *s, char c)
{
	int		k;
	int		word_len;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	k = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		word_len = 0;
		while (s[word_len] != c && s[word_len] != '\0')
			word_len++;
		if (word_len > 0)
		{
			tab[k] = ft_strnew(word_len);
			tab[k] = copy_word(tab[k], s, c);
			k++;
		}
		s += word_len;
	}
	tab[k] = NULL;
	return (tab);
}
