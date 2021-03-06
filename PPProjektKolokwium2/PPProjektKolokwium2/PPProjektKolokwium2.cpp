// PPProjektKolokwium2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	int data;
	Node* next = nullptr;
};

void addFirst(Node *& head, int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void show(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void readFile(string fname, Node*& head)
{
	ifstream file(fname);
	int x = 0;

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> x;
			addFirst(head, x);
		}
	}
}

void writeFile(string fname, Node* head)
{
	ofstream file(fname);
	int x = 0;

	if (file.is_open())
	{
		while (head != NULL)
		{
			file << head->data << endl;
			head = head->next;
		}
	}
}

void intersection(Node* head1, Node* head2, Node* ohead)
{

}

void clear(Node* head)
{
	cout << "Before clearing: ";
	show(head);

	Node* current = head;
	Node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;

	cout << endl << "After clearing: ";
	show(head);
}


int main()
{
	Node* head = nullptr;
	readFile("lista.txt", head);
	writeFile("lista2.txt", head);
	clear(head);
}

