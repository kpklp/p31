#include <iostream>
#include <string.h>
#include<windows.h>

using namespace std;

class child; //çàðàíåå îáúÿâëÿåì êëàññ, êîòîðûé ñòàíåò äðóæåñòâåííûì

class schoolchild //îïðåäåëÿåì ñëåäóþùèé êëàññ
{
    char name[16];
    char surname[16];
    int group;
public:
    schoolchild (char*, char*, int);//êîíñòðóêòîð
    void getData();
    friend child;//óêàçûâàåì, ÷òî êëàññ äðóæåñòâåííûé
};
// îïðåäåëÿåì ìåòîäû êëàññà schoolchild
schoolchild::schoolchild(char *n, char *s, int c)
{
    strcpy(name, n);
    strcpy(surname, s);
    group = c;
}

void schoolchild::getData()
{
    cout << name << " " << surname << "\t" << group << "-é êóðñ"<< endl;
}

class child //îïðåäåëÿåì äðóæåñòâåííûé êëàññ
{
public:
    void changeClas(schoolchild &, int );
    void getChangeData(schoolchild);
};
// 
void child::changeClas(schoolchild &obj, int newCl) //ïåðåäàåì îáúåêò êëàññà è âíîñèì èçìåíåíèÿ â int clas
{
    obj.group = newCl;
}

void child::getChangeData(schoolchild obj)
{
    cout << obj.name << "  " << obj.surname << "\t ïåðåâåäåí(à)  íà " << obj.group << "-é êóðñ\n";
}

int main()
{
    system("chcp 1251 >nul");

    //
    schoolchild vudych  ( "Ìàðòà", "Âóäè÷", 3);
    schoolchild klusyk  ( "Îëåêñàíäð", "Êëþñèê", 3);
    schoolchild ivanov  ( "Ïåòðî", "²âàíîâ", 3);

    cout << "Ñïèñîê ñòóäåíò³â 3-ãî êóðñó:\n";
    vudych.getData();
    klusyk.getData();
    ivanov.getData();

    child transfer; //ñîçäàåì îáúåêò transfer - ïåðåâîä â ñ ñëåäóþùèé êëàññ

    transfer.changeClas(vudych, 4);
    transfer.changeClas(klusyk, 4);

    cout << "\nÏåðåâåäåí íà íàñòóïíèé êóðñ:\n";
    transfer.getChangeData(vudych);
    transfer.getChangeData(klusyk);

    cout << "\nÑïèñîê ñòóäåíò³â 4-ãî êóðñó:\n";
    vudych.getData();
    klusyk.getData();

    cout << "\nÑïèñîê ñòóäåíò³â 3-ãî êóðñó:\n";
    
    cout << "add for github" << endl;
    ivanov.getData();

return 0;
}
