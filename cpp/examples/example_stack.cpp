#include <iostream>
#include "../include/ds/stack.hpp"

int main() {
    Stack<int> s(3);

    s.push(10);
    s.push(20);

    std::cout << "Top: " << s.peek() << '\n';

    s.pop();
    std::cout << "Size: " << s.size() << '\n';

    return 0;
}
