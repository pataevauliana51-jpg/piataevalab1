#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <string>
#define INPUT_LINE(in, str) getline(in >> std::ws, str); \
    std::cerr << str << std::endl
#define PRINT_PARAM(out, x) out << #x << "=" << x << std::endl
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
template <typename T, typename P>
using Filter = bool(*)(const T&, P);
template <typename T, typename P>
std::vector<int> FindByFilter(const std::vector<T>& objects, Filter<T, P> filter, P param)
{
    std::vector<int> result;
    for (int i = 0; i < (int)objects.size(); i++)
    {
        if (filter(objects[i], param))
        {
            result.push_back(i);
        }
    }
    return result;
}
