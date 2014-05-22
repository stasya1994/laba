
#include "stdafx.h"

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;
/// \file TMP_3.cpp

///class tree
class Tree
{
	int lvl; //uroven'
	int right_key, left_key, m_Count; // pravyi i levyi kluchi i kol-vo elementov
	int *top; // massiv pod derevo
	bool full; // proverka:polnoe or pustoe derevo
public:

	Tree()
	{
		lvl = 0;
		top = 0;
		right_key = 0;
		left_key = 0;
	}

	void Fill(int lv, int max_count) // zapolnenie dereva
	{
		full = false;
		cout<<"How much tops do you want to add: ";
		int c;
		cin>>c;

		if (c == pow(2.0, lv))
			full = true;
		m_Count = c;

		lvl = lv;
		top = new int[max_count];

		cout<<"Enter tops: " <<endl;
		for (int i = 0; i<m_Count; i++)
			cin>>top[i];

		for (int i = m_Count; i<max_count; i++)
			top[i] = 0;
	}

	int Check() // proverka ryada na polnotu
	{
		if (full)
		{
			return -1;
		}
		else
			return m_Count;
	}

	int Check1() // proverka ryada na polnotu
	{
		if (m_Count != 0)
			return m_Count;
		else
			return 0;
	}

	void Add(int Element, int lv, int kol_max, int position) // add elementa sprava na pustoe mesto or na novyi uroven'
	{
		full = false;
		lvl = lv;

		if (position == 0)
		{
			m_Count = 0;
			if ((m_Count+1) == pow(2.0, lv))
			{
				full = true;
			}
			else
				m_Count = m_Count + 1;

			top = new int[kol_max];

			for (int i = m_Count; i<kol_max; i++)
				top[i] = 0;
		}
		else
		{
			m_Count = m_Count + 1;
			if (m_Count == pow(2.0, lv))
			{
				full = true;
			}
		};

		top[position] = Element;
		cout<<"\n"<<m_Count<<"\n";
	}

	void Delete() // udalyaem krainyi pravyi element
	{
		if(m_Count != 0)
		{
			top[m_Count] = 0;
			--m_Count;
			if (full)
				full = false;
		}
		cout<<"\n";
	}

	void Print(int lvl_num) //vyvodim derevo
	{
		int k1 = lvl_num - lvl;
		k1 = pow(2.0, k1);
		for(int emp = (m_Count); emp >= 0; emp--)
		{
			if (emp == (m_Count))
				for (int j = 1; j<k1; j++)
					cout<<" ";
			else
			{
				for (int i = 0; i<m_Count; i++)
				{
					cout<<top[i];
					emp--;

					for(int j = 1; j<((2*k1)+1); j++)
						cout<<" ";
				}
				cout<<"\n";
			}
		}

	}
};

int main()
{
	int lvl_number;
	cout<<"Enter height of tree: ";
	cin>>lvl_number;
	Tree *A;
	Tree *B;
	B = new Tree[lvl_number]; // vydelyaem pamyat'

	for (int i = 0; i<lvl_number; i++)
	{
		// zapolnyaem urovny
		cout<<"Level "<<i<<". Enter tops: "<<endl;
		int k;
		k = pow(2.0,i);
		B[i].Fill(i, k);
	};
	cout<<"Print tree: "<<endl;

	for (int i = 0; i<lvl_number; i++)
		B[i].Print(lvl_number-1);

	bool first = false;
	first = true;

// add dlya nachala element, proveriv snachala polnotu urovnya
	cout<<"\nAdd element 7: "<<endl;

	if (B[lvl_number-1].Check() == -1)
	{
		A = new Tree[lvl_number];

		for (int i = 0; i<lvl_number; i++)
			A[i] = B[i];

		++lvl_number;
		int i;
		B = new Tree[lvl_number];

		for (i = 0; i<lvl_number-1; i++)
			B[i] = A[i];

		int k;
		k = pow(2.0,(lvl_number-1));
		i = lvl_number - 1;
		B[i].Add(7, lvl_number-1, k, 0);

		for (int i = 0; i<lvl_number; i++)
			B[i].Print(lvl_number-1);
	}
	else
	{
		int pos;
		pos = B[lvl_number-1].Check();
		int k;
		k = pow(2.0,(lvl_number-1));
		int i = lvl_number - 1;
		B[i].Add(7, lvl_number-1, k, pos);

		for (int i = 0; i<lvl_number; i++)
			B[i].Print(lvl_number-1);
	}

// teper' udalim element, proveriv predvaritel'no pustotu urovnya
	cout <<"After delete: " <<endl;
	if (B[lvl_number-1].Check1() != 0)
	{
		int i = lvl_number - 1;
		B[i].Delete();

		for (int i = 0; i<lvl_number; i++)
			B[i].Print(lvl_number-1);
	}
	else
	{
		A = new Tree[lvl_number];

		for (int i = 0; i<lvl_number; i++)
			A[i] = B[i];
		--lvl_number;
		int i;
		B = new Tree[lvl_number];

		for (i = 0; i<lvl_number; i++)
			B[i] = A[i];

		int k;
		k = pow(2.0,(lvl_number-1));
		i = lvl_number - 1;
		B[i].Delete();

		for (int i = 0; i<lvl_number; i++)
			B[i].Print(lvl_number-1);
	}

	system ("pause");
}