
#include <stddef.h>

double pi_generator(int precision)
{
    double pi_gen(int i)
    {
        if (i == precision)
        {
            double bab = i * 2 + 1;
            double billy = i;
            double bob = billy / bab;
            return 1 + bob;
        }
        double bab = i * 2 + 1;
        double billy = i;
        double bob = billy / bab;

        return 1 + bob * pi_gen(i + 1);
    }
    return 2 * pi_gen(1);
}
