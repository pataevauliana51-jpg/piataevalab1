#ifndef PIPE_H
#define PIPE_H
#include <iostream>
#include <string>
#include <vector>
class Station;
class Pipe
{
private:
    int id;
    int length;
    int diameter;
    std::string name;
    bool isRepair;
public:
    Pipe();
    bool matchesName(const std::string& text) const;
    bool matchesRepair(bool repair) const;
    bool hasID(int value) const;
    void edit();
    friend std::istream& operator>>(std::istream& in, Pipe& pipe);
    friend std::ostream& operator<<(std::ostream& out, const Pipe& pipe);
    void setRepair(bool repair);
    void setDiameter(int value);
    void setLength(int value);
};
void addPipe(std::vector<Pipe>& pipes);
void showPipes(const std::vector<Pipe>& pipes);
void editPipe(std::vector<Pipe>& pipes);
void deletePipe(std::vector<Pipe>& pipes);
void saveData(const std::vector<Pipe>& pipes, const std::vector<Station>& stations);
void loadData(std::vector<Pipe>& pipes, std::vector<Station>& stations);
void searchPipes(std::vector<Pipe>& pipes);
#endif
