/*
 * Calculator.cpp
 *
 *  Date: 01/17/2025
 *  Author: David Neff
 */

#include <iostream>

using namespace std;

int main()
{
	//char statement[100] pretty sure this doesn't do anything;
    //changed type from int to double so we can do floating point math
	double op1, op2;
	char operation;
    //added and changed case of y to match other times it is used and changed from string literal to char literal;
	char answer = 'y';
	while (answer=='y')
	{
        //swapped the order of op1 and op2
		cin >> op1 >> operation >> op2;
        //changed : to char literal
		if (operation == '+')
        //change direction <<
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
		if (operation == '-')
        //changed direction <<
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
		if (operation == '*')
        //added missing quote and fixed incorrect operation;
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        //fixed incorrect operation
		if (operation == '/')
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;

		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;
	}
    return 0;
}






