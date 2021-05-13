#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <thread>
#include "objs.h"
//
////можно реализовать наследованени
////класс graund -> камен или трава и инициализировать их на моменте создания.
////таким образом снижаем общую потреб память так как испоьзуем всего M x N объектов , вместо K x M x N объектов
////проблема в доступе к члену sprite в стоках типа obj[i]->sprite
//
////enum tyLocality {GRASS , ROCK};
//
//struct Cell
//{
//    int x, y; //левый верхний угол . центр
//    static const int Height = 150, Wight = 150; //высота и ширина ячейки
//    int numberX; //кличество ячеек по горизонтали
//    int numberY; //кличество ячеек по вертикали
//
//};
////11 12 13 ...
////21 22 23 ...
////31 32 33 ...
////  ....
//
//struct Rock
//{
//    tyLocality ty = ROCK;
//    //int x1, y1, x2, y2; //верхний левый, нижний левый, верхний правый, нижний левый
//    int hSp = 60; //высота внутреннего спрайта
//    int wSp = 80; //ширина внутреннего спрайта
//    sf::Vector2i origin;
//    sf::Texture texture;
//    sf::Sprite sprite;
//    //Rock() { if (!texture.loadFromFile("rock.png")) cout << "Ошибка загрузки текстуры камня\n"; sprite.setTexture(texture);}
//};
//struct Grass
//{
//    tyLocality ty = GRASS;
//    sf::Texture texture;
//    sf::Sprite sprite;
//
//    //Grass() { if (!texture.loadFromFile("grass.png")) cout << "Ошибка загрузки текстуры травы\n"; sprite.setTexture(texture); }
//};
//struct Hero
//{
//    int hSp = 120; //высота
//    int wSp = 80; //ширина спрайта
//    int hSpCol = 40; //высота спрайта для столкновений
//    int wSpCol = 60; //ширина спрайта для столкновений
//    int firstNumCell[2][2]; //каждую итерацию герой обновляет список ячеек где находится. //11 12
//    int SecondNumCell[2][2];                                                              //21 22 нумерация ячеек
//    sf::Texture texture;
//    sf::Sprite sprite;
//    Hero()
//    {
//        if (!texture.loadFromFile("hero.png")) cout << "Ошибка загрузки текстуры героя\n";
//        sprite.setTexture(texture);
//        sprite.setOrigin(0, 120);
//    }
//};
//
////хотя бы одна точка второго спрайта в первом , то false
//bool intersection(sf::Vector2i spr1a, sf::Vector2i spr1b, sf::Vector2i spr2a, sf::Vector2i spr2b)
//{
//    if (spr2a.x > spr1a.x && spr2a.x < spr1b.x && spr2a.y > spr1a.y && spr2a.y < spr1b.y ||
//        spr2b.x > spr1a.x && spr2b.x < spr1b.x && spr2b.y > spr1a.y && spr2b.y < spr1b.y ||
//        spr2b.x > spr1a.x && spr2b.x < spr1b.x && spr2b.y > spr1a.y && spr2b.y < spr1b.y ||
//        spr2a.x > spr1a.x && spr2a.x < spr1b.x && spr2b.y > spr1a.y && spr2b.y < spr1b.y ||
//        spr2b.x > spr1a.x && spr2b.x < spr1b.x && spr2a.y > spr1a.y && spr2a.y < spr1b.y
//        /*spr2b.x - spr2a.x > spr1a.x && spr2b.x - spr2a.x < spr1b.x && spr2a.y > spr1a.y && spr2a.y < spr1b.y ||
//        spr2a.x > spr1a.x && spr2a.x < spr1b.x && spr2b.y - spr2a.y > spr1a.y && spr2b.y - spr2a.y < spr1b.y*/) return false;
//    return true;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
    
//    bool wayClear = true; //проверяем нет ли на пути камня
//
//    sf::RenderWindow window(sf::VideoMode(wWidth , wHeight), "Win");
//
//    
//
//    Hero hero;
//    hero.sprite.setPosition(0,600);
//
//    Grass g[heightMap][widthMap];
//    Rock r[heightMap][widthMap];
//
//    //расставляю камни
//    //тут я загружаю текстуру в каждый нужный камень и во всю траву. немного экономлю память.
//
//    /*for (int i = 0; i < heightMap; i++)
//    {
//        for (int j = 0; j < widthMap; j++)
//        {
//            if (!g[i][j].texture.loadFromFile("grass.png")) cout << "Ошибка загрузки текстуры травы\n";
//            g[i][j].sprite.setTexture(g[i][j].texture);
//            g[i][j].sprite.setPosition(i * 100, j * 100);
//            if (j == 0 && i == 1 ||
//                j == 1 && i == 5 ||
//                j == 2 && i == 3 ||
//                j == 3 && i == 2 ||
//                j == 3 && i == 5 ||
//                j == 4 && i == 6 ||
//                j == 5 && i == 3
//               )
//            {
//                
//                if (!r[i][j].texture.loadFromFile("rock.png")) cout << "Ошибка загрузки текстуры камня\n";
//                r[i][j].sprite.setTexture(r[i][j].texture);
//                r[i][j].sprite.setPosition(i * 100, j * 100);
//                r[i][j].origin.x = i * 100;
//                r[i][j].origin.y = j * 100;
//            }
//        }
//    }*/
//
//
//    if (!r[3][3].texture.loadFromFile("rock.png")) cout << "Ошибка загрузки текстуры камня\n";
//    r[3][3].sprite.setTexture(r[3][3].texture);
//    r[3][3].sprite.setPosition(3 * 100, 3 * 100);
//    r[3][3].origin.x = 3 * 100;
//    r[3][3].origin.y = 3 * 100;
//    cout << r[3][3].origin.x + 10 << " " << r[3][3].origin.y + 40 << endl;
//    cout << r[3][3].origin.x + 90 << " " << r[3][3].origin.y + 100 << endl;
//    Sleep(2000);
//    
//    while (window.isOpen())
//    {
//        sf::Vector2f heroOrigin = hero.sprite.getPosition();
//        sf::Event event;
//
//        ////************
//        sf::RectangleShape rectangle(sf::Vector2f(60.f, 40.f));
//        rectangle.setPosition(heroOrigin.x+10 , heroOrigin.y-40);
//        rectangle.setFillColor(sf::Color::Green);
//        ////***********
//
//        //*************
//        //for(int i = 0;i<)
//        //*************
//
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
//        //обнаружение ячейки в которой находитсся герой
//        //////////////////////////////////////////////////////////
//        {
//            //нашли координату X у ячеек в которых находится герой
//            hero.firstNumCell[0][0] = (int)((heroOrigin.x + 0.5 * (hero.wSp - hero.wSpCol)) / Cell::Wight);
//            hero.firstNumCell[0][1] = (int)((heroOrigin.x + hero.wSp - 0.5 * (hero.wSp - hero.wSpCol)) / Cell::Wight);
//            hero.firstNumCell[1][0] = (int)((heroOrigin.x + 0.5 * (hero.wSp - hero.wSpCol)) / Cell::Wight);
//            hero.firstNumCell[1][1] = (int)((heroOrigin.x + hero.wSp - 0.5 * (hero.wSp - hero.wSpCol)) / Cell::Wight);
//            //нашли координату Y у ячеек в которых находится герой
//            hero.SecondNumCell[0][0] = (int)((heroOrigin.y - (hero.hSpCol)) / Cell::Height);
//            hero.SecondNumCell[0][1] = (int)((heroOrigin.y - (hero.hSpCol)) / Cell::Height);
//            hero.SecondNumCell[1][0] = (int)((heroOrigin.y) / Cell::Height);
//            hero.SecondNumCell[1][1] = (int)((heroOrigin.y) / Cell::Height);
//
//
//            cout << hero.firstNumCell[0][0] << " " << hero.SecondNumCell[0][0] << " " << hero.firstNumCell[0][1] << " " << hero.SecondNumCell[0][1] << endl;
//            cout << hero.firstNumCell[1][0] << " " << hero.SecondNumCell[1][0] << " " << hero.firstNumCell[1][1] << " " << hero.SecondNumCell[1][1] << endl << endl;
//            //Sleep(100);
//        }
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            
//        }
//        
//
//        //приняли положение джойстика
//        int dx = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
//        int dy = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
//        
//        //////////////////////////////////////////////////////////
//        //проверка столкнвений. ПЕРЕПИСАТЬ!
//        for (int i = 0; i < heightMap; i++)
//        {
//            for (int j = 0; j < widthMap; j++)
//            {
//                wayClear = intersection(sf::Vector2i(heroOrigin.x+10,heroOrigin.y-40),
//                                        sf::Vector2i(heroOrigin.x + 70, heroOrigin.y),
//                                        sf::Vector2i(r[i][j].origin.x+10, r[i][j].origin.y+40),
//                                        sf::Vector2i(r[i][j].origin.x+90, r[i][j].origin.y+100));//координаты спрайта героя , затем камня
//            }
//        }
//        //////////////////////////////////////////////////////////
//
//        //движение героя. ДЖОЙСТИК. проверка на стокновения
//        /*if (wayClear)
//        {
//            hero.sprite.move(dx * 0.01, dy * 0.01);
//        }*/
//
//        //столкнвения. ПЕРЕПИСАТЬ
//        if (wayClear)
//        {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) hero.sprite.move(-1, 0);
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) hero.sprite.move(1, 0);
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) hero.sprite.move(0, -1);
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) hero.sprite.move(0, 1);
//        }
//
//
//
//        window.clear();
//        for (int i = 0; i < 6; i++)
//        {
//            for (int j = 0; j < 8; j++)
//            {
//                window.draw(g[i][j].sprite);
//                window.draw(r[i][j].sprite);
//            }
//        }
//        window.draw(hero.sprite);
//        for (int i = 0; i < widthMap + heightMap; i++)
//            window.draw(line[i]);
//        window.draw(rectangle);
//        window.display();
//    }
//    return 0;
//}

//не работает!

const int wHeight = 600, wWidth = 800; //высота, ширина окна
const int heightMap = 6, widthMap = 8; //колическто крадратов 100х100 травы на карте

int main()
{
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Win");
	ground *gr[widthMap][heightMap];
	bool way_clear = true;
	bool flag = 1 , flag_y = 1;


	mainHero hero((char*)"hero.png");

	//расстановка камней и травы	
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
				) gr[i][j] = new rock();
			else
				gr[i][j] = new grass();
			gr[i][j]->initObj(sf::Vector2i(100 * i, 100 * j));
		}
	}

	while (window.isOpen())
	{
		hero.upDate();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		sf::Vector2i move;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move = sf::Vector2i(-1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move += sf::Vector2i(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move += sf::Vector2i(0, -1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move += sf::Vector2i(0, 1);

		//проверка на столкновения
		for (int i = 0; i < widthMap; i++)
		{
			for (int j = 0; j < heightMap; j++)
			{
				if (gr[i][j]->ty == ROCK)
				{
					flag = intersection_(hero.origin_collision_sprite + move,
						((rock*)gr[i][j])->origin_collision_sprite,
						hero.size_of_collision_sprite,
						((rock*)gr[i][j])->size_of_collision_sprite);
					if (flag) goto outFor; //если обнаружили стокновение , то сразу выходим из цикла
				}
			}
		}


		
	outFor://выходим вот сюда
		//std::cout << flag << std::endl;
		if(!flag) hero.sprite.move(move.x, move.y);




		//блок отрисовки
		window.clear();

		for (int i = 0; i <widthMap; i++)
		{
			for (int j = 0; j < heightMap; j++)
			{
				window.draw(gr[i][j]->sprite);
				//window.draw(gr[i][j]->sprite_of_collition_sprite);
			}
		}
		window.draw(hero.sprite);
		
		window.display();
	}

	return 0;
}
