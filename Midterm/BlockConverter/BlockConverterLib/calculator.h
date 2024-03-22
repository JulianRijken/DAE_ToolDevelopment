#pragma once



class Calculator
{
public:
	enum class CalcOperator {
		Add = 0,
		Subtract = 1,
		Multiply = 2,
		Divide = 3,
		Modulo = 4
	};

	Calculator() = default;
	~Calculator() = default;

	int Calculate(int first, int second, CalcOperator op);
	int Add(int first, int second) const;
	int Multiply(int first, int second) const;
	int Subtract(int first, int second) const;
	int Divide(int first, int second) const;
	int Modulo(int first, int second) const;
};