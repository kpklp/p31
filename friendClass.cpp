#include <iostream>
#include <string.h>
#include<windows.h>

using namespace std;

class child; //������� ��������� �����, ������� ������ �������������

class schoolchild //���������� ��������� �����
{
    char name[16];
    char surname[16];
    int group;
public:
    schoolchild (char*, char*, int);//�����������
    void getData();
    friend child;//���������, ��� ����� �������������
};
// ���������� ������ ������ schoolchild
schoolchild::schoolchild(char *n, char *s, int c)
{
    strcpy(name, n);
    strcpy(surname, s);
    group = c;
}

void schoolchild::getData()
{
    cout << name << " " << surname << "\t" << group << "-� ����"<< endl;
}

class child //���������� ������������� �����
{
public:
    void changeClas(schoolchild &, int );
    void getChangeData(schoolchild);
};
// ���������� ������ ������ child
void child::changeClas(schoolchild &obj, int newCl) //�������� ������ ������ � ������ ��������� � int clas
{
    obj.group = newCl;
}

void child::getChangeData(schoolchild obj)
{
    cout << obj.name << "  " << obj.surname << "\t ���������(�)  �� " << obj.group << "-� ����\n";
}

int main()
{
    system("chcp 1251 >nul");

    //������� ������� ������ schoolchild
    schoolchild vudych  ( "�����", "�����", 3);
    schoolchild klusyk  ( "���������", "������", 3);
    schoolchild ivanov  ( "�����", "������", 3);

    cout << "������ �������� 3-�� �����:\n";
    vudych.getData();
    klusyk.getData();
    ivanov.getData();

    child transfer; //������� ������ transfer - ������� � � ��������� �����

    transfer.changeClas(vudych, 4);
    transfer.changeClas(klusyk, 4);

    cout << "\n��������� �� ��������� ����:\n";
    transfer.getChangeData(vudych);
    transfer.getChangeData(klusyk);

    cout << "\n������ �������� 4-�� �����:\n";
    vudych.getData();
    klusyk.getData();

    cout << "\n������ �������� 3-�� �����:\n";
    ivanov.getData();

return 0;
}
