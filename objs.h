#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum tyLocality { GRASS = 0, ROCK, ROAD , WATER , MOUNTAIN };

bool isIntersection(sf::Vector2i origin1, sf::Vector2i origin2, sf::Vector2i size1, sf::Vector2i size2);
bool isIntersectionOneCoordinatX(sf::Vector2i origin1, sf::Vector2i origin2, sf::Vector2i size1, sf::Vector2i size2);
bool isIntersectionOneCoordinatY(sf::Vector2i origin1, sf::Vector2i origin2, sf::Vector2i size1, sf::Vector2i size2);

class ground
{
public:
	tyLocality ty;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2i origin_sprite; //временная. поэтому используется только для инициализации

	ground() { }
	ground(char* nameTexture , tyLocality type)
	{
		if(!texture.loadFromFile(nameTexture)) std::cout << "Ошибка загрузки текстуры\n";
		texture.setSmooth(true);
		sprite.setTexture(texture);
		ty = type;
	}
	virtual void initObj(sf::Vector2i pos_of_origin) { }
};

class grass : public ground
{
public:

	grass()
	{
		//ground((char*)"grass.png", GRASS);
		if (!texture.loadFromFile("grass.png")) std::cout << "Ошибка загрузки текстуры травы\n";
		texture.setSmooth(true);
		sprite.setTexture(texture);
		ty = GRASS;
	}
	void initObj(sf::Vector2i pos_of_origin)
	{
		sprite.setPosition(pos_of_origin.x, pos_of_origin.y);
	}
};

class rock : public ground
{
public:
	sf::Vector2i origin_collision_sprite; //в центре collisionSprite
	sf::Vector2i size_of_collision_sprite;
	grass background;

	rock()
	{
		if (!texture.loadFromFile("rock.png")) std::cout << "Ошибка загрузки текстуры камня\n";
		texture.setSmooth(true);
		sprite.setTexture(texture);
		ty = ROCK;
		
	}
	void initObj(sf::Vector2i pos_of_origin) //заполняем спрайт и инициализируем все остальное. collSprite, центры и размеры
	{
		sprite.setPosition(pos_of_origin.x, pos_of_origin.y);
		origin_sprite = sf::Vector2i(sprite.getPosition());

		origin_collision_sprite = sf::Vector2i(origin_sprite.x + 50, origin_sprite.y + 70);
		size_of_collision_sprite.x = 100;
		size_of_collision_sprite.y = 60;
	}
};

class road : public ground
{
public:
	road()
	{
		if (!texture.loadFromFile("sand.png")) std::cout << "Ошибка загрузки текстуры\n";
		texture.setSmooth(true);
		sprite.setTexture(texture);
		ty = ROAD;
	}
	void initObj(sf::Vector2i pos_of_origin)
	{
		sprite.setPosition(pos_of_origin.x, pos_of_origin.y);
	}
};

class water :public ground
{
public:
	sf::Vector2i origin_collision_sprite; //в центре collisionSprite
	sf::Vector2i size_of_collision_sprite;

	sf::Texture texture[4];
	int c = 0;

	water()
	{
		if (!texture[0].loadFromFile("water1.png")) std::cout << "Ошибка загрузки текстуры\n";
		if (!texture[1].loadFromFile("water2.png")) std::cout << "Ошибка загрузки текстуры\n";
		if (!texture[2].loadFromFile("water3.png")) std::cout << "Ошибка загрузки текстуры\n";
		if (!texture[3].loadFromFile("water4.png")) std::cout << "Ошибка загрузки текстуры\n";
		sprite.setTexture(texture[0]);
		ty = WATER;
	}
	void initObj(sf::Vector2i pos_of_origin)
	{
		sprite.setPosition(pos_of_origin.x, pos_of_origin.y);
		origin_sprite = sf::Vector2i(sprite.getPosition());

		origin_collision_sprite = sf::Vector2i(origin_sprite.x + 50, origin_sprite.y + 50);
		size_of_collision_sprite.x = 100;
		size_of_collision_sprite.y = 100;
	}
	void upDate()
	{
		sprite.setTexture(texture[c++]);
		if (c == 4) c = 0;
	}
};

class mountain : public ground
{
public:
	sf::Vector2i origin_collision_sprite; //в центре collisionSprite
	sf::Vector2i size_of_collision_sprite;
	mountain()
	{
		if (!texture.loadFromFile("mountain.png")) std::cout << "Ошибка загрузки текстуры горы\n";
		texture.setSmooth(true);
		sprite.setTexture(texture);
		ty = MOUNTAIN;

	}
	void initObj(sf::Vector2i pos_of_origin) //заполняем спрайт и инициализируем все остальное. collSprite, центры и размеры
	{
		sprite.setPosition(pos_of_origin.x, pos_of_origin.y);
		origin_sprite = sf::Vector2i(sprite.getPosition());

		origin_collision_sprite = sf::Vector2i(origin_sprite.x + 50, origin_sprite.y + 50);
		size_of_collision_sprite.x = 100;
		size_of_collision_sprite.y = 100;
	}
};

class mainHero
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2i origin_sprite;
	sf::Vector2i old_origin_sprite;
	sf::Vector2i origin_collision_sprite;
	sf::Vector2i old_origin_collision_sprite;

	sf::Vector2i size_of_collision_sprite;


	mainHero() {}
	mainHero(char* nameTexture)
	{
		if (!texture.loadFromFile(nameTexture)) std::cout << "Ошибка загрузки текстуры героя\n";
		sprite.setTexture(texture);
		origin_sprite = sf::Vector2i(sprite.getPosition());

		origin_collision_sprite = sf::Vector2i(origin_sprite.x + 40, origin_sprite.y + 100);
		size_of_collision_sprite.x = 60;
		size_of_collision_sprite.y = 40;
	}
	void upDate()
	{
		origin_sprite = sf::Vector2i(sprite.getPosition());
		origin_collision_sprite = sf::Vector2i(origin_sprite.x + 40, origin_sprite.y + 100);
	}
};
