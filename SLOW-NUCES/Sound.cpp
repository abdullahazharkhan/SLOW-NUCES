#include "Sound.h"

Sound::Sound()
{
	clickBuffer.loadFromFile("./Assets/SFX/buttonClick.mp3");
	clickSFX.setBuffer(clickBuffer);
	bookBuffer.loadFromFile("./Assets/SFX/bookPage.wav");
	bookSFX.setBuffer(bookBuffer);
	cashBuffer.loadFromFile("./Assets/SFX/cash.wav");
	cashSFX.setBuffer(cashBuffer);
	coinsBuffer.loadFromFile("./Assets/SFX/coins.wav");
	coinsSFX.setBuffer(coinsBuffer);
	doorBuffer.loadFromFile("./Assets/SFX/doorOpen.wav");
	doorSFX.setBuffer(doorBuffer);
	pongBuffer.loadFromFile("./Assets/SFX/pongBlip.wav");
	pongSFX.setBuffer(pongBuffer);
}

void Sound::clickSound()
{
	clickSFX.play();
}

void Sound::bookSound()
{
	bookSFX.play();
}

void Sound::cashSound()
{
	cashSFX.play();
}

void Sound::coinsSound()
{
	coinsSFX.play();
}

void Sound::doorSound()
{
	doorSFX.play();
}

void Sound::pongSound()
{
	pongSFX.play();
}