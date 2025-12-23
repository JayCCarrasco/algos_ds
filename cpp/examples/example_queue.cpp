#include <iostream>
#include "../include/ds/queue.hpp"

int main() {
    Queue<int> q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front: " << q.front() << "\n";

    q.pop();
    std::cout << "Front after pop: " << q.front() << "\n";

    while (!q.isEmpty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";

    return 0;
}
