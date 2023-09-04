#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_IDENT_SIZE 16

/**
 * check_elf - Check if a file is an ELF file.
 * @e_ident: Pointer to an array containing ELF magic numbers.
 *
 * If the file is not an ELF file, exit with code 98.
 */
void check_elf(unsigned char *e_ident);

/**
 * print_magic - Print the magic numbers of an ELF header.
 * @e_ident: Pointer to an array containing ELF magic numbers.
 *
 * Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident);

/**
 * print_class - Print the class of an ELF header.
 * @e_ident: Pointer to an array containing ELF class.
 *
 * Prints the class (32-bit or 64-bit) of an ELF header.
 */
void print_class(unsigned char *e_ident);

/**
 * print_data - Print the data encoding of an ELF header.
 * @e_ident: Pointer to an array containing ELF data encoding.
 *
 * Prints the data encoding (little-endian or big-endian) of an ELF header.
 */
void print_data(unsigned char *e_ident);

/**
 * print_version - Print the version of an ELF header.
 * @e_ident: Pointer to an array containing ELF version.
 *
 * Prints the version of an ELF header.
 */
void print_version(unsigned char *e_ident);

/**
 * print_osabi - Print the OS/ABI of an ELF header.
 * @e_ident: Pointer to an array containing ELF OS/ABI.
 *
 * Prints the OS/ABI of an ELF header.
 */
void print_osabi(unsigned char *e_ident);

/**
 * print_abi - Print the ABI version of an ELF header.
 * @e_ident: Pointer to an array containing ELF ABI version.
 *
 * Prints the ABI version of an ELF header.
 */
void print_abi(unsigned char *e_ident);

/**
 * print_type - Print the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: Pointer to an array containing ELF class.
 *
 * Prints the type of an ELF header.
 */
void print_type(unsigned int e_type, unsigned char *e_ident);

/**
 * print_entry - Print the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: Pointer to an array containing ELF class.
 *
 * Prints the entry point address of an ELF header.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/**
 * close_elf - Close an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * If the file cannot be closed, exit with code 98.
 */
void close_elf(int elf);

int main(int argc, char *argv[])
{

	Elf64_Ehdr *header = malloc(sizeof(Elf64_Ehdr));
	int fd = open(argv[1], O_RDONLY);
	ssize_t bytes_read = read(fd, header, sizeof(Elf64_Ehdr));

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: elf_header elf_fiElf64_Ehdr *header = malloc(sizeof(Elf64_Ehdr));lename\n");
        exit(98);
    }

    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    if (header == NULL)
    {
        close_elf(fd);
        dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
        exit(98);
    }

    if (bytes_read == -1)
    {
        free(header);
        close_elf(fd);
        dprintf(STDERR_FILENO, "Error: Read failed\n");
        exit(98);
    }

    check_elf(header->e_ident);
    printf("ELF Header:\n");
    print_magic(header->e_ident);
    print_class(header->e_ident);
    print_data(header->e_ident);
    print_version(header->e_ident);
    print_osabi(header->e_ident);
    print_abi(header->e_ident);
    print_type(header->e_type, header->e_ident);
    print_entry(header->e_entry, header->e_ident);

    free(header);
    close_elf(fd);

    return 0;
}

void check_elf(unsigned char *e_ident)
{
    int index;
    for (index = 0; index < 4; index++)
    {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

void print_magic(unsigned char *e_ident)
{
    int index;
    printf(" Magic: ");
    for (index = 0; index < MAX_IDENT_SIZE; index++)
    {
        printf("%02x", e_ident[index]);
        if (index == MAX_IDENT_SIZE - 1)
            printf("\n");
        else
            printf(" ");
    }
}

void print_class(unsigned char *e_ident)
{
    printf(" Class: ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data(unsigned char *e_ident)
{
    printf(" Data: ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

void print_version(unsigned char *e_ident)
{
    printf(" Version: %d", e_ident[EI_VERSION]);
    switch (e_ident[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

void print_osabi(unsigned char *e_ident)
{
    printf(" OS/ABI: ");
    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

void print_abi(unsigned char *e_ident)
{
    printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

void print_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf(" Type: ");
    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf(" Entry point address: ");
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);
    else
        printf("%#lx\n", e_entry);
}

void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}
