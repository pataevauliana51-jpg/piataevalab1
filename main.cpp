
#include <iostream>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include "Template.h"
using namespace std;

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
        cout << "0. Выход\n";
        cout << "Введите команду: ";
        command = GetCorrectNumber(0, 4);
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
        case 0:
            cout << "Выход из программы\n";
            break;
        }
    } while (command != 0);

    return 0;
}
