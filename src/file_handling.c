#include "../headers/maze.h"

/**
 * read_file - Reads the content of a file and stores it in a buffer.
 * @filename: The name of the file to read.
 * Return: A pointer to the buffer containing the file content.
 */
char *read_file(const char *filename)
{
    FILE *file;
    char *buffer;
    long length;

    file = fopen(filename, "r");
    if (!file)
        return (NULL);

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = malloc(length + 1);
    if (!buffer)
    {
        fclose(file);
        return (NULL);
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);
    return (buffer);
}

