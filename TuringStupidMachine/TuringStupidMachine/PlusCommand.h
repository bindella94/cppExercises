#pragma once
#include "ICommand.h"
class PlusCommand: public ICommand
{
public:
	virtual void doOperation(char& in) override {
		++in;
	}
};

