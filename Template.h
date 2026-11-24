#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <fstream>
#include <algorithm>
#define INPUT_LINE(in, str) getline(in >> std::ws, str); \
                            std::cerr << str << std::endl
class redirect_output_wrapper
{
    std::ostream& stream;
    std::streambuf* const old_buf;
public:
    redirect_output_wrapper(std::ostream& src)
        : stream(src), old_buf(src.rdbuf())
    {
    }
    ~redirect_output_wrapper()
    {
        stream.rdbuf(old_buf);
    }
    void redirect(std::ostream& dest)
    {
        stream.rdbuf(dest.rdbuf());
    }
};
template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while (!(std::cin >> x) || std::cin.peek() != '\n' || x < min || x > max)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите число от " << min << " до " << max << ": ";
    }
    std::cerr << x << std::endl;
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
        currentID() = id + 1;
}
template <typename T, typename P>
using Filter = bool(*)(const T&, P);
template <typename T, typename P>
std::vector<int> FindByFilter(const std::vector<T>& objects, Filter<T, P> filter, P param)
{
    std::vector<int> result;
    for (int i = 0; i < (int)objects.size(); i++)
    {
        if (filter(objects[i], param))
            result.push_back(i);
    }
    return result;
}
inline void logAction(const std::string& action)
{
    std::cerr << action << std::endl;
}
template <typename T>
std::vector<int> selectObjects(const std::vector<T>& objects, const std::vector<int>& found)
{
    std::cout << "\n1. Все найденные\n";
    std::cout << "2. Выбрать по ID\n";
    int choice = GetCorrectNumber(1, 2);
    if (choice == 1)
        return found;
    std::vector<int> selected;
    std::cout << "Введите ID объектов (0 - закончить):\n";
    while (true)
    {
        int id = GetCorrectNumber(0, 1000000);
        if (id == 0)
            break;
        for (int index : found)
        {
            if (objects[index].hasID(id))
            {
                bool exists = false;
                for (int i : selected)
                    if (i == index)
                        exists = true;
                if (!exists)
                {
                    selected.push_back(index);
                    std::cout << "Объект выбран\n";
                }
                break;
            }
        }
    }
    std::sort(selected.begin(), selected.end());
    return selected;
}