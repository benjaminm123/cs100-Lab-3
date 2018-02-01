#pragma once

#include "Composite.h"

#include <cmath>
#include <math.h>

class NumberDecorator : public Base
{
public:
	NumberDecorator(Base *child)
	{
		this->child = child;
	}

	double evaluate()
	{
		return child->evaluate();
	}

private:
	Base *child;

};

class Ceiling : public NumberDecorator
{
public:
	Ceiling(Base *child) : NumberDecorator(child)
	{

	}

	double evaluate()
	{
		return ceil(NumberDecorator::evaluate());
	}
};