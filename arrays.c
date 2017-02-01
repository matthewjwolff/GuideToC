#include <stdio.h>

#define LENGTH(x) (sizeof(x) / sizeof(x[0]))

void array_print(int a[], int length) {
    printf("[");
    for(int i=0; i<length; i++) {
        printf("%d", a[i]);
        if(i!=length-1)
            printf(",");
    }
    printf("]");
}
