#include "objs.h"


bool intersection_(sf::Vector2i origin1, sf::Vector2i origin2, sf::Vector2i size1, sf::Vector2i size2)
{
	if (abs(origin1.x - origin2.x) > (size1.x * 0.5 + size2.x * 0.5)) return false;
	if (abs(origin1.y - origin2.y) > (size1.y * 0.5 + size2.y * 0.5)) return false;
	return true;
}

bool intersection_one_coordinate(int origin1, int origin2, int size1, int size2)
{
	if (abs(origin1 - origin2) > (size1 * 0.5 + size2 * 0.5)) return false;
	return true;
}
