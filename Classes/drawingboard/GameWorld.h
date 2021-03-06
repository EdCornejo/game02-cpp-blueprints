#ifndef __GAMEWORLD_H__
#define __GAMEWORLD_H__

#include "GameGlobals.h"

class BackgroundManager;
class Player;
class Enemy;
class Blast;
class Missile;

class GameWorld : public Layer
{
public:
	GameWorld();
	~GameWorld();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(GameWorld);

    void CreateGame();
	void CreateBoundary();
	void CreatePlayer();
	void CreateContainers();
	void CreateHUD();

	void AddEnemyFormation();
	EEnemyFormation GetEnemyFormationType();
	void AddPowerUp();

	void AddBlast(Blast* blast);
	void AddMissile(Missile* missile);

	virtual void update(float dt);
	void CheckCollisions();
	void CheckRemovals();
	void Tick(float dt);

	void EnemyKilled();
	void ComboTimeUp();

	void PauseGame();
	void ResumeGame();
	void GameOver();

    virtual void onAcceleration(Acceleration* acc, Event* event);
	bool onTouchBegan(const std::vector<Touch*>& touches, Event* evt);
	void onTouchMoving(const std::vector<Touch*>& touches, Event* evt);
	void onTouchEnded(const std::vector<Touch*>& touches, Event* evt);

	void HandleInput(Point input);

	BackgroundManager* background_;

	Rect boundary_rect_;
	Player* player_;
	__Array* enemies_;
	__Array* powerups_;
	__Array* blasts_;
	__Array* missiles_;
	Label* score_label_;

	int seconds_;
	int enemies_killed_total_;
	int enemies_killed_combo_;
	int combo_timer_;
	int score_;
	bool is_popup_active_;
private:
	bool useAccel;
};

#endif // __GAMEWORLD_H__
