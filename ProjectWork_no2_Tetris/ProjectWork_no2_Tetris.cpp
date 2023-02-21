// ProjectWork_no2_Tetris.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameWorld.h"
#include <Windows.h>

void draw(sf::RenderWindow* _window, GameWorld* _world) {
    _window->clear();
    _world->draw();
    _window->display();
}



int main()
{
    const int windowHeight = 450;
    const int windowWidth = 800;
    sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "Tetris");
    sf::Event event;
    GameWorld world= GameWorld(windowHeight, windowWidth ,&window);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            world.keyPressed("right");
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            world.keyPressed("left");
            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            world.keyPressed("down");
            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            world.keyPressed("up");

        }
        draw(&window, &world);
        Sleep(300);
    }
}









// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
