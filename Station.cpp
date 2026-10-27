#include "Station.h"
#include "Template.h"
Station::Station()
{
    id = generateID();
    name = "Station";
    workshops = 1;
    activeWorkshops = 1;
    classNumber = 1;
}
int Station::GetID() const { return id; }
string Station::GetName() const { return name; }
int Station::GetWorkshops() const { return workshops; }
int Station::GetActiveWorkshops() const { return activeWorkshops; }
int Station::GetClassNumber() const { return classNumber; }
void Station::SetID(int newID)
{
    id = newID;
    registerID(newID);
}
void Station::SetName(const string& newName)
{
    name = newName;
}
void Station::SetWorkshops(int value)
{
    workshops = value;
}
void Station::SetActiveWorkshops(int value)
{
    activeWorkshops = value;
}
void Station::SetClassNumber(int value)
{
    classNumber = value;
}

void inputStation(Station& station)
{
    string name;
    int workshops, active, classNumber;
    cout << "Введите название станции: ";
    getline(cin >> ws, name);
    cout << "Введите количество цехов: ";
    workshops = readNumber();
    while (workshops <= 0)
    {
        cout << "Ошибка. Должно быть больше 0: ";
        workshops = readNumber();
    }
    cout << "Введите количество работающих цехов: ";
    active = readNumber();
    while (active < 0 || active > workshops)
    {
        cout << "Ошибка. Введите от 0 до "
             << workshops << ": ";
        active = readNumber();
    }
    cout << "Введите класс станции (1 или 2): ";
    classNumber = readNumber();
    while (classNumber < 1 || classNumber > 2)
    {
        cout << "Ошибка. Введите 1 или 2: ";
        classNumber = readNumber();
    }
    station.SetName(name);
    station.SetWorkshops(workshops);
    station.SetActiveWorkshops(active);
    station.SetClassNumber(classNumber);
}

void printStation(const Station& station)
{
    cout << "ID: " << station.GetID() << '\n';
    cout << "Название: " << station.GetName() << '\n';
    cout << "Всего цехов: " << station.GetWorkshops() << '\n';
    cout << "Работающих цехов: "
         << station.GetActiveWorkshops() << '\n';
    cout << "Класс станции: " << station.GetClassNumber() << '\n';
}
