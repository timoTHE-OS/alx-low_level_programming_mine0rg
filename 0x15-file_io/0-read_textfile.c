#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t lenr, lenw;
char *buffer;

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buffer = malloc(sizeof(char) * (letters));
if (!buffer)
return (0);

lenr = read(fd, buffer, letters);
lenw = write(STDOUT_FILENO, buffer, lenr);

close(fd);

free(buffer);

return (lenw);
}
