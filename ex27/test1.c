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