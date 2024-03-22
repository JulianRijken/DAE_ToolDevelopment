#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

bool parseArgs(int argc, char* args[], int& first, int& second, Calculator::CalcOperator& op)
{
	if (argc != 4) {

		return false;
	}

	try
	{
		first = stoi(args[1]);
		second = stoi(args[3]);

		char strOp = *args[2];

		switch (strOp)
		{
		default:
		case '+':
			op = Calculator::CalcOperator::Add;
			break;
		case 'x':
			op = Calculator::CalcOperator::Multiply;
			break;
		case '-':
			op = Calculator::CalcOperator::Subtract;
			break;
		case '/':
			op = Calculator::CalcOperator::Divide;
			break;
		case '%':
			op = Calculator::CalcOperator::Modulo;
			break;
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

int main(int argc, char* args[])
{
	int first;
	int second;
	Calculator::CalcOperator op;

	if (!parseArgs(argc, args, first, second, op)) {
		std::cerr << "Invalid arguments" << endl;
		return -1;
	}

	//TODO: use Calculator lib
	Calculator calc{};

	const int result = calc.Calculate(first,second,op);

	std::cout << result << endl;

}
