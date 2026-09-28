#include <iostream>
#include <string>
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
void changeRepair(Pipe& pipe, bool status)
{
    pipe.isRepair = status;
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
