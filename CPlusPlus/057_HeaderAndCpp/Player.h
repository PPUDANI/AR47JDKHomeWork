#pragma once // 해당 cpp파일 내에 헤더의 중복을 막아주는 전처리문

// 헤더중복을 제거하는 것도 일이기 떄문에 컴파일 시간이 늘어지게 된다.
// 헤더는 최소한으로 사용하자.

Player::Player()
{

}

inline void Player::Damage(int _Damage)
{
	Hp -= _Damage;
}
