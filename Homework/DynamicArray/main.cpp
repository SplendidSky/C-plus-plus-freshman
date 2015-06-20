#include <iostream>
#include <vector>
#include "dynamicArray.h"
 
int main() {
    int a[] = {2, 3, 3};
    std::vector<int> v(1, 2);
    dynamic_array a1,
                  a2(5),
                  a3(5, 6),
                  a4(a, 3),
                  a5(v);
    dynamic_array a6(a4);
    std::cin >> a2[5];
    std::cout << a1 << std::endl
              << a2 << std::endl
              << a3 << std::endl
              << a4 << std::endl
              << a5 << std::endl
              << a6 << std::endl
              << a6.getSize() << std::endl;
    return 0;
}
 