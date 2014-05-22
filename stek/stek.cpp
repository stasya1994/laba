// stek.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"
#include <iostream>
#include <windows.h>
#include <locale.h>
using namespace std;
 
/// \file Spisok.cpp

/// Struktura spiska
struct Node
{
    int number;
    Node* next;
};
 
/// \fn osnovnaya funkciya
void main()
{
    Node* head = NULL;
    Node* lastPtr = NULL;
    short action = -1;
	setlocale(LC_ALL,"rus");  /// Delaem vivid po russki
    while (1)
    {
        cout<<"1. �������� �������\n";  /// Menu
        cout<<"2. �������� ������\n";
        cout<<"3. ����� ��������\n";
        cout<<"4. ������� �������\n";
        cout<<"5. ������� ������� �� ������\n";
        cout<<"0. �����\n\n";
        cout<<"��� �����: ";
        cin>>action;
        if (action == 0)  /// Vixod iz programm
        {
            system("CLS");
            break;
        }
 
        if (action == 1) /// Add element
        {
            system("CLS");
            Node* ptr = new Node;
            int numb = -1;
            cout<<"������� �����: ";
            cin>>numb;
            ptr->number = numb;
            ptr->next = NULL;
            if (head == 0)
            {
                head = ptr;
                lastPtr = ptr;
                system("CLS");
                continue;
            }
            lastPtr->next = ptr;
            lastPtr = ptr;
            system("CLS");
            continue;
        }
 
        if (action == 2)  /// Prosmotor spiska
        {
            Node* ptr = NULL;
            system("CLS");
            if (head == NULL)
            {
                cout<<"\t!!! ������ ���� !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"* * * * * ������ * * * * *\n\n";
            ptr = head;
            while (1)
            {
                cout<<ptr->number<<" ";
                if (ptr->next == 0)
                    break;
                ptr = ptr->next;
            }
            cout<<"\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
 
        if (action == 3)  /// Ishem element
        {
            Node* ptr = NULL;
            int key = -1;
            system("CLS");
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
 
        if (action == 4)  /// Delete element
        {
            system("CLS");
            Node* ptrDelete = NULL;         
            if (head == NULL)
            {
                cout<<"\t!!! ������ ���� !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            if (head->next == NULL)
            {
                head = NULL;
                delete head;
                continue;
            }
            ptrDelete = head;
            head = ptrDelete->next;
            delete ptrDelete;
            continue;
        }
 
        if (action == 5)  /// Delete element po viboru
        {
            system("CLS");
            Node* ptrPrev = NULL;
            Node* ptrDelete = NULL;
            int key = -1;
            if (head == NULL)
            {
                cout<<"\t!!! ������ ���� !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"������� ������� ��� ��������: ";
            cin>>key;
            ptrDelete = head;
            if (ptrDelete->number == key)
            {
                head = ptrDelete->next;
                delete ptrDelete;
                system("CLS");
                continue;
            }
            while (1)
            {
                if (key == ptrDelete->number)
                {
                    ptrPrev->next = ptrDelete->next;
                    delete ptrDelete;
                    break;
                }
                if (ptrDelete->next == 0)
                {
                    cout<<"\n\t!!! ������� �� ������ !!!\n";
                    system("PAUSE");
                    break;
                }
                ptrPrev = ptrDelete;
                ptrDelete = ptrDelete->next;
            }
            system("CLS");
            continue;
        }
 
        if (action > 5)  /// if vibrali ne tot punkt menu
        {
            system("CLS");
            cout<<"\t!!! �������� �����. ��������� ���� !!!\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
    }   
}