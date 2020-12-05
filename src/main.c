#include "h/cli.h"
#include <stdio.h>      // printf
#include <stdlib.h>     // atoi, srand, rand
#include <time.h>       // time_t
#include <unistd.h>     // sleep

const char arr_password_material [] = "abcdefghkjlmnopqrstuvwxyzABCDEFGHKJLMNOPQRSTUVWZYZ1234567890!@#$%%^&*()_+|\\=-{}][\"'.><,?";

void generate_password (cli_args_t opts)
{
  size_t i = 0;
  for (; i < opts.size; i++)
    {
      printf ("%c", arr_password_material [rand () % sizeof (arr_password_material)]);
    }
  printf ("\n");
}

int main (int argc, char ** argv)
{
  time_t time_var;
  cli_args_t opts = parse_cli_args (argc, argv);
  if (!opts.size)
    {
      printf ("Type in the size of the password to be generated: ");
      scanf ("%lu", &opts.size);
    }
  srand ((unsigned) time (&time_var));

  generate_password (opts);
  usleep (150);
  return 0;
}
