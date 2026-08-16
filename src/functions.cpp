#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "../include/functions.h"

using namespace std;

struct Source {

    Source * next = nullptr;

    Source * prev = nullptr;

    int index;

    string name;

    string type;

    string origin;

    string about;

    string reason;

    string status;
    int statusFlag;

    string link;

    string significance;
    int significanceFlag;
};


List :: List() {}

List :: ~List() {}

void List :: PrintList() {
    if(size != 0) {
        Source * source = start;

        while(source->next != nullptr) {
            cout << source->index << " " << source->type << " " << source->origin << " " << source->about << " "  << source->reason << " " << source->status << " " << source->significance << endl;
            source = source->next;
        }

        cout << source->index << " " << source->type << " " << source->origin << " " << source->about << " "  << source->reason << " " << source->status << " " << source->significance << endl;
    }
}

void List :: AddSource() {

}

void List :: DeleteSource() {

}

void List :: UpdateSource() {

}

int List :: GetSize() {
    return size;
}

void List :: SetSize(int NewSize) {
    size = NewSize;
}

Source * List :: GetStart() {
    return start;
}

void List :: SetStart(Source * NewStart) {
    start = NewStart;
}

Source * List :: GetEnd() {
    return end;
}

void List :: SetEnd(Source * NewEnd) {
    end = NewEnd;
}

int List :: GetMaxSize() {
    return maxsize;
}

void List :: SetMaxSize(int NewMaxSize) {
    maxsize = NewMaxSize;
}


void GetStartMenu() {
    cout << " ___________________________________________________\n";
    cout << "|                                                   |\n";
    cout << "|            K N O W L E D G E   B A S E            |\n";
    cout << "|___________________________________________________|\n";
    cout << "|                           |                       |\n";
    cout << "| add {»ндекс источника}    |   добавить источник   |\n";
    cout << "|___________________________|_______________________|\n";
    cout << "|                           |                       |\n";
    cout << "| delete {»ндекс источника} |    удалить источник   |\n";
    cout << "|___________________________|_______________________|\n";
    cout << "|                           |                       |\n";
    cout << "| update {»ндекс источника} | редактровать источник |\n";
    cout << "|___________________________|_______________________|\n";
    cout << "|                           |                       |\n";
    cout << "|           start           | отобразить источники  |\n";
    cout << "|___________________________|_______________________|\n";
    cout << "|                           |                       |\n";
    cout << "|           help            |   отобразить команды  |\n";
    cout << "|___________________________|_______________________|\n";
    cout << "|                           |                       |\n";
    cout << "|           exit            |  завершить программу  |\n";
    cout << "|___________________________|_______________________|\n";
}

void StartSource(List * list) {
    ifstream fin ("../base/database.txt");
    string str;
    Source * sorce;
    Source * prev;
    int index;
    

    while(fin >> index) {
        sorce = new Source;
        fin.ignore();
        sorce->index = index;

        if(list->GetSize() != 0) {
            prev->next = sorce;
            sorce->prev = prev;
        }

        getline(fin, str);
        list->SetMaxSize(CheckLength(str, list->GetMaxSize()));
        sorce->name = str;

        getline(fin, str);
        list->SetMaxSize(CheckLength(str, list->GetMaxSize()));
        sorce->type = str;

        getline(fin, str);
        list->SetMaxSize(CheckLength(str, list->GetMaxSize()));
        sorce->origin = str;

        getline(fin, str);
        list->SetMaxSize(CheckLength(str, list->GetMaxSize()));
        sorce->about = str;

        getline(fin, str);
        list->SetMaxSize(CheckLength(str, list->GetMaxSize()));
        sorce->reason = str;

        getline(fin, str);
        list->SetMaxSize(CheckLength(str, list->GetMaxSize()));
        sorce->status = str;

        fin >> sorce->statusFlag;
        fin.ignore();

        getline(fin, str);
        list->SetMaxSize(CheckLength(str, list->GetMaxSize()));
        sorce->significance = str;

        fin >> sorce->significanceFlag;
        fin.ignore();

        if(list->GetSize() == 0) {
            list->SetStart(sorce);
        }

        list->SetEnd(sorce);
        list->SetSize(list->GetSize()+1);

        prev = sorce;
    }

    fin.close();
}

void AddNewSource() {

}

void ClearWindow() {
    system("cls");
}

int CheckLength(string &str, int max) {
    if(max < str.size()) {
        max = str.size();
    }
    return max;
}