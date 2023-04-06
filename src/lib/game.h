#include <SFML\Graphics.hpp>
#include "resource.h"

class Game
{
public:
	Game()
		: mWindow(sf::VideoMode(1280, 720), "SFML Application")
		, mIsMovingUp(false)
		, mIsMovingDown(false)
		, mIsMovingLeft(false)
		, mIsMovingRight(false)
		, mPlayerSpeed(180.f)
	{
		textures.load(Textures::Airplane, "C:\\Users\\leona\\Desktop\\Project_Maverick\\textures\\Eagle.png");
		mPlayerPlane.setTexture(textures.get(Textures::Airplane));
	}

	void run()
	{
		sf::Clock clock;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		sf::Time timePerFrame = sf::seconds(1.f / 60.f);
		while (mWindow.isOpen())
		{
			processEvents();
			timeSinceLastUpdate += clock.restart();
			while (timeSinceLastUpdate > timePerFrame)
			{
				timeSinceLastUpdate -= timePerFrame;
				processEvents();
				update(timePerFrame);
			}
			render();
		}
	}

private:
	sf::RenderWindow mWindow;
	ResourceHolder<sf::Texture, Textures::ID> textures;
	sf::Sprite mPlayerPlane;

	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
	float mPlayerSpeed;

	void processEvents()
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				processPlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				processPlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
			}
		}
	}

	void processPlayerInput(sf::Keyboard::Key key, bool isPressed)
	{
		if (key == sf::Keyboard::W)
			mIsMovingUp = isPressed;
		if (key == sf::Keyboard::S)
			mIsMovingDown = isPressed;
		if (key == sf::Keyboard::A)
			mIsMovingLeft = isPressed;
		if (key == sf::Keyboard::D)
			mIsMovingRight = isPressed;
	}

	void update(sf::Time deltaTime)
	{
		sf::Vector2f movement(0.f, 0.f);
		if (mIsMovingUp)
			movement.y -= mPlayerSpeed;
		if (mIsMovingDown)
			movement.y += mPlayerSpeed;
		if (mIsMovingLeft)
			movement.x -= mPlayerSpeed;
		if (mIsMovingRight)
			movement.x += mPlayerSpeed;

		movement *= deltaTime.asSeconds();
		mPlayerPlane.move(movement);
	}

	void render()
	{
		mWindow.clear();
		mWindow.draw(mPlayerPlane);
		mWindow.display();
	}
};