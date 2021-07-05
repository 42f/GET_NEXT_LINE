/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:34:36 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/06 08:03:38 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_l
{
	int			fd;
	char		*ct;
	struct s_l	*next;
}				t_list;

int				get_next_line(int fd, char **line);
int				ft_read(int fd, t_list *fd_cursor, t_list *read_buffer_head);
int				ft_write_line(char **line, t_list *read_buffer_head);
t_list			*ft_create_node(int new_fd, char *content);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
t_list			*ft_lst_manager(t_list *cursor, int fd_to_find);
int				ft_gnl_from_fd(int fd, char **line, t_list *fd_cursor);
t_list			*ft_free_fd_cursor(t_list *fd_head, int fd);

#endif
