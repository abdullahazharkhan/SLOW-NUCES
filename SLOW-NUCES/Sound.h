#pragma once
#include <SFML/Audio.hpp>

class Sound
{
private:
	sf::SoundBuffer clickBuffer;
	sf::Sound clickSFX;
	sf::SoundBuffer bookBuffer;
	sf::Sound bookSFX;
	sf::SoundBuffer cashBuffer;
	sf::Sound cashSFX;
	sf::SoundBuffer coinsBuffer;
	sf::Sound coinsSFX;
	sf::SoundBuffer doorBuffer;
	sf::Sound doorSFX;
	sf::SoundBuffer pongBuffer;
	sf::Sound pongSFX;
public:
	Sound();
	void clickSound();
	void bookSound();
	void cashSound();
	void coinsSound();
	void doorSound();
	void pongSound();
};

