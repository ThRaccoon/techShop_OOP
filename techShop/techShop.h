#pragma once
#include <string>

class TechShop {
public:

	TechShop() = default;
	TechShop(std::string name, float price, int warranty, int id);

	void setName(const std::string& name);
	void setPrice(const float& price);
	void setWarranty(const int& warranty);
	void setId(const int& id);

	std::string getName();
	std::string getName() const;
	float getPrice();
	float getPrice() const;
	int getWarranty();
	int getWarranty() const;
	int getId();
	int getId() const;

private:
	std::string m_name;
	float m_price;
	int m_warranty;
	int m_id;
};
