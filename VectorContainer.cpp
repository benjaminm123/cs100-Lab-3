#include "VectorContainer.h"

VectorContainer::VectorContainer()
{

}

void VectorContainer::add_element(Base *element)
{
	tree.push_back(element);
}

void VectorContainer::print() const
{
	if (tree.size() == 0)
	{
		return;
	}

	for (const auto &i : tree)
	{
		std::cout << i->evaluate() << " ";
	}
}

void VectorContainer::sort()
{
	sort_function->sort(this);
}

void VectorContainer::swap(int i, int j)
{
	Base *temp = tree[i];
	tree[i] = tree[j];
	tree[j] = temp;
}

Base * VectorContainer::at(int i) const
{
	return tree[i];
}

unsigned int VectorContainer::size() const
{
	return tree.size();
}
