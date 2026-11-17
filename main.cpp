#include <iostream>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include "Template.h"
using namespace std;
void printMenu()
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
    cout << "9. Поиск труб\n";
    cout << "10. Поиск станций\n";
    cout << "11. Сохранить в файл\n";
    cout << "12. Загрузить из файла\n";
    cout << "0. Выход\n";
    cout << "Введите команду: ";
}
int main()
{
    vector<Pipe> pipes;
    vector<Station> stations;
    int command;
    do
    {
        printMenu();
        command = GetCorrectNumber(0, 12);
        switch (command)
        {
            case 1:
                addPipe(pipes);
                break;
            case 2:
                addStation(stations);
                break;
            case 3:
                showPipes(pipes);
                break;
            case 4:
                showStations(stations);
                break;
            case 5:
                editPipe(pipes);
                break;
            case 6:
                editStation(stations);
                break;
            case 7:
                deletePipe(pipes);
                break;
            case 8:
                deleteStation(stations);
                break;
            case 9:
                searchPipes(pipes);
                break;
            case 10:
                searchStations(stations);
                break;
            case 11:
                saveData(pipes, stations);
                break;
            case 12:
                loadData(pipes, stations);
                break;
            case 0:
                cout << "Выход из программы\n";
                break;
        }
    }
    while (command != 0);
    return 0;
}
