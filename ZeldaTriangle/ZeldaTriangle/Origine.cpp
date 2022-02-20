#include <iostream>
#include <string>
#include <vector>




class Triangle
{
public:
	Triangle(const int& size) :
		size_(size)
	{
		matrix_.resize(size);
		createTriangle();
	}

	std::string getStarLine(int index)
	{
		std::string line;
		for (int i = 0; i < size_; ++i) {

			if (i >= index && i < (size_ - index))
				line += "*";
			else
				line += " ";
		}


		return line;
	}

	void createTriangle() {
		for (int i = 0; i < size_ / 2  + 1;++i) {
			matrix_[i] = getStarLine(size_ / 2 - i);
		}
	}


public:


	int size_;
	std::vector<std::string> matrix_;
};


class CuttedTriangle
{
public:
	CuttedTriangle(const int& size) :
		size_(size)
	{
		matrix_.resize(size);
		createCuttedTriangle();
	}



	std::string getStarLineV2(int index)
	{
		std::string line;
		for (int i = 0; i < size_; ++i) {

			if (i >= index && i < (size_ - index))
				line += "*";
			else if (i < index)
				line += " ";
		}


		return line;
	}


	void createCuttedTriangle()
	{
		for (int i = 0; i < size_ / 2 + 1;++i) {
			matrix_[i] = getStarLineV2(size_ / 2 - i);
		}
	}
public:


	int size_;
	std::vector<std::string> matrix_;
};


class Padding
{
public:
	Padding(const int& size) :
		size_(size)
	{
		matrix_.resize(size);
		createPadding();
	}

	std::string getSpaceLine(int spaceSize)
	{
		std::string line;
		for (int i = 0; i < spaceSize; ++i) {

				line += " ";
		}


		return line;
	}


	void createPadding() {
		for (int i = 0; i < size_;++i) {
			matrix_[i] = getSpaceLine(size_);
		}
	}
public:


	int size_;
	std::vector<std::string> matrix_;
};


class ThinPadding
{
public:
	ThinPadding(const int& size) :
		size_(size)
	{
		matrix_.resize(size);
		createPadding();
	}

	std::string getSpaceLine(int spaceSize)
	{
		std::string line;
		for (int i = 0; i < spaceSize; ++i) {

			line += " ";
		}


		return line;
	}


	void createPadding() {
		for (int i = 0; i < size_;++i) {
			matrix_[i] = getSpaceLine(1);
		}
	}
public:


	int size_;
	std::vector<std::string> matrix_;
};


class Figure
{
public:
	Figure(const int& size) :
		n_(size)
	{
		createFigure();
	}

	void createFigure()
	{
		Triangle triangle(n_);
		Padding padding(n_ / 2 + 1);
		CuttedTriangle cuttedTriangle(n_);
		for (auto i = 0; i < n_ / 2 + 1; ++i) {
			auto line = padding.matrix_[i];

			line += cuttedTriangle.matrix_[i];
			//line += padding.matrix_[i];


			complexMatrix_.push_back(line);
		}

		ThinPadding thinPad(n_ / 2 + 1);

		for (auto i = 0; i < n_ / 2 + 1; ++i) {
			auto line = triangle.matrix_[i];

			line += thinPad.matrix_[i];
			line += cuttedTriangle.matrix_[i];


			complexMatrix_.push_back(line);
		}
	}


	void printFigure() {
		for (auto elem : complexMatrix_) {
			std::cout << elem << "\n";
		}
	}
	int n_;
	std::vector<std::string> complexMatrix_;

};
int main()
{

	
	int size = 1;

	Figure figure(size);
	figure.complexMatrix_[0].replace(0, 1, ".");

	figure.printFigure();

}