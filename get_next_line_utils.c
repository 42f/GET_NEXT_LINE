/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:34:40 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/04 16:05:36 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_free_fd_cursor(t_list *fd_head, int fd)
{
	t_list			*fd_cursor;
	t_list			*fd_next;

	fd_cursor = fd_head;
	fd_next = fd_cursor;
	while (fd_next != NULL)
	{
		if (fd_next->fd != fd)
		{
			fd_cursor = fd_next;
			fd_next = fd_cursor->next;
			continue ;
		}
		if (fd_next == fd_head)
			fd_head = fd_next->next;
		else
			fd_cursor->next = fd_next->next;
		free(fd_next->ct);
		free(fd_next);
		break ;
	}
	return (fd_head);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_len;
	size_t			src_len;
	size_t			ret;
	int				i;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	ret = src_len + dst_len;
	while (dst_len < dstsize - 1 && src[i] != '\0' && src[i] != '\n')
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (ret);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			len;

	if (!dst || !src)
		return (0);
	len = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i + 1));
		i++;
	}
	return (NULL);
}

t_list	*ft_lst_manager(t_list *cursor, int fd_to_find)
{
	while (cursor != NULL)
	{
		if (cursor->fd == fd_to_find)
			return (cursor);
		if (cursor->next != NULL)
			cursor = cursor->next;
		else
			break ;
	}
	cursor->next = ft_create_node(fd_to_find, NULL);
	return (cursor->next);
}
