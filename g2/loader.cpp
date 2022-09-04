#pragma once
#include <SFML/Graphics.hpp>

/*
Загрузщик текстур!
Иконки      i_
Гуи         g_

Карта       e_
Здания      h_
Объекты     o_
Барьеры     b_
Игроки      p_
Мобы        m_
НПС         n_

Прочее      x_

*/

using namespace sf;
class Loader {
public:
    Image g_ico1Image;
    Texture g_ico1Texure;

    Image g_select1Image;
    Texture g_select1Texure;

    Image g_but1Image;
    Texture g_but1Texure;

    Image g_ipn1Image;
    Texture g_ipn1Texure;

    Image x_b80Image;
    Texture x_b80Texure;

    Image x_fonAuthImage;
    Texture x_fonAuthTexure;

    Image m_testImage;
    Texture m_testTexure;

    Image x_logoImage;
    Texture x_logoTexure;
    void PreLoad(void)
    {
        g_ico1Image.loadFromFile("resurse/texturs/ico1.png");
        g_select1Image.loadFromFile("resurse/texturs/g_select1.png");
        g_but1Image.loadFromFile("resurse/texturs/g_but1.png");
        g_ipn1Image.loadFromFile("resurse/texturs/g_input1.png");
        x_b80Image.loadFromFile("resurse/texturs/b80.png");
        x_fonAuthImage.loadFromFile("resurse/texturs/layer/fonAuth.png");
        m_testImage.loadFromFile("resurse/texturs/m_test.png");
        x_logoImage.loadFromFile("resurse/texturs/layer/logo.png");
    }
    void Load(void)
    {
        g_ico1Texure.loadFromImage(Loader::g_ico1Image);
        g_select1Texure.loadFromImage(Loader::g_select1Image);
        g_but1Texure.loadFromImage(Loader::g_but1Image);
        g_ipn1Texure.loadFromImage(Loader::g_ipn1Image);
        x_b80Texure.loadFromImage(Loader::x_b80Image);
        x_fonAuthTexure.loadFromImage(Loader::x_fonAuthImage);
        m_testTexure.loadFromImage(Loader::m_testImage);
        x_logoTexure.loadFromImage(Loader::x_logoImage);
    }
};