#include <stdio.h>

11;rgb:0000/0000/0000/**
		      * main - prints the number of arguments passed into it.
		      * @argc: number of command line arguments.
		      * @argv: array that contains the program command line arguments.
		      * Return: 0 - success.
		      */
int main(int argc, char *argv[] __attribute__((unused)))
{
  printf("%d\n", argc - 1);
  return (0);
}
