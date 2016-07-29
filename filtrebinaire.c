#include <stdlib.h>
#include "my.h"
#include <math.h>

void    my_filtre(char *str);
void    my_char_to_bin(unsigned char c, unsigned char bintab[8]);
unsigned char   bin_to_char(unsigned char bintab[8]);

int	main(int ac, char **av)
{

  int	i;
  
  i = 1;
  if (ac < 2)
    {
      my_putstr("Args error");
      exit(-1);
    }
 while (i < ac)
   {
     my_putchar('\n');
     my_filtre(av[i]);
     i++;
   }
 return (0);
}

void		my_filtre(char *str)
{
  unsigned char	bintab[8];
 
  while (*str)
    {
      my_char_to_bin(*str, bintab);
      my_putchar(bin_to_char(bintab));
      str++;
    }
}

void		my_char_to_bin(unsigned char c, unsigned char bintab[8])
{
  int	i;
  
  i = 0;
  while (i < 8)
    {
      bintab[i] = (c & 01);
      c >>= 1;
      i++;
    }
}

unsigned char	bin_to_char(unsigned char bintab[8])
{
  unsigned char c;
  int	i;
  
  c = 0;
  i = 0;
  while (i < 8)
    {
      bintab[i] ? c +=  my_power_rec(2 , i) : 0;
       i++;
    }
  return (c);
}
