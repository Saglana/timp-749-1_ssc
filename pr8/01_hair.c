#include<stdio.h>
#define RFACTOR (1.24733)
FILE *f;


void print_in_file(int Array[], int length){
    int i;
    for (int i = 0; i < length; i++)
        fprintf(f, "%d ", Array[i]);
    fprintf(f, "\n");
}

void hair_sort(int *array, int size) {
    int gap = size;
    int swaps = 1;
    int i, j;
    print_in_file(array, size);
    while ( gap > 1 || swaps ) {
        gap = (int)(gap / RFACTOR);
        if ( gap < 1 )
            gap = 1;
        swaps = 0;
        for ( i = 0; i < size - gap; ++i ) {
            j = i + gap;
            if ( array[i] > array[j] ) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                swaps = 1;
                print_in_file(array, size);
            }
        }
    }
}


int main() {
    f = fopen("hairbrush.log", "w");
    int length;
    scanf("%d",&length);
    int Array[length];
    for(int i = 0; i < length; i++)
    {
        scanf("%d",&Array[i]);
    }
    hair_sort(Array, length);
    for(int i = 0; i < length; i++)
    {
        printf("%d", Array[i]);
        printf(" ");
    }
}