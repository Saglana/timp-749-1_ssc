#include<stdio.h>
FILE *f;


void print_in_file(int Array[], int length){
    int i;
    for (int i = 0; i < length; i++)
        fprintf(f, "%d ", Array[i]);
    fprintf(f, "\n");
}

void heap(int Array[], int root, int bottom)
{
    int maxChild, done = 0;
    while((root * 2 + 1 <= bottom) && (!done))
    {
        if(root * 2 + 2 <= bottom)
        {
            if(Array[root * 2 + 2] > Array[root * 2 + 1])
                maxChild = root * 2 + 2;
            else
                maxChild = root * 2 + 1;
        }
        else
            maxChild = root * 2 + 1;
        if(Array[root] < Array[maxChild])
        {
            int temp = Array[root];
            Array[root] = Array[maxChild];
            Array[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}

void pyramid(int Array[], int len)
{
    for (int i = (len / 2) - 1; i >= 0; i--)
        heap(Array, i, len - 1);
    for (int i = len - 1; i >= 1; i--)
    {
        int temp = Array[0];
        Array[0] = Array[i];
        Array[i] = temp;
        print_in_file(Array, len);
        heap(Array, 0, i - 1);
    }
}


int main() {
    f = fopen("heapsort.log", "w");
    int length;
    scanf("%d",&length);
    int Array[length];
    for(int i = 0; i < length; i++)
    {
        scanf("%d",&Array[i]);
    }
    pyramid(Array, length);
    for(int i = 0; i < length; i++)
    {
        printf("%d", Array[i]);
        printf(" ");
    }
}