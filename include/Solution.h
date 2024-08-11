#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int solution(std::vector<std::pair<int, int>> task) {

    int sad = 0;

    // —ортируем задачи по дедлайну и стрессу
    // 1 приоритет дедлайн (по убыванию)
    // 2 приоритет стресс (по возрастанию)
    std::sort(task.begin(), task.end(),
        [](const std::pair<int, int>& l, const std::pair<int, int>& r)
        {
            if (l.first > r.first)
                return false;
            if (l.first == r.first && l.second <= r.second)
                return false;

            return true;
        }
    );

    // ќставл€ем только те задани€, которые возможно выполнить
    // Ќа n-ый день, не может быть больше n задач 
    std::vector<std::pair<int, int>> possibleTask;
    possibleTask.push_back(task[0]);
    int day = task[0].first, elemAdd = 1;
    for (size_t i = 1; i < task.size(); i++)
    {
        if (task[i].first != day)
        {
            day = task[i].first;
            elemAdd = 1;
            possibleTask.push_back(task[i]);
        }
        else if (elemAdd != day)
        {
            elemAdd++;
            possibleTask.push_back(task[i]);
        }
        else
        {
            sad += task[i].second;
        }
    }

    // —оставл€ем оптимальный список задач
    int total = 1;
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;

    for (auto& elem : possibleTask)
    {
        // ≈сли задач больше чем возможно выполнить
        // ¬ыполним с наибольшим стрессом
        if (elem.first < total)
        {
            if (minHeap.top() < elem.second)
            {
                sad += minHeap.top();
                minHeap.pop();
                minHeap.push(elem.second);
            }
            else
                sad += elem.second;
        }
        else
        {
            total++;
            minHeap.push(elem.second);
        }
    }

    return sad;
}
