#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main3.h"
/**
 * print_addr - prints address
 * @ptr: magic.
 * Return: no return.
 */
void print_addr(char *ptr)
{
int i;
int begin;
char sys;

printf("  Entry point address:               0x");

sys = ptr[4] + '0';
if (sys == '1')
{
begin = 26;
printf("80");
for (i = begin; i >= 22; i--)
{
if (ptr[i] > 0)
printf("%x", ptr[i]);
else if (ptr[i] < 0)
printf("%x", 256 + ptr[i]);
}
if (ptr[7] == 6)
printf("00");
}

if (sys == '2')
{
begin = 26;
for (i = begin; i > 23; i--)
{
if (ptr[i] >= 0)
printf("%02x", ptr[i]);

else if (ptr[i] < 0)
printf("%02x", 256 + ptr[i]);

}
}
printf("\n");
}

/**
 * print_type - prints type
 * @ptr: magic.
 * Return: no return.
 */
void print_type(char *ptr)
{
char type = ptr[16];

if (ptr[5] == 1)
type = ptr[16];
else
type = ptr[17];

printf("  Type:                              ");
if (type == 0)
printf("NONE (No file type)\n");
else if (type == 1)
printf("REL (Relocatable file)\n");
else if (type == 2)
printf("EXEC (Executable file)\n");
else if (type == 3)
printf("DYN (Shared object file)\n");
else if (type == 4)
printf("CORE (Core file)\n");
else
printf("<unknown: %x>\n", type);
}

/**
 * print_osABI - prints osabi
 * @ptr: magic.
 * Return: no return.
 */
void print_osABI(char *ptr)
{
char osABI = ptr[7];

printf("  OS/ABI:                            ");
if (osABI == 0)
printf("UNIX - System V\n");
else if (osABI == 2)
printf("UNIX - NetBSD\n");
else if (osABI == 6)
printf("UNIX - Solaris\n");
else
printf("<unknown: %x>\n", osABI);

printf("  ABI Version:                       %d\n", ptr[8]);
}

/**
 * main - check the code for Holberton School students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
int fd, ret_read;
char ptr[27];

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
exit(98);
}

fd = open(argv[1], O_RDONLY);

if (fd < 0)
{
dprintf(STDERR_FILENO, "Err: file can not be open\n");
exit(98);
}

lseek(fd, 0, SEEK_SET);
ret_read = read(fd, ptr, 27);

if (ret_read == -1)
{
dprintf(STDERR_FILENO, "Err: The file can not be read\n");
exit(98);
}

if (!check_elf(ptr))
{
dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
exit(98);
}

check_sys(ptr);
close(fd);

return (0);
}
