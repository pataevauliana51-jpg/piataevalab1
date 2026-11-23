#ifndef STATION_H
#define STATION_H
#include <iostream>
#include <string>
#include <vector>
class Station
{
private:
    int id;
    std::string name;
    int workshops;
    int activeWorkshops;
    int classNumber;
public:
    Station();
    bool matchesName(const std::string& text) const;
    bool matchesUnused(int percent) const;
    bool hasID(int value) const;
    void edit();
    friend std::istream& operator>>(std::istream& in, Station& station);
    friend std::ostream& operator<<(std::ostream& out, const Station& station);
};
void addStation(std::vector<Station>& stations);
void showStations(const std::vector<Station>& stations);
void editStation(std::vector<Station>& stations);
void deleteStation(std::vector<Station>& stations);
void searchStations(std::vector<Station>& stations);
#endif
