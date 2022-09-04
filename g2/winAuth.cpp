#pragma once
#include <SFML/Graphics.hpp>
#include "loader.cpp"
#include <string>
class WinAuths
{
public:
    int lenlogin = 0;
    sf::Font font;
    Loader Textur;
    Sprite x_fonAuthSprite;
    sf::Text txt;
    sf::Text txt_login;
    sf::Text txt_pass;
    sf::Text txt_auth_but;
    sf::Text txt_reg_but;
    String login;
    String login1;
    String password;
    String head_auth = L"¿‚ÚÓËÁ‡ˆËˇ";
    String text_login = L"ashdkjahdsjqa";
    String text_password = L"dsa,md,.asm,das";
    String text_auth_but = L"¿¬“Œ–»«¿÷»ﬂ";
    String text_reg_but = L"–≈√»—“–¿÷»ﬂ";
    void rend(sf::RenderWindow& window)
    {
        window.clear();

        Sprite x_fonAuthSprite;
        x_fonAuthSprite.setTexture(Textur.x_fonAuthTexure);
        x_fonAuthSprite.setPosition(0, 0);
        window.draw(x_fonAuthSprite);

        Sprite g_ipn1Sprite;
        g_ipn1Sprite.setTexture(Textur.g_ipn1Texure);
        g_ipn1Sprite.setPosition(624, 600);
        window.draw(g_ipn1Sprite);
        Sprite g_ipn1Sprite2;
        g_ipn1Sprite2.setTexture(Textur.g_ipn1Texure);
        g_ipn1Sprite2.setPosition(624, 650);
        window.draw(g_ipn1Sprite2);


        Sprite g_but1Sprite;
        g_but1Sprite.setTexture(Textur.g_but1Texure);
        g_but1Sprite.setPosition(672, 710);
        window.draw(g_but1Sprite);
        Sprite g_but1Sprite2;
        g_but1Sprite2.setTexture(Textur.g_but1Texure);
        g_but1Sprite2.setPosition(672, 760);
        window.draw(g_but1Sprite2);



        txt.setFont(font);
        txt.setPosition(695, 560);
        txt.setString(head_auth);
        txt.setCharacterSize(24);
        txt.setStyle(sf::Text::Bold);
        window.draw(txt);

        txt_login.setFont(font);
        txt_login.setPosition(633, 609);
        txt_login.setString(login);
        txt_login.setCharacterSize(18);
        txt_login.setStyle(sf::Text::Bold);
        window.draw(txt_login);

        txt_pass.setFont(font);
        txt_pass.setPosition(633, 659);
        txt_pass.setString(password);
        txt_pass.setCharacterSize(18);
        txt_pass.setStyle(sf::Text::Bold);
        window.draw(txt_pass);

        txt_auth_but.setFont(font);
        txt_auth_but.setPosition(721, 721);
        txt_auth_but.setString(text_auth_but);
        txt_auth_but.setCharacterSize(14);
        txt_auth_but.setStyle(sf::Text::Bold);
        window.draw(txt_auth_but);

        txt_reg_but.setFont(font);
        txt_reg_but.setPosition(724, 771);
        txt_reg_but.setString(text_reg_but);
        txt_reg_but.setCharacterSize(14);
        txt_reg_but.setStyle(sf::Text::Bold);
        window.draw(txt_reg_but);

        window.display();

    }

    void load(void) {
        Textur.PreLoad();
        Textur.Load();

        font.loadFromFile("resurse/fonts/f.otf");
    }
};