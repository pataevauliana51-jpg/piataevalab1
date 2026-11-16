#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
using namespace std;
template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((cin >> x).fail() || cin.peek() != '\n'
           || x < min || x > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите число от " << min << " до " << max << ": ";
    }
    return x;
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