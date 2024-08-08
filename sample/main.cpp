#include <iostream>
#include <vector>
#include <Solution.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++)
        std::cin >> tasks[i].first >> tasks[i].second;

    std::cout << "result : " << solution(tasks);
    return 0;
}