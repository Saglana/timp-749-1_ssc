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

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 1: написать программу реализующую обход дерева в ширину:

- считать с входного потока 7 чисел и занести их в дерево;
- вывести все значения вершин дерева через пробел в порядке их посещения.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr6/sh.png)
Рисунок 2.1 ─ Обход дерева в ширину

input | output
:----:|:----
5 3 7 2 4 6 8 | 5 3 7 2 4 6 8
| |

Код программы:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left;
    struct node *right;
    struct node *parent;
    int value;
} node;


typedef struct tree {
    struct node *root;
    int count;
} tree;


typedef struct queue {
    int value;
    struct queue *next;
} queue;

typedef struct list {
    struct queue *head;
} list;


void  init_list(list *l){
    l->head = NULL;
}

void init(tree *t) {
    t->root = NULL;
    t->count = 0;
}

bool is_empty(list *l){
    if (l->head == NULL)
        return 1;
    else
        return 0;
}

int push_back(list *l, int value){
    queue* Nnode;
    Nnode = (queue*)malloc(sizeof(queue));
    Nnode->value = value;
    Nnode->next = NULL;
    if (is_empty(l))
        l->head = Nnode;
    else{
        queue* p = l->head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = Nnode;
    }
    return 0;
}

node *find(tree *t, int value) {
    node *temp;
    temp = t->root;
    if (temp == NULL)
        return NULL;
    while (temp->value != value) {
        if (value > temp->value)
            temp = temp->right;
        else
            temp = temp->left;
        if (temp == NULL)
            return NULL;
    }
    return temp;
}

int insert(tree *t, int value) {
    node *error;
    error = find(t, value);
    if (error != NULL)
        return 1;
    node *temp;
    node *elem;
    elem = (node *) malloc(sizeof(node));
    elem->value = value;
    elem->left = NULL;
    elem->right = NULL;
    temp = t->root;
    if (temp == NULL) {
        elem->parent = NULL;
        t->root = elem;
        t->count++;
        return 0;
    }
    int i;
    while (true) {
        if (temp->value > value) {
            if (temp->left != NULL)
                temp = temp->left;
            else {
                temp->left = elem;
                elem->parent = temp;
                t->count++;
                return 0;
            }
        } else {
            if (temp->right != NULL)
                temp = temp->right;
            else {
                temp->right = elem;
                elem->parent = temp;
                t->count++;
                return 0;
            }
        }
    }
}

int remove_first(tree *t, list *l, int value){
    queue* p1 = l->head;
    node* b;
    b = find(t, value);
    if (b->left != NULL)
        push_back(l, b->left->value);
    if (b->right != NULL)
        push_back(l, b->right->value);
    l->head = p1->next;
    free(p1);
    return 0;
}

void print_head(list *l, tree* t){
    while (l->head != NULL){
        printf("%d ", l->head->value);
        remove_first(t, l, l->head->value);
    }
}

int main() {
    tree T;
    list L;
    init_list(&L);
    int i, input;
    node *b;
    init(&T);
    // Задание 1
    for (i = 0; i < 7; i++) {
        (void) scanf("%d", &input);
        insert(&T, input);
    }
    push_back(&L, T.root->value);
    print_head(&L, &T);
    return 0;
}
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 2: написать программу реализующую прямой обход дерева:

Использование рекурсии недопускается

- считать с входного потока 7 чисел и занести их в дерево;
- вывести все значения вершин дерева через пробел в порядке их посещения.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr6/sp.png)
Рисунок 2.2 ─ Прямой обход дерева

input | output
:----:|:----
5 3 7 2 4 6 8 | 5 3 2 4 7 6 8
| |

Код программы:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left;
    struct node *right;
    struct node *parent;
    int value;
} node;


typedef struct tree {
    struct node *root;
    int count;
} tree;

void init(tree *t) {
    t->root = NULL;
    t->count = 0;
}

node *find(tree *t, int value) {
    node *temp;
    temp = t->root;
    if (temp == NULL)
        return NULL;
    while (temp->value != value) {
        if (value > temp->value)
            temp = temp->right;
        else
            temp = temp->left;
        if (temp == NULL)
            return NULL;
    }
    return temp;
}

void straight(tree * t)
{
    node * a[15];
    int a_i = 0;
    node * nmb[15];
    int w_i = 0;
    node * n = t->root;
    while (w_i < t->count)
    {
        while (n != NULL)
        {
            w_i++;
            if (n->right != NULL)
            {
                a_i++;
                a[a_i] = n->right;
            }
            nmb[w_i] = n;
            n = n->left;
        }
        n = a[a_i];
        a_i -= 1;
    }
    int fl = 0;
    for (int i = 1; i <= w_i; i++)
    {
        if (fl > 0) printf(" ");
        else fl++;
        printf("%d", nmb[i]->value);
    }
    printf("\n");
}

int insert(tree *t, int value) {
    node *error;
    error = find(t, value);
    if (error != NULL)
        return 1;
    node *temp;
    node *elem;
    elem = (node *) malloc(sizeof(node));
    elem->value = value;
    elem->left = NULL;
    elem->right = NULL;
    temp = t->root;
    if (temp == NULL) {
        elem->parent = NULL;
        t->root = elem;
        t->count++;
        return 0;
    }
    int i;
    while (true) {
        if (temp->value > value) {
            if (temp->left != NULL)
                temp = temp->left;
            else {
                temp->left = elem;
                elem->parent = temp;
                t->count++;
                return 0;
            }
        } else {
            if (temp->right != NULL)
                temp = temp->right;
            else {
                temp->right = elem;
                elem->parent = temp;
                t->count++;
                return 0;
            }
        }
    }
}

int main() {
    tree T;
    int i, input;
    node *b;
    init(&T);
    // Задание 1
    for (i = 0; i < 7; i++) {
        (void) scanf("%d", &input);
        insert(&T, input);
    }
    straight(&T);
    return 0;
}
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Задача 3: написать программу реализующую обратный обход дерева:

Обязательное использование рекурсии

- считать с входного потока 7 чисел и занести их в дерево;
- вывести все значения вершин дерева через пробел в порядке их посещения.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr6/so.png)
Рисунок 2.3 ─ Обратный обход дерева

input | output
:----:|:----
5 3 7 2 4 6 8 | 2 4 3 6 8 7 5
| |

Код программы:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left;
    struct node *right;
    struct node *parent;
    int value;
} node;


typedef struct tree {
    struct node *root;
    int count;
} tree;

void init(tree *t) {
    t->root = NULL;
    t->count = 0;
}

node *find(tree *t, int value) {
    node *temp;
    temp = t->root;
    if (temp == NULL)
        return NULL;
    while (temp->value != value) {
        if (value > temp->value)
            temp = temp->right;
        else
            temp = temp->left;
        if (temp == NULL)
            return NULL;
    }
    return temp;
}

void Reverse(node* n){
    if (n == NULL)
        return;
    Reverse(n -> left);
    Reverse(n -> right);
    printf("%d ", n -> value);
}

int insert(tree *t, int value) {
    node *error;
    error = find(t, value);
    if (error != NULL)
        return 1;
    node *temp;
    node *elem;
    elem = (node *) malloc(sizeof(node));
    elem->value = value;
    elem->left = NULL;
    elem->right = NULL;
    temp = t->root;
    if (temp == NULL) {
        elem->parent = NULL;
        t->root = elem;
        t->count++;
        return 0;
    }
    int i;
    while (true) {
        if (temp->value > value) {
            if (temp->left != NULL)
                temp = temp->left;
            else {
                temp->left = elem;
                elem->parent = temp;
                t->count++;
                return 0;
            }
        } else {
            if (temp->right != NULL)
                temp = temp->right;
            else {
                temp->right = elem;
                elem->parent = temp;
                t->count++;
                return 0;
            }
        }
    }
}

int main() {
    tree T;
    int i, input;
    node *b;
    init(&T);
    // Задание 1
    for (i = 0; i < 7; i++) {
        (void) scanf("%d", &input);
        insert(&T, input);
    }
    Reverse(T.root);
    return 0;
}
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; После написания программ файлы были загружены на GitLab и прошёли тесты.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; На рисунке 2.4 представлена результаты проверки программ.

![](https://gitlab.com/Saglana/practices/-/raw/master/pr5/s1.png)

Рисунок 2.4 ─ Результаты проверки программ

## 3 Заключение

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; В результате работы были написаны программы и загружены на GitLab.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Был написан отчет с помощью языка разметки Markdown.
