#include "Pipe.h"
#include "Template.h"
using namespace std;
Pipe::Pipe()
{
    id = generateID();
    length = 1;
    diameter = 1;
    name = "Pipe";
    isRepair = false;
}
int Pipe::GetID() const { return id; }
string Pipe::GetName() const { return name; }
bool Pipe::GetRepair() const { return isRepair; }
int Pipe::GetLength() const { return length; }
int Pipe::GetDiameter() const { return diameter; }
void Pipe::SetID(int newID)
{
    id = newID;
    registerID(newID);
}
void Pipe::SetName(const string& newName)
{
    name = newName;
}
void Pipe::SetLength(int newLength)
{
    length = newLength;
}
void Pipe::SetDiameter(int newDiameter)
{
    diameter = newDiameter;
}
void Pipe::SetRepair(bool repair)
{
    isRepair = repair;
}
void inputPipe(Pipe& pipe)
{
    string name;
    int length, diameter, repair;
    cout << "Введите название трубы: ";
    getline(cin >> ws, name);
    cout << "Введите длину: ";
    length = readNumber();
    while (length <= 0)
    {
        cout << "Ошибка. Длина должна быть положительной: ";
        length = readNumber();
    }
    cout << "Введите диаметр: ";
    diameter = readNumber();
    while (diameter <= 0)
    {
        cout << "Ошибка. Диаметр должен быть положительным: ";
        diameter = readNumber();
    }
    cout << "Находится ли труба в ремонте? (1 - да, 0 - нет): ";
    repair = readNumber();
    while (repair != 0 && repair != 1)
    {
        cout << "Ошибка. Введите 0 или 1: ";
        repair = readNumber();
    }
    pipe.SetName(name);
    pipe.SetLength(length);
    pipe.SetDiameter(diameter);
    pipe.SetRepair(repair == 1);
}
void printPipe(const Pipe& pipe)
{
    cout << "ID: " << pipe.GetID() << '\n';
    cout << "Название: " << pipe.GetName() << '\n';
    cout << "Длина: " << pipe.GetLength() << " км\n";
    cout << "Диаметр: " << pipe.GetDiameter() << " мм\n";
    cout << "Ремонт: "
         << (pipe.GetRepair() ? "Да" : "Нет") << '\n';
}
