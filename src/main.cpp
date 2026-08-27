#include <iostream>
#include <clocale>
#include <string>
#include <windows.h>
#include "../include/functions.h"

using namespace std;

int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return 1;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int windowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int windowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    COORD newBufferSize;
    newBufferSize.X = 1000; 
    newBufferSize.Y = windowHeight; 

    SetConsoleScreenBufferSize(hConsole, newBufferSize);

    SetConsoleCP(1251);      
    SetConsoleOutputCP(1251); 
    std::setlocale(LC_ALL, ".1251");

    List * list = new List;
    GetStartMenu();

    bool StartFlag = false;


    while(true) {
        string cmd;
        cout << "Введите команду: ";
        cin >> cmd;
        cin.ignore();

        if(cmd == "start") {
            if(!StartFlag) LaunchTable(list);
            ClearWindow();
            list->PrintList();
            StartFlag = true;
        } else if(cmd == "add") {
            list->AddSource();
            ClearWindow();
            list->PrintList();
        } else if(cmd == "delete") {
            list->DeleteSource();
            ClearWindow();
            list->PrintList();
        } else if(cmd == "update") {
            list->UpdateSource();
            ClearWindow();
            list->PrintList();
        } else if(cmd == "open") {
            list->OpenLink();
            ClearWindow();
            list->PrintList();
        } else if(cmd == "sort") {
            list->SortList();
            ClearWindow();
            list->PrintList();
        }else if(cmd == "help") {
            ClearWindow();
            GetStartMenu();
        } else if(cmd == "exit") {
            UpdateTable(list);
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