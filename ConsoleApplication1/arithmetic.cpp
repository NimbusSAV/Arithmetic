#include "Stack.h"
using namespace std;


//в этой функции рассмотрим все возможные операции, что могут встретиться в строке
bool operation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

//данная функция будет возвращать приоритет поступившей операции
int prioritet(char op) {
    if (op < 0) return 3;
    else {
        if (op == '+' || op == '-')return 1;
        else if (op == '*' || op == '/')return 2;
        else if (op == '^')return 4;
        else return -1;
    }
}

//следующая функция описывает принцип работы каждого оператора
void action(MyStack<long> &value, char op) {
    if (op < 0) {                            //для унарных операций
        long unitar = value.back();
        value.pop_back();
        if (-op == '-')value.push_back(-unitar);
    }
    else {                               //для бинарных операций
        long res;
        long right = value.back();
        value.pop_back();
        long left = value.back();
        value.pop_back();
        if (op == '+')
        {
            res = left + right;
            value.push_back(res);
        }
        else if (op == '-')
        {
            res = left - right;
            value.push_back(res);
        }
        else if (op == '*')
        {
            res = left * right;
            value.push_back(res);
        }
        else if (op == '/')
        {
            res = left / right;
            value.push_back(res);
        }
        else if (op == '^')
        {
            res = pow(left, right);
            value.push_back(res);
        }
    }
}

long calculus(string& formula) {
    bool unary = true;        //создадим булеву переменную, для распределения операторов на унарные и бинарные
    MyStack<long>value;        //заведем массив для целых чисел
    MyStack<char>op;           //и соответственно для самых операторов
    for (int i = 0; i < formula.size(); i++) {
        if (formula[i] == '(') {    //если текущий элемент — открывающая скобка, то положим её в стек
            op.push_back('(');
            unary = true;
        }
        else if (formula[i] == ')') {
            while (op.back() != '(') {  //если закрывающая скобка - выполняем все операции, находящиеся внутри этой скобки
                action(value, op.back());
                op.pop_back();
            }
            op.pop_back();
            unary = false;
        }
        else if (operation(formula[i])) { //если данный элемент строки является одни из выше перечисленных операндов,то
            char zn = formula[i];
            if (unary == true)zn = -zn; //придает отрицательное значение, для распознавания функции унарности оператора 
            while (!op.empty() && prioritet(op.back()) >= prioritet(zn)) {
                action(value, op.back());   //выполняем сами алгебраические вычисления, где все уже операции упорядочены  
                op.pop_back();              //в одном из стеков по строгому убыванию приоритета, если двигаться от вершины
            }
            op.push_back(zn);
            unary = true;
        }
        else {
            string number;      //заведем строку для найденных числовых операндов
            while (i < formula.size() && isdigit(formula[i]))number += formula[i++];//распознаем их с помощью библиотечной функции строк
            i--;
            value.push_back(atol(number.c_str()));//поместим в наш стек с числовыми выражениями
            unary = false;
        }
    }
    while (!op.empty()) {     //выполним еще не использованные операции в стеке 
        action(value, op.back());
        op.pop_back();
    }
    return value.back(); //получим на выходе значение выражения
}

int main()
{
    string formula; //введем две строки: сам многочлен/числовое выражение и по необходимости значение переменной 
    cin >> formula;
    cout << calculus(formula);  //выведем ответ
    return 0;
}