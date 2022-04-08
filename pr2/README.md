Министерство науки и высшего образования Российской Федерации
Федеральное государственное бюджетное образовательное учреждение
высшего образования
«ТОМСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ СИСТЕМ
УПРАВЛЕНИЯ И РАДИОЭЛЕКТРОНИКИ» (ТУСУР)
Факультет безопасности (ФБ)
Кафедра безопасности информационных систем (БИС)

ОДНОПРОХОДНЫЕ АЛГОРИТМЫ

Отчет по практической работе №2

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

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; В таблице 1.1 представлены задания к работе.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Таблица 1.1 ─ Задания

Номер задания | Номер по варианту | Описания
:-----: | :----: | -----
1   | 03 | Сумма последовательности. На вход подаётся число 𝑛 ∈ N 𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z 𝑥𝑖 ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение суммы этих чисел.
2  | 13  | Сумма квадратов. На вход подаётся число 𝑛 ∈ N  𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z  𝑥𝑖 ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение суммы квадратов этих чисел.

## 2 Ход работы

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 1. Сумма последовательности. На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖| ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение суммы этих чисел.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; На рисунке 2.1 представлена блок-схема программы 1.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr2/s1.png)

Рисунок 2.1 ─ Блок-схема программы 1

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Ниже представлен листинг кода программы 1.

```c
#include <stdio.h>

int main()
{
    int n;
    double sum = 0, input;
    (void) scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        (void)scanf("%lf", &input);
        sum += input;
    }
    printf("%lf", sum);
    return 0;
}
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 2. Сумма квадратов. На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖| ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение суммы квадратов этих чисел.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; На рисунке 2.1 представлена блок-схема программы 1.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr2/s2.png)

Рисунок 2.2 ─ Блок-схема программы 2

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Ниже представлен листинг кода программы 1.

```c
#include <stdio.h>

int main()
{
    int n;
    double sum = 0, input;
    (void) scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        (void)scanf("%lf", &input);
        sum += input;
    }
    printf("%lf", sum);
    return 0;
}
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; После написания кода выполнили проверку по splint. На рисунке 2.3 представлен результат проверки по splint. После загрузки, результат выполненных тестов представлен на рисунке 2.4.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr2/s3.png)

Рисунок 2.3 ─ Результаты проверки splint

![](https://gitlab.com/Saglana/practices/-/raw/master/pr2/s4.png)

Рисунок 2.4 ─ Результаты проверки тестов

## 3 Заключение

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; В результате работы были написаны программы и загружены на GitLab.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Был написан отчет с помощью языка разметки Markdown.
