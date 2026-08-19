#include <iostream>
#include <clocale>
#include <string>
#include "../include/functions.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    List * list = new List;
    GetStartMenu();

    while(true) {
        string cmd;
        cout << "¬ведите команду: ";
        cin >> cmd;

        if(cmd == "start") {
            StartSource(list);
            ClearWindow();
            list->PrintList();
        } else if(cmd == "add") {

        } else if(cmd == "delete") {

        } else if(cmd == "update") {

        } else if(cmd == "help") {

        } else if(cmd == "exit") {
            break;
        } else {
            cout << "¬ведена не правильна€ команда!\n";
        }
    }
    delete list;
    return 0;
}