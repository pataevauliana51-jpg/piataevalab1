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
        INPUT_LINE(in, pipe.name);
        cout << "Введите длину трубы: ";
        pipe.length = GetCorrectNumber(1, 1000000);
        cout << "Введите диаметр трубы: ";
        pipe.diameter = GetCorrectNumber(1, 1000000);
        cout << "Труба в ремонте? (1 - да, 0 - нет): ";
        pipe.isRepair = GetCorrectNumber(0, 1);
    }
    else
    {
        in >> pipe.id;
        getline(in >> ws, pipe.name);
        in >> pipe.length >> pipe.diameter >> pipe.isRepair;
        if (!in)
            return in;
        if (pipe.id >= 1 && !pipe.name.empty() &&
            pipe.length >= 1 && pipe.diameter >= 1)
        {
            registerID(pipe.id);
        }
        else
        {
            in.setstate(ios::failbit);
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
    cin >> *this;
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
void Pipe::setRepair(bool repair)
{
    isRepair = repair;
}
void addPipe(vector<Pipe>& pipes)
{
    Pipe pipe;
    cin >> pipe;
    pipes.push_back(pipe);
    logAction("Добавлена труба");
}
void showPipes(const vector<Pipe>& pipes)
{
    if (pipes.empty())
    {
        cout << "Труб нет" << endl;
        return;
    }
    for (const Pipe& pipe : pipes)
        cout << pipe;
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
            logAction("Отредактирована труба");
            return;
        }
    }
    cout << "Труба не найдена" << endl;
}
void deletePipe(vector<Pipe>& pipes)
{
    cout << "Введите ID трубы: ";
    int id = GetCorrectNumber(1, 1000000000);
    for (int i = 0; i < (int)pipes.size(); i++)
    {
        if (pipes[i].hasID(id))
        {
            pipes.erase(pipes.begin() + i);
            logAction("Удалена труба");
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
void batchPipes(vector<Pipe>& pipes, const vector<int>& selected, int action)
{
    if (action == 1)
    {
        cout << "Новое состояние ремонта (1 - да, 0 - нет): ";
        bool repair = GetCorrectNumber(0, 1) == 1;
        for (int index : selected)
            pipes[index].setRepair(repair);
        cout << "Изменено труб: " << selected.size() << "\n";
    }
    else
    {
        for (int i = (int)selected.size() - 1; i >= 0; i--)
            pipes.erase(pipes.begin() + selected[i]);
        cout << "Удалено труб: " << selected.size() << "\n";
    }
    logAction("Пакетная операция с трубами");
}
void searchPipes(vector<Pipe>& pipes)
{
    cout << "\nПоиск труб:\n";
    cout << "1. Поиск по названию\n";
    cout << "2. Поиск по ремонту\n";
    cout << "Выберите пункт: ";
    int choice = GetCorrectNumber(1, 2);
    vector<int> found;
    if (choice == 1)
    {
        cout << "Введите название: ";
        string name;
        INPUT_LINE(cin, name);
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
        cout << "Ничего не найдено\n";
        return;
    }
    cout << "\nНайдено труб: " << found.size() << "\n";
    for (int index : found)
        cout << pipes[index] << endl;
    cout << "\nЧто сделать с найденными трубами?\n";
    cout << "1. Редактировать\n";
    cout << "2. Удалить\n";
    cout << "0. Назад\n";
    cout << "Выберите действие: ";
    int action = GetCorrectNumber(0, 2);
    if (action == 0)
        return;
    vector<int> selected = selectObjects(pipes, found);
    if (selected.empty())
    {
        cout << "Объекты не выбраны\n";
        return;
    }
    batchPipes(pipes, selected, action);
}
void saveData(const vector<Pipe>& pipes, const vector<Station>& stations)
{
    cout << "Введите имя файла: ";
    string filename;
    INPUT_LINE(cin, filename);
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
    out.flush();
    if (!out)
    {
        cout << "Ошибка записи файла" << endl;
        return;
    }
    cout << "Данные сохранены" << endl;
    logAction("Данные сохранены в файл");
}
void loadData(vector<Pipe>& pipes, vector<Station>& stations)
{
    cout << "Введите имя файла: ";
    string filename;
    INPUT_LINE(cin, filename);
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
    pipes = loadedPipes;
    stations = loadedStations;
    cout << "Данные загружены" << endl;
    logAction("Данные загружены из файла");
}