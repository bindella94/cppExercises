#pragma once

#include "ICommand.h"

	class ResetCommand : public ICommand
	{




	public:
		virtual void doOperation(char& in) override {
			in = turing::RESET_VALUE;
		}
	};
