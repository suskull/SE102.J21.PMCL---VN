#pragma once

#include"SpriteManager.h"
#include"GameTime.h"
#include"GameTexture.h"


struct SCORE_LOCATION
{
	int X;
	int Y;
	int MaxLength;

};
class ScoreBar
{

	GameTexture* scoreBar;
	Sprite* itemsInScoreBar;
	static ScoreBar* instance;
	SCORE_LOCATION scoreLocation;
	SCORE_LOCATION timeLocation;
	SCORE_LOCATION playerLifeLocation;

	SCORE_LOCATION subWeaponLocation;
	SCORE_LOCATION stageLocation;
	SCORE_LOCATION playerHealthLocation;
	SCORE_LOCATION bossHealthLocation;

	GameTime gameTime;

	int score;
	int time;
	int playerLife;
	int currentStageNumber;
	int playerHealth;
	int bossHealth;
	

public:
	static ScoreBar* getInstance();
	ScoreBar();
	~ScoreBar();
	void render();
	void update();
	void renderNumber(int num, int x, int y, int maxLength);
	void renderHealth(int health, int x, int y, int maxHealth);

	void setScore(int score);
	int getScore();
	void increaseScore(int score);

	void setTime(int time);
	void decreaseTime(int time);

	int getPlayerLife();
	void setPlayerLife(int playerLife);
	void increasePlayerLife(int playerLife);

	void setCurrentStageNumber(int currentStageNumber);
	int getCurrentStageNumber();
	void increaseCurrentStageNumber(int number);


	int getPlayerHealth();
	void setPlayerHealth(int health);
	//void increaseHealth(int health);
	void restorePlayerHealth();

	int getBossHealth();
	void setBossHealth(int health);
	void increaseBossHealth(int health);
	void restoreBossHealth();
};