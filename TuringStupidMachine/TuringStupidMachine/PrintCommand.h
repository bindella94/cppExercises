#pragma once
#include "ICommand.h"
#include <iostream>


class PrintCommand : public ICommand
{
public:
	virtual void doOperation(char& in) override{
		std::cout << in;
	}
};
