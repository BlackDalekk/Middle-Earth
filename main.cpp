#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <thread>
#include "objs.h"
//struct Cell
//{
//    int x, y; //левый верхний угол . центр
//    static const int Height = 150, Wight = 150; //высота и ширина €чейки
//    int numberX; //кличество €чеек по горизонтали
//    int numberY; //кличество €чеек по вертикали
//
//};
////11 12 13 ...
////21 22 23 ...
////31 32 33 ...
////  ....
//        //********************************************************
//        sf::RectangleShape line[widthMap + heightMap];
//        for (int i = 1; i < int(wWidth / 150) + 1; i++)
//        {
//            line[i].setPosition(150 * i, 0);
//            line[i].setSize(sf::Vector2f(600.f, 2.f));
//            line[i].rotate(90);
//        }
//        for (int i = int(wWidth / 150) + 1; i < int(wWidth / 150) + int(wHeight / 150) + 1; i++)
//        {
//            line[i].setPosition(0, 150 * (i - int(wWidth / 150)));
//            line[i].setSize(sf::Vector2f(2.f, 800.f));
//            line[i].rotate(-90);
//        }
//        //********************************************************
//
//        //обнаружение €чейки в которой находитсс€ герой
//        //////////////////////////////////////////////////////////
//        {
//            //нашли координату X у €чеек в которых находитс€ герой
//            hero.firstNumCell[0][0] = (int)((heroOrigin.x + 0.5 * (hero.wSp - hero.wSpCol)) / Cell::Wight);
//            hero.firstNumCell[0][1] = (int)((heroOrigin.x + hero.wSp - 0.5 * (hero.wSp - hero.wSpCol)) / Cell::Wight);
//            hero.firstNumCell[1][0] = (int)((heroOrigin.x + 0.5 * (hero.wSp - hero.wSpCol)) / Cell::Wight);
//            hero.firstNumCell[1][1] = (int)((heroOrigin.x + hero.wSp - 0.5 * (hero.wSp - hero.wSpCol)) / Cell::Wight);
//            //нашли координату Y у €чеек в которых находитс€ герой
//            hero.SecondNumCell[0][0] = (int)((heroOrigin.y - (hero.hSpCol)) / Cell::Height);
//            hero.SecondNumCell[0][1] = (int)((heroOrigin.y - (hero.hSpCol)) / Cell::Height);
//            hero.SecondNumCell[1][0] = (int)((heroOrigin.y) / Cell::Height);
//            hero.SecondNumCell[1][1] = (int)((heroOrigin.y) / Cell::Height);
//
//
//            cout << hero.firstNumCell[0][0] << " " << hero.SecondNumCell[0][0] << " " << hero.firstNumCell[0][1] << " " << hero.SecondNumCell[0][1] << endl;
//            cout << hero.firstNumCell[1][0] << " " << hero.SecondNumCell[1][0] << " " << hero.firstNumCell[1][1] << " " << hero.SecondNumCell[1][1] << endl << endl;
//        //прин€ли положение джойстика
//        int dx = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
//        int dy = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

const int wHeight = 600, wWidth = 800; //высота, ширина окна
const int heightMap = 13, widthMap = 18; //колическто крадратов 100х100 травы на карте

int main()
{
	setlocale(LC_ALL, "Russian");
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Win");
	window.setFramerateLimit(60);
	sf::View view(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f));
	//window.setVerticalSyncEnabled(true);//ввертикальна€ синхронизаци€
	ground* gr[widthMap][heightMap];
	bool flag_x = 1 , flag_y = 1;
	const int speed = 5;

	ground* rocks[widthMap][heightMap];

	mainHero hero((char*)"hero.png");

	//расстановка камней и травы	
	for (int x = 0; x < widthMap; x++)//x
	{
		for (int y = 0; y < heightMap; y++)//y
		{
			if (y == 2 && (x >= 0 && x < 4) ||
				x == 3 && (y >= 2 && y < 6) ||
				y == 6 && (x >= 3 && x < 6) ||
				x == 6 && (y >= 6 && y < 10) ||
				y == 10 && (x >= 6 && x < 16) ||
				x == 16 && (y >= 2 && y <= 10) ||
				y == 2 && (x >= 16 && x < 18))
				gr[x][y] = new road();
			else if ((x >= 7 && x < 9) && (y >= 0 && y < 5) ||
				y == 5 && (x >= 7 && x < 10) ||
				y == 6 && (x >= 8 && x < 11) ||
				y == 7 && (x >= 9 && x < 13) ||
				y == 8 && (x >= 10 && x < 13) ||
				(y >= 9 && y < 11) && (x >= 11 && x < 13) ||
				(y >= 11 && y < 13) && (x >= 11 && x < 13))
				gr[x][y] = new water();
			else
				gr[x][y] = new grass();
			gr[x][y]->initObj(sf::Vector2i(100 * x, 100 * y));
		}
	}

	while (window.isOpen())
	{
		hero.upDate();
		window.setView(view);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		sf::Vector2i move;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move = sf::Vector2i(-speed, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move += sf::Vector2i(speed, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move += sf::Vector2i(0, -speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move += sf::Vector2i(0, speed);

		// ќЋЋ»«»»
		for (int i = 0; i < widthMap; i++)
		{
			for (int j = 0; j < heightMap; j++)
			{
				if (gr[i][j]->ty == WATER)
				{
					/*flag_x = isIntersection(hero.origin_collision_sprite + move,
						((water*)gr[i][j])->origin_collision_sprite,
						hero.size_of_collision_sprite,
						((water*)gr[i][j])->size_of_collision_sprite);*/

					flag_x = isIntersectionOneCoordinatX(hero.origin_collision_sprite + move,
						((water*)gr[i][j])->origin_collision_sprite,
						hero.size_of_collision_sprite,
						((water*)gr[i][j])->size_of_collision_sprite);

					flag_y = isIntersectionOneCoordinatY(hero.origin_collision_sprite + move,
						((water*)gr[i][j])->origin_collision_sprite,
						hero.size_of_collision_sprite,
						((water*)gr[i][j])->size_of_collision_sprite);
					if (flag_x || flag_y) goto outFor; //если обнаружили стокновение , то сразу выходим из цикла
				}
			}
		}	
	outFor://выходим вот сюда

		//зависимость от размера спрайта песонажа
		if(!flag_x && (hero.origin_sprite.x+move.x >= 0 && hero.origin_sprite.x+move.x <= 1720)) hero.sprite.move(move.x, 0);
		if(!flag_y && (hero.origin_sprite.y+move.y >= 0 && hero.origin_sprite.y+move.y <= 1180)) hero.sprite.move(0, move.y);
		
		//блок отрисовки
		window.clear();
		for (int i = 0; i < widthMap; i++)
		{
			for (int j = 0; j < heightMap; j++)
			{
				window.draw(gr[i][j]->sprite);
				//window.draw(gr[i][j]->sprite_of_collition_sprite);
			}
		}
		//перемещение камеры
		if (hero.origin_sprite.x > 360 && hero.origin_sprite.x <= 1360)
			view.setCenter(hero.origin_sprite.x+40, view.getCenter().y);
		if (hero.origin_sprite.y > 240 && hero.origin_sprite.y < 940)
			view.setCenter(view.getCenter().x, hero.origin_sprite.y+60);

		for (int i = 0; i < widthMap; i++)
			{
				for (int j = 0; j < heightMap; j++)
				{
					if (j == 0 && i == 1 ||
						j == 1 && i == 5 ||
						j == 2 && i == 3 ||
						j == 3 && i == 2 ||
						j == 3 && i == 5 ||
						j == 4 && i == 6 ||
						j == 5 && i == 3
						)
						window.draw(rocks[i][j]->sprite);
				}
			}
		window.draw(hero.sprite);

		window.display();
	}

	return 0;
}
