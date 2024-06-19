/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:38 by braugust          #+#    #+#             */
/*   Updated: 2024/06/19 18:03:24 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include<stdlib.h>
# include<unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_get_line(char *buffer);
char	*ft_new_line(char *buffer);
char	*read_line(int fd, char *buffer);
char	*initialize_buffer(char *buffer, int bytes_read);
char	*append_to_buffer(char *buffer, char *buff);
int		read_and_update_buffer(int fd, char **buffer, char *buff);

#endif