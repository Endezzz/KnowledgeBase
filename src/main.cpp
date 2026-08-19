#include <iostream>
#include <clocale>
#include <string>
#include <windows.h>
#include "../include/functions.h"

using namespace std;

int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
    setlocale(LC_ALL, "RUS");
    List * list = new List;
    GetStartMenu();

    while(true) {
        string cmd;
        cout << "Введите команду: ";
        cin >> cmd;

        if(cmd == "start") {
            StartSource(list);
            ClearWindow();
            list->PrintList();
        } else if(cmd == "add") {

        } else if(cmd == "delete") {

        } else if(cmd == "update") {

        } else if(cmd == "help") {
            ClearWindow();
            GetStartMenu();
        } else if(cmd == "exit") {
            cout << "До свидания!\n";
            system("pause");
            break;
        } else {
            cout << "Введена не правильная команда!\n";
        }
    }
    delete list;
    return 0;
}