КОД ДЛЯ КУРСОВОЙ:




#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Класс направления движения
class Direction {
public:
    string name;
    int trafficDensity; // машины в минуту
    Direction(string n, int d) : name(n), trafficDensity(d) {}
};

// Функция эмуляции работы светофора
void runTrafficLight(vector<Direction>& directions) {
    bool running = true;

    while (running) {
        cout << "\nТекущая ситуация на перекрестке:\n";
        for (auto& dir : directions) {
            cout << dir.name << ": плотность потока = " << dir.trafficDensity << " машин/мин\n";
        }

        Direction maxDensityDir = directions[0];
        for (auto& dir : directions) {
            if (dir.trafficDensity > maxDensityDir.trafficDensity)
                maxDensityDir = dir;
        }

        cout << "\nЗеленый свет на направлении: " << maxDensityDir.name << endl;
        int greenTime = max(10, 60 - maxDensityDir.trafficDensity / 2);

        cout << "Продолжительность зелёного сигнала: " << greenTime << " сек\n";
        this_thread::sleep_for(chrono::seconds(greenTime));

        cout << "Красный свет для всех направлений.\n";
        this_thread::sleep_for(chrono::seconds(5));

        char choice;
        cout << "Продолжить управление? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
            running = false;
    }
}

int main() {
    system("chcp 65001"); //поддержка русского языка
    cout << "Алгоритм управления светофорами\n";
    setlocale(LC_ALL, "Russian");
    vector<Direction> directions = {
        {"Север", 0},
        {"Юг", 0},
        {"Запад", 0},
        {"Восток", 0}
    };

    for (auto& dir : directions) {
        cout << "Введите плотность потока для направления " << dir.name << " (машин в минуту): ";
        cin >> dir.trafficDensity;
    }

    cout << "\nЗапуск управления светофорами...\n";
    runTrafficLight(directions);

    cout << "Программа завершена.\n";
    return 0;
}
