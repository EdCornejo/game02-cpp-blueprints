#ifndef _SPACECRAZE_GAME_GLOBALS_H_
#define _SPACECRAZE_GAME_GLOBALS_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "GameResources.h"

USING_NS_CC;

using namespace std;

namespace spacecraze
{
#define SCREEN_SIZE GameGlobals::screen_size_
#define SOUND_ENGINE CocosDenshion::SimpleAudioEngine::getInstance()
#define MAX_STARS 15
#define BULLET_MOVE_DURATION 1.5f
#define MAX_BULLETS 25
#define MAX_LEVELS 5

	// enum used for proper z-ordering
	enum E_ZORDER
	{
		E_LAYER_BACKGROUND = 0,
		E_LAYER_FOREGROUND = 2,
		E_LAYER_ENEMIES_BRICKS = 4,
		E_LAYER_BULLETS = 6,
		E_LAYER_PLAYER = 8,
		E_LAYER_HUD = 10,
		E_LAYER_POPUP = 12,
	};

	class GameGlobals
	{
	public:
		GameGlobals(void) {};
		~GameGlobals(void) {};

		// initialise common global data here...called when application finishes launching
		static void Init();
		// load initial/all game data here
		static void LoadData();

		// save screen size for fast access
		static Size screen_size_;

		// function takes comma separated string & returns vector of values
		static vector<float> GetFloatListFromString(string input);
		// function takes comma separated string & returns CCPoint
		static Point GetPointFromString(string input);
	};
}

#endif // _SPACECRAZE_GAME_GLOBALS_H_
