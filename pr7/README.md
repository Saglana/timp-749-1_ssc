Министерство науки и высшего образования Российской Федерации
Федеральное государственное бюджетное образовательное учреждение
высшего образования
«ТОМСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ СИСТЕМ
УПРАВЛЕНИЯ И РАДИОЭЛЕКТРОНИКИ» (ТУСУР)
Факультет безопасности (ФБ)
Кафедра безопасности информационных систем (БИС)

ОБХОД БИНАРНОГО ДЕРЕВА

Отчет по практической работе №6

по дисциплине «Технологии и методы программирования»         
Студентка гр. 749-1

_________ Сат С.Ч.

_________   &nbsp;

Младший научный сотрудник

_________   _________ Перминов П.В.

_________   &nbsp;  
Томск 2022

## 1 Введение

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Цель работы: написать программы и загрузить их на GitLab.

## 2 Ход работы

Пример вводимых данных

input | 8
:----:|:----
| |-74 70 -23 -68 -62 -53 41 44
output | -74 -68 -62 -53 -23 41 44 70

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 1: написать программу реализующую быструю сортировку.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr7/s2.jpg)

Рисунок 2.1 ─ Логи быстрой сортировки

Код программы:

```c
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
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 2: написать программу реализующую пирамидальную сортировку.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr7/s3.jpg)

Рисунок 2.2 ─ Логи пиромидальной сортировки

Код программы:

```c
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
```

## 3 Заключение

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; В результате работы были написаны программы и загружены на GitLab.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Был написан отчет с помощью языка разметки Markdown.
