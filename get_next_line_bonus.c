/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:19:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/06 08:03:49 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_create_node(int new_fd, char *ct)
{
	t_list			*new_node;
	int				i;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = new_fd;
	new_node->next = NULL;
	new_node->ct = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new_node->ct == NULL)
		return (NULL);
	i = 0;
	if (ct != NULL)
		ft_strlcpy(new_node->ct, ct, BUFFER_SIZE + 1);
	else
	{
		while (i < BUFFER_SIZE + 1)
		{
			new_node->ct[i] = '\0';
			i++;
		}
	}
	return (new_node);
}

int		ft_read(int fd, t_list *fd_cursor, t_list *read_buffer_head)
{
	int				ret;
	t_list			*buff;

	if (read_buffer_head != NULL && read_buffer_head->ct[0] == '\0')
		buff = read_buffer_head;
	else
	{
		read_buffer_head->next = ft_create_node(-1, NULL);
		buff = read_buffer_head->next;
	}
	ret = 1;
	while (ret > 0)
	{
		if (buff == NULL || (ret = read(fd, buff->ct, BUFFER_SIZE)) < 0)
			return (-1);
		buff->ct[ret] = '\0';
		if (ft_strchr(buff->ct, '\n') != NULL)
			break ;
		buff->next = ft_create_node(-1, NULL);
		buff = buff->next;
	}
	ft_strlcpy(fd_cursor->ct, ft_strchr(buff->ct, '\n'), BUFFER_SIZE);
	if (ret <= BUFFER_SIZE && ret > 0)
		ret = 1;
	return (ret);
}

int		ft_write_line(char **line, t_list *read_buffer_head)
{
	size_t			dst_size;
	size_t			buff_len;
	t_list			*cursor;

	cursor = read_buffer_head;
	buff_len = 0;
	while (cursor != NULL)
	{
		cursor = cursor->next;
		buff_len++;
	}
	dst_size = BUFFER_SIZE * buff_len + 1;
	if ((*line = (char *)malloc(sizeof(char) * (dst_size + 1))) == NULL)
		return (-1);
	*line[0] = '\0';
	while (read_buffer_head != NULL)
	{
		ft_strlcat(*line, read_buffer_head->ct, dst_size);
		if (read_buffer_head->fd < 0)
			read_buffer_head = read_buffer_head->next;
		else
			break ;
	}
	return (1);
}

int		ft_gnl_from_fd(int fd, char **line, t_list *fd_cursor)
{
	int				ret;
	t_list			*read_buffer_head;
	t_list			*next;

	ret = 0;
	read_buffer_head = ft_create_node(-1, fd_cursor->ct);
	if (read_buffer_head == NULL)
		return (-1);
	ret = ft_read(fd, fd_cursor, read_buffer_head);
	if (ft_write_line(line, read_buffer_head) == -1)
		ret = -1;
	while (read_buffer_head != NULL)
	{
		next = read_buffer_head->next;
		free(read_buffer_head->ct);
		free(read_buffer_head);
		read_buffer_head = next;
	}
	free(read_buffer_head);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	static	t_list	*fd_head;
	t_list			*fd_cursor;

	ret = -1;
	if (BUFFER_SIZE <= 0 || line == NULL || fd < 0)
		return (-1);
	if (fd_head == NULL)
		if ((fd_head = ft_create_node(fd, NULL)) == NULL)
			return (-1);
	fd_cursor = ft_lst_manager(fd_head, fd);
	if (fd_cursor != NULL && ft_strchr(fd_cursor->ct, '\n') != NULL)
	{
		if ((ret = ft_write_line(line, fd_cursor)) == -1)
			return (-1);
		ft_strlcpy(fd_cursor->ct, ft_strchr(fd_cursor->ct, '\n'), BUFFER_SIZE);
	}
	else if (fd_cursor != NULL)
		ret = ft_gnl_from_fd(fd, line, fd_cursor);
	if (ret < 1)
		fd_head = ft_free_fd_cursor(fd_head, fd);
	return (ret);
}
