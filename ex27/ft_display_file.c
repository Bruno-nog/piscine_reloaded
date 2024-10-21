/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:02:34 by brunogue          #+#    #+#             */
/*   Updated: 2024/10/09 18:01:50 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c, int std)
{
	write(std, &c, 1);
}

void	ft_putstr(char *str, int std)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], std);
}

int	show_char(char **argv)
{
	char	temp[1];
	int		fd;
	int		ret;

	ret = 1;
	fd = open(argv[1], O_RDONLY); O
	if (fd == -1)
		return (0);
	while (ret > 0)
	{
		ret = read(fd, temp, 1);
		if (ret == -1)
			return (0);
		if (ret > 0)
			ft_putchar(temp[0], 1);
	}
	ret = close(fd);
	if (ret == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n", 2);
	else if (argc == 2)
	{
		if (show_char(argv) == 0)
			return (0);
	}
	else
		ft_putstr("Too many arguments.\n", 2);
	return (0);
}
/*
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void	display_error(const char *msg)
{
	while (*msg)
	{
		write(2, msg++, 1);
	}
}

char	ft_error_message(int argc, char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (argc < 2)
	{
		display_error("File name missing.\n");
		return (-1);
	}
	if (argc > 2)
	{
		display_error("Too many arguments\n");
		return (-1);
	}
	if (fd < 0)
	{
		display_error("Cannot open file.\n");
		return (-1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = ft_error_message(argc, argv);
	if (fd == -1)
		return (1);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		write (1, buffer, bytes_read);
	}
	close(fd);
	return (0);
}*/