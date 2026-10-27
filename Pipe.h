#ifndef PIPE_H
#define PIPE_H
#include <iostream>
#include <string>
using namespace std;
class Pipe
{
private:
    int id;
    int length;
    int diameter;
    string name;
    bool isRepair;
public:
    Pipe();
    int GetID() const;
    string GetName() const;
    bool GetRepair() const;
    int GetLength() const;
    int GetDiameter() const;
    void SetID(int newID);
    void SetName(const string& newName);
    void SetLength(int newLength);
    void SetDiameter(int newDiameter);
    void SetRepair(bool repair);
};
int generateID();
void registerID(int id);
void inputPipe(Pipe& pipe);
void printPipe(const Pipe& pipe);
#endif
