#pragma once
#include "ICommand.h"
class MinusCommand :public ICommand
{
public:
	virtual void doOperation(char& in) override {
		--in;
	}
};

