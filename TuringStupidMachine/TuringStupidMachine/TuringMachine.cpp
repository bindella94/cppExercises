#include "TuringMachine.h"


void TuringMachine::handleCommand(const char& input)
{
	
		switch (input)
		{
		case '+':
		{
			handler_.chooseOperation(turing::eOperation::eOperation_PLUS, value_);
			break;
		}
		case '-':
		{
			handler_.chooseOperation(turing::eOperation::eOperation_MINUS, value_);
			break;
		}
		case '.':
		{
			handler_.chooseOperation(turing::eOperation::eOperation_PRINT, value_);
			break;
		}
		case '@':
		{
			handler_.chooseOperation(turing::eOperation::eOperation_RESET, value_);
			break;
		}



		break;
		}
	
}
