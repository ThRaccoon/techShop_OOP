#include "techShop.h"
#include <iostream>
#include <vector>
#include <fstream> 

void addItem(std::vector<TechShop>& items, const std::string& name
	, const int& price, const int& warranty, const int& id);
void addItemFromFile(std::vector<TechShop>& items, const std::string& name
	, const int& price, const int& warranty, const int& id);
void eraseItem(std::vector<TechShop>& items);
void printItems(std::vector<TechShop>& items);
void printItem(std::vector<TechShop>& items);
void write(const std::vector<TechShop>& items);
void read(std::vector<TechShop>& items);
template <typename T>
void isItDigit(T& digit);
bool operator==(const int& a, const TechShop& b);
bool operator==(const TechShop& a, const int& b);


int main()
{
	std::vector<TechShop> items;

	std::string name;
	float price = 0;
	int warranty = 0;
	int id = 0;

	read(items);


	std::cout << "----------------------------" << std::endl;
	std::cout << "  Welcome to my programe " << std::endl;
	std::cout << "To continue press any number" << std::endl;
	std::cout << "----------------------------" << std::endl;

	while (true)
	{
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "1.For adding new item to the list press: (1)" << std::endl;
		std::cout << "2.For erasing item from the liss press:  (2)" << std::endl;
		std::cout << "3.For showing the list press:            (3)" << std::endl;
		std::cout << "4.For showing item by id press:          (4)" << std::endl;
		std::cout << "5.To exit press:                         (5)" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;

		int op;
		std::cin >> op;

		isItDigit(op);

		switch (op)
		{
		case 1:
		{
			std::cin.ignore();
			std::cout << "Please enter item name: " << std::endl;
			getline(std::cin, name);

			std::cout << "Please enter item price: " << std::endl;
			std::cin >> price;

			isItDigit(price);

			std::cout << "Please enter item warranty: " << std::endl;
			std::cin >> warranty;

			isItDigit(warranty);

			std::cout << "Please enter item id: " << std::endl;
			std::cin >> id;

			isItDigit(id);

			addItem(items, name, price, warranty, id);

			break;
		}
		case 2:
		{
			eraseItem(items);

			break;
		}
		case 3:
		{
			printItems(items);

			break;
		}
		case 4:
		{
			printItem(items);
			break;
		}
		case 5:
		{
			std::cout << "Thanks for using my app!" << std::endl;
			write(items);
			exit(0);
			break;
		}
		default:
		{
			std::cout << "Error" << std::endl;
			std::cout << "Use only the numbers from (1-5)" << std::endl;
			break;
		}
		}
	}
	return 0;
}

void read(std::vector<TechShop>& items)
{
	std::string name;
	float price;
	int warranty, id;

	std::fstream myFile;
	myFile.open("Database.txt", std::ios::in);
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> name >> price >> warranty >> id;
			addItemFromFile(items, name, price, warranty, id);
		}

		myFile.close();
	}
	else
	{
		std::cout << "File did not open" << std::endl;
	}
}

void write(const std::vector<TechShop>& items)
{
	std::fstream myFile;
	myFile.open("Database.txt", std::ios::out);
	if (myFile.is_open())
	{
		for (int i = 0; i < items.size(); i++)
		{
			myFile << items[i].getName() << std::endl;
			myFile << items[i].getPrice() << std::endl;
			myFile << items[i].getWarranty() << std::endl;
			myFile << items[i].getId() << std::endl;
		}
		myFile.close();
	}
}

template <typename T>
void isItDigit(T& digit)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cin >> digit;
	}
}

void printItem(std::vector<TechShop>& items)
{
	int wantedId;
	std::cout << "Enter the id of the item that you want to see" << std::endl;
	std::cin >> wantedId;

	std::vector<TechShop>::iterator it = std::find(items.begin(), items.end(), wantedId);

	if (it != items.end())
	{

		{
			std::cout << "---------------" << std::endl;
			std::cout << "Item name: " << it->getName() << std::endl;
			std::cout << "Item price: " << it->getPrice() << "$" << std::endl;
			std::cout << "Item warranty: " << it->getWarranty() << " years" << std::endl;
			std::cout << "Item id: #" << it->getId() << std::endl;
			std::cout << "---------------" << std::endl;
		}
	}
	else
	{
		std::cout << "Item with this id does not exist" << std::endl;
		return;
	}
}

void printItems(std::vector<TechShop>& items)
{
	int size;
	size = items.size();

	if(size == 0)
	{
		std::cout << "List is empty!" << std::endl;
	}
	else 
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "---------------" << std::endl;
			std::cout << "Item name: " << items[i].getName() << std::endl;
			std::cout << "Item price: " << items[i].getPrice() << "$" << std::endl;
			std::cout << "Item warranty: " << items[i].getWarranty() << " years" << std::endl;
			std::cout << "Item id: #" << items[i].getId() << std::endl;
			std::cout << "---------------" << std::endl;
		}
	}
}

void addItemFromFile(std::vector<TechShop>& items, const std::string& name
	, const int& price, const int& warranty, const int& id)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (id == items[i].getId())
		{
			std::cout << "One of the items was copied twice and was removed!" << std::endl;
			std::cout << std::endl;
			return;
		}
	}

	items.push_back(TechShop(name, price, warranty, id));

}

void addItem(std::vector<TechShop>& items, const std::string& name
	, const int& price, const int& warranty, const int& id)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (id == items[i].getId())
		{
			std::cout << "This id is already taken" << std::endl;
			return;
		}
	}

	items.push_back(TechShop(name, price, warranty, id));
}

void eraseItem(std::vector<TechShop>& items)
{

	int wantedId;
	std::cout << "Enter the id of the item that you want to delete" << std::endl;
	std::cin >> wantedId;

	auto it = std::find(items.begin(), items.end(), wantedId);


	if (it != items.end())
	{
		items.erase(it);
		std::cout << "The item with id: #" << wantedId << " was deleted" << std::endl;
	}
	else
	{
		std::cout << "This id was not found" << std::endl;
		return;
	}
}

bool operator==(const TechShop& a, const int& b)
{
	return b == a.getId();
}

bool operator==(const int& a, const TechShop& b)
{
	return a == b.getId();
}
