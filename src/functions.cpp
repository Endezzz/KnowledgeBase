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
    int statusFlag = 0;

    string link;

    string significance;
    int significanceFlag = 0;
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
    if(size > 0) {
        prev->next = newSource;
    } else {
        start = newSource;
    }
    newSource->prev = prev;
    SetEnd(newSource);

    newSource->index = GetSize();
    SetSize(GetSize()+1);
    cout << endl;

    string name;
    cout << "Введите название источника: ";
    getline(cin, name);
    if(size > 0) {
        while(CheckSource(name)) {
            cout << "Источник с заданным именем уже существует!\n";
            cout << "Введите название источника: ";
            getline(cin, name);
        }
    }
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
        cin.ignore();
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
    cin.ignore();
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
        cin.ignore();
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
        cout << "Укажите приоритет освоения источника: ";
    }

    newSource->significanceFlag = significanceFlag - 48;
    newSource->significance = significance;
    cout << endl;
    cout << "Источник успешно добавлен!\n";
    system("pause");
}

void List :: DeleteSource() {
    if(size > 0) {
        Source * deleteSource = start;
        string name;
        cout << "Введите название источника: ";
        getline(cin, name);
        while(deleteSource != end && deleteSource->name != name) {
            deleteSource = deleteSource->next;
        }
        if(deleteSource->name == name) {
            Source * source = deleteSource;
            while(source != end) { 
                source = source->next;
                source->index -= 1;
            }
            if(deleteSource == start && deleteSource == end) {
                start = nullptr;
                end = nullptr;
            } else if(deleteSource == end) {
                deleteSource->prev->next = nullptr;
                end = deleteSource->prev;
            } else if(deleteSource == start) {
                deleteSource->next->prev = nullptr;
                start = deleteSource->next;
            } else {
                deleteSource->prev->next = deleteSource->next;
                deleteSource->next->prev = deleteSource->prev;
            }
            size--;
            delete deleteSource;
        } else {
            cout << "Источник с заданным именем не найден!\n";
        }
    } else {
        cout << "Список источников пуст!\n";
    }
    system("pause");
}

void List :: UpdateSource() {
    if(size > 0) {
        Source * source;
        string name;
        cout << endl;
        while(true) {
            source = start;
            cout << "Укажите название источника, который хотите изменить: ";
            getline(cin, name);
            while(source->next != nullptr) {
                if(source->name == name) {
                    break;
                }
                source = source->next;
            }
            if(source->name == name) {
                break;
            }
            cout << "Источника с указанным именем не существует!\n";
            cout << endl;
        }

        string ptr;
        cout << "Чтобы завершить редактирование введите save!\n";
        cout << "Возможные поля: name, type, origin, about, reason, status, link, significance\n";
        while(true) {
            cout << "Укажите поле, которое хотите изменить: ";
            getline(cin, ptr);
            cout << endl;
            if(ptr == "name") {
                cout << "Введите новое имя для источника: ";
                getline(cin, name);
                SetMaxSize(CheckLength(name, GetMaxSize()));
                source->name = name;
                cout << endl;
            } else if(ptr == "type") {
                string type;
                cout << "Введите новый тип для источника: ";
                getline(cin, type);
                SetMaxSize(CheckLength(type, GetMaxSize()));
                source->type = type; 
                cout << endl;
            } else if(ptr == "origin") {
                string origin;
                cout << "Введите новую ифнормацию о том, кто посоветовал данный источник: ";
                getline(cin, origin);
                SetMaxSize(CheckLength(origin, GetMaxSize()));
                source->origin = origin;
                cout << endl;
            } else if(ptr == "about") {
                string about;
                cout << "Введите новую информацию, о чём данный источник: ";
                getline(cin, about);
                SetMaxSize(CheckLength(about, GetMaxSize()));
                source->about = about;
                cout << endl;
            } else if(ptr == "reason") {
                string reason;
                cout << "Введите новое обоснование для изучения данного источника: "; 
                getline(cin, reason);
                SetMaxSize(CheckLength(reason, GetMaxSize()));
                source->reason = reason;
                cout << endl;
            } else if(ptr == "status") {
                string status;
                cout << "[" << 1 << "]" << " - " << " Не начато\n";
                cout << "[" << 2 << "]" << " - " << " В процессе\n";
                cout << "[" << 3 << "]" << " - " << " Изучен\n";
                cout << "Укажите новый статус освоения источника: ";
                char statusFlag;
                while(true) {
                    cin >> statusFlag;
                    cin.ignore();
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
                    cout << "Укажите новый статус освоения источника: ";
                }

                source->statusFlag = statusFlag - 48;
                source->status = status;
                cout << endl;
            } else if(ptr == "link") {
                string link;
                cout << "Введите новую ссылку на источник: ";
                getline(cin, link);
                source->link = link;
                cout << endl;
            } else if(ptr == "significance") {
                string significance;
                cout << "[" << 1 << "]" << " - " << " Не важно\n";
                cout << "[" << 2 << "]" << " - " << " Нейтрально\n";
                cout << "[" << 3 << "]" << " - " << " Важно\n";
                cout << "Укажите новый приоритет освоения источника: ";
                char significanceFlag;
                while(true) {
                    cin >> significanceFlag;
                    cin.ignore();
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
                    cout << "Укажите новый приоритет освоения источника: ";
                }

                source->significanceFlag = significanceFlag - 48;
                source->significance = significance;
                cout << endl;
            } else if(ptr == "save") {
                cout << "Изменения успешно внесены!\n";
                cout << endl;
                break;
            } else {
                cout << "Неправильное указано название поля!\n";
                cout << "Попробуйте ещё раз...\n";
                cout << endl;
            }
        }
    } else {
        cout << "В таблице отсутвуют источники!\n";
        cout << endl;
    }
    system("pause");
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

bool List :: CheckSource(string name) {
    Source * source = start;

    while(source != end) {
        if(source->name == name) {
            break;
        }
        source = source->next;
    }

    if(source->name == name) {
        return true;
    }
    return false;
}

void List :: OpenLink() {
    Source * source = start;
    string name;
    cout << "Введите название источника, на который хотите перейти: ";
    getline(cin, name);

    while(source != end) {
        if(source->name == name) {
            break;
        }
        source = source->next;
    }
    string cmd = "start " + source->link;
    if(source->name == name) {
        string cmd = "start " + source->link;
        system(cmd.c_str());
    } else {
        cout << "Источника с данным наванием не существует!\n";
        system("pause");
    }
}

void List :: SortStatus() {
    for(int i = 0; i < size; i++) {
        for(Source * source1 = start->next; source1 != nullptr;) {
            Source * NewSource = source1->next;
            if(source1->statusFlag < source1->prev->statusFlag) {

                Source * prev = source1->prev->prev;
                Source * next = source1->prev;

                if(source1->prev->prev != nullptr)
                    source1->prev->prev->next = source1;

                if(source1->next != nullptr)
                    source1->next->prev = source1->prev;

                if(source1->prev == start)
                    start = source1;
                if(source1 == end)
                    end = source1->prev;
            
                source1->prev->next = source1->next;
                source1->prev->prev = source1;

                source1->prev = prev;
                source1->next = next;
            }
            source1 = NewSource;
        }
    }
}

void List :: SortSignificance() {
    for(int i = 0; i < size; i++) {
        for(Source * source1 = start->next; source1 != nullptr;) {
            Source * NewSource = source1->next;
            if(source1->significanceFlag > source1->prev->significanceFlag) {

                Source * prev = source1->prev->prev;
                Source * next = source1->prev;

                if(source1->prev->prev != nullptr)
                    source1->prev->prev->next = source1;

                if(source1->next != nullptr)
                    source1->next->prev = source1->prev;

                if(source1->prev == start)
                    start = source1;
                if(source1 == end)
                    end = source1->prev;
            
                source1->prev->next = source1->next;
                source1->prev->prev = source1;

                source1->prev = prev;
                source1->next = next;
            }
            source1 = NewSource;
        }
    }
}

void List :: SortIndex() {
    for(int i = 0; i < size; i++) {
        for(Source * source1 = start->next; source1 != nullptr;) {
            Source * NewSource = source1->next;
            if(source1->index < source1->prev->index) {

                Source * prev = source1->prev->prev;
                Source * next = source1->prev;

                if(source1->prev->prev != nullptr)
                    source1->prev->prev->next = source1;

                if(source1->next != nullptr)
                    source1->next->prev = source1->prev;

                if(source1->prev == start)
                    start = source1;
                if(source1 == end)
                    end = source1->prev;
            
                source1->prev->next = source1->next;
                source1->prev->prev = source1;

                source1->prev = prev;
                source1->next = next;
            }
            source1 = NewSource;
        }
    }
}

void List :: SortList() {
    string cmd;
    cout << "Сортировка по важжности: significance\n";
    cout << "Сортировка по статусу: status\n";
    while(true) {
        cout << "Введите по какому полю будет осуществляться сортировка: ";
        getline(cin, cmd);
        if(cmd == "status") {
            SortStatus();
            break;
        } else if(cmd == "significance") {
            SortSignificance();
            break;
        }  else {
            cout << "Указанное поле введене неправильно!\n";
        }
    }
}

void GetStartMenu() {
    cout << " ___________________________________________________________\n";
    cout << "|                                                           |\n";
    cout << "|                 K N O W L E D G E   B A S E               |\n";
    cout << "|___________________________________________________________|\n";
    cout << "|                             |                             |\n";
    cout << "|  add {Название источника}   |       добавить источник     |\n";
    cout << "|_____________________________|_____________________________|\n";
    cout << "|                             |                             |\n";
    cout << "| delete {Название источника} |        удалить источник     |\n";
    cout << "|_____________________________|_____________________________|\n";
    cout << "|                             |                             |\n";
    cout << "| update {Название источника} |    редактровать источник    |\n";
    cout << "|_____________________________|_____________________________|\n";
    cout << "|                             |                             |\n";
    cout << "|             start           |  считать источники из файла |\n";
    cout << "|_____________________________|_____________________________|\n";
    cout << "|                             |                             |\n";
    cout << "|  open {Название источника}  |      открыть в браузере     |\n";
    cout << "|_____________________________|_____________________________|\n";
    cout << "|                             |                             |\n";
    cout << "|             sort            |    отсортировать таблицу    |\n";
    cout << "|_____________________________|_____________________________|\n";
    cout << "|                             |                             |\n";
    cout << "|             help            |      отобразить команды     |\n";
    cout << "|_____________________________|_____________________________|\n";
    cout << "|                             |                             |\n";
    cout << "|             exit            |     завершить программу     |\n";
    cout << "|_____________________________|_____________________________|\n";
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

    Source * source = list->GetStart();
    
    if(list->GetSize() > 0) {
        while(source != list->GetEnd()) {
            out  << source->index << "\n";
            out << source->name << "\n";
            out << source->type << "\n";
            out << source->origin << "\n";
            out << source->about << "\n";
            out << source->reason << "\n";
            out << source->status << "\n";
            out << source->statusFlag << "\n";
            out << source->link << "\n";
            out << source->significance << "\n";
            out << source->significanceFlag << "\n";
            source = source->next;
        }
        out  << source->index << "\n";
        out << source->name << "\n";
        out << source->type << "\n";
        out << source->origin << "\n";
        out << source->about << "\n";
        out << source->reason << "\n";
        out << source->status << "\n";
        out << source->statusFlag << "\n";
        out << source->link << "\n";
        out << source->significance << "\n";
        out << source->significanceFlag << "\n";
    }

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