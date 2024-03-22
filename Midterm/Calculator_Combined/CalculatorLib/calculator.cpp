#include "calculator.h"

int Calculator::Add(int first, int second) const {
	return first + second;
}

int Calculator::Subtract(int first, int second) const {
	return first - second;
}

int Calculator::Multiply(int first, int second) const {
	return first * second;
}

int Calculator::Divide(int first, int second) const {
	return first / second;
}

int Calculator::Modulo(int first, int second) const
{
	return first % second;
}
int Calculator::Calculate(int first, int second, CalcOperator op) {
	switch (op) 
	{
		default:
		case CalcOperator::Add:			return Add(first, second);
		case CalcOperator::Subtract:	return Subtract(first, second);
		case CalcOperator::Multiply:	return Multiply(first, second);
		case CalcOperator::Divide:		return Divide(first, second);
		case CalcOperator::Modulo:		return Modulo(first, second);
	}
}
