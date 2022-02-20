#include  <iostream>
#include "TuringMachine.h"
#include "main.h"


int main() {
	TuringMachine machine;

	std::string s("Manuel Bannella");

	for (auto ptr = s.begin(); ptr != s.end(); ++ptr)
	{
		machine.handleCommand('@');
		if (*ptr != ' ') {
			machine.handleCommand(*ptr);
			if (*ptr == machine.checkUpperCase(*ptr))
			{

				//std::cout << "Upper case\n";
				while (!machine.checkWord(*ptr) && !machine.isOutOfBound()) {
					machine.handleCommand('-');
				}
			}
			else
			{
				//std::cout << "Lower case\n";
				while (!machine.checkWord(*ptr) && !machine.isOutOfBound()) {
					machine.handleCommand('+');
				}
			}
			machine.handleCommand('.');
		}
		else {
			std::cout << " ";
		}
	}
	return 0;
}