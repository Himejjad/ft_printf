#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


void test(int n, ...)
{
    va_list ap;
    int i = 0;

    printf("gb_offset : %u\n",ap->gp_offset);
    printf("fp_offset : %u\n",ap->fp_offset);
    printf("overflow_arg_area : %p\n",ap->overflow_arg_area);
    printf("reg_save_area : %p\n",ap->reg_save_area);

    va_start(ap, n);
    while (i<n)
    {
        printf ("===================================\n");
        printf("gb_offset : %u\n",ap->gp_offset);
        printf("fp_offset : %u\n",ap->fp_offset);
        printf("overflow_arg_area : %i\n",ap->overflow_arg_area);
        printf("reg_save_area : %d\n",ap->reg_save_area);
        printf("va_arg content : %d\n",va_arg(ap, int));
        i++;
    }
    va_end(ap);
}

int main()
{
    test(8,25,30,31,40,35,40,45,50);
}