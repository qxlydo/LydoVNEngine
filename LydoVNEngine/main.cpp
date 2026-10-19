// LydoVNEngine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include "Core.h"
#include "GameUi.h"


int main(){
    lydo::Application app;

    app.addObjects(std::make_unique<GameUi>("Menu", sf::Vector2f{500.f,1030.f}, "assets/Motrhead_Grotesk.ttf"));
    app.addObjects(std::make_unique<GameUi>("Load", sf::Vector2f{800.f,1030.f}, "assets/Motrhead_Grotesk.ttf"));
    app.addObjects(std::make_unique<GameUi>("Save", sf::Vector2f{1100.f,1030.f}, "assets/Motrhead_Grotesk.ttf"));
    app.addObjects(std::make_unique<GameUi>("Settings",sf::Vector2f{1400.f,1030.f}, "assets/Motrhead_Grotesk.ttf"));

    app.run();

    std::cout << "Hello World!\n";
}