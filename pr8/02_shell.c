#include<stdio.h>
FILE *f;


void print_in_file(int Array[], int length){
    int i;
    for (int i = 0; i < length; i++)
        fprintf(f, "%d ", Array[i]);
    fprintf(f, "\n");
}

void Shell(int n, int mass[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
            print_in_file(mass, n);
        }
}


int main() {
    f = fopen("Shell.log", "w");
    int length;
    scanf("%d",&length);
    int Array[length];
    for(int i = 0; i < length; i++)
    {
        scanf("%d",&Array[i]);
    }
    Shell(length, Array);
    for(int i = 0; i < length; i++)
    {
        printf("%d", Array[i]);
        printf(" ");
    }
}