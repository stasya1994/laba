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
        cout<<"1. Äîáàâèòü Ýëåìåíò\n";  /// Menu
        cout<<"2. Ïðîñìîòð Ñïèñêà\n";
        cout<<"3. Ïîèñê Ýëåìåíòà\n";
        cout<<"4. Óäàëèòü Ýëåìåíò\n";
        cout<<"5. Óäàëèòü Ýëåìåíò Ïî Âûáîðó\n";
        cout<<"0. Âûõîä\n\n";
        cout<<"Âàø Âûáîð: ";
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
            cout<<"Ââåäèòå ×èñëî: ";
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
                cout<<"\t!!! ÑÏÈÑÎÊ ÏÓÑÒ !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"* * * * * ÑÏÈÑÎÊ * * * * *\n\n";
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
                cout<<"\t!!! ÑÏÈÑÎÊ ÏÓÑÒ !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"Ââåäèòå Ýëåìåíò Äëÿ Ïîèñêà: ";
            cin>>key;
            ptr = head;
            while (1)
            {
                if (key == ptr->number)
                {
                    cout<<"\n\t!!! ÝËÅÌÅÍÒ ÍÀÉÄÅÍ !!!\n";
                    break;
                }
                if (ptr->next == NULL)
                {
                    cout<<"\n\t!!! ÝËÅÌÅÍÒ ÍÅ ÍÀÉÄÅÍ !!!\n";
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
                cout<<"\t!!! ÑÏÈÑÎÊ ÏÓÑÒ !!!\n\n";
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
                cout<<"\t!!! ÑÏÈÑÎÊ ÏÓÑÒ !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"Ââåäèòå Ýëåìåíò Äëÿ Óäàëåíèÿ: ";
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
                    cout<<"\n\t!!! ÝËÅÌÅÍÒ ÍÅ ÍÀÉÄÅÍ !!!\n";
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
            cout<<"\t!!! ÍÅÂÅÐÍÛÉ ÂÛÁÎÐ. ÏÎÂÒÎÐÈÒÅ ÂÂÎÄ !!!\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
    }   
}