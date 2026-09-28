#include <iostream>
#include <string>
using namespace std;
struct Pipe
{
    int kilometr_mark;
    int length;
    int diameter;
    string name;
    bool isRepair;
}
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
    while (cin.fail() 
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

void addPipe(Pipe& pipes)
{
    cout << "Enter pipe name: ";
    getline(cin, pipes[count].name);
    cout << "Enter kilometr mark: ";
    pipes[count].kilometr_mark = readNumber();
    cout << "Enter length: ";
    pipes[count].length = readNumber();
    cout << "Enter diameter: ";
    pipes[count].diameter = readNumber();
    cout << "Is the pipe under repair? (1 for yes, 0 for no): ";
    int repairInput = readNumber();
    pipes[count].isRepair = (repairInput == 1);
    count++;
}