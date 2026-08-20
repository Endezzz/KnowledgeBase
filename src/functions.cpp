#include <iostream>
#include <iomanip>
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
        int maxsize = this->maxsize + 1;

        // Отображение шапки таблицы
        {
            cout << " " << setw(maxsize) << setfill('_');
            cout << " " << setw(maxsize) << setfill('_');
            cout << " " << setw(maxsize) << setfill('_');
            cout << " " << setw(maxsize) << setfill('_');
            cout << " " << setw(maxsize) << setfill('_');
            cout << " " << setw(maxsize) << setfill('_');
            cout << " " << setw(maxsize) << setfill('_') << " ";

            cout << endl;

            cout << "|" << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";

            cout << endl;
        }
        {
            string name = "Название";
            string type = "Тип";
            string origin = "Кто посоветовал?";
            string about = "О чём источник?";
            string reason = "Зачем изучать?";
            string status = "Статус";
            string significance = "Приоритет";

            cout << "|" << setw(name.size()/2 + maxsize/2) << setfill(' ') << name << setw(maxsize - name.size()/2 - maxsize/2) << setfill(' ') << "|";
            cout << setw(type.size()/2 + maxsize/2) << setfill(' ') << type << setw(maxsize - type.size()/2 - maxsize/2) << setfill(' ') << "|";
            cout << setw(origin.size()/2 + maxsize/2) << setfill(' ') << origin << setw(maxsize - origin.size()/2 - maxsize/2) << setfill(' ') << "|";
            cout << setw(about.size()/2 + maxsize/2) << setfill(' ') << about << setw(maxsize - about.size()/2 - maxsize/2) << setfill(' ') << "|";
            cout << setw(reason.size()/2 + maxsize/2) << setfill(' ') << reason << setw(maxsize - reason.size()/2 - maxsize/2) << setfill(' ') << "|";
            cout << setw(status.size()/2 + maxsize/2) << setfill(' ') << status << setw(maxsize - status.size()/2 - maxsize/2) << setfill(' ') << "|";
            cout << setw(significance.size()/2 + maxsize/2) << setfill(' ') << significance << setw(maxsize - significance.size()/2 - maxsize/2) << setfill(' ') << "|";

            cout << endl;

            cout << "|" << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";

            cout << endl;
        }
        
        while(source->next != nullptr) {
            cout << "|" << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";
            cout << setw(maxsize) << setfill(' ') << "|";

            cout << endl;

            cout << "|" << setw(maxsize-1) << setfill(' ') << source->name << "|";
            cout << setw(maxsize-1) << setfill(' ') << source->type << "|";
            cout << setw(maxsize-1) << setfill(' ') << source->origin << "|";
            cout << setw(maxsize-1) << setfill(' ') << source->about << "|";
            cout << setw(maxsize-1) << setfill(' ') << source->reason << "|";

            if(source->statusFlag == 1)
                cout << "\033[31m";
            else if(source->statusFlag == 2) 
                cout << "\033[33m";
            else 
                cout << "\033[32m";
            cout << setw(maxsize-1) << setfill(' ') << source->status;
            cout << "\033[0m";
            cout << "|";

            if(source->significanceFlag == 1)
                cout << "\033[32m";
            else if(source->significanceFlag == 2) 
                cout << "\033[33m";
            else 
                cout << "\033[32m";
            cout << setw(maxsize-1) << setfill(' ') << source->significance;
            cout << "\033[0m";
            cout << "|";

            cout << endl;

            cout << "|" << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";
            cout << setw(maxsize) << setfill('_') << "|";

            cout << endl;
            source = source->next;
        }

        cout << "|" << setw(maxsize) << setfill(' ') << "|";
        cout << setw(maxsize) << setfill(' ') << "|";
        cout << setw(maxsize) << setfill(' ') << "|";
        cout << setw(maxsize) << setfill(' ') << "|";
        cout << setw(maxsize) << setfill(' ') << "|";
        cout << setw(maxsize) << setfill(' ') << "|";
        cout << setw(maxsize) << setfill(' ') << "|";

        cout << endl;

        cout << "|" << setw(maxsize-1) << setfill(' ') << source->name << "|";
        cout << setw(maxsize-1) << setfill(' ') << source->type << "|";
        cout << setw(maxsize-1) << setfill(' ') << source->origin << "|";
        cout << setw(maxsize-1) << setfill(' ') << source->about << "|";
        cout << setw(maxsize-1) << setfill(' ') << source->reason << "|";

        if(source->statusFlag == 1)
            cout << "\033[31m";
        else if(source->statusFlag == 2) 
            cout << "\033[33m";
        else 
            cout << "\033[32m";
        cout << setw(maxsize-1) << setfill(' ') << source->status;
        cout << "\033[0m";
        cout << "|";

        if(source->significanceFlag == 1)
            cout << "\033[32m";
        else if(source->significanceFlag == 2) 
            cout << "\033[33m";
        else 
            cout << "\033[31m";
        cout << setw(maxsize-1) << setfill(' ') << source->significance;
        cout << "\033[0m";
        cout << "|";

        cout << endl;

        cout << "|" << setw(maxsize) << setfill('_') << "|";
        cout << setw(maxsize) << setfill('_') << "|";
        cout << setw(maxsize) << setfill('_') << "|";
        cout << setw(maxsize) << setfill('_') << "|";
        cout << setw(maxsize) << setfill('_') << "|";
        cout << setw(maxsize) << setfill('_') << "|";
        cout << setw(maxsize) << setfill('_') << "|";

        cout << endl;
    }
}

void List :: AddSource() {
    Source * prev = GetEnd();
    Source * newSource = new Source;
    prev->next = newSource;
    newSource->prev = prev;
    SetEnd(newSource);

    newSource->index = GetSize();
    SetSize(GetSize()+1);
    cin.ignore();
    cout << endl;
    string name;
    cout << "Введите название источника: ";
    getline(cin, name);
    SetMaxSize(CheckLength(name, GetMaxSize()));
    newSource->name = name;
    cout << endl;

    string type;
    cout << "Тип источника: ";
    getline(cin, type);
    SetMaxSize(CheckLength(type, GetMaxSize()));
    newSource->type = type;
    cout << endl;

    string origin;
    cout << "Кто посоветовал?: ";
    getline(cin, origin);
    SetMaxSize(CheckLength(origin, GetMaxSize()));
    newSource->origin = origin;
    cout << endl;

    string about;
    cout << "О чём источник?: ";
    getline(cin, about);
    SetMaxSize(CheckLength(about, GetMaxSize()));
    newSource->about = about;
    cout << endl;

    string reason;
    cout << "Зачем изучать?: ";
    getline(cin, reason);
    SetMaxSize(CheckLength(reason, GetMaxSize()));
    newSource->reason = reason;
    cout << endl;

    string status;
    cout << "[" << 1 << "]" << " - " << " Не начато\n";
    cout << "[" << 2 << "]" << " - " << " В процессе\n";
    cout << "[" << 3 << "]" << " - " << " Изучен\n";
    cout << "Укажите статус освоения источника: ";
    char statusFlag;
    while(true) {
        cin >> statusFlag;
        if(statusFlag == '1') {
            status = "Не начато";
            break;
        }
        else if(statusFlag == '2') {
            status = "В процессе";
            break;
        }
        else if(statusFlag == '3') {
            status = "Изучен";
            break;
        }
        cout << "\nВы ввели неправильное значение!\n";
        cout << "Укажите статус освоения источника: ";
    }

    newSource->statusFlag = statusFlag - 48;
    newSource->status = status;
    cout << endl;

    string link;
    cout << "Укажите ссылку на источник: ";
    cin >> link;
    newSource->link = link;
    cout << endl;

    string significance;
    cout << "[" << 1 << "]" << " - " << " Не важно\n";
    cout << "[" << 2 << "]" << " - " << " Нейтрально\n";
    cout << "[" << 3 << "]" << " - " << " Важно\n";
    cout << "Укажите приоритет освоения источника: ";
    char significanceFlag;
    while(true) {
        cin >> significanceFlag;
        if(significanceFlag == '1') {
            significance = "Не важно";
            break;
        }
        else if(significanceFlag == '2') {
            significance = "Нейтрально";
            break;
        }
        else if(significanceFlag == '3') {
            significance = "Важно";
            break;
        }
        cout << "\nВы ввели неправильное значение!\n";
        cout << "Укажите важность освоения источника: ";
    }

    newSource->significanceFlag = significanceFlag - 48;
    newSource->significance = significance;
    cout << endl;
    cout << "Источник успешно добавлен!\n";
    system("pause");
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
    cout << " _____________________________________________________\n";
    cout << "|                                                     |\n";
    cout << "|             K N O W L E D G E   B A S E             |\n";
    cout << "|_____________________________________________________|\n";
    cout << "|                             |                       |\n";
    cout << "|  add {Название источника}   |   добавить источник   |\n";
    cout << "|_____________________________|_______________________|\n";
    cout << "|                             |                       |\n";
    cout << "| delete {Название источника} |    удалить источник   |\n";
    cout << "|_____________________________|_______________________|\n";
    cout << "|                             |                       |\n";
    cout << "| update {Название источника} | редактровать источник |\n";
    cout << "|_____________________________|_______________________|\n";
    cout << "|                             |                       |\n";
    cout << "|             start           |  отобразить источники |\n";
    cout << "|_____________________________|_______________________|\n";
    cout << "|                             |                       |\n";
    cout << "|  open {Название источника}  |   открыть в браузере  |\n";
    cout << "|_____________________________|_______________________|\n";
    cout << "|                             |                       |\n";
    cout << "|             help            |   отобразить команды  |\n";
    cout << "|_____________________________|_______________________|\n";
    cout << "|                             |                       |\n";
    cout << "|             exit            |  завершить программу  |\n";
    cout << "|_____________________________|_______________________|\n";
}

void LaunchTable(List * list) {
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
        sorce->link = str;

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

void UpdateTable(List * list) {
    ofstream out("../base/database.txt", ios::trunc);
    out.close();
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