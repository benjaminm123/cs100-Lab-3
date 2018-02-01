#include "Composite.h"
#include "Strategy.h"
#include "VectorContainer.h"
#include "ListContainer.h"
#include "Decorator.h"

#include <iostream>

using namespace std;

int main()
{
	VectorContainer *v = new VectorContainer();
	ListContainer *l = new ListContainer();

	Base *number = new Add(new Operand(3), new Operand(2));
	cout << "Add: " << number->evaluate() << endl;
	v->add_element(number);
	l->add_element(number);

	number = new Subtract(new Operand(3), new Operand(2));
	cout << "Subtract: " << number->evaluate() << endl;
	v->add_element(number);
	l->add_element(number);
	
	number = new Multiply(new Operand(3), new Operand(2));
	cout << "Multiply: " << number->evaluate() << endl;
	v->add_element(number);
	l->add_element(number);

	number = new Divide(new Operand(3), new Operand(2));
	cout << "Divide: " << number->evaluate() << endl;
	v->add_element(number);
	l->add_element(number);
	
	number = new Square(new Operand(3));
	cout << "Square: " << number->evaluate() << endl;
	v->add_element(number);
	l->add_element(number);

	cout << "Container Before Selection Sort: " << endl;
	v->print();
	cout << endl;

	cout << "Container After Selection Sort: " << endl;
	v->set_sort_function(new SelectionSort());
	v->sort();
	v->print();
	cout << endl;

	cout << "Container Before Bubble Sort: " << endl;
	l->print();
	cout << endl;

	cout << "Container After Bubble Sort: " << endl;
	l->set_sort_function(new BubbleSort());
	l->sort();
	l->print();
	cout << endl;

	number = new Add(new Operand(-6.3), new Operand(-1.2));

	cout << "Before Ceiling: " << endl;
	cout << number->evaluate() << endl;

	cout << "Before Floor: " << endl;
	cout << number->evaluate() << endl;

	cout << "Before Absolute Value: " << endl;
	cout << number->evaluate() << endl;

	number = new Ceiling(new Add(new Operand(-6.3), new Operand(-1.2)));

	cout << "After Ceiling: " << endl;
	cout << number->evaluate() << endl;

	number = new Floor(new Add(new Operand(-6.3), new Operand(-1.2)));

	cout << "After Floor: " << endl;
	cout << number->evaluate() << endl;

	number = new AbsoluteValue(new Add(new Operand(-6.3), new Operand(-1.2)));

	cout << "After Absolute Value: " << endl;
	cout << number->evaluate() << endl;

	int buffer;

	cin >> buffer;

	return 0;
}