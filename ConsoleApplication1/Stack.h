#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


// ���������� ��� ��������������� ���� ������
template<typename T>
// ����� �����
class MyStack
{
private:
    // ��������� ��������
    struct Cell {
        // �������� ��������
        T value;
        // ��������� �� ���������
        Cell* next;
    };
    // ���������� ������ ������
    Cell* begin = NULL;
    // ����� �����
    void output(Cell* a)
    {
        if (a == NULL) return;
        output(a->next);
        cout << a->value << " ";
    }
   
public:

    // ���������� ��������
    void push_back(T item)
    {
        // ��������� ����� �������
        Cell* c;
        // ���� ���� ����
        if (begin == NULL)
        {
            // �������� ������ ��� ������ ��������
            c = new Cell;
            // ���������� ����������
            c->value = item;
            // �������� ���������
            c->next = NULL;
            // ������ ��� ������ ���������
            begin = c;
            return;
        }
        else
        {
            // ��������� � ������ �����
            c = begin;
            // ��������� � �����
            while (c->next != NULL)
            {
                c = c->next;
            }
            // �������� ������ ��� ����������
            c->next = new Cell;
            // ��������� � ������
            c = c->next;
            // ���������� ��������
            c->value = item;
            // �������� ���������
            c->next = NULL;
            return;
        }



    }
    // ������� ����������� ���������� ��������
    T back()
    {
        // ���������� ������ �����
        Cell* c = begin;
        // ��������� � ����� �����
        while (c->next != NULL)
        {
            c = c->next;
        }
        // ���������� ��������
        return c->value;
    }

    // �������� ���������� ��������
    void pop_back()
    {
        // ���� � ����� ���� �������
        if (begin->next == NULL)
        {
            // �������� ��������� �� ������ �����
            begin = NULL;
            return;
        }
        // ���������� ������ �����
        Cell* c = begin;
        // ��������� � �������������� ��������
        while (c->next != NULL)
        {
            // ���� ������� ������������� 
            if (c->next->next == NULL)
            {
                // �������� ��������� �� ���������
                c->next = NULL;
                break;
            }
            c = c->next;
        }
        return;

    }
    // ���������� �������� � ������ �����
    void push(T item)
    {
        // ��������� ����� ������� � �������� ������ ��� ���� 
        Cell* c = new Cell();
        // ���������� �������
        c->value = item;
        // ��������� ��������� �� ������ �����
        c->next = begin;
        // ������ ����� ������ ����� �������
        begin = c;
    }

    // �������� ������� �������
    void pop()
    {
        Cell* a;
        if (begin != NULL)
        {
            a = begin;
            begin = a->next;

        }
    }

    // ������� �� �������� ������� �����
    int empty()
    {
        return (begin == NULL);
    }
    // ������� ������ �����
    void show()
    {
        output(begin);
    }

};