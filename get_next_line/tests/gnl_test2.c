int		main(void)
 {
 	char	*line;
	int		fd;
 	int		count;

	count = 1;
	fd = open("amsterdam.txt", O_RDONLY);
 	count = get_next_line(fd, &line);
	free(line);
	line = NULL;
 	printf("%d | %s\n", count, line);
	count = get_next_line(fd, &line);
	free(line);
	line = NULL;
 	printf("%d | %s\n", count, line);
	count = get_next_line(fd, &line);
	free(line);
	line = NULL;
 	printf("%d | %s\n", count, line);	
	count = get_next_line(fd, &line);
	free(line);
	line = NULL;
 	
	//while (1){;}
 	close(fd);
 	return (0);
 }
