
#include "Pipe.h"
#include "Station.h"
#include "Template.h"
#include <fstream>
using namespace std;
Pipe::Pipe()
{
    id = generateID();
    length = 0;
    diameter = 0;
    name = "";
    isRepair = false;
}
istream& operator>>(istream& in, Pipe& pipe)
{
    if (&in == &cin)
    {
        cout << "Введите название трубы: ";
        getline(in >> ws, pipe.name);
        cout << "Введите длину трубы: ";
        pipe.length = GetCorrectNumber(1, 1000000);
        cout << "Введите диаметр трубы: ";
        pipe.diameter = GetCorrectNumber(1, 1000000);
        cout << "Труба в ремонте? (1 - да, 0 - нет): ";
        pipe.isRepair = GetCorrectNumber(0, 1) == 1;
    }
    else
    {
        int repair;
        if (!(in >> pipe.id))
        {
            return in;
        }
        getline(in >> ws, pipe.name);
        in >> pipe.length >> pipe.diameter >> repair;
        if (in)
        {
            if (pipe.id < 1 || pipe.name.empty() || pipe.length < 1 || pipe.diameter < 1 || (repair != 0 && repair != 1))
            {
                in.setstate(ios::failbit);
            }
            else
            {
                pipe.isRepair = repair == 1;
                registerID(pipe.id);
            }
        }
    }
    return in;
}
ostream& operator<<(ostream& out, const Pipe& pipe)
{
    if (&out == &cout)
    {
        out << "ID: " << pipe.id << endl;
        out << "Название: " << pipe.name << endl;
        out << "Длина: " << pipe.length << " км" << endl;
        out << "Диаметр: " << pipe.diameter << " мм" << endl;
        out << "Ремонт: " << (pipe.isRepair ? "Да" : "Нет") << endl;
    }
    else
    {
        out << pipe.id << endl;
        out << pipe.name << endl;
        out << pipe.length << endl;
        out << pipe.diameter << endl;
        out << pipe.isRepair << endl;
    }
    return out;
}
void Pipe::edit()
{
    cout << "Введите новое название: ";
    getline(cin >> ws, name);
    cout << "Введите новую длину: ";
    length = GetCorrectNumber(1, 1000000);
    cout << "Введите новый диаметр: ";
    diameter = GetCorrectNumber(1, 1000000);
    cout << "Труба в ремонте? (1 - да, 0 - нет): ";
    isRepair = GetCorrectNumber(0, 1) == 1;
}
bool Pipe::matchesName(const string& text) const
{
    return name.find(text) != string::npos;
}
bool Pipe::matchesRepair(bool repair) const
{
    return isRepair == repair;
}
bool Pipe::hasID(int value) const
{
    return id == value;
}
void addPipe(vector<Pipe>& pipes)
{
    Pipe pipe;
    cin >> pipe;
    pipes.push_back(pipe);
}
void showPipes(const vector<Pipe>& pipes)
{
    if (pipes.empty())
    {
        cout << "Труб нет" << endl;
    }
    for (const Pipe& pipe : pipes)
    {
        cout << pipe;
    }
}
void editPipe(vector<Pipe>& pipes)
{
    cout << "Введите ID трубы: ";
    int id = GetCorrectNumber(1, 1000000000);
    for (Pipe& pipe : pipes)
    {
        if (pipe.hasID(id))
        {
            pipe.edit();
            return;
        }
    }
    cout << "Труба не найдена" << endl;
}
void deletePipe(vector<Pipe>& pipes)
{
    cout << "Введите ID трубы: ";
    int id = GetCorrectNumber(1, 1000000000);
    for (auto it = pipes.begin(); it != pipes.end(); ++it)
    {
        if (it->hasID(id))
        {
            pipes.erase(it);
            cout << "Труба удалена" << endl;
            return;
        }
    }
    cout << "Труба не найдена" << endl;
}
bool pipeNameFilter(const Pipe& pipe, string name)
{
    return pipe.matchesName(name);
}
bool pipeRepairFilter(const Pipe& pipe, bool repair)
{
    return pipe.matchesRepair(repair);
}
void searchPipes(const vector<Pipe>& pipes)
{
    cout << "1. Поиск по названию" << endl;
    cout << "2. Поиск по ремонту" << endl;
    cout << "Выберите пункт: ";
    int choice = GetCorrectNumber(1, 2);
    vector<int> found;
    if (choice == 1)
    {
        cout << "Введите название: ";
        string name;
        getline(cin >> ws, name);
        found = FindByFilter(pipes, pipeNameFilter, name);
    }
    else
    {
        cout << "Ремонт (1 - да, 0 - нет): ";
        bool repair = GetCorrectNumber(0, 1) == 1;
        found = FindByFilter(pipes, pipeRepairFilter, repair);
    }
    if (found.empty())
    {
        cout << "Ничего не найдено" << endl;
    }
    else
    {
        for (int i : found)
        {
            cout << pipes[i];
        }
    }
}
void saveData(const vector<Pipe>& pipes, const vector<Station>& stations)
{
    cout << "Введите имя файла: ";
    string filename;
    getline(cin >> ws, filename);
    ofstream out(filename);
    if (!out)
    {
        cout << "Не удалось открыть файл" << endl;
        return;
    }
    for (const Pipe& pipe : pipes)
    {
        out << "Pipe" << endl;
        out << pipe;
    }
    for (const Station& station : stations)
    {
        out << "Station" << endl;
        out << station;
    }
    if (!out)
    {
        cout << "Ошибка записи файла" << endl;
        return;
    }
    cout << "Данные сохранены" << endl;
}
void loadData(vector<Pipe>& pipes, vector<Station>& stations)
{
    cout << "Введите имя файла: ";
    string filename;
    getline(cin >> ws, filename);
    ifstream in(filename);
    if (!in)
    {
        cout << "Не удалось открыть файл" << endl;
        return;
    }
    vector<Pipe> loadedPipes;
    vector<Station> loadedStations;
    string type;
    while (in >> type)
    {
        if (type == "Pipe")
        {
            Pipe pipe;
            if (!(in >> pipe))
            {
                cout << "Ошибка чтения трубы" << endl;
                return;
            }
            loadedPipes.push_back(pipe);
        }
        else if (type == "Station")
        {
            Station station;
            if (!(in >> station))
            {
                cout << "Ошибка чтения станции" << endl;
                return;
            }
            loadedStations.push_back(station);
        }
        else
        {
            cout << "Неизвестный тип объекта" << endl;
            return;
        }
    }
    if (!in.eof())
    {
        cout << "Ошибка чтения файла" << endl;
        return;
    }
    for (const Pipe& pipe : loadedPipes)
    {
        for (const Pipe& previous : pipes)
        {
            (void)previous;
        }
        (void)pipe;
    }
    pipes = loadedPipes;
    stations = loadedStations;
    cout << "Данные загружены" << endl;
}
