#include <iostream>
#include <clocale>
#include <string>
#include <windows.h>
#include "../include/functions.h"

using namespace std;

int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);

    SetConsoleCP(1251);      
    SetConsoleOutputCP(1251); 
    std::setlocale(LC_ALL, ".1251");

    List * list = new List;
    GetStartMenu();


    while(true) {
        string cmd;
        cout << "Введите команду: ";
        cin >> cmd;

        if(cmd == "start") {
            if(list->GetSize() == 0) LaunchTable(list);
            ClearWindow();
            list->PrintList();
        } else if(cmd == "add") {
            list->AddSource();
            ClearWindow();
            list->PrintList();
        } else if(cmd == "delete") {
            list->DeleteSource();
        } else if(cmd == "update") {
            list->UpdateSource();
        } else if(cmd == "open") {
            
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