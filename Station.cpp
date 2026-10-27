#include "Station.h"
#include "Pipe.h"
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
    cout << "Название станции: ";
    cin >> name;
    cout << "Количество цехов: ";
    cin >> workshops;
    cout << "Количество работающих цехов: ";
    cin >> active;
    cout << "Класс станции: ";
    cin >> classNumber;
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
