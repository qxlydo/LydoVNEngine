#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <format>
#include <iostream>

namespace lydo {

    struct LiteLogger {
        template <typename T>
        static void logLite(T& arg, std::string path) {
            if (!arg.loadFromFile(path)) {
                std::string res = std::format("[ERROR] -> Не удалось загрузить -> {}", path);
                std::cout << res << " \n";
            }
            else
            {
                std::string res1 = std::format("[DEBUG] -> Загружено -> {}", path);
                std::cout << res1 << " \n";
            }

        }
    };

    enum State
    {
        int MENU,
        int PAUSE,
        int GAME
    };

    

    class DesktopeMode{
    public:
        sf::VideoMode desktopeMode = sf::VideoMode::getDesktopMode();

        unsigned int width = desktopeMode.width;
        unsigned int height = desktopeMode.height;
        unsigned int bpp = desktopeMode.bitsPerPixel;
    };



	class GameObject {
	public:
		virtual ~GameObject() = default;
		virtual void update(float deltaTime) {}
		virtual void render(sf::RenderWindow& window){}
	};

	class Application {
        DesktopeMode DM;
	private:
		sf::RenderWindow window;
		sf::Clock clock;
		std::vector<std::unique_ptr<GameObject>> objects;

	public:
        //(sf::VideoMode(1920, 1080)
		Application() : window(sf::VideoMode(1920, 1080), "VN") {}

		void addObjects(std::unique_ptr<GameObject> obj) {
			objects.push_back(std::move(obj));
		}
        void run() {
            window.setFramerateLimit(300);
            while (window.isOpen()) {

                // Events
                sf::Event event;

                while (window.pollEvent(event)) {

                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                float deltaTime = clock.restart().asSeconds();

                for (auto& object : objects) {
                    object->update(deltaTime);
                }

                window.clear();

                for (auto& object : objects) {
                    object->render(window);
                }

                window.display();
            }
        }

	};
 
}

