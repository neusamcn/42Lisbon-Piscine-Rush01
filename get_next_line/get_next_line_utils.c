/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:40:10 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/30 21:03:07 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	s = (void *)ptr;
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	flowcheck;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	flowcheck = nmemb * size;
	if (flowcheck / nmemb == size)
	{
		ptr = malloc(nmemb * size);
		if (ptr == NULL)
			return (NULL);
		ft_bzero(ptr, size * nmemb);
		return (ptr);
	}
	return (NULL);
}

static char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chr;
	char			*p;

	i = 0;
	chr = (unsigned char)c;
	p = (char *)s;
	while (*(p + i))
	{
		if (*(p + i) == chr)
			return (p + i);
		i++;
	}
	if (chr == '\0')
		return (p + i);
	return (NULL);
}

static char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0 && src[ft_strlen(src)] == '\0')
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
static char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1len;
	char	*trimmed;

	if (!s1)
		return (NULL);
	i = 0;
	s1len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, (int)s1[i]) != NULL)
		i++;
	if (i == s1len)
	{
		trimmed = ft_calloc(1, 1);
		if (!trimmed)
			return (NULL);
		return (trimmed);
	}
	s1len--;
	while (s1[s1len] && ft_strrchr(set, (int)s1[s1len]) != NULL)
		s1len--;
	trimmed = malloc((s1len - i + 2) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + i, s1len - i + 2);
	return (trimmed);
}
size_t	nl_buffer(int fd)
{
	ssize_t	bytesread;
    size_t  bf_sz;
	char	*tmp_buffer;
	char	*line;
    char    *trim;

	bytesread = 0;
	tmp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return (0);
	bytesread = read(fd, tmp_buffer, BUFFER_SIZE);
	if (bytesread == 0 || bytesread == -1)
	{
		free(tmp_buffer);
		return (0);
	}
	tmp_buffer[bytesread] = '\0';
    printf("tmp_buffer: >>>%s<<<\n", tmp_buffer); // TESTING
    trim = ft_strchr(tmp_buffer, 10);
    printf("trim: >>>%s<<<\n", trim); // TESTING
	line = ft_strtrim(tmp_buffer, trim);
    printf("line: >>>%s<<<\n", line); // TESTING
	free(tmp_buffer);
    bf_sz = ft_strlen(line);
    printf("bf_sz: >>>%zu<<<\n", bf_sz); // TESTING
    free(line);
	return (bf_sz);
}
// FOR TESTING ONLY:
// int	main(void)
// {
// 	char	*file;
// 	char	*line;
// 	int		fd;

// 	file = "test.txt";
// 	fd = open(file, O_RDONLY);
// 	// file offset (mark of current position @ file) set to beginning of file.
// 	if (fd == -1)
// 		printf("fd = %d => cannot open '%s'\n", fd, file);
// 	else
// 		printf("fd = %d => '%s' will be opened successfully.\n-------------\n", fd, file);
// 	printf("%s\n", line = get_next_line(fd));
// 	free(line);
// 	printf("***** Next line: *****\n");
// 	printf("%s\n", line = get_next_line(fd));
// 	free(line);
// 	printf("***** Next line: *****\n");
// 	printf("%s\n", line = get_next_line(fd));
// 	free(line);
// 	close(fd);
// 	return (0);
// }