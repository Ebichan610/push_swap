/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:49:39 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/14 01:49:40 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/* ===== 構造体 ===== */
typedef struct s_list
{
    int             value;
    struct s_list  *next;
}   t_list;

typedef struct s_stack
{
    t_list *top;
    int     size;
}   t_stack;

/* ===== ft_split ===== */
static size_t count_words(char const *str, char c)
{
    size_t word_count = 0;
    size_t in_word = 0;
    while (*str)
    {
        if (!in_word && *str != c)
        {
            word_count++;
            in_word = 1;
        }
        else if (in_word && *str == c)
            in_word = 0;
        str++;
    }
    return (word_count);
}

static char *strndup_split(char const *s, size_t n)
{
    char *word = (char *)malloc(sizeof(char) * (n + 1));
    size_t i;
    if (word == NULL)
        return (NULL);
    for (i = 0; i < n; i++)
        word[i] = s[i];
    word[i] = '\0';
    return (word);
}

static void free_split(char **result, int i_max)
{
    int i = 0;
    while (i < i_max)
    {
        free(result[i]);
        i++;
    }
    free(result);
}

static char **words_split(char **result, char const *s, char c, size_t word_count)
{
    size_t i = 0;
    size_t n;
    while (i < word_count)
    {
        n = 0;
        while (*s == c && *s)
            s++;
        while (*s != c && *s)
        {
            n++;
            s++;
        }
        result[i] = strndup_split(s - n, n);
        if (result[i] == NULL)
        {
            free_split(result, (int)i);
            return (NULL);
        }
        i++;
    }
    result[i] = NULL;
    return (result);
}

char **ft_split(char const *s, char c)
{
    char **result;
    size_t word_count = count_words(s, c);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (result == NULL)
        return (NULL);
    return (words_split(result, s, c, word_count));
}

/* ===== ユーティリティ ===== */
static int check_num(char *str)
{
    int i = 0;
    if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
    {
        if (str[i] == '-')
            i++;
        if (str[i] == '\0')
            return (-1); // "-"のみはNG
        while (str[i] != '\0')
        {
            if (str[i] < '0' || str[i] > '9')
                return (-1);
            i++;
        }
        return (0);
    }
    return (-1);
}

static long ft_atol(const char *str)
{
    long res = 0;
    int sign = 1;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);
}

static void push_num(t_stack *stack, int num)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL)
        exit(1);
    node->value = num;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

static void free_stack(t_stack *stack)
{
    t_list *tmp;
    while (stack->top != NULL)
    {
        tmp = stack->top;
        stack->top = tmp->next;
        free(tmp);
    }
    stack->size = 0;
}

/* ===== 重複チェック ===== */
static int has_duplicate(t_stack *a, int num)
{
    t_list *tmp = a->top;
    while (tmp)
    {
        if (tmp->value == num)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

/* ===== organize_astack ===== */
void organize_astack(int argc, char **argv, t_stack *a)
{
    int i = argc - 1;
    while (i >= 1)
    {
        char **nums;
        int j = 0;
        nums = ft_split(argv[i], ' ');
        if (!nums)
            exit(1);
        while (nums[j] != NULL)
            j++;
        while (--j >= 0)
        {
            long val;
            if (check_num(nums[j]) != 0)
            {
                write(2, "Error\n", 6);
                free_split(nums, 0);
                free_stack(a);
                exit(1);
            }
            val = ft_atol(nums[j]);
            if (val < INT_MIN || val > INT_MAX || has_duplicate(a, (int)val))
            {
                write(2, "Error\n", 6);
                free_split(nums, 0);
                free_stack(a);
                exit(1);
            }
            push_num(a, (int)val);
            free(nums[j]);
        }
        free(nums);
        i--;
    }
}

/* ===== 操作関数 ===== */
void sa(t_stack *a){t_list*f,*s;if(a->size<2)return;f=a->top;s=f->next;f->next=s->next;s->next=f;a->top=s;printf("sa\n");}
void ra(t_stack *a){t_list*f,*l;if(a->size<2)return;f=a->top;a->top=f->next;l=a->top;while(l->next)l=l->next;l->next=f;f->next=NULL;printf("ra\n");}
void rra(t_stack *a){t_list*p=NULL,*l;if(a->size<2)return;l=a->top;while(l->next){p=l;l=l->next;}p->next=NULL;l->next=a->top;a->top=l;printf("rra\n");}
void pa(t_stack *a,t_stack *b){t_list*t;if(b->size==0)return;t=b->top;b->top=t->next;t->next=a->top;a->top=t;b->size--;a->size++;printf("pa\n");}
void pb(t_stack *a,t_stack *b){t_list*t;if(a->size==0)return;t=a->top;a->top=t->next;t->next=b->top;b->top=t;a->size--;b->size++;printf("pb\n");}

/* ===== 小規模ソート ===== */
int find_min(t_stack *a){t_list*t=a->top;int min=t->value;while(t){if(t->value<min)min=t->value;t=t->next;}return min;}
void bring_min_to_top(t_stack *a,int min){t_list*t=a->top;int pos=0,i;while(t&&t->value!=min){pos++;t=t->next;}if(pos<=a->size/2){for(i=0;i<pos;i++)ra(a);}else{for(i=0;i<a->size-pos;i++)rra(a);}}
void sort_three(t_stack *a){int x=a->top->value,y=a->top->next->value,z=a->top->next->next->value;
    if(x>y&&y<z&&x<z) sa(a);
    else if(x>y&&y>z){sa(a);rra(a);}
    else if(x>y&&y<z&&x>z) ra(a);
    else if(x<y&&y>z&&x<z){sa(a);ra(a);}
    else if(x<y&&y>z&&x>z) rra(a);
}
void sort_four(t_stack *a,t_stack *b){int min=find_min(a);bring_min_to_top(a,min);pb(a,b);sort_three(a);pa(a,b);}
void sort_five(t_stack *a,t_stack *b){int min;while(a->size>3){min=find_min(a);bring_min_to_top(a,min);pb(a,b);}sort_three(a);while(b->size>0)pa(a,b);}

/* ===== インデックス付け ===== */
static int *stack_to_array(t_stack *a)
{
    int *arr = malloc(sizeof(int) * a->size);
    t_list *t = a->top;
    int i = 0;
    while (t)
    {
        arr[i++] = t->value;
        t = t->next;
    }
    return arr;
}

static void sort_array(int *arr, int size)
{
    int i, j, tmp;
    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (arr[i] > arr[j]) {tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;}
}

static int get_index(int *arr, int size, int value)
{
    int i;
    for (i = 0; i < size; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

static void index_stack(t_stack *a)
{
    int *arr = stack_to_array(a);
    t_list *t = a->top;
    int size = a->size;
    sort_array(arr, size);
    while (t)
    {
        t->value = get_index(arr, size, t->value);
        t = t->next;
    }
    free(arr);
}

/* ===== Radix Sort ===== */
void radix_sort(t_stack *a, t_stack *b)
{
    int max_bits = 0;
    int max_num;
    int i, j, size;

    index_stack(a);
    max_num = a->size - 1;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    size = a->size;
    for (i = 0; i < max_bits; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (((a->top->value >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
        }
        while (b->size > 0)
            pa(a, b);
    }
}

/* ===== デバッグ表示 ===== */
void print_stack(t_stack *s, char name){t_list*t=s->top;printf("%c: ",name);while(t){printf("%d ",t->value);t=t->next;}printf("\n");}

/* ===== main ===== */
int main(int argc, char **argv)
{
    t_stack a, b;
    a.top=NULL; a.size=0;
    b.top=NULL; b.size=0;

    if (argc < 2)
        return 0;

    organize_astack(argc, argv, &a);

    printf("初期状態:\n");
    print_stack(&a, 'A');
    print_stack(&b, 'B');

    if (a.size == 2 && a.top->value > a.top->next->value)
        sa(&a);
    else if (a.size == 3)
        sort_three(&a);
    else if (a.size == 4)
        sort_four(&a, &b);
    else if (a.size == 5)
        sort_five(&a, &b);
    else
        radix_sort(&a, &b);

    printf("ソート後:\n");
    print_stack(&a, 'A');
    print_stack(&b, 'B');

    free_stack(&a);
    free_stack(&b);
    return 0;
}
