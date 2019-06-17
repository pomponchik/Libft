#include "libft.h"

void ft_bits_print(void *mem, size_t num_bytes)
{
  size_t index;
  size_t index2;
  char *temp;

  if (!mem)
    return ;
  index = 0;
  temp = (char *)mem;
  while (index < num_bytes)
  {
    index2 = 0;
    while (index2 < 8)
    {
      if (ft_bits_read_bit(&temp[index], index2))
        ft_putchar('1');
      else
        ft_putchar('0');
      index2++;
    }
    index++;
  }
}
