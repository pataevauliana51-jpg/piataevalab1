
#include <iostream>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include "Template.h"
using namespace std;

int findPipeIndex(const vector<Pipe>& pipes, int id)
{
    for (int i = 0; i < (int)pipes.size(); i++)
    {
        if (pipes[i].GetID() == id)
            return i;
    }
    return -1;
}

int findStationIndex(const vector<Station>& stations, int id)
{
    for (int i = 0; i < (int)stations.size(); i++)
    {
        if (stations[i].GetID() == id)
            return i;
    }
    return -1;
}

int main()
{
    setlocale(LC_ALL, "");
    vector<Pipe> pipes;
    vector<Station> stations;
    int command;
    do
    {
        cout << "\nМеню:\n";
        cout << "1. Добавить трубу\n";
        cout << "2. Добавить станцию\n";
        cout << "3. Показать все трубы\n";
        cout << "4. Показать все станции\n";
        cout << "5. Редактировать трубу\n";
        cout << "6. Редактировать станцию\n";
        cout << "7. Удалить трубу\n";
        cout << "8. Удалить станцию\n";
        cout << "0. Выход\n";
        cout << "Введите команду: ";
        command = GetCorrectNumber(0, 8);
        switch (command)
        {
        case 1:
        {
            Pipe pipe;
            inputPipe(pipe);
            pipes.push_back(pipe);
            cout << "Труба добавлена\n";
            break;
        }
        case 2:
        {
            Station station;
            inputStation(station);
            stations.push_back(station);
            cout << "Станция добавлена\n";
            break;
        }
        case 3:
        {
            if (pipes.empty())
                cout << "Труб пока нет\n";
            else
            {
                for (int i = 0; i < (int)pipes.size(); i++)
                {
                    cout << "\nТруба " << i + 1 << ":\n";
                    printPipe(pipes[i]);
                }
            }
            break;
        }
        case 4:
        {
            if (stations.empty())
                cout << "Станций пока нет\n";
            else
            {
                for (int i = 0; i < (int)stations.size(); i++)
                {
                    cout << "\nСтанция " << i + 1 << ":\n";
                    printStation(stations[i]);
                }
            }
            break;
        }
        case 5:
        {
            int id;
            cout << "Введите ID трубы: ";
            id = GetCorrectNumber(1, 1000000);

            int index = findPipeIndex(pipes, id);

            if (index == -1)
             cout << "Труба не найдена\n";
            else
            {
               inputPipe(pipes[index]);
                cout << "Труба изменена\n";
            }
            break;
        }

        case 6:
        {
             int id;
            cout << "Введите ID станции: ";
            id = GetCorrectNumber(1, 1000000);

            int index = findStationIndex(stations, id);

            if (index == -1)
                 cout << "Станция не найдена\n";
            else
            {
                inputStation(stations[index]);
                cout << "Станция изменена\n";
            }
            break;
        }

        case 7:
        {
             int id;
             cout << "Введите ID трубы для удаления: ";
            id = GetCorrectNumber(1, 1000000);

            int index = findPipeIndex(pipes, id);

            if (index == -1)
                cout << "Труба не найдена\n";
            else
            {
                pipes.erase(pipes.begin() + index);
                cout << "Труба удалена\n";
            }
            break;
        }

        case 8:
        {
            int id;
            cout << "Введите ID станции для удаления: ";
            id = GetCorrectNumber(1, 1000000);

            int index = findStationIndex(stations, id);

            if (index == -1)
                cout << "Станция не найдена\n";
            else
            {
                stations.erase(stations.begin() + index);
                cout << "Станция удалена\n";
            }
            break;
        }

        case 0:
            cout << "Выход из программы\n";
            break;
        }
    } while (command != 0);

    return 0;
}
