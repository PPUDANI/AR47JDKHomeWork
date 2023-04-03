#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	GameObject(const GameObject& _Other) = delete;
	GameObject(GameObject&& _Other) noexcept = delete;
	GameObject& operator=(const GameObject& _Other) = delete;
	GameObject& operator=(GameObject&& _Other) noexcept = delete;
protected:

private:

};

