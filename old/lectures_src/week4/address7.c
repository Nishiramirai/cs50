#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("Address: %p   Value: %c\n", s, *s);

    printf("Address: %p   Value: %c\n", &s[0], *s);
    printf("Address: %p   Value: %c\n", &s[1], *(s + 1));
    printf("Address: %p   Value: %c\n", &s[2], *(s + 2));
    printf("Address: %p   Value: %c\n", &s[3], *(s + 3));

}