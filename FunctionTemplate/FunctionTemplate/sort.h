#include <algorithm>
template<typename T, typename fnc> 
void mySort(T f, T s, fnc cmp) {
    for (T i = f; i != s; i++) {
        for (T j = i; j != s; j++) {
            if (!cmp(*i, *j))
                std::swap(*i, *j);
        }
    }
}

template<typename T>
void mySort(T f, T s) {
    for (T i = f; i != s; i++) {
        for (T j = i; j != s; j++) {
            if (*j < *i)
                std::swap(*i, *j);
        }
    }
}
