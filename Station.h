#ifndef STATION_H
#define STATION_H
#include <iostream>
#include <string>
using namespace std;
class Station
{
private:
    int id;
    string name;
    int workshops;
    int activeWorkshops;
    int classNumber;
public:
    Station();
    int GetID() const;
    string GetName() const;
    int GetWorkshops() const;
    int GetActiveWorkshops() const;
    int GetClassNumber() const;
    void SetID(int newID);
    void SetName(const string& newName);
    void SetWorkshops(int value);
    void SetActiveWorkshops(int value);
    void SetClassNumber(int value);
};
void inputStation(Station& station);
void printStation(const Station& station);
#endif
