#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Pipe
{
    int kilometer_mark;
    int length;
    int diameter;
    string name;
    bool isRepair;
};
struct Compress_Station 
{
    string name;
    int workshops;
    int active_workshops;
    int class_number;
};
int readNumber()
{
    int number;
    cin >> number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> number;
    }
    return number;
}
void addPipe(Pipe& pipe)
{
    cout << "Enter pipe name: ";
    getline(cin>>ws, pipe.name);
    while (pipe.name.empty()) {
        cout << "Error. Name cannot be empty: ";
        getline(cin >> ws, pipe.name);
    }
    cout << "Enter kilometr mark: ";
    pipe.kilometer_mark= readNumber();
    while (pipe.kilometer_mark <= 0) {
        cout << "Error. Kilometer mark cannot be negative: ";
        pipe.kilometer_mark = readNumber();
    }
    cout << "Enter length: ";
    pipe.length = readNumber();
    while (pipe.length <= 0) {
        cout << "Error. Length must be positive: ";
        pipe.length = readNumber();
    }
    cout << "Enter diameter: ";
    pipe.diameter = readNumber();
    while (pipe.diameter <= 0) {
        cout << "Error. Diameter must be positive: ";
        pipe.diameter = readNumber();
    }
    int repair;
    cout << "Is the pipe under repair? (1 for yes, 0 for no): ";
        repair = readNumber();
    while (repair != 0 && repair != 1)
    {
        cout << "Error. Enter 0 or 1: ";
        repair = readNumber();
    }
    pipe.isRepair = repair;
}
void showPipe(const Pipe& pipe)
{
    cout << "Pipe:\n";
    cout << "Name: " << pipe.name << "\n";
    cout << "Kilometer mark: " << pipe.kilometer_mark << "\n";
    cout << "Length: " << pipe.length << " km\n";
    cout << "Diameter: " << pipe.diameter << " mm\n";
    cout << "Repair: " << (pipe.isRepair ? "Yes" : "No") << "\n";
}
void addStation(Compress_Station& station)
{
    cout << "Enter station name: ";
    getline(cin >> ws, station.name);
    while (station.name.empty()) {
        cout << "Error. Name cannot be empty: ";
        getline(cin >> ws, station.name);
    }
    cout << "Enter number of workshops: ";
    station.workshops = readNumber();
    while (station.workshops <= 0) {
        cout << "Error. Must be greater than 0: ";
        station.workshops = readNumber();
    }
    cout << "Enter number of working workshops: ";
    station.active_workshops = readNumber();
    while (station.active_workshops < 0 ||
           station.active_workshops > station.workshops) {
        cout << "Error. Enter from 0 to "
             << station.workshops << ": ";
        station.active_workshops = readNumber();
    }
    cout << "Enter station class (1 or 2): ";
    station.class_number = readNumber();
    while (station.class_number < 1 ||
           station.class_number > 2) {
        cout << "Error. Enter 1 or 2: ";
        station.class_number = readNumber();
    }
}
void showStation(const Compress_Station& station)
{
    cout << "Compressor station:\n";
    cout << "Name: " << station.name << "\n";
    cout << "Workshops: " << station.workshops << "\n";
    cout << "Working workshops: " << station.active_workshops << "\n";
    cout << "Class: " << station.class_number << "\n";
}
void startShop(Compress_Station& station)
{
    if (station.active_workshops < station.workshops) {
        station.active_workshops++;
        cout << "Workshop started.\n";
    }
    else {
        cout << "All workshops are already working.\n";
    }
}
void stopShop(Compress_Station& station)
{
    if (station.active_workshops > 0) {
        station.active_workshops--;
        cout << "Workshop stopped.\n";
    }
    else {
        cout << "All workshops are already stopped.\n";
    }
}
void showAll(const Pipe& pipe, const Compress_Station& station)
{
    if (pipe.name.empty())
        cout << "Pipe is not created.\n";
    else
        showPipe(pipe);
    cout << "\n";
    if (station.name.empty())
        cout << "Compressor station is not created.\n";
    else
        showStation(station);
}
void changePipe(Pipe& pipe)
{
    if (pipe.name.empty()) {
        cout << "Pipe is not created.\n";
        return;
    }
    cout << "1. Set repair\n";
    cout << "2. Set not repair\n";
    cout << "0. Back\n";
    cout << "Enter command: ";
    int command = readNumber();
    while (command < 0 || command > 2) {
        cout << "Error. Enter 0, 1 or 2: ";
        command = readNumber();
    }
    if (command == 1)
         pipe.isRepair = true;
    else if (command == 2)
        pipe.isRepair = false;
}
void changeStation(Compress_Station& station)
{
    if (station.name.empty()) {
        cout << "Station is not created.\n";
        return;
    }
    cout << "1. Start workshop\n";
    cout << "2. Stop workshop\n";
    cout << "0. Back\n";
    cout << "Enter command: ";
    int command = readNumber();
    while (command < 0 || command > 2) {
        cout << "Error. Enter 0, 1 or 2: ";
        command = readNumber();
    }
    if (command == 1)
        startShop(station);
    else if (command == 2)
        stopShop(station);
}
void writePipe(ofstream& file, const Pipe& pipe)
{
    file << pipe.name << "\n";
    file << pipe.kilometer_mark << "\n";
    file << pipe.length << "\n";
    file << pipe.diameter << "\n";
    file << pipe.isRepair << "\n";
}
void writeStation(ofstream& file, const Compress_Station& station)
{
    file << station.name << "\n";
    file << station.workshops << "\n";
    file << station.active_workshops << "\n";
    file << station.class_number << "\n";
}
void readPipe(ifstream& file, Pipe& pipe)
{
    getline(file >> ws, pipe.name);
    file >> pipe.kilometer_mark;
    file >> pipe.length;
    file >> pipe.diameter;
    file >> pipe.isRepair;
}
void readStation(ifstream& file, Compress_Station& station)
{
    getline(file >> ws, station.name);
    file >> station.workshops;
    file >> station.active_workshops;
    file >> station.class_number;
}
