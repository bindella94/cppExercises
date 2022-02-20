#pragma once
namespace turing
{
	constexpr char RESET_VALUE = 'a';
	enum class eOperation: char
	{
		eOperation_PLUS,
		eOperation_MINUS,
		eOperation_PRINT,
		eOperation_RESET
	};
};