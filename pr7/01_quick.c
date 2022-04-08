#include<stdio.h>
FILE *f;


void print_in_file(int Array[], int length){
    int i;
    for (int i = 0; i < length; i++)
        fprintf(f, "%d ", Array[i]);
    fprintf(f, "\n");
}

void qsort(int Array[], int first, int last, int length)
{
    int left = first,
            right = last,
            pivot = Array[(left + right) / 2];
    do
    {
        while(Array[left] < pivot) {
            left++;
        }
        while(Array[right] > pivot) {
            right--;
        }
        if(left <= right)
        {
            int temp = Array[left];
            Array[left] = Array[right];
            Array[right] = temp;
            left++;
            right--;
        }
        print_in_file(Array, length);
    } while(left <= right);
    if (first < right )
        qsort(Array, first, right, length);
    if (last > left )
        qsort(Array, left, last, length);
}


int main() {
    int length;
    f = fopen("quicksort.log", "w");
    scanf("%d",&length);
    int Array[length];
    for(int i = 0; i < length; i++)
    {
        scanf("%d",&Array[i]);
    }
    qsort(Array, 0, length, length);
    for(int i = 0; i < length; i++)
    {
        printf("%d", Array[i]);
        printf(" ");
    }
}