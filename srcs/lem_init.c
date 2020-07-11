#include "../includes/lemin.h"

void    lm_strdel(char **str)
{
    while (*str != NULL)
    {
        ft_strdel(&(*str));
        str += 1;
    }
}

static int  get_size_path(t_links *link, int start, int final)
{
    t_node  *tmp;
    int     i;
    int     k;

    i = 0;
    tmp = link->adjace[start];
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    k = 0;
    tmp = link->adjace[final];
    while (tmp)
    {
        tmp = tmp->next;
        k++;
    }
    // printf("i = %d | k = %d\n", i, k);
    return ((i > k) ? k : i);
}

static t_node   **creat_paths(int size)
{
    t_node  **path;
    int     i;

    if (!(path = malloc(sizeof(t_node *) * size + 1)))
        ft_error(ERR);
    i = -1;
    while (++i < size)
        path[i] = NULL;
    path[i] = NULL;
    return (path);
}

void    lemin_init(t_lemin *lemin, char *str[])
{
    t_rooms *tmp;

    g_id = 0;
    lemin->count = 0;
    lemin->ants = get_ants(str[0]);
    lemin->rooms = get_rooms(&str);
    lemin->links = get_links(lemin->rooms, str);
    tmp = lemin->rooms;
    lemin->size = get_size_path(lemin->links, tmp->start->id, tmp->end->id);
    // printf("size = %d\n", lemin->size);
    lemin->paths = creat_paths(lemin->size);
}