#include "ListContainer.h"

ListContainer::ListContainer()
{

}

void ListContainer::add_element(Base *element)
{
	tree.push_back(element);
}

void ListContainer::print() const
{
	std::list<Base *>::const_iterator it;

	for (it = tree.begin(); it != tree.end(); ++it)
	{
		std::cout << (*it)->evaluate() << " ";
	}
}

void ListContainer::sort()
{
	sort_function->sort(this);
}

void ListContainer::swap(int i, int j)
{
	std::list<Base *>::iterator it;
	
	int counti = 0;
	int countj = 0;
	
	Base *temp1, *temp2;

	for (it = tree.begin(); it != tree.end(); ++counti, ++countj, ++it)
	{
		if (counti == i)
		{
			temp1 = *it;
		}
		if (countj == j)
		{
			temp2 = *it;
		}
	}

	counti = 0;
	countj = 0;

	for (it = tree.begin(); it != tree.end(); ++counti, ++countj, ++it)
	{
		if (counti == i)
		{
			*it = temp2;
		}
		if (countj == j)
		{
			*it = temp1;
		}
	}
}

Base * ListContainer::at(int i) const
{
	std::list<Base*>::const_iterator it;

	int count = 0;
	
	for (it = tree.begin(); it != tree.end(); ++count, ++it)
	{
		if (count == i)
		{
			return *it;
		}
	}
}

unsigned int ListContainer::size() const
{
	return tree.size();
}