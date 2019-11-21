
#include "player.h"
#include "main.h"
#include "input.h"
#include "sprite.h"
#include "table.h"
#include "bullet.h"
#include "collision.h"
#include "game.h"


#define PLAYER_WIDTH	(32)
#define PLAYER_HEIGHT	(32)

#define ANIME_PATTERN_MAX		3
#define ANIME_PATTERN_SKIPFRAME 8


typedef struct
{
	D3DXVECTOR2 pos;			//位置
	int			muki ;			//向き
	int			color;			//色

	int			animePattern;	//アニメパターン
	int			animeFrame;		//パターン切り替えウエイト

	CIRCLE		collision;		//円の当たり判定
	int			hitpoint;		//ヒットポイント
	int         hp;

}PLAYER;

PLAYER player;
static int Score;

int tama;
int tama_za;

void Player_Initialize(void)
{
	//プレイヤーの初期化
	player.pos.x = 512;
	player.pos.y = 500;

	player.color = 0;
	player.muki = 0;

	player.collision.cy = player.pos.y;
	player.collision.r = PLAYER_WIDTH * 0.8f;

	player.collision.cx = player.pos.x;
	Score = 0;
	player.hitpoint = 1000;

	player.hp = 5;

	tama = 3;
	tama_za = 0;
}

void Player_Finalize(void)
{

}

void Player_Update(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(0, BUTTON_UP)){
		dir.y -= 5.0f;
		//player.muki = 3;
	}
	if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_DOWN)){
		dir.y += 5.0f;
		//player.muki = 0;
	}
	if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(2, BUTTON_LEFT)){
		dir.x -= 5.0f;
		//player.muki = 1;
	}
	if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(2, BUTTON_RIGHT)){
		dir.x += 5.0f;
		//player.muki = 2;
	}
	
	if (tama > 0)
	{
		//スペースが押されたら弾を発射
		if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(2, BUTTON_A)) {
			Bullet_Create(player.pos.x, player.pos.y, dir);
			dir = D3DXVECTOR2(0.0f, 0.0f);
				tama--;

		}
	}

	if (tama <= 2)
	{
		if (tama_za >= 210)
		{
			tama++;
			tama_za = 0;
		}
		tama_za++;
	}

	// 座標の更新処理
	player.pos += dir;

	if (player.pos.x <= 256)
		player.pos.x = 256;

	if (player.pos.x >= 768)
		player.pos.x = 768;

	if (player.pos.y >= 500)
		player.pos.y = 500;

	if (player.pos.y <=499)
		player.pos.y = 500;


	//当たり判定用座標の更新
	player.collision.cx = player.pos.x + 32;
	player.collision.cy = player.pos.y;

	if (Score >= 2)
	{
		Player_AddDamage(1);
		Score = 0;
	}

	Score++;

	////スキップするフレーム値を超えたら
	//if (++player.animeFrame > ANIME_PATTERN_SKIPFRAME)
	//{
	//	//アニメパターンを進める(最大値を超えたらリセット)
	//	if (++player.animePattern >= ANIME_PATTERN_MAX)
	//		player.animePattern = 0;
	//	//フレームは元に戻す
	//	player.animeFrame = 0;
	//}
}

void Player_Draw(void)
{
	Sprite_Draw(TEXTURE_INDEX_PLAYER,
		player.pos.x,
		player.pos.y);
	if (tama >= 1)
	{
		Sprite_Draw(TEXTURE_INDEX_BULLET,10, 400);
	}
	if (tama >= 2)
	{
		Sprite_Draw(TEXTURE_INDEX_BULLET,42, 400);
	}
	if (tama >= 3)
	{
		Sprite_Draw(TEXTURE_INDEX_BULLET,74, 400);
	}

	if (player.hp >= 1)
	{
		Sprite_Draw(TEXTURE_INDEX_PLAYER,10, 300);
	}

	if (player.hp >= 2)
	{
		Sprite_Draw(TEXTURE_INDEX_PLAYER,42, 300);
	}

	if (player.hp >= 3)
	{
		Sprite_Draw(TEXTURE_INDEX_PLAYER,74, 300);
	}

	if (player.hp >= 4)
	{
		Sprite_Draw(TEXTURE_INDEX_PLAYER,106, 300);
	}

	if (player.hp >= 5)
	{
		Sprite_Draw(TEXTURE_INDEX_PLAYER,138 , 300);
	}

}

const CIRCLE* Player_GetCollision()
{
	return &player.collision;
}

void Player_AddDamage(int damage)
{
	player.hitpoint -= damage;
	if (player.hitpoint < 0)
		player.hitpoint = 0;
}
void Player_HP(int dama)
{
	player.hp -= dama;
	if (player.hp < 0)
		player.hp = 0;
}

int Player_GetHitPoint()
{
	return player.hitpoint;
}
int Player_GetHP()
{
	return player.hp;
}
