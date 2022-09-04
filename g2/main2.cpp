#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
#include <string>
#include "winAuth.cpp"
#include "loader.cpp"
#include "winSelect.cpp"
#include <iostream>
/*
0 - Окно авторизации
1 - Окно выбора персонажа
2 - Окно загрузки
3 - Окно игры
*/

class Key
{
public:
    int reg = 0;
    String focus_mous = "";
    void load(sf::RenderWindow& window) {

    }
    void event(sf::RenderWindow& window, WinAuths& WinAuth, int& active_windows) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (focus_mous == "login") {
                    if (event.text.unicode >= 33 && event.text.unicode <= 126) {
                        WinAuth.login += event.text.unicode;
                    }
                    else if (event.text.unicode == 8) {
                        WinAuth.lenlogin = 0;
                        while (WinAuth.login[WinAuth.lenlogin] != '\0' && WinAuth.lenlogin < 100)
                        {
                            ++WinAuth.lenlogin;
                        }
                        WinAuth.lenlogin;
                        if ((WinAuth.lenlogin) > 0) {
                            WinAuth.login.erase((WinAuth.lenlogin - 1), 1);
                        }
                    }
                }
                else if (focus_mous == "password") {
                    if (event.text.unicode >= 33 && event.text.unicode <= 126) {
                        WinAuth.password += event.text.unicode;
                    }
                    else if (event.text.unicode == 8) {
                        WinAuth.lenlogin = 0;
                        while (WinAuth.password[WinAuth.lenlogin] != '\0' && WinAuth.lenlogin < 100)
                        {
                            ++WinAuth.lenlogin;
                        }
                        WinAuth.lenlogin;
                        if ((WinAuth.lenlogin) > 0) {
                            WinAuth.password.erase((WinAuth.lenlogin - 1), 1);
                        }
                    }
                }
            }
        }

        if (active_windows == 0)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition(window);
                if (position.x > 624 && position.x < 926 && position.y > 600 && position.y <= 640)
                {
                    focus_mous = "login";
                }
                else if (position.x > 624 && position.x < 926 && position.y >= 650 && position.y < 690)
                    focus_mous = "password";
                else if (position.x > 721 && position.x < 930 && position.y >= 721 && position.y < 762)
                {
                    focus_mous = "";
                    active_windows = 1;
                }
                else if (position.x > 672 && position.x < 881 && position.y >= 710 && position.y < 750)
                {
                    focus_mous = "";
                    active_windows = 1;
                }
                else if (position.x > 672 && position.x < 881 && position.y >= 760 && position.y < 800)
                {
                    focus_mous = "";
                    if (reg == 0) {

                        reg = 1;
                    }
                }
                else
                    focus_mous = "";

            }
        }

    }
};


class Game
{
public:

    String login_t = "";
    int i = 0;
    int active_windows = 0;//Окно

    int w = 1550;
    int h = 870;
    String nameprog = "RedLava";
    Clock clock;
    float time;

    Key key;
    //
    bool winAuthLoad = false;
    WinAuths WinAuth;
    bool sound_job = false;

    bool winSelLoad = false;
    WinSelect WinSel;

    String focus_mous = "";
    /*
    Основной цикл
    */
    void sound(int x) {
        
    }
    void Run(void)
    {
        if (!sound_job) {
            sound_job = true;
        }
        sf::RenderWindow window(sf::VideoMode(w, h), nameprog);// ,sf::Style::Fullscreen параметры экрана
        window.setFramerateLimit(200);
        load();

        while (window.isOpen())
        {
            if (active_windows == 0) {
                if (!winAuthLoad)
                {
                    WinAuth.load();
                    winAuthLoad = true;
                }
                WinAuth.rend(window);
            }
            else if (active_windows == 1)
            {
                if (!winSelLoad)
                {
                    WinSel.load();
                    winSelLoad = true;
                }
                WinSel.rend(window);
            }
            else
            {

            }
            event(window, WinAuth, active_windows);
            //mciSendString("play cl/resurse/voice/test.mp3 wait", NULL, 0, NULL)  ;          

        }
    }
    /*
    Отрисовка
    */
    Loader Textur;
    void load(void) {
        Textur.PreLoad();
        Textur.Load();
    }

    /*
    События
    */
    void event(sf::RenderWindow& window, WinAuths& WinAuth, int& active_windows)
    {
        key.event(window, WinAuth, active_windows);
        //if(Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)){m_testSprite.move(-0.1*time,-0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),896,128,128));}          
    }
};