
#include "Pipe.h"

static int currentID = 1;

int generateID()
{
    return currentID++;
}

void registerID(int id)
{
    if (id >= currentID)
        currentID = id + 1;
}

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

    cout << "Название трубы: ";
    cin >> name;

    cout << "Длина в км: ";
    cin >> length;

    cout << "Диаметр в мм: ";
    cin >> diameter;

    cout << "Ремонт? (1 - да, 0 - нет): ";
    cin >> repair;

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
