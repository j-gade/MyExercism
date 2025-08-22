#pragma once

#include <vector>

namespace list_ops {

template <typename T>
void append(std::vector<T>& left, std::vector<T>& right)
{
    for (auto item : right)
        left.emplace_back(item);
}

template <typename T>
std::vector<T> concat(std::vector<std::vector<T> > lists)
{
    std::vector<T> new_list;
    if (lists.empty())
        return new_list;
    for (auto list : lists)
        for (auto item : list)
            new_list.emplace_back(item);

    return new_list;
}

template <typename T, typename F>
std::vector<T> filter(std::vector<T> list, F isTrue)
{
    std::vector<T> new_list;
    if (list.empty())
        return new_list;
    for (auto item : list)
        if (isTrue(item))
            new_list.emplace_back(item);

    return new_list;
}

template <typename T>
size_t length(std::vector<T> list)
{
    return list.size();
}

template <typename T, typename F>
std::vector<T> map(std::vector<T> list, F apply)
{
    std::vector<T> new_list;
    if (list.empty())
        return new_list;
    for (auto item : list)
        new_list.emplace_back(apply(item));

    return new_list;
}

template <typename T, typename F>
T foldl(std::vector<T> list, T init, F apply)
{
    T acc{ init };
    if (list.empty())
        return acc;
    for (auto item : list)
        acc = apply(acc, item);

    return acc;
}

template <typename T, typename F>
T foldr(std::vector<T> list, T init, F apply)
{
    T acc{ init };
    if (list.empty())
        return acc;
    for (auto i {list.rbegin()}; i != list.rend(); ++i)
        acc = apply(acc, *i);

    return acc;
}

template <typename T>
std::vector<T> reverse(std::vector<T> list)
{
    std::vector<T> new_list;
    if (list.empty())
        return new_list;
    for (auto i{ list.rbegin() }; i != list.rend(); ++i)
        new_list.emplace_back(*i);

    return new_list;
}

}  // namespace list_ops
