#include "Station.h"
#include "Template.h"
using namespace std;
Station::Station()
{
    id = generateID();
    name = "";
    workshops = 0;
    activeWorkshops = 0;
    classNumber = 1;
}
istream& operator>>(istream& in, Station& station)
{
    if (&in == &cin)
    {
        cout << "Введите название станции: ";
        INPUT_LINE(in, station.name);
        cout << "Введите количество цехов: ";
        station.workshops = GetCorrectNumber(1, 1000000);
        cout << "Введите количество работающих цехов: ";
        station.activeWorkshops = GetCorrectNumber(0, station.workshops);
        cout << "Введите класс станции (1 или 2): ";
        station.classNumber = GetCorrectNumber(1, 2);
    }
    else
    {
        in >> station.id;
        getline(in >> ws, station.name);
        in >> station.workshops >> station.activeWorkshops >> station.classNumber;
        if (!in)
            return in;
        if (station.id >= 1 && !station.name.empty() &&
            station.workshops >= 1 && station.activeWorkshops >= 0 &&
            station.activeWorkshops <= station.workshops &&
            (station.classNumber == 1 || station.classNumber == 2))
        {
            registerID(station.id);
        }
        else
        {
            in.setstate(ios::failbit);
        }
    }
    return in;
}
ostream& operator<<(ostream& out, const Station& station)
{
    if (&out == &cout)
    {
        out << "ID: " << station.id << endl;
        out << "Название: " << station.name << endl;
        out << "Всего цехов: " << station.workshops << endl;
        out << "Работающих цехов: " << station.activeWorkshops << endl;
        out << "Класс станции: " << station.classNumber << endl;
    }
    else
    {
        out << station.id << endl;
        out << station.name << endl;
        out << station.workshops << endl;
        out << station.activeWorkshops << endl;
        out << station.classNumber << endl;
    }
    return out;
}
void Station::edit()
{
    cin >> *this;
}
bool Station::matchesName(const string& text) const
{
    return name.find(text) != string::npos;
}
bool Station::matchesUnused(int percent) const
{
    return (workshops - activeWorkshops) * 100LL >=
           (long long)percent * workshops;
}
bool Station::hasID(int value) const
{
    return id == value;
}
void addStation(vector<Station>& stations)
{
    Station station;
    cin >> station;
    stations.push_back(station);
    logAction("Добавлена станция");
}
void showStations(const vector<Station>& stations)
{
    if (stations.empty())
    {
        cout << "Станций нет" << endl;
        return;
    }
    for (const Station& station : stations)
        cout << station;
}
void editStation(vector<Station>& stations)
{
    cout << "Введите ID станции: ";
    int id = GetCorrectNumber(1, 1000000000);
    for (Station& station : stations)
    {
        if (station.hasID(id))
        {
            station.edit();
            logAction("Отредактирована станция");
            return;
        }
    }
    cout << "Станция не найдена" << endl;
}
void deleteStation(vector<Station>& stations)
{
    cout << "Введите ID станции: ";
    int id = GetCorrectNumber(1, 1000000000);
    for (int i = 0; i < (int)stations.size(); i++)
    {
        if (stations[i].hasID(id))
        {
            stations.erase(stations.begin() + i);
            logAction("Удалена станция");
            return;
        }
    }
    cout << "Станция не найдена" << endl;
}
bool stationNameFilter(const Station& station, string name)
{
    return station.matchesName(name);
}
bool stationUnusedFilter(const Station& station, int percent)
{
    return station.matchesUnused(percent);
}
void searchStations(vector<Station>& stations)
{
    cout << "\nПоиск станций:\n";
    cout << "1. Поиск по названию\n";
    cout << "2. Поиск по проценту неработающих цехов\n";
    cout << "Выберите пункт: ";
    int choice = GetCorrectNumber(1, 2);
    vector<int> found;
    if (choice == 1)
    {
        cout << "Введите название: ";
        string name;
        INPUT_LINE(cin, name);
        found = FindByFilter(stations, stationNameFilter, name);
    }
    else
    {
        cout << "Минимальный процент неработающих цехов: ";
        int percent = GetCorrectNumber(0, 100);
        found = FindByFilter(stations, stationUnusedFilter, percent);
    }
    if (found.empty())
    {
        cout << "Ничего не найдено\n";
        return;
    }
    cout << "\nНайдено станций: " << found.size() << "\n";
    for (int index : found)
        cout << stations[index] << endl;
}