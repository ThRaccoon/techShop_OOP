#include "techShop.h"
#include <iostream>

TechShop::TechShop(std::string name, float price, int warranty, int id)

	: m_name(name)
	, m_price(price)
	, m_warranty(warranty)
	, m_id(id)
{
}

void TechShop::setName(const std::string& name)
{
	m_name = name;
}

void TechShop::setPrice(const float& price)
{
	m_price = price;
}

void TechShop::setWarranty(const int& warrnaty)
{
	m_warranty = warrnaty;
}

void TechShop::setId(const int& id)
{
	m_id = id;
}

std::string TechShop::getName()
{
	return m_name;
}

float TechShop::getPrice()
{
	return m_price;
}

int TechShop::getWarranty()
{
	return m_warranty;
}

int TechShop::getId()
{
	return m_id;
}

int TechShop::getId() const
{
	return m_id;
}

int TechShop::getWarranty() const
{
	return m_warranty;
}

float TechShop::getPrice() const
{
	return m_price;
}

std::string TechShop::getName() const
{
	return m_name;
}