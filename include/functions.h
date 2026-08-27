#pragma once

using namespace std;

struct Source; 

class List {
    private:
        int size = 0;
        int maxsize = 11;
        Source * start = nullptr;
        Source * end = nullptr;
    public:
        List();
        ~List();
        void PrintList();
        void AddSource();
        void DeleteSource();
        void UpdateSource();
        int GetSize();
        void SetSize(int NewSize);
        Source * GetStart();
        void SetStart(Source * NewStart);
        Source * GetEnd();
        void SetEnd(Source * NewEnd);
        int GetMaxSize();
        void SetMaxSize(int NewMaxSize);
        bool CheckSource(string name);
        void OpenLink();
        void SortList();
        void SortStatus();
        void SortSignificance();
        void SortIndex();
};

void GetStartMenu();

void LaunchTable(List * list);

void ClearWindow();

void UpdateTable(List * list);

void ShowSourceList();

int CheckLength(string &str, int max);