#pragma once // �ش� cpp���� ���� ����� �ߺ��� �����ִ� ��ó����

// ����ߺ��� �����ϴ� �͵� ���̱� ������ ������ �ð��� �þ����� �ȴ�.
// ����� �ּ������� �������.

Player::Player()
{

}

inline void Player::Damage(int _Damage)
{
	Hp -= _Damage;
}
