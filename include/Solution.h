#pragma once
#include <iostream>
#include <vector>
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
    
    // ѕоиск индекса задачи с наименьшим стрессом
    auto minElemIndx = [](const std::vector<std::pair<int, int>>& data) 
        {
            int min = data[0].second, index = 0;
            for (int i = 1; i < (int)data.size(); i++)
            {
                if (data[i].second < min)
                {
                    min = data[i].second;
                    index = i;
                }
            }
            return index;
        };

    // —оставл€ем оптимальный список задач
    int total = 1;
    std::vector<std::pair<int, int>> resultTask;
    for (auto& elem : possibleTask)
    {
        if (elem.first < total)
        {
            int indx = minElemIndx(resultTask);
            if (resultTask[indx].second < elem.second)
            {
                sad += resultTask[indx].second;
                resultTask[indx] = elem;
            }
            else
                sad += elem.second;
        }
        else
        {
            total++;
            resultTask.push_back(elem);
        }
    }

    return sad;
}
