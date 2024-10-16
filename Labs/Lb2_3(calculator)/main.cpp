#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

int precedence(char c)
{
	if (c == '+' || c == '-')
	{
		return 1;
	}
	if (c == '*' || c == '/')
	{
		return 2;
	}
	return 0;
}

int performOperation(char operation, int operand1, int operand2)
{
	switch (operation)
	{
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		if (operand2 == 0)
		{
			throw invalid_argument("Division by zero");
		}
		return operand1 / operand2;
	default:
		return 0;
	}
}

string infixToPostfix(const string &expression) // converts an infix expression to postfix
{
	stack<char> operators;
	string postfix;
	int n = expression.length();

	for (int i = 0; i < n; i++)
	{
		char current = expression[i];

		if (isspace(current))
			continue;

		if (isdigit(current))
		{
			while (i < n && isdigit(expression[i])) // If number is longer than 1
				postfix += expression[i++];
			postfix += ' ';
			i--;
		}
		else if (current == '(')
			operators.push(current);

		else if (current == ')')
		{
			while (!operators.empty() && operators.top() != '(')
			{
				postfix += operators.top();
				postfix += ' ';
				operators.pop();
			}
			operators.pop();
		}
		else
		{
			while (!operators.empty() && precedence(operators.top()) >= precedence(current))
			{
				postfix += operators.top();
				postfix += ' ';
				operators.pop();
			}
			operators.push(current);
		}
	}

	while (!operators.empty())
	{
		postfix += operators.top();
		postfix += ' ';
		operators.pop();
	}

	return postfix;
}

int evaluatePostfix(const string &expression)
{
	stack<int> operands;
	int n = expression.length();

	for (int i = 0; i < n; i++)
	{
		char current = expression[i];

		if (isspace(current))
			continue;

		if (isdigit(current))
		{
			int number = 0;

			while (i < n && isdigit(expression[i])) // it goes on every digit
			{
				number = number * 10 + (expression[i] - '0'); // ansi division from string to int
				i++;
			}
			operands.push(number);
			i--;
		}
		else
		{
			int operand2 = operands.top(); // last value on the stack
			operands.pop();
			int operand1 = operands.top();
			operands.pop();
			int result = performOperation(current, operand1, operand2); // here is calulating
			operands.push(result);
		}
	}
	return operands.top();
}

int main()
{
	string expression;

	while (true)
	{
		cout << "Enter an infix expression (or type 'exit' to quit): ";
		getline(cin, expression);

		if (expression == "exit")
			break;

		string postfix = infixToPostfix(expression);
		cout << "Postfix expression: " << postfix << endl;
		int result = evaluatePostfix(postfix);
		cout << "Result: " << result << endl;
	}

	return 0;
}
