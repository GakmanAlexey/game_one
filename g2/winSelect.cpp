#pragma once
#include <SFML/Graphics.hpp>
#include "loader.cpp"
#include <string>
#include <iostream>
class WinSelect
{
public:
    Loader Textur;
    bool preload_status = false;
    sf::Font font;
    sf::Text txt;
    sf::Text text_count;
    sf::Text tec_count;
    sf::Text slash_count;
    sf::Text all_count;

    String s1 = "";
    String s2 = "";
    int max_list = 9;
    int i = 0;

    Sprite g_select1Sprite;
    Sprite x_fonAuthSprite;
    Sprite x_b80Sprite;
    Sprite plus;

    int coun_pesr = 0;
    int coun_max_pesr = 0;
    void preload(void) {
        coun_pesr = 2;
        coun_max_pesr = 5;
        s1 = std::to_string(coun_pesr);
        s2 = std::to_string(coun_max_pesr);


    }
    void rend(sf::RenderWindow& window)
    {
        if (!preload_status) {
            preload_status = true;
            preload();
        }
        window.clear();
        x_fonAuthSprite.setTexture(Textur.x_fonAuthTexure);
        x_fonAuthSprite.setPosition(0, 0);
        window.draw(x_fonAuthSprite);
        x_b80Sprite.setTexture(Textur.x_b80Texure);//примен€ем текстуру
        x_b80Sprite.setTextureRect(sf::IntRect(1, 1, 400, 870));//область дл€ отображени€
        x_b80Sprite.setPosition(0, 0);//позици€ отрисовки
        window.draw(x_b80Sprite);



        txt.setFont(font);
        txt.setPosition(70, 20);
        txt.setString(L"¬ыбор персонажа");
        txt.setCharacterSize(24);
        txt.setStyle(sf::Text::Bold);
        window.draw(txt);

        text_count.setFont(font);
        text_count.setPosition(40, 70);
        text_count.setString(L"ƒоступно");
        text_count.setCharacterSize(18);
        text_count.setStyle(sf::Text::Bold);
        window.draw(text_count);

        tec_count.setFont(font);
        tec_count.setPosition(330, 65);
        tec_count.setString(s1);
        tec_count.setCharacterSize(18);
        tec_count.setStyle(sf::Text::Bold);
        window.draw(tec_count);

        slash_count.setFont(font);
        slash_count.setPosition(345, 65);
        slash_count.setString("/");
        slash_count.setCharacterSize(18);
        slash_count.setStyle(sf::Text::Bold);
        window.draw(slash_count);

        all_count.setFont(font);
        all_count.setPosition(360, 65);
        all_count.setString(s2);
        all_count.setCharacterSize(18);
        all_count.setStyle(sf::Text::Bold);
        window.draw(all_count);
        i = 0;
        while (i < max_list) {
            g_select1Sprite.setTexture(Textur.g_select1Texure);
            g_select1Sprite.setPosition(0, 100 + (i * 70));
            window.draw(g_select1Sprite);

            //add pers
            if (i >= coun_pesr && i < coun_max_pesr) {

                plus.setTexture(Textur.g_ico1Texure);
                plus.setPosition(160, 102 + (i * 70));
                plus.setTextureRect(IntRect(64, 0, 64, 64));
                window.draw(plus);
            }
            if (i >= coun_max_pesr) {

                plus.setTexture(Textur.g_ico1Texure);
                plus.setPosition(160, 102 + (i * 70));
                plus.setTextureRect(IntRect(0, 0, 64, 64));
                window.draw(plus);
            }
            ++i;
        }




        window.display();
    }
    void load(void) {
        Textur.PreLoad();
        Textur.Load();

        font.loadFromFile("resurse/fonts/f.otf");
    }
};