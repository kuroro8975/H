
#include "enemy.h"
#include "main.h"
#include "sprite.h"
#include "table.h"
#include "player.h"
#include "enemybullet.h"
#include "enemylaser.h"
#include "explosion.h"
#include <time.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define ENEMY_WIDTH				(32)
#define ENEMY_HEIGHT			(32)
#define ANIME_PATTERN_MAX		(3)
#define ANIME_PATTERN_SKIPFRAME (8)

#define ENEMY_SEARCH_RADIUS		(200.0f)
#define ENEMY_SEARCH_ANGLE		(0.85f)
#define ENEMY_CHASE_SPEED		(3.0f)
#define ENEMY_RETURN_SPEED		(1.0f)

typedef struct
{
	int			enable;	//�����t���O

	D3DXVECTOR2 pos;	//�ʒu
	float		rot;	//��]
	int			color;	//�F
	int			muki;	//�����i�ړ������j

	int			animePattern;	//�A�j���p�^�[��
	int			animeFrame;		//�p�^�[���؂�ւ��E�G�C�g

	CIRCLE		collision;

	int			frame;
	int			frame_alpha;
	int			state;
	D3DXVECTOR2 dir_shot;
	D3DXVECTOR2 pos_return;

}ENEMY_DATA;

ENEMY_DATA enemy[ENEMY_COUNT];

int frame;
int enemy_pop;
int w;

//typedef enum
//{
//	ENEMY_STATE_INIT,		//������
//	ENEMY_STATE_SEARCH,		//���͂��T�[�`
//	ENEMY_STATE_FIND,		//�G�𔭌�
//	ENEMY_STATE_CHASE,		//�ǐ�
//	ENEMY_STATE_SHOT,		//�V���b�g����
//	ENEMY_STATE_LASER,		//���[�U�[����
//	ENEMY_STATE_COOLDOWN,	//�V���b�g�I��
//	ENEMY_STATE_RETURN,		//��ʒu�ɖ߂�
//	ENEMY_STATE_DEAD,		//���S���
//
//	ENEMY_STATE_MAX
//
//}ENEMY_STATE;
//
//
//int Enemy_CalcMuki(D3DXVECTOR2 dir);
//
//void Enemy_StateInit(int index);
//void Enemy_StateSearch(int index);
//void Enemy_StateFind(int index);
//void Enemy_StateChase(int index);
//void Enemy_StateShot(int index);
//void Enemy_StateLaser(int index);
//void Enemy_StateCooldown(int index);
//void Enemy_StateReturn(int index);



void Enemy_Initialize(void)
{
	//�G�̏�����
	for (int i = 0; i < ENEMY_COUNT; i++) {

		enemy[i].enable = false;
		//Enemy_StateInit(i);
		//enemy[i].state = ENEMY_STATE_SEARCH;
	}
	frame = 110;
	w = 2;

		SetEnemy(288, 500);
		SetEnemy(352, 500);
		SetEnemy(480, 500);

}

void Enemy_Finalize(void)
{

}

void Enemy_Update(void)
{
	for (int i = 0; i < ENEMY_COUNT; i++) {

		//�����蔻��p���W�̍X�V
		enemy[i].collision.cx = enemy[i].pos.x + 32;
		enemy[i].collision.cy = enemy[i].pos.y;	
		
		//enemy[i].pos.x += w;
		//enemy[i].pos.y += 1.0;
		
		//if (enemy[i].pos.x <= 768)
		//	w *= -1;
	
	/*	if (enemy[i].pos.x >= 257)
			w *= -1;*/

			//if (enemy[i].pos.y >= 576)
			//enemy[i].enable = false;

	}
		//srand((unsigned int)time(NULL));

		//if (frame == 150)
		//{
		//	enemy_pop = rand() % 5 + 1;
		//	if (enemy_pop == 1)
		//	{
		//		SetEnemy(288, 100);
		//		SetEnemy(352, 100);
		//		SetEnemy(480, 100);
		//	}
		//	if (enemy_pop == 2)
		//	{
		//		SetEnemy(352, 100);
		//		SetEnemy(480, 100);
		//		SetEnemy(544, 100);

		//	}
		//	if (enemy_pop == 3)
		//	{
		//		SetEnemy(288,100);
		//		SetEnemy(480, 100);
		//		SetEnemy(544, 100);
		//		SetEnemy(618, 100);
		//	}
		//	if (enemy_pop == 4)
		//	{
		//		SetEnemy(288,100);
		//		SetEnemy(480, 100);
		//		SetEnemy(682, 100);
		//		SetEnemy(618, 100);

		//	}
		//	if (enemy_pop == 5)
		//	{
		//		SetEnemy(288,100);
		//		SetEnemy(480, 100);
		//		SetEnemy(544, 100);
		//		SetEnemy(682, 100);

		//	}
		//	frame = 0;
		//}
		
		


		//frame++;

		//�X�L�b�v����t���[���l�𒴂�����
		//if (++enemy[i].animeFrame > ANIME_PATTERN_SKIPFRAME)
		//{
		//	//�A�j���p�^�[����i�߂�(�ő�l�𒴂����烊�Z�b�g)
		//	if (++enemy[i].animePattern >= ANIME_PATTERN_MAX)
		//		enemy[i].animePattern = 0;
		//	//�t���[���͌��ɖ߂�
		//	enemy[i].animeFrame = 0;
		//}

		///*switch (enemy[i].state)
		//{
		//case ENEMY_STATE_INIT:
		//	Enemy_StateInit(i);
		//	break;*/
		///*case ENEMY_STATE_SEARCH:
		//	Enemy_StateSearch(i);
		//	break;
		//case ENEMY_STATE_FIND:
		//	Enemy_StateFind(i);
		//	break;
		//case ENEMY_STATE_CHASE:
		//	Enemy_StateChase(i);
		//	break;
		//case ENEMY_STATE_SHOT:
		//	Enemy_StateShot(i);
		//	break;
		//case ENEMY_STATE_LASER:
		//	Enemy_StateLaser(i);
		//	break;
		//case ENEMY_STATE_COOLDOWN:
		//	Enemy_StateCooldown(i);
		//	break;
		//case ENEMY_STATE_RETURN:
		//	Enemy_StateReturn(i);
		//	break;*/
		//default:
		//	break;
		//}
	
}

void Enemy_Draw(void)
{
	for (int i = 0; i < ENEMY_COUNT; i++){

		//�����t���O��TRUE�̓G�̂ݏ������s��
		if (!enemy[i].enable) {
			continue;
		}

		Sprite_Draw(TEXTURE_INDEX_YUKIDARUMA,
			enemy[i].pos.x,
			enemy[i].pos.y);
	}
}

void SetEnemy(float x, float y)
{

	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		if (enemy[i].enable == false)
		{
			enemy[i].pos.x = x;
			enemy[i].pos.y = y;
			enemy[i].enable = true;
			break;
		}
	}

}
void Enemy_Destroy(int index)
{
	//enemy[index].state = ENEMY_STATE_DEAD;
	enemy[index].enable = false;
}

bool Enemy_IsEnable(int index)
{
	return enemy[index].enable;
}

const CIRCLE* Enemy_GetCollision(int index)
{
	return &enemy[index].collision;
}

//���������
//int Enemy_CalcMuki(D3DXVECTOR2 dir)
//{
//	int muki = 0;
//
//	//�ړ��������L�����`�F�b�N
//	if (D3DXVec2Length(&dir) > 0.01f)
//	{
//		//X������Y�����̑傫�����ׂāA�ǂ���̕����傫���̂��𒲂ׂ�
//		//X�����̕����傫���ꍇ
//		if (fabs(dir.x) > fabs(dir.y))
//		{
//			//X�������v���X�̒l�Ȃ̂��}�C�i�X�̒l�Ȃ̂��𒲂ׂ�
//			//�}�C�i�X�����̏ꍇ�͍�����
//			if (dir.x < 0.0f)
//				muki = 1;
//			//��������Ȃ��i�v���X�����j�ꍇ�͉E����
//			else
//				muki = 2;
//		}
//		//Y�����̕����傫���ꍇ
//		else
//		{
//			//Y�������v���X�̒l�Ȃ̂��}�C�i�X�̒l�Ȃ̂��𒲂ׂ�
//			//�}�C�i�X�����̏ꍇ�͏����
//			if (dir.y < 0.0f)
//				muki = 3;
//			//��������Ȃ��i�v���X�����j�ꍇ�͏����
//			else
//				muki = 0;
//		}
//	}
//
//	return muki;
//}

//void Enemy_StateInit(int index)
//{
//	enemy[index].pos.x = frand() * SCREEN_WIDTH;
//	enemy[index].pos.y = frand() * SCREEN_HEIGHT;
//	enemy[index].rot = 0;
//	enemy[index].color = 1;
//
//	enemy[index].muki = rand() % 4;
//	enemy[index].enable = TRUE;
//
//	enemy[index].collision.cx = enemy[index].pos.x;
//	enemy[index].collision.cy = enemy[index].pos.y;
//	enemy[index].collision.r = ENEMY_WIDTH * 0.8f;
//
//	enemy[index].frame = 0;
//
//	//�X�e�[�g���T�[�`��Ԃֈڍs
//	enemy[index].state = ENEMY_STATE_SEARCH;
//
//}

//void Enemy_StateSearch(int index)
//{
//	//�t���[����i�߂�
//	enemy[index].frame++;
//
//	D3DXVECTOR2 dir;
//
//	//�����Ă�������̃x�N�g�������
//	switch (enemy[index].muki)
//	{
//	case 0://������
//		dir = D3DXVECTOR2( 0.0f,  1.0f);
//		break;
//	case 1://������
//		dir = D3DXVECTOR2(-1.0f,  0.0f);
//		break;
//	case 2://�E����
//		dir = D3DXVECTOR2( 1.0f,  0.0f);
//		break;
//	case 3://�����
//		dir = D3DXVECTOR2( 0.0f, -1.0f);
//		break;
//	}
//
//	//�v���C���[�̍��W���擾����
//	D3DXVECTOR2 pl_pos = D3DXVECTOR2(Player_GetCollision()->cx, Player_GetCollision()->cy);
//
//	//�G�ƃv���C���[�̋������v�Z����
//	D3DXVECTOR2 vLen = enemy[index].pos - pl_pos;
//	float length = D3DXVec2Length(&vLen);
//
//	//���肷�鋗���̒��ɓ����Ă��邩���`�F�b�N����
//	if (length < ENEMY_SEARCH_RADIUS)
//	{
//		//�G���猩�ăv���C���[�̍��W�ւ̕����x�N�g�������
//		D3DXVECTOR2 pl_dir = pl_pos - enemy[index].pos;
//		D3DXVec2Normalize(&pl_dir, &pl_dir);
//
//		//�G�̌����ƃv���C�����W�ւ̕����x�N�g���œ��ς����
//		float dot = D3DXVec2Dot(&dir, &pl_dir);
//
//		//���肷��p�x���ɓ����Ă��邩���`�F�b�N����
//		if (dot > ENEMY_SEARCH_ANGLE)
//		{
//			Explosion_Create(enemy[index].pos.x, enemy[index].pos.y);
//
//			//����ɒʂ�΃v���C���[�����X�e�[�g�Ɉڍs����
//			enemy[index].state = ENEMY_STATE_FIND;
//			enemy[index].frame = 0;
//
//			//�߂��ė�����W��ۑ�����
//			enemy[index].pos_return = enemy[index].pos;
//		}
//	}
//
//	//������ω�������
//	if (enemy[index].frame > 60)
//	{
//		enemy[index].muki = (enemy[index].muki + 1) % 4;
//		enemy[index].frame = 0;
//	}
//
//}
//
//void Enemy_StateFind(int index)
//{
//	//�t���[����i�߂�
//	enemy[index].frame++;
//
//	//��莞�Ԍo������ǐՃX�e�[�g�ֈڍs
//	if (enemy[index].frame > 20){
//
//		enemy[index].frame = 0;
//
//		//�X�e�[�g���T�[�`��Ԃֈڍs
//		enemy[index].state = ENEMY_STATE_CHASE;
//	}
//}
//
//void Enemy_StateChase(int index)
//{
//	//�t���[����i�߂�
//	enemy[index].frame++;
//
//	//�v���C���[�̍��W���擾����
//	D3DXVECTOR2 pl_pos = D3DXVECTOR2(Player_GetCollision()->cx, Player_GetCollision()->cy);
//	
//	D3DXVECTOR2 dir = pl_pos - enemy[index].pos;
//	D3DXVec2Normalize(&dir, &dir);
//	dir *= ENEMY_CHASE_SPEED;
//
//	enemy[index].pos += dir;
//
//	//�ړ�����������������
//	enemy[index].muki = Enemy_CalcMuki(dir);
//
//	//��莞�Ԍo������e�ˏo�X�e�[�g�ֈڍs
//	if (enemy[index].frame > 120){
//
//		enemy[index].frame = 0;
//
//		//�ړ�������ۑ�
//		enemy[index].dir_shot = dir;
//
//		//�����_���Łu�΂�T���e�v�������́u���[�U�[�v���ˏo
//		if (rand() % 2)
//		{
//			//�X�e�[�g���T�[�`��Ԃֈڍs
//			enemy[index].state = ENEMY_STATE_SHOT;
//		}
//		else{
//			//�X�e�[�g���T�[�`��Ԃֈڍs
//			enemy[index].state = ENEMY_STATE_LASER;
//		}
//	}
//}

//void Enemy_StateShot(int index)
//{
//	//�t���[����i�߂�
//	enemy[index].frame++;
//
//	float shot_rad = atan2(enemy[index].dir_shot.y, enemy[index].dir_shot.x);
//	shot_rad = (float)(M_PI * 2 / 20)*enemy[index].frame;
//
//	//�ˏo�p�x�N�g�����t���[���l�ŉ�]������
//	D3DXVECTOR2 shot_dir;
//	shot_dir.x = enemy[index].dir_shot.x*cosf(shot_rad) - enemy[index].dir_shot.y*sinf(shot_rad);
//	shot_dir.y = enemy[index].dir_shot.x*sinf(shot_rad) + enemy[index].dir_shot.y*cosf(shot_rad);
//
//	EnemyBullet_Create(enemy[index].pos.x, enemy[index].pos.y, shot_dir);
//
//	//��莞�Ԍo������N�[���_�E���X�e�[�g�ֈڍs
//	if (enemy[index].frame > 90){
//
//		enemy[index].frame = 0;
//
//		//�X�e�[�g���A�ҏ�Ԃֈڍs
//		enemy[index].state = ENEMY_STATE_COOLDOWN;
//	}
//}
//
//void Enemy_StateLaser(int index)
//{
//	if (enemy[index].frame == 0){
//		EnemyLaser_Create(enemy[index].pos.x, enemy[index].pos.y, enemy[index].dir_shot);
//	}
//
//	//�t���[����i�߂�
//	enemy[index].frame++;
//
//
//	//��莞�Ԍo������N�[���_�E���X�e�[�g�ֈڍs
//	if (enemy[index].frame > 90){
//
//		enemy[index].frame = 0;
//
//		//�X�e�[�g���A�ҏ�Ԃֈڍs
//		enemy[index].state = ENEMY_STATE_COOLDOWN;
//	}
//}
//
//void Enemy_StateCooldown(int index)
//{
//	//�t���[����i�߂�
//	enemy[index].frame++;
//
//	//��莞�Ԍo������A�҃X�e�[�g�ֈڍs
//	if (enemy[index].frame > 30){
//
//		enemy[index].frame = 0;
//
//		//�X�e�[�g���A�ҏ�Ԃֈڍs
//		enemy[index].state = ENEMY_STATE_RETURN;
//	}
//}
//
//void Enemy_StateReturn(int index)
//{
//	//�t���[����i�߂�
//	enemy[index].frame++;
//
//	//�v���C���[�̍��W���擾����
//	D3DXVECTOR2 pl_pos = D3DXVECTOR2(Player_GetCollision()->cx, Player_GetCollision()->cy);
//
//	//�A�҂�����W�ւ̌����x�N�g�����v�Z����
//	D3DXVECTOR2 dir = enemy[index].pos_return - enemy[index].pos;
//
//	//�x�N�g���̒������v�Z����
//	float length = D3DXVec2Length(&dir);
//
//	D3DXVec2Normalize(&dir, &dir);
//	dir *= ENEMY_CHASE_SPEED;
//
//	enemy[index].pos += dir;
//
//	//�ړ�����������������
//	enemy[index].muki = Enemy_CalcMuki(dir);
//
//	//�A�҂�����W�ɓ���������
//	if (length <= ENEMY_CHASE_SPEED){
//
//		enemy[index].frame = 0;
//
//		//�X�e�[�g���T�[�`��Ԃֈڍs
//		enemy[index].state = ENEMY_STATE_SEARCH;
//	}
//}
