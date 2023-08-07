#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "main.h"

void error_exit(const char *message);
void display_elf_header(Elf64_Ehdr *elf_header);

void error_exit(const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(98);
}

void display_elf_header(Elf64_Ehdr *elf_header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", elf_header->e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n",
	       (elf_header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
	       (elf_header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
	       (elf_header->e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" : "unknown");
	printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (elf_header->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
		case ELFOSABI_LINUX: printf("Linux\n"); break;
		default: printf("unknown\n"); break;
	}
	printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (elf_header->e_type)
	{
		case ET_NONE: printf("NONE (Unknown type)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("unknown\n"); break;
	}
	printf("  Entry point address:               %#lx\n", (unsigned long)elf_header->e_entry);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Cannot open file");

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
		error_exit("Error: Cannot read ELF header");

	if (lseek(fd, (off_t)0, SEEK_SET) == -1)
		error_exit("Error: Cannot seek file");

	display_elf_header(&elf_header);

	close(fd);
	return 0;
}
