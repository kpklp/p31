#include <iostream>
#include <string.h>
#include<windows.h>

using namespace std;

class child; //заранее объявляем класс, который станет дружественным

class schoolchild //определяем следующий класс
{
    char name[16];
    char surname[16];
    int group;
public:
    schoolchild (char*, char*, int);//конструктор
    void getData();
    friend child;//указываем, что класс дружественный
};
// определяем методы класса schoolchild
schoolchild::schoolchild(char *n, char *s, int c)
{
    strcpy(name, n);
    strcpy(surname, s);
    group = c;
}

void schoolchild::getData()
{
    cout << name << " " << surname << "\t" << group << "-й курс"<< endl;
}

class child //определяем дружественный класс
{
public:
    void changeClas(schoolchild &, int );
    void getChangeData(schoolchild);
};
// определяем методы класса child
void child::changeClas(schoolchild &obj, int newCl) //передаем объект класса и вносим изменения в int clas
{
    obj.group = newCl;
}

void child::getChangeData(schoolchild obj)
{
    cout << obj.name << "  " << obj.surname << "\t переведен(а)  на " << obj.group << "-й курс\n";
}

int main()
{
    system("chcp 1251 >nul");

    //создаем объекты класса schoolchild
    schoolchild vudych  ( "Марта", "Вудич", 3);
    schoolchild klusyk  ( "Олександр", "Клюсик", 3);
    schoolchild ivanov  ( "Петро", "Іванов", 3);

    cout << "Список студентів 3-го курсу:\n";
    vudych.getData();
    klusyk.getData();
    ivanov.getData();

    child transfer; //создаем объект transfer - перевод в с следующий класс

    transfer.changeClas(vudych, 4);
    transfer.changeClas(klusyk, 4);

    cout << "\nПереведен на наступний курс:\n";
    transfer.getChangeData(vudych);
    transfer.getChangeData(klusyk);

    cout << "\nСписок студентів 4-го курсу:\n";
    vudych.getData();
    klusyk.getData();

    cout << "\nСписок студентів 3-го курсу:\n";
    ivanov.getData();

return 0;
}
