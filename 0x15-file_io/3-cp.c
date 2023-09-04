#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * check_arguments - Check the number of command-line arguments.
 * @argc: The argument count.
 *
 * Return: 0 if the number of arguments is correct, otherwise 1.
 */
int check_arguments(int argc)
{
	if (argc != 3)
		return (1);
	return (0);
}

/**
 * open_files - Open the source file and handle errors.
 * @from_file: The name of the source file.
 *
 * Return: The file descriptor of the source file.
 */
int open_files(const char *from_file)
{
	int from_fd;

	from_fd = open(from_file, O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_file);
		exit(98);
	}

	return (from_fd);
}

/**
 * copy_contents - Copy the contents of one file to another.
 * @from_fd: The file descriptor of the source file.
 * @to_fd: The file descriptor of the destination file.
 *
 * Return: 0 on success, 1 on failure.
 */
int copy_contents(int from_fd, int to_fd)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	while ((bytes_read = read(from_fd, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written == -1)
			return (1);
	}

	if (bytes_read == -1)
		return (1);

	return (0);
}

/**
 * close_files - Close file descriptors and handle errors.
 * @from_fd: The file descriptor of the source file.
 * @to_fd: The file descriptor of the destination file.
 */
void close_files(int from_fd, int to_fd)
{
	if (close(from_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
		exit(100);
	}

	if (close(to_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
		exit(100);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: An array of strings containing command-line arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd;

	if (check_arguments(argc) != 0)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open_files(argv[1]);
	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (to_fd == -1)
	{
		close_files(from_fd, to_fd);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	if (copy_contents(from_fd, to_fd) != 0)
	{
		close_files(from_fd, to_fd);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	close_files(from_fd, to_fd);

	return (0);
}
