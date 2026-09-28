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
