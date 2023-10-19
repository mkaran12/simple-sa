#include "shell.h"
/** 
*main -Simple Shell *main  function
*@ac: Count of arguments
*@av: Arguments
*Return: 0 Always (success).
**/
int main(int ac, char **argv)
{
  char *line = NULL;
  int status = 0;
  (void) ac;
  (void) argv;
  
while (1)
  {
    line = readline();
    if (line == NULL) 
    {
       write(STDOUT_FILENO, "\n ", 1);
       return (status);
    }
     

    printf ("%s", line); 
    free(line);
  }
}