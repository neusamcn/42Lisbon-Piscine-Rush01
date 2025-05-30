/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/30 21:32:47 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	ssize_t	bytesread;
	size_t	bf_sz;
	char	*buffer;
	char	*line;
	int	i;

	// bf_sz = nl_buffer(fd);
	// if (bf_sz == 0)
	// 	return (NULL);
	// buffer = malloc(bf_sz * sizeof(char));
	// if (!buffer)
	// 	return (NULL);
	// bytesread = read(fd, buffer, bf_sz - 1);
	// buffer[bf_sz] = '\0';

	bytesread = 0;
	bf_sz = 0;
	i = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (*buffer != '\n' && bf_sz <= BUFFER_SIZE)
	{
		bytesread = read(fd, buffer, bf_sz++);
		line[i] = buffer;
	}
	printf("bytesread: %zu\n", bytesread);
	line[bytesread] = '\n';
	line[bytesread + 1] = '\0';
	return (line);
}
// FOR TESTING ONLY:
int	main(void)
{
	char	*file;
	char	*line;
	int		fd;

	file = "test.txt";
	fd = open(file, O_RDONLY);
	// file offset (mark of current position @ file) set to beginning of file.
	if (fd == -1)
		printf("fd = %d => cannot open '%s'\n", fd, file);
	else
		printf("fd = %d => '%s' will be opened successfully.\n-------------\n", fd, file);
	printf("%s\n", line = get_next_line(fd));
	free(line);
	printf("***** Next line: *****\n");
	printf("%s\n", line = get_next_line(fd));
	free(line);
	printf("***** Next line: *****\n");
	printf("%s\n", line = get_next_line(fd));
	free(line);
	close(fd);
	return (0);
}

// int	main(void)
// {
// 	char *file = "test.txt";
// 	int fd = open(file, O_RDONLY);
// 	// file offset (mark of current position @ file) set to beginning of file.
// 	char *line = ;

// 	if (fd == -1)
// 		printf("fd = %d => cannot open '%s'\n", fd, file);
// 	else
// 		printf("fd = %d => '%s' will be opened successfully.\n\n", fd, file);
// 	while (line != NULL)
// 	{
// 		printf("***** Next line: *****\n");
// 		printf("%s\n", line);
// 	}
// 	close(fd);
// 	return (0);
// }