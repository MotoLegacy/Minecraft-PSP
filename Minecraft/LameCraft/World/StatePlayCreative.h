
#ifndef STATEPLAYCREATIVE_H_
#define STATEPLAYCREATIVE_H_

#include <Aurealis/Utils/StateManager.h>
#include <Aurealis/Utils/GameState.h>

#include "../Menu/Version.h"
#include <math.h>
#include <psptypes.h>

#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/Utils/Logger.h>
#include <Aurealis/Utils/Timer.h>
#include <Aurealis/System/SystemManager.h>
#include <Aurealis/Graphics/Camera.h>
#include <Aurealis/Graphics/Sprite.h>
#include <Aurealis/Graphics/TextureUtil.h>
#include <Aurealis/Graphics/Effects/SkyLight.h>
#include <Aurealis/Graphics/Effects/SnowBall2.h>
#include <Aurealis/Graphics/Effects/SkyBox.h>
#include <Aurealis/Graphics/Effects/Destroyer.h>
#include <Aurealis/Graphics/Effects/StarsBox.h>
#include <Aurealis/Graphics/Effects/Drop.h>
#include <Aurealis/Graphics/Effects/TNT.h>
#include <Aurealis/Graphics/Effects/Particle.h>
#include <Aurealis/Math/Ray.h>
#include "Mob/LameMob.h"
#include "CraftWorld2.h"
#include <Aurealis/Utils/InputHelper.h>
#include <Aurealis/Audio/SoundManager.h>
#include "Data/blocks/Chest2.h"
#include "Data/blocks/Furnace2.h"
#include "Data/entity/NoteBlockEntity.h"
#include "Data/entity/JukeboxEntity.h"
#include "Data/entity/MonsterSpawnerEntity.h"
#include "Data/entity/ItemFrameEntity.h"

#include <Aurealis/Utils/LameFunctions.h>


using namespace Aurealis::Graphics;
using namespace Aurealis::Utils;
using namespace Aurealis::System;
using namespace Aurealis::Audio;
using namespace Aurealis;


class StatePlayCreative : public CGameState
{
public:
	StatePlayCreative();
	virtual ~StatePlayCreative();

	void Init();
	void InitParametric(bool makeTrees,bool makeWater,bool makeCaves, unsigned int seedIII, int worldType, char gameMode);
	void Enter();
	void CleanUp();

	void Pause();
	void Resume();
	void LoadTextures();

	void HandleEvents(StateManager* sManager);
	void Update(StateManager* sManager);
	void Draw(StateManager* sManager);

	void LoadMap(std::string fileName,bool compressed);
	void SetWorldAndSaveName(std::string worldName,std::string fileName);
	void InitCamera();

	//keys helpers
	bool keyPressed(int currentKey);
	bool keyHold(int currentKey);
	void PutInInventory(int id, int num, bool st);

private:

	void advancedBlit(int sx, int sy, int sw, int sh, int dx, int dy, int slice);
	bool TryToMove(Vector3 moveVector,float dt);
	void SetDayTimeAfterLoad();
	void CraftItem2x2();
	void CraftItem3x3();

	void CheckForFurnFuel(Furnace* Fur);
	void CheckForFurnWorking(Furnace* Fur);
	void ReadyFurnSmelting(Furnace* Fur);

    int FindFurnaceId(int x, int y, int z);

	int FindChestId(int x, int y, int z);


private:

	Camera *fppCam;

	std::string saveFileName;
	int freeMemory;
	float freeMemoryTimer;

    float cloudsOffset;

	CraftWorld *mWorld;

    SkyLight *skyLight;
    SkyLight *skyMoonLight;
    SkyBox *skyBox;
    Destroyer *destroyer;
    StarsBox *starsBox;
    float starsAngle;
    bool check;
    bool cycle;

	bool startDt;
    float dT;
    float dET;          // ����� �������
    char dStd;          // ������ �������� ���������� �����

    bool hurt;
    float hurt_time;
    float dtt;

    float furnaceTimes;

    Vector3 testPos1;

	Vector3 cubePos;
	bool showCube;

    float sleepMessageTime;
    int sleepMessageType;
    float sleepTime;

    short craftSlotId[4];
    short craftSlotAm[4];
    bool craftSlotSt[4];

    short craftSlotId3[9];
    short craftSlotAm3[9];
    bool craftSlotSt3[9];

    short creativeSlotId[27];

    short craftItemId;
    short craftItemAm;
    bool craftItemSt;

    short craftItemId3;
    short craftItemAm3;
    bool craftItemSt3;

    float musicTimeGo;
    float musicTime;

    char chestId;
    char furnaceId;

    Chest* UseChest;
    Furnace* UseFurnace;
	//zmienne do poruszania
	float GRAVITY;
	float JUMPVELOCITY;
	float CLIMBVELOCITY;

	Vector3 playerVelocity;
	Vector3 playerPosition;
	Vector3 newPlayerPos;
	Vector3 oldPlayerPos;

	Timer handAmbient;
	float elapsedTimeHandAmbient;

    bool moveForward;
	bool walkingOnGround;
	bool moving;
	bool jumping;
	bool headInWater;
	bool footInWater;
	bool headInLava;
	bool footInLava;

	bool invEn;
	bool upEn;
	bool craft3xEn;
	bool chestEn;
	bool furnaceEn;

	bool usingSlider; // craive vars
	bool onDestroySlot;

	bool showSlotName;
	float showSlotTimer;
	float showSlotTimerMax;
	int slotId;

    char barPosition;
    char invXPosition;
    char invYPosition;

    char tempXFurnace;
    char tempYFurnace;
    bool tempUpFurnace;

    char tempXInv;
    char tempYInv;
    bool tempUpInv;

    char tempXCT;
    char tempYCT;
    bool tempUpCT;

    char tempXChest;
    char tempYChest;
    bool tempUpChest;

	int ram1;
	int ram2;

    float tickCave; //cave sounds timer
	float tickHunger;
	float tickHealth;
	float tickOS;
    float tickChunk;
    float tickShowFlymodeMessage;
    float tickShowSlotName;
    float rainSoundFrequency;

    float inputDiskNameTimer;
	std::string inputDiskName;

	short chunks; // 0 - 7;

    int chunkId;

	Timer mTimer;
	float dt;

	//int texture[16];
	Texture* barItems;
	Texture* texture;
	Texture* texture_mips;
	Texture* waterAnimation;
	
	Texture* blue;
	Texture* red;
	Texture* black;
	Texture* stars;
	
    Texture* snowBall4;
	Texture* cloudsTex;
	Texture* suntex;
	Texture* moontex;
	Texture* grassColorTex;

	unsigned char currentTexture;
	unsigned char timeTexture;

    float pre_fps;
	int average_fps;
	float tick_fps;
	int ticks;

    Sprite *waterScreen;

    Sprite *invCellSprite;
	Sprite *invSprite;
	Sprite *sliderSprite;
	Sprite *sliderLightedSprite;
    Sprite *crtSprite;
    Sprite *chtSprite;
    Sprite *selectInvSprite;
	Sprite *barSprite;
	Sprite *crossSprite;
	Sprite *selectSprite;

	Sprite *furArrowSprite[22];
	Sprite *furFireSprite[14];
    Sprite *furSprite;
    Sprite *toolPointSprite[14];

	float cameraSpeed;
	float cameraMoveSpeed;

	//menu sprites
	Sprite *buttonSprite;
	Sprite *sbuttonSprite;
	Sprite *nbuttonSprite;
	Sprite *moverSprite;

	int menuState;//0 game,1 menu
	bool menuOptions;
	int optionsMenuPos;
	int selectPos;

    char statisticsPage;
	//some settings
	bool canFly;
	bool devMode;
	bool analogLeft,analogRight,analogUp,analogDown;

	//for sound of walkinng
	float walkSoundAccu;
	bool  isWalking;

	//Headbob
	bool canHeadBob;
	float bobCycle;
	bool bobType;
	float cubeLight;

    float shift_x;
    float shift_y;
    float changeY;

    float animDest;
    float animSpeed;
    bool animGo;

    bool anim[3];
	bool makeScreen;
	bool dieFactor;

	float angleFactor;

    void SetCreativePage(char page);
    void InitCreativeInventory();

    void DrawText(int x,int y, unsigned int color, float size, const char *message, ...);
    void DrawText2(int x,int y, unsigned int color, float size, const char *message, ...);
    void DrawAmount(int x,int y, int amount);

	std::vector<SnowBall2*> mSnowBalls;
	std::vector<int> inventoryItems;
	std::vector<Particle*> mParticles;

    int creativePage;
    int creativePageMax;
};

#endif
