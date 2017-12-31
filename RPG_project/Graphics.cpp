#include "Graphics.h"

Graphics::Graphics(sf::RenderWindow& win, const Settings& settings)
	:
	win(win),
	textureList(settings),
	spriteScale(settings.GetSpriteScale())
{
	textureList.LoadAll();
}

void Graphics::DrawSprite(const sf::Texture& texture, const sf::Vector2f& pos) const
{
	sf::VertexArray quad(sf::Quads, 4);

	const int texWidth = texture.getSize().x;
	const int texHeight = texture.getSize().y;
	const int width = texWidth * spriteScale;
	const int height = texHeight * spriteScale;

	quad[0].position = pos;
	quad[1].position = sf::Vector2f(pos.x + width, pos.y);
	quad[2].position = sf::Vector2f(pos.x + width, pos.y + height);
	quad[3].position = sf::Vector2f(pos.x, pos.y + height);

	quad[0].texCoords = sf::Vector2f(0,0);
	quad[1].texCoords = sf::Vector2f(float(texWidth), 0);
	quad[2].texCoords = sf::Vector2f(float(texWidth), float(texHeight));
	quad[3].texCoords = sf::Vector2f(0, float(texHeight));

	win.draw(quad, &texture);
}

void Graphics::DrawSprite(const int index, const sf::Vector2f & pos) const
{
	DrawSprite(textureList.GetTexture(index), pos);
}

void Graphics::Clear(const sf::Color& color) const
{
	win.clear(color);
}

void Graphics::Display() const
{
	win.display();
}

void Graphics::SetView(const sf::View view) const
{
	win.setView(view);
}

const sf::View & Graphics::GetView() const
{
	return win.getView();
}
