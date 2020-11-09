#include "get_next_line_bonus.h"

static int	check_gnl(char **line, char **storage, char *nl)
{
	char	*temp;

	if (nl != NULL)
	{
		*line = ft_strndup(*storage, nl - *storage);
		temp = ft_strndup(nl + 1, ft_strlen(nl + 1));
		free(*storage);
		*storage = temp;
		return (1);
	}
	if (*storage != NULL)
	{
		*line = *storage;
		*storage = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*storage[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			byte;
	char		*temp;
	char		*nl;

	if (fd < 0 || line == NULL || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	nl = ft_strchr(storage[fd], '\n');
	byte = read(fd, buff, BUFFER_SIZE);
	while (nl == 0 && byte > 0)
	{
		buff[byte] = 0;
		temp = storage[fd] == NULL ? ft_strndup(buff, byte) :
			ft_strjoin(storage[fd], buff);
		if (storage[fd] != 0)
			free(storage[fd]);
		storage[fd] = temp;
		nl = ft_strchr(storage[fd], '\n');
		byte = read(fd, buff, BUFFER_SIZE);
	}
	if (byte < 0)
		return (-1);
	return (check_gnl(line, &storage[fd], nl));
}