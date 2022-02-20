#pragma once
#include <memory>
#include "CommandConst.h"
#include "ICommand.h"
#include "PlusCommand.h"
#include "MinusCommand.h"
#include "PrintCommand.h"
#include "ResetCommand.h"

class CommandHandler
{
public:
	void chooseOperation(const turing::eOperation& op, char& in) {

		doCommand(op, in);
	}



private:
	std::shared_ptr< ICommand > command_ = nullptr;


	void doCommand(const turing::eOperation& operation, char& in)
	{
		std::shared_ptr<ICommand> op;

		switch (operation)
		{
		case turing::eOperation::eOperation_PLUS:
		{
			command_ = std::make_shared<PlusCommand>();
			break;
		}
		case turing::eOperation::eOperation_MINUS:
		{
			command_ = std::make_shared<MinusCommand>();
			break;
		}
		case turing::eOperation::eOperation_PRINT:
		{
			command_ = std::make_shared<PrintCommand>();
			break;
		}
		case turing::eOperation::eOperation_RESET:
		{
			command_ = std::make_shared<ResetCommand>();
			break;
		}
		break;
		}





		if (command_ != nullptr) {
			command_->doOperation(in);


		}


	}

};