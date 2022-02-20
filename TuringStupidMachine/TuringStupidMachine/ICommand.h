#pragma once


class ICommand
{
public:
	virtual void doOperation(char& in) = 0;
};