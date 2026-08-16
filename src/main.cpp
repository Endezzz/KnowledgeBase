#include <iostream>
#include <string>
#include "../include/functions.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    
    GetStartMenu();

    while(true) {
        string cmd;
        cout << "¬ведите команду: ";
        cin >> cmd;

        if(cmd == "start") {

        } else if(cmd == "add") {

        } else if(cmd == "delete") {

        } else if(cmd == "update") {

        } else if(cmd == "help") {

        } else if(cmd == "exit") {

        } else {
            cout << "¬ведена не правильна€ команда!\n";
        }
    }
    return 0;
}