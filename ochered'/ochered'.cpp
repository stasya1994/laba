#include "StdAfx.h"
#include <iostream>
#include <windows.h>
#include <locale.h>
using namespace std;
 
/// \file Ochered.cpp

/// Struktura ocheredi
struct Node
{
    int number;
    Node* last;
    Node* next;
};
 
/// \fn osnovnaya functiya
void main()
{
    Node* head = NULL;
    Node* tail = NULL;
    Node* ptrLast = NULL;
    short action = -1;
    setlocale(LC_ALL,"rus"); ///Vivod po russki
    while(1)
    {
        cout<<"1. �������� �������\n";  ///Menu
        cout<<"2. �������� �������\n";
        cout<<"3. ������� �������\n";
        cout<<"4. ����� ��������\n";
        cout<<"0. �����\n\n";
        cout<<"��� �����: ";
        cin>>action;
 
        if (action == 0) ///Vixod iz programm
        {
            system("CLS");
            break;
        }
 
        if (action == 1) ///Add element
        {
            system("CLS");
            int numb = -1;
            cout<<"������� �����: ";
            cin>>numb;
            Node* ptr = new Node;
            ptr->number = numb;
            ptr->next = NULL;
            tail = ptr;
            if (head == NULL)
            {
                head = ptr;
                ptrLast = ptr;
                ptr->last = NULL;
                system("CLS");
                continue;
            }
            ptr->last = ptrLast;
            ptrLast->next = ptr;
            ptrLast = ptr;
            system("CLS");
            continue;
        }
 
        if (action == 2)  ///Prosmotr ocheredi
        {
            system("CLS");
            Node* ptr = NULL;           
            if (head == NULL)
            {
                cout<<"\t!!! ������� ����� !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"* * * * * ������� * * * * *\n\n";
            ptr = tail;
            while (1)
            {
                cout<<ptr->number<<" ";
                if (ptr->last == 0)
                    break;
                ptr = ptr->last;
            }
            cout<<"\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
  
        if (action == 3)   ///Delete element
        {
            system("CLS");
            Node* ptrDelete = NULL;
            if (head == NULL)
            {
                cout<<"\t!!! ������� ����� !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            if (head->next == NULL)
            {
                head = NULL;
                tail = NULL;
                delete tail;
                continue;
            }           
            ptrDelete = head;
            head = ptrDelete->next;
            head->last = NULL;
            delete ptrDelete;
            continue;
        }
 
        if (action == 4)  ///Poisk elementa
        {
            system("CLS");
            Node* ptr = NULL;
            int key = -1;
            if (head == NULL)
            {
                cout<<"\t!!! ������ ���� !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"������� ������� ��� ������: ";
            cin>>key;           
            ptr = head;
            while (1)
            {
                if (key == ptr->number)
                {
                    cout<<"\n\t!!! ������� ������ !!!\n";
                    break;
                }
                if (ptr->next == NULL)
                {
                    cout<<"\n\t!!! ������� �� ������ !!!\n";
                    break;
                }
                ptr = ptr->next;
            }
            system("PAUSE");
            system("CLS");
            continue;
        }
 
        if (action > 4)  ///if vibrali ne iz menu
        {
            system("CLS");
            cout<<"\t!!! �������� �����. ��������� ���� !!!\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
    }
}