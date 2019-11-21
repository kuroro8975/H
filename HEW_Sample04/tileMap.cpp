//=============================================================================
//
// ”wŒiˆ— [bg.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "tileMap.h"
#include "input.h"
#include "player.h"
#include "texture.h"
#include "sprite.h"

static float y;

void BG_Init()
{
	y = 0;
}
void BG_Uninit()
{

}
void BG_Update() 
{
	y += 1.0f;
	if (y > 500)
		y = 0;
}

void BG_Draw()
{
	Sprite_Draw(TEXTURE_INDEX_TEST, 0.0f, 0.0f,0,0,1024,576);	
	//Sprite_Draw(TEXTURE_INDEX_TEST, 0.0f, 200.0f,200,200,624,150);
	//Sprite_Draw(TEXTURE_INDEX_GAME, 0.0f, 0.0f);
	//Sprite_Draw(TEXTURE_INDEX_BG, 0.0f, y);
	//Sprite_Draw(TEXTURE_INDEX_BG, 0.0f, -500 + y);
}