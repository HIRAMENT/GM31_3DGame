#pragma once

#include <list>
#include <vector>
#include "gameObject.h"

class Scene
{
protected:
	std::list<GameObject*> m_GameObject;

public:
	Scene() {}
	virtual ~Scene() {}

	virtual void Init() = 0;
		 
	// 終了処理
	virtual void Uninit()
	{
		for (GameObject* object : m_GameObject)		// 範囲forループ
		{
			object->Uninit();
			delete object;
		}
		m_GameObject.clear();	// リスト構造の入れ物をクリア
	}

	// 更新処理
	virtual void Update()
	{
		for (GameObject* object : m_GameObject)		// 範囲forループ
		{
			object->Update();
		}

		// ラムダ式
		m_GameObject.remove_if([](GameObject* object) {return object->Destroy(); });


	}

	// 描画処理
	virtual void Draw()
	{
		for (GameObject* object : m_GameObject)
		{
			object->Draw();
		}
	}

	// オブジェクトの追加
	GameObject* Add(GameObject* gameObject)
	{
		gameObject->Init();

		int priority = gameObject->GetDrawPriority();
		auto itr = m_GameObject.begin();
		auto end = m_GameObject.end();
		for (; itr != end; ++itr)
		{
			int nowPri = (*itr)->GetDrawPriority();
			if (priority < nowPri)
			{
				break;
			}
		}
		m_GameObject.insert(itr, gameObject);
		return gameObject;
	}

	// オブジェクトの取得(返り値：GameObject*)
	GameObject* GetGameObject(ObjectType type)
	{
		for (GameObject* object : m_GameObject)
		{
			if (object->GetObjectType() == type) // 元々の型を調べている (RTTI動的型情報)
			{
				return object;
			}
		}
		return nullptr;
	}

	// オブジェクトの取得(返り値：T*)
	template<typename T>
	T* GetGameObject(ObjectType type)
	{
		for (GameObject* object : m_GameObject)
		{
			if (object->GetObjectType() == type) // 元々の型を調べている (RTTI動的型情報)
			{
				return (T*)object;
			}
		}
		return nullptr;
	}

	// オブジェクトの取得(返り値：std::vector<GameObject*>)
	std::vector<GameObject*> GetGameObjects(ObjectType type)
	{
		std::vector<GameObject*> objects; // STLの配列 
		for (GameObject* object : m_GameObject)
		{
			if (object->GetObjectType() == type)
			{
				objects.push_back(object);
			}
		}
		return objects;
	}

	// オブジェクトの取得(返り値：std::vector<T*>)
	template<typename T>
	std::vector<T*> GetGameObjects(ObjectType type)
	{
		std::vector<T*> objects; // STLの配列 
		for (GameObject* object : m_GameObject)
		{
			if (object->GetObjectType() == type)
			{
				objects.push_back((T*)object);
			}
		}
		return objects;
	}


	// オブジェクト同士の当たり判定
	GameObject* CollisionObject(GameObject* object, ObjectType type)		// なんでもできるように改良
	{
		std::vector<GameObject*> objectList = GetGameObjects(type);
		for (GameObject* objects : objectList)
		{
			D3DXVECTOR3 objectsPosition = objects->GetPosition();

			D3DXVECTOR3 direction = object->GetPosition() - objectsPosition;
			float length = D3DXVec3Length(&direction);

			if (length < 2.0f)
			{
				return objects;
			}
		}

		return nullptr;
	}


	

private:
	void TestSmarPointer(void)
	{
		//std::list<std::shared_ptr<GameObject>> m_pGameObject;
		//std::list<std::shared_ptr<GameObject>>::iterator it;

		/*void Update(void)
		{
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				(*it)->Update();
			}

			// ラムダ式
			m_pGameObject.remove_if([](std::shared_ptr<GameObject> object) {return object->Destroy(); });
		}
		
		void Draw()
		{
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				(*it)->Draw();
			}
		}

		// オブジェクトの追加
		GameObject* Add(GameObject* gameObject)
		{
			gameObject->Init();

			int Upriority = gameObject->GetDrawPriority();
			auto uitr = m_pGameObject.begin();
			auto uend = m_pGameObject.end();
			for (; uitr != uend; uitr++)
			{
				int nowPri = (*uitr)->GetDrawPriority();
				if (Upriority < nowPri)
				{
					break;
				}
			}
			m_pGameObject.insert(uitr, std::unique_ptr<GameObject>(gameObject));
			return gameObject;
		}

		// オブジェクトの取得(返り値：GameObject*)
		std::shared_ptr<GameObject> GetGameObject(ObjectType type)
		{
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				if ((*it)->GetObjectType() == type) // 元々の型を調べている (RTTI動的型情報)
				{
					return *it;
				}
			}
			return nullptr;
		}

		// オブジェクトの取得(返り値：T*)
		template<typename T>
		std::shared_ptr<T> GetGameObject(ObjectType type)
		{
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				if ((*it)->GetObjectType() == type) // 元々の型を調べている (RTTI動的型情報)
				{
					return std::shared_ptr<T>(*it);
				}
			}
			return nullptr;
		}

		// オブジェクトの取得(返り値：std::vector<GameObject*>)
		std::vector<std::shared_ptr<GameObject>> GetGameObjects(ObjectType type)
		{
			std::vector<std::shared_ptr<GameObject>> objects; // STLの配列 
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				if ((*it)->GetObjectType() == type)
				{
					objects.push_back((*it));
				}
			}
			return objects;
		}

		// オブジェクト同士の当たり判定
		std::shared_ptr<GameObject> CollisionObject(GameObject* object, ObjectType type)		// なんでもできるように改良
		{
			std::vector<std::shared_ptr<GameObject>> objectList = GetGameObjects(type);
			for (auto itr = objectList.begin(); itr != objectList.end(); itr++)
			{
				D3DXVECTOR3 objectsPosition = (*itr)->GetPosition();

				D3DXVECTOR3 direction = object->GetPosition() - objectsPosition;
				float length = D3DXVec3Length(&direction);

				if (length < 2.0f)
				{
					return (*itr);
				}
			}

			return nullptr;
		}*/
	}
};