#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Pipe
{
    int length;
    int diameter;
    string name;
    bool isRepair;
};
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
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка. Введите число:";
        cin >> number;
    }
    return number;
}
void addPipe(Pipe& pipe)
{
    cout << "Введите название трубы: ";
    getline(cin>>ws, pipe.name);
    cout << "Введите длину: ";
    pipe.length = readNumber();
    while (pipe.length <= 0) {
        cout << "Ошибка. Длина должна быть положительной: ";
        pipe.length = readNumber();
    }
    cout << "Введите диаметр: ";
    pipe.diameter = readNumber();
    while (pipe.diameter <= 0) {
        cout << "Ошибка. Диаметр должен быть положительным: ";
        pipe.diameter = readNumber();
    }
    int repair;
    cout << "Находится ли труба в ремонте? (1 для да, 0 для нет): ";
        repair = readNumber();
    while (repair != 0 && repair != 1)
    {
        cout << "Ошибка. Введите 0 или 1: ";
        repair = readNumber();
    }
    pipe.isRepair = repair;
}
void showPipe(const Pipe& pipe)
{
    cout << "Труба:\n";
    cout << "Название: " << pipe.name << "\n";
    cout << "Длина: " << pipe.length << " km\n";
    cout << "Диаметр: " << pipe.diameter << " mm\n";
    cout << "Ремонт: " << (pipe.isRepair ? "Да" : "Нет") << "\n";
}
void addStation(Compress_Station& station)
{
    cout << "Введите название компрессорной станции: ";
    getline(cin >> ws, station.name);
    cout << "Введите количество цехов: ";
    station.workshops = readNumber();
    while (station.workshops <= 0) {
        cout << "Ошибка. Должно быть больше 0: ";
        station.workshops = readNumber();
    }
    cout << "Введите количество работающих цехов: ";
    station.active_workshops = readNumber();
    while (station.active_workshops < 0 ||
           station.active_workshops > station.workshops) {
        cout << "Ошибка. Введите от 0 до "
             << station.workshops << ": ";
        station.active_workshops = readNumber();
    }
    cout << "Введите класс станции (1 или 2): ";
    station.class_number = readNumber();
    while (station.class_number < 1 ||
           station.class_number > 2) {
        cout << "Ошибка. Введите 1 или 2: ";
        station.class_number = readNumber();
    }
}
void showStation(const Compress_Station& station)
{
    cout << "Компрессорная станция:\n";
    cout << "Название: " << station.name << "\n";
    cout << "Цеха: " << station.workshops << "\n";
    cout << "Работающие цеха: " << station.active_workshops << "\n";
    cout << "Класс: " << station.class_number << "\n";
}
void showAll(const Pipe& pipe, const Compress_Station& station)
{
    if (pipe.name.empty())
        cout << "Труба не создана.\n";
    else
        showPipe(pipe);
    cout << "\n";
    if (station.name.empty())
        cout << "Компрессорная станция не создана.\n";
    else
        showStation(station);
}
void changePipe(Pipe& pipe)
{
    if (pipe.name.empty()) {
        cout << "Труба не создана.\n";
        return;
    }
    cout << "1. Переместить в ремонт\n";
    cout << "2. Снять с ремонта\n";
    cout << "0. Назад\n";
    cout << "Введите команду: ";
    int command = readNumber();
    while (command < 0 || command > 2) {
        cout << "Ошибка. Введите 0, 1 или 2: ";
        command = readNumber();
    }
    if (command == 1)
         pipe.isRepair = true;
    else if (command == 2)
        pipe.isRepair = false;
}
void startShop(Compress_Station& station)
{
    if (station.active_workshops < station.workshops) {
        station.active_workshops++;
        cout << "Цех запущен.\n";
    }
    else {
        cout << "Все цеха уже запущены.\n";
    }
}
void stopShop(Compress_Station& station)
{
    if (station.active_workshops > 0) {
        station.active_workshops--;
        cout << "Цех остановлен.\n";
    }
    else {
        cout << "Нет работающих цехов.\n";
    }
}
void changeStation(Compress_Station& station)
{
    if (station.name.empty()) {
        cout << "Компрессорная станция не создана.\n";
        return;
    }
    cout << "1. Запустить цех\n";
    cout << "2. Остановить цех\n";
    cout << "0. Назад\n";
    cout << "Введите команду: ";
    int command = readNumber();
    while (command < 0 || command > 2) {
        cout << "Ошибка. Введите 0, 1 или 2: ";
        command = readNumber();
    }
    if (command == 1)
        startShop(station);
    else if (command == 2)
        stopShop(station);
}
void writePipe(ofstream& file, const Pipe& pipe)
{
    file << "Pipe\n";  
    file << pipe.name << "\n";
    file << pipe.length << "\n";
    file << pipe.diameter << "\n";
    file << pipe.isRepair << "\n";
}
void writeStation(ofstream& file, const Compress_Station& station)
{
    file << "STATION\n";
    file << station.name << "\n";
    file << station.workshops << "\n";
    file << station.active_workshops << "\n";
    file << station.class_number << "\n";
}
void readPipe(ifstream& file, Pipe& pipe)
{
    getline(file >> ws, pipe.name);
    file >> pipe.length;
    file >> pipe.diameter;
    file >> pipe.isRepair;
}
void readStation(ifstream& file, Compress_Station& station)
{
    getline(file >> ws, station.name);
    file >> station.workshops;
    file >> station.active_workshops;
    file >> station.class_number;
}
void saveData(const Pipe& pipe, const Compress_Station& station)
{
    string fileName;
    cout << "Введите имя файла: ";
    getline(cin >> ws, fileName);
    ofstream file(fileName);
    if (!file) {
        cout << "Ошибка открытия файла.\n";
        return;
    }
    bool savedSomething = false;
    if (!pipe.name.empty()) {
        writePipe(file, pipe);
        savedSomething = true;
    }
    if (!station.name.empty()) {
        writeStation(file, station);
        savedSomething = true;
    }
    if (!savedSomething) {
        cout << "Нечего сохранять: объекты не созданы.\n";
        return;
    }
    cout << "Данные сохранены.\n";
}
void loadData(Pipe& pipe, Compress_Station& station)
{
    string fileName;
    cout << "Введите имя файла: ";
    getline(cin >> ws, fileName);
    ifstream file(fileName);
    if (!file) {
        cout << "Ошибка открытия файла.\n";
        return;
    }
    if (file.peek() == EOF) {
        cout << "Файл пуст.\n";
        return;
    }
    pipe = {};
    station = {};
    string marker;
    while (file >> marker) {
        if (marker == "PIPE") {
            Pipe temp;
            getline(file >> ws, temp.name);
            if (file >> temp.length >> temp.diameter >> temp.isRepair) {
                pipe = temp;
                cout << "Труба загружена.\n";
            } else {
                cout << "Ошибка чтения трубы.\n";
                file.clear();
                break;
            }
        }
        else if (marker == "STATION") {
            Compress_Station temp;
            getline(file >> ws, temp.name);
            if (file >> temp.workshops >> temp.active_workshops
                     >> temp.class_number) {
                station = temp;
                cout << "Станция загружена.\n";
            } else {
                cout << "Ошибка чтения станции.\n";
                file.clear();
                break;
            }
        }
        else {
            cout << "Неизвестный маркер: " << marker << "\n";
            break;
        }
    }
}
void menu()
{
    cout << "1. Добавить трубу\n"
         << "2. Добавить компрессорную станцию\n"
         << "3. Показать все объекты\n"
         << "4. Редактировать трубу\n"
         << "5. Редактировать компрессорную станцию\n"
         << "6. Сохранить\n"
         << "7. Загрузить\n"
         << "0. Выход\n";
}
int main()
{
    Pipe pipe{};
    Compress_Station station{};
    while (true) {
        menu();
        cout << "\nВведите команду: ";
        int command = readNumber();
        while (command < 0 || command > 7) {
            cout << "Ошибка. Введите 0 to 7: ";
            command = readNumber();
        }

        switch (command) {
        case 1:
            addPipe(pipe);
            break;
        case 2:
            addStation(station);
            break;
        case 3:
            showAll(pipe, station);
            break;
        case 4:
            changePipe(pipe);
            break;
        case 5:
            changeStation(station);
            break;
        case 6:
            saveData(pipe, station);
            break;
        case 7:
            loadData(pipe, station);
            break;

        case 0:
            return 0;
        }
    }
}