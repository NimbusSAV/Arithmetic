#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


// переменна€ дл€ неопределенного типа данных
template<typename T>
// класс стека
class MyStack
{
private:
    // структура элемента
    struct Cell {
        // значение элемента
        T value;
        // указатель на следующий
        Cell* next;
    };
    // объ€вление начала списка
    Cell* begin = NULL;
    // вывод стека
    void output(Cell* a)
    {
        if (a == NULL) return;
        output(a->next);
        cout << a->value << " ";
    }
   
public:

    // добавление элемента
    void push_back(T item)
    {
        // объ€вл€ем новый элемент
        Cell* c;
        // если стек пуст
        if (begin == NULL)
        {
            // выдел€ем пам€ть дл€ нового элеемнта
            c = new Cell;
            // запоминаем переменную
            c->value = item;
            // занул€ем указатель
            c->next = NULL;
            // делаем его первым элементом
            begin = c;
            return;
        }
        else
        {
            // переходим в начало стека
            c = begin;
            // переходим в конец
            while (c->next != NULL)
            {
                c = c->next;
            }
            // выдел€ем пам€ть дл€ следующего
            c->next = new Cell;
            // переходим к новому
            c = c->next;
            // запоминаем значение
            c->value = item;
            // занул€ем указатель
            c->next = NULL;
            return;
        }



    }
    // функци€ возвращени€ последнего элемента
    T back()
    {
        // запоминаем начало стека
        Cell* c = begin;
        // переходим в конец стека
        while (c->next != NULL)
        {
            c = c->next;
        }
        // возвращаем значение
        return c->value;
    }

    // удаление последнего элемента
    void pop_back()
    {
        // если в стеке один элемент
        if (begin->next == NULL)
        {
            // занул€ем указатель на начало стека
            begin = NULL;
            return;
        }
        // запоминаем начало стека
        Cell* c = begin;
        // переходим к предпоследнему элементу
        while (c->next != NULL)
        {
            // если элемент предпоследний 
            if (c->next->next == NULL)
            {
                // занул€ем указатель на следующий
                c->next = NULL;
                break;
            }
            c = c->next;
        }
        return;

    }
    // добавление элемента в начало стека
    void push(T item)
    {
        // объ€вл€ем новый элемент и выдел€ем пам€ть под него 
        Cell* c = new Cell();
        // запоминаем элемент
        c->value = item;
        // указатель указывает на начало стека
        c->next = begin;
        // начало стека теперь новый элемент
        begin = c;
    }

    // удаление первого элемент
    void pop()
    {
        Cell* a;
        if (begin != NULL)
        {
            a = begin;
            begin = a->next;

        }
    }

    // функци€ на проверку пустоты стека
    int empty()
    {
        return (begin == NULL);
    }
    // функци€ вывода стека
    void show()
    {
        output(begin);
    }

};