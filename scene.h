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
		 
	// �I������
	virtual void Uninit()
	{
		for (GameObject* object : m_GameObject)		// �͈�for���[�v
		{
			object->Uninit();
			delete object;
		}
		m_GameObject.clear();	// ���X�g�\���̓��ꕨ���N���A
	}

	// �X�V����
	virtual void Update()
	{
		for (GameObject* object : m_GameObject)		// �͈�for���[�v
		{
			object->Update();
		}

		// �����_��
		m_GameObject.remove_if([](GameObject* object) {return object->Destroy(); });


	}

	// �`�揈��
	virtual void Draw()
	{
		for (GameObject* object : m_GameObject)
		{
			object->Draw();
		}
	}

	// �I�u�W�F�N�g�̒ǉ�
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

	// �I�u�W�F�N�g�̎擾(�Ԃ�l�FGameObject*)
	GameObject* GetGameObject(ObjectType type)
	{
		for (GameObject* object : m_GameObject)
		{
			if (object->GetObjectType() == type) // ���X�̌^�𒲂ׂĂ��� (RTTI���I�^���)
			{
				return object;
			}
		}
		return nullptr;
	}

	// �I�u�W�F�N�g�̎擾(�Ԃ�l�FT*)
	template<typename T>
	T* GetGameObject(ObjectType type)
	{
		for (GameObject* object : m_GameObject)
		{
			if (object->GetObjectType() == type) // ���X�̌^�𒲂ׂĂ��� (RTTI���I�^���)
			{
				return (T*)object;
			}
		}
		return nullptr;
	}

	// �I�u�W�F�N�g�̎擾(�Ԃ�l�Fstd::vector<GameObject*>)
	std::vector<GameObject*> GetGameObjects(ObjectType type)
	{
		std::vector<GameObject*> objects; // STL�̔z�� 
		for (GameObject* object : m_GameObject)
		{
			if (object->GetObjectType() == type)
			{
				objects.push_back(object);
			}
		}
		return objects;
	}

	// �I�u�W�F�N�g�̎擾(�Ԃ�l�Fstd::vector<T*>)
	template<typename T>
	std::vector<T*> GetGameObjects(ObjectType type)
	{
		std::vector<T*> objects; // STL�̔z�� 
		for (GameObject* object : m_GameObject)
		{
			if (object->GetObjectType() == type)
			{
				objects.push_back((T*)object);
			}
		}
		return objects;
	}


	// �I�u�W�F�N�g���m�̓����蔻��
	GameObject* CollisionObject(GameObject* object, ObjectType type)		// �Ȃ�ł��ł���悤�ɉ���
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

			// �����_��
			m_pGameObject.remove_if([](std::shared_ptr<GameObject> object) {return object->Destroy(); });
		}
		
		void Draw()
		{
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				(*it)->Draw();
			}
		}

		// �I�u�W�F�N�g�̒ǉ�
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

		// �I�u�W�F�N�g�̎擾(�Ԃ�l�FGameObject*)
		std::shared_ptr<GameObject> GetGameObject(ObjectType type)
		{
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				if ((*it)->GetObjectType() == type) // ���X�̌^�𒲂ׂĂ��� (RTTI���I�^���)
				{
					return *it;
				}
			}
			return nullptr;
		}

		// �I�u�W�F�N�g�̎擾(�Ԃ�l�FT*)
		template<typename T>
		std::shared_ptr<T> GetGameObject(ObjectType type)
		{
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				if ((*it)->GetObjectType() == type) // ���X�̌^�𒲂ׂĂ��� (RTTI���I�^���)
				{
					return std::shared_ptr<T>(*it);
				}
			}
			return nullptr;
		}

		// �I�u�W�F�N�g�̎擾(�Ԃ�l�Fstd::vector<GameObject*>)
		std::vector<std::shared_ptr<GameObject>> GetGameObjects(ObjectType type)
		{
			std::vector<std::shared_ptr<GameObject>> objects; // STL�̔z�� 
			for (it = m_pGameObject.begin(); it != m_pGameObject.end(); it++)
			{
				if ((*it)->GetObjectType() == type)
				{
					objects.push_back((*it));
				}
			}
			return objects;
		}

		// �I�u�W�F�N�g���m�̓����蔻��
		std::shared_ptr<GameObject> CollisionObject(GameObject* object, ObjectType type)		// �Ȃ�ł��ł���悤�ɉ���
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