#pragma once
#include <iostream>
#include "ICommand.h"
#include "CommandConst.h"
#include "CommandHandler.h"


class TuringMachine
{
public:

	TuringMachine():
		value_(0)
	{
		handler_.chooseOperation(turing::eOperation::eOperation_RESET,value_);

	}
	void handleCommand(const char& input);

	char getValue() {
		return value_;
	}

	bool isOutOfBound() {
		auto result = true;

		if ((value_ >= 'A' && value_ <= 'z')) { //&& value_ <= 'Z') || (value_ >= 'a' &&
			result = false;
		}


		return result;
	}
	bool checkWord(const char& chr) {
		if (chr != value_) {
			return false;
		}


		return true;
	}

	bool checkUpperCase(const char& value) {
		auto result = false;

		if (value_ >= 'A' && value_ <= 'Z') {
			result = true;
		}


		return result;
	}
private:
	char value_;
	CommandHandler handler_;
};

