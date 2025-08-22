#include <assert.h>

#include "list_ops.h"

static list_t *new_empty_list(size_t length)
{
    list_t * list = (list_t*)malloc(sizeof(list_t) +
        sizeof(list_element_t) * length);
    assert(list);
    list->length = length;
    return list;
}

list_t *new_list(size_t length, list_element_t elements[])
{
    list_t * list = new_empty_list(length);
    for (size_t i = 0; i < length; ++i)
        list->elements[i] = elements[i];

    return list;
}

list_t *append_list(list_t *list1, list_t *list2)
{
    size_t length = list1->length + list2->length;
    list_t * appended = new_empty_list(length);
    
    for (size_t i = 0; i < list1->length; ++i)
        appended->elements[i] = list1->elements[i];

    for (size_t start = list1->length, i = 0; i < list2->length; ++i)
        appended->elements[start + i] = list2->elements[i];
    
    return appended;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    list_t * filtered = new_empty_list(list->length);
    size_t length = 0;
    for (size_t i = 0; i < list->length; ++i)
        if (filter(list->elements[i])) {
            filtered->elements[length] = list->elements[i];
            ++length;
    }

    filtered->length = length;
    return filtered;
}

size_t length_list(list_t *list)
{
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    list_t * mapped = new_empty_list(list->length);
    for (size_t i = 0; i < list->length; ++i)
        mapped->elements[i] = map(list->elements[i]);

    return mapped;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
    for (size_t i = 0; i < list->length; ++i)
        initial = foldl(list->elements[i], initial);
    
    return initial;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t))
{
    for (size_t i = list->length; i > 0; --i)
        initial = foldr(list->elements[i - 1], initial);

    return initial;
}   

list_t *reverse_list(list_t *list)
{
    list_t * reversed = new_empty_list(list->length);
    for (size_t i = 0, j = list->length - 1; i < list->length; ++i, --j)
        reversed->elements[i] = list->elements[j];

    return reversed;
}

void delete_list(list_t *list)
{
    list->length = 0;
    free(list);
}
