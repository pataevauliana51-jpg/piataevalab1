
#include <iostream>
#include "Pipe.h"
#include "Station.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Pipe pipe;
    inputPipe(pipe);

    cout << "\nИнформация о трубе:\n";
    printPipe(pipe);

    Station station;
    inputStation(station);

    cout << "\nИнформация о станции:\n";
    printStation(station);

    return 0;
}
