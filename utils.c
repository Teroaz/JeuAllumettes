#include <stdio.h>
#include "utils.h"

void secure_scanf(char *format, void *value) {
    scanf("%*c");
    scanf(format, value);
}
