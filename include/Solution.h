#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<std::pair<int, int>> task) {

    int sad = 0;
    
    // ��������� ������ �� �������� � �������
    // 1 ��������� ������� (�� ��������)
    // 2 ��������� ������ (�� �����������)
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
    
    // ��������� ������ �� �������, ������� �������� ���������
    // �� n-�� ����, �� ����� ���� ������ n ����� 
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
    
    // ����� ������� ������ � ���������� ��������
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

    // ���������� ����������� ������ �����
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
