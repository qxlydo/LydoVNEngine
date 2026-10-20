#include "GameUi.h"

GameUi::GameUi(
	const std::string& textValue,
	const sf::Vector2f& basePosition,
	const std::string& path,
	const int& state)
{
	text.setPosition(basePosition);
	lydo::LiteLogger::logLite(font, path);
	text.setFont(font);
	text.setString(textValue);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(30);
}




GameUi::GameUi(const sf::Texture& texture, const std::string& textValue)
{

}

void GameUi::render(sf::RenderWindow& window) {
	window.draw(text);
}



