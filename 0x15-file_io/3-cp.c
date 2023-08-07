#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "main.h"

int open_file_read(const char *filename);
int open_file_write(const char *filename);
int copy_content(int fd_from, int fd_to);
int close_files(int fd_from, int fd_to);

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The array of argument strings.
 *
 * Return: 0 on success, or an error code.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	fd_from = open_file_read(argv[1]);
	if (fd_from == -1)
		return (98);

	fd_to = open_file_write(argv[2]);
	if (fd_to == -1)
	{
		close(fd_from);
		return (99);
	}

	if (!copy_content(fd_from, fd_to))
	{
		close(fd_from);
		close(fd_to);
		return (99);
	}

	if (close_files(fd_from, fd_to) == -1)
		return (100);

	return (0);
}

/**
 * open_file_read - Opens a file for reading.
 * @filename: The name of the file to open.
 *
 * Return: The file descriptor on success, or -1 on failure.
 */
int open_file_read(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	return (fd);
}

/**
 * open_file_write - Opens a file for writing.
 * @filename: The name of the file to open.
 *
 * Return: The file descriptor on success, or -1 on failure.
 */
int open_file_write(const char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	return (fd);
}

/**
 * copy_content - Copies content from one file to another.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 *
 * Return: 1 on success, 0 on failure.
 */
int copy_content(int fd_from, int fd_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			return (0);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		return (0);
	}

	return (1);
}

/**
 * close_files - Closes two file descriptors.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 *
 * Return: 0 on success, -1 on failure.
 */
int close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		return (-1);
	}
	return (0);
}
