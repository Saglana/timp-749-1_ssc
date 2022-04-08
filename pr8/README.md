Министерство науки и высшего образования Российской Федерации
Федеральное государственное бюджетное образовательное учреждение
высшего образования
«ТОМСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ СИСТЕМ
УПРАВЛЕНИЯ И РАДИОЭЛЕКТРОНИКИ» (ТУСУР)
Факультет безопасности (ФБ)
Кафедра безопасности информационных систем (БИС)

АЛГОРИТМЫ СОРТИРОВКИ

Отчет по практической работе №8

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

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 1: написать программу реализующую сортировку "Расчёска".


input | -74 70 -23 -68 -62 -53 41 44
:----:|:----
output | -74 -68 -62 -53 -23 41 44 70

![](https://gitlab.com/Saglana/practices/-/raw/master/pr8/s1.png)

Рисунок 2.1 ─ Логи сортировки "Расчёска"

Код программы:

```c
#include<stdio.h>
#define ConstValue (1.24733)
FILE *f;


void print_in_file(int Array[], int length){
    int i;
    for (int i = 0; i < length; i++)
        fprintf(f, "%d ", Array[i]);
    fprintf(f, "\n");
}

void hair_sort(int Array[], int size) {
    int len = size;
    int swap = 1;
    int i, j;
    print_in_file(Array, size);
    while (len > 1 || swap ) {
        len = (int)(len / ConstValue);
        if (len < 1 )
            len = 1;
        swap = 0;
        for ( i = 0; i < size - len; ++i ) {
            j = i + len;
            if (Array[i] > Array[j] ) {
                int temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
                swap = 1;
                print_in_file(Array, size);
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
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 2: написать программу реализующую сортировку Шелла.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr8/s2.png)

Рисунок 2.2 ─ Логи сортировки Шелла

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

void Shell(int size, int Array[])
{
    int i, j, step;
    int temp;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++)
        {
            temp = Array[i];
            for (j = i; j >= step; j -= step)
            {
                if (temp < Array[j - step])
                    Array[j] = Array[j - step];
                else
                    break;
            }
            Array[j] = temp;
            print_in_file(Array, size);
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
```

## 3 Заключение

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; В результате работы были написаны программы и загружены на GitLab.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Был написан отчет с помощью языка разметки Markdown.
