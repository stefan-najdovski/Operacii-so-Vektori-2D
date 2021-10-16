/*
 *  Креирано од Стефан Најдовски (15.10.2021).
 *  Цел на оваја програма да исцртам Декакартов Коордиантен систем каде што
 *  ќе вршам елементарни операции со вектори, преку библиотеката SFML.
 *  (Тестирано само на macOS Big Sur + CLion (C++ 11))
 * Фонтот не е моја креација, а оригинално припаѓа на Marijaco Galevski.
 */
#include <SFML/Graphics.hpp>
#include "SFML/System/Vector2.hpp"
#include <iostream>
#include "debugHelper.h"


class debugHelper;

//TODO
class xOska{};
class yOska{};
class vektorStrelka{};
//Primer za Vektorska ALGEBRA
//TODO
/*    sf::Vector2f v1(16.5f, 24.f);
    v1.x = 18.2f;
    float y = v1.y;
    sf::Vector2f v2 = v1 * 5.f;
    sf::Vector2f v3;
    v3 = v1 + v2;
    bool different = (v2 != v3);*/



int main()
{    
    debugHelper helper;
    sf::RenderWindow window(sf::VideoMode(640, 480), "Operacii so Vektori");
    sf::Text tekstDekartovKoordinatenSistem = helper.tekstDekartovKoordinatenSistem;
    tekstDekartovKoordinatenSistem.setPosition((window.getSize().x/2.f)-150.f,0);
    
        sf::Font mkd;
        std::cout << "Debug msg: " << std::endl;
        
                if (!mkd.loadFromFile("mkd.ttf")) {
                    std::cout << "GRESKA:Fontot ne postoi vo direktoriumot!!!" << std::endl;
                } else
                    std::cout << "USPESNO:mkd.ttf" << std::endl;

        tekstDekartovKoordinatenSistem.setFont(mkd);
        helper.xOskaValue.setFont(mkd);
        helper.yOskaValue.setFont(mkd);
        
            tekstDekartovKoordinatenSistem.setString(L"Декартов Координатен Систем");
            tekstDekartovKoordinatenSistem.setFillColor(sf::Color::White);
            tekstDekartovKoordinatenSistem.setCharacterSize(12);

        
        //X-OSKA PRIMER
        sf::VertexArray lines(sf::Lines, 2);
                lines[0].position = sf::Vector2f(0, window.getSize().y/2);
                lines[1].position = sf::Vector2f(window.getSize().x, window.getSize().y/2);
                lines[0].color = sf::Color::Red;
                lines[1].color = sf::Color::Red;


    //Glaven Blok za Events
    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
                window.clear();
                window.draw(tekstDekartovKoordinatenSistem);
                window.draw(lines);
                window.display();
                
        //Najnelegantnoto mozno resenie :)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            tekstDekartovKoordinatenSistem.move(-1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            tekstDekartovKoordinatenSistem.move(1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            tekstDekartovKoordinatenSistem.move(0.f, -1.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            tekstDekartovKoordinatenSistem.move(0.f, 1.f);
        }
    }
}
