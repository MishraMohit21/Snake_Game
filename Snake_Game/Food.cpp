#include "Food.h"

void Food::Foodinit() {
	point = rand() % 5;
	if (point == 0)
	{
		point = 1;
	}

	this->setRadius(8.0f);

	switch (static_cast<int>(point))
	{
	case 1:
		this->setFillColor(this->Gold_Yellow);
		break;
	case 2:
		this->setFillColor(this->Cherry);
		break;

	case 3:
		this->setFillColor(this->Lime);
		break;

	case 4:
		this->setFillColor(this->Elblue);
		break;

	default:
		break;
	}
}

const float Food::givePoint() const
{
	return this->point;
}
