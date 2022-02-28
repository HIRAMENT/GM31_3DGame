#include "main.h"
#include "manager.h"
#include "resource.h"
#include "input.h"
#include "scene.h"
#include "player.h"
#include "playerMove.h"
#include "camera.h"
#include "movement.h"
#include "playerIdle.h"
#include "playerJump.h"
#include "playerAttack.h"
#include "obstancle.h"
#include "collision.h"
#include "status.h"
#include "attack.h"

#define LIMIT_OF_AREA_X (150.0f)
#define LIMIT_OF_AREA_Z (150.0f)

PlayerMove::PlayerMove(Player* player)
{
	player->SetAnimation(AnimationTag::Run);
}

void PlayerMove::Update(Player * player)
{
	D3DXVECTOR3 rot = { 0.0f,0.0f,0.0f };
	D3DXVECTOR2 move = { 0.0f,0.0f };
	float angle;
	bool isMove = false;

	Camera* camera = Manager::GetInstance()->GetScene()->GetGameObject<Camera>(ObjectType::eObCamera);
	D3DXVECTOR2 forward = { camera->GetForwardVec().x,camera->GetForwardVec().z };
	D3DXVECTOR2 right = { camera->GetRightVec().x, camera->GetRightVec().z };

	angle = Movement::GetInstance()->GetTwoVecAngle({ Vec3::Forward.x,Vec3::Forward.z }, forward);
	if (forward.x < 0.0f) angle *= -1;

	if (Keyboard_IsPress(DIK_A))
	{
		move += right * 0.1f;
		rot.x = radToDeg(angle) + 90;
	}
	if (Keyboard_IsPress(DIK_D)) 
	{
		move -= right * 0.1f;
		rot.x = radToDeg(angle) - 90;
	}
	if (Keyboard_IsPress(DIK_W)) 
	{
		move += forward * 0.1f;
		rot.x = radToDeg(angle) + 180;
	}
	if (Keyboard_IsPress(DIK_S)) 
	{
		move -= forward * 0.1f;
		rot.x = radToDeg(angle);
	}

	if (move.x != 0.0f || move.y != 0.0f)
	{
		player->SetTransformRot(Vec3::Up, rot.x);
		player->SetRotation(D3DXVECTOR3(player->GetRotation().x, D3DXToRadian(rot.x), player->GetRotation().z));
		isMove = true;
	}

	if (   player->GetPosition().x + move.x >= LIMIT_OF_AREA_X || player->GetPosition().x + move.x <= -LIMIT_OF_AREA_X
		|| player->GetPosition().z + move.y >= LIMIT_OF_AREA_Z || player->GetPosition().z + move.y <= -LIMIT_OF_AREA_Z)
	{
		move = D3DXVECTOR2(0.0f, 0.0f);
	}

	std::vector<Obstancle*> obstancles = player->GetScene()->GetGameObjects<Obstancle>(ObjectType::eObObstancle);
	for (auto obs : obstancles)
	{
		if (Collision::GetInstance()->ObbToObb(player->GetObb(), obs->GetObb()))
		{
			D3DXVECTOR3 nor = player->GetPosition() - obs->GetPosition();
			D3DXVec3Normalize(&nor, &nor);
			move = D3DXVECTOR2(nor.x, nor.z) * 0.02f;
		}
	}

	// 位置の更新
	player->SetTransformTrans({ move.x, 0.0f, move.y });

	// スペースキーを押したらジャンプステートに移動
	if(Keyboard_IsPress(DIK_SPACE))
	{ 
		player->ChangeState(new PlayerJump(player, { move.x, 0.0f, move.y }));
	}

	// 左クリック&攻撃ができるなら攻撃に移行
	if (Mouse_IsLeftTrigger() && player->GetStatus()->GetAttack()->CheckCoolTime())
	{
		player->ChangeState(new PlayerAttack(player));
	}

	// 動いてなかったらアイドルステートに移動
	if(!isMove)
	{
		player->ChangeState(new PlayerIdle(player));
	}
}
