#pragma once
#include "Core.h"
#include <SFML/Graphics.hpp>



class GameUi : public lydo::GameObject {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Text text;
	sf::Font font;

public:
	// text
	GameUi(
		const std::string& textValue,
		const sf::Vector2f& basePosition,
		const std::string& path
	);

	// sprite
	GameUi(const sf::Texture& texture);
	// text + sprite
	GameUi(
		const sf::Texture& texture,
		const std::string& textValue
	);

	void render(sf::RenderWindow& window) override;


};

