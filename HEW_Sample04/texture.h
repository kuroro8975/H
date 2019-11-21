#pragma once

#include <d3d9.h>

typedef enum 
{
    TEXTURE_INDEX_PLAYER,
	TEXTURE_INDEX_BULLET,
	TEXTURE_INDEX_LASER,
	TEXTURE_INDEX_EXPLOSION,
	TEXTURE_INDEX_NUMBER,
	TEXTURE_INDEX_TITLE,
	TEXTURE_INDEX_RESULT,
	TEXTURE_INDEX_BG,
	TEXTURE_INDEX_GAME,	
	TEXTURE_INDEX_YUKIDARUMA,
	TEXTURE_INDEX_TEST,
	TEXTURE_INDEX_A,
	TEXTURE_INDEX_BULLET_z,
	TEXTURE_INDEX_PLAYER_z,

    TEXTURE_INDEX_MAX
}TextureIndex;

int Texture_Load(void); //������
void Texture_Release(void); //�I������
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);
int Texture_GetWidth(TextureIndex index);
int Texture_GetHeight(TextureIndex index);
