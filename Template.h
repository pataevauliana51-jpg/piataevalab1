#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
using namespace std;
inline int readNumber()
{
    int number;
    cin >> number;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка. Введите число: ";
        cin >> number;
    }
    return number;
}
inline int& currentID()
{
    static int id = 1;
    return id;
}
inline int generateID()
{
    return currentID()++;
}
inline void registerID(int id)
{
    if (id >= currentID())
    {
        currentID() = id + 1;
    }
}

#endif