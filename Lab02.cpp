#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

vector<int> stack;
void operation(string op);

int main()
{
	int string_to_int;
	string input="1";
	cout << "RPN Calculator" << endl;
	cout << "Enter operation one character at a time.\n";
	cout << "When finished enter '='.\n";
	while (input != "=")
	{
		cin >> input;
		if (input == "+" || input == "-" || input == "*" || input == "/")
		{
			operation(input);
		}
		else
		{
			char *end;
			string_to_int = strtol(input.c_str(), &end, 10);
			stack.push_back(string_to_int);
		}
	}
	cout << stack[0] << endl;
	return 0;
}

void operation(string op)
{
	int value;
	if (op == "+")
	{
		value = stack[stack.size()-1] + stack[stack.size()-2];
		stack.pop_back();
		stack.pop_back();
		stack.push_back(value);
	}
	else if (op == "-")
	{
		value = stack[stack.size() - 2] - stack[stack.size() - 1];
		stack.pop_back();
		stack.pop_back();
		stack.push_back(value);
	}
	else if (op == "*")
	{
		value = stack[stack.size() - 1] * stack[stack.size() - 2];
		stack.pop_back();
		stack.pop_back();
		stack.push_back(value);
	}
	else if (op == "/")
	{
		value = stack[stack.size() - 2] / stack[stack.size() - 1];
		stack.pop_back();
		stack.pop_back();
		stack.push_back(value);
	}
}