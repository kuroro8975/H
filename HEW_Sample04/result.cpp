#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"

static float y;


void Result_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
	y = 0;
}

void Result_Finalize(void)
{
}

void Result_Update(void)
{
	if( Keyboard_IsTrigger(DIK_SPACE) ) {
		Scene_Change(SCENE_INDEX_TITLE);
	}
	y += 1.0f;
	if (y > 500)
		y = 0;

}

void Result_Draw(void)
{
	//Sprite_Draw(TEXTURE_INDEX_RESULT, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_GAME, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_BG, 0.0f, y);
	Sprite_Draw(TEXTURE_INDEX_BG, 0.0f, -500 + y);

}
