
#include <iostream>
#include <conio.h>
#include <Windows.h>


void BombTimeCounting(short* _BombTimerArr, const short _MaxBombNum)
{
	for (size_t i = 0; i < _MaxBombNum; i++)
	{
		if (_BombTimerArr[i] > 1)
		{
			--_BombTimerArr[i];
		}
	}
}

int main()
{
	
	// 기본 맵 생성
	const short ScreenYSize = 20;
	const short ScreenXSize = 20;
	short MapDataArr[ScreenYSize][ScreenXSize];

	// 맵 초기화
	for (short y = 0; y < ScreenYSize; y++)
	{
		for (short x = 0; x < ScreenXSize; x++)
		{
			if (x == 0 || y == 0 || x == ScreenXSize - 1 || y == ScreenYSize - 1)
			{
				MapDataArr[y][x] = 1;
			}
			else
			{
				MapDataArr[y][x] = 0;
			}
		}
	}

	const short ScreenFrame = 10;
	short Window = 1;

	const short MaxBombNum = 5; // 폭탄 설치 개수
	const short TimeOfBomb = 50; // 폭탄의 시간
	short BombTimerArr[MaxBombNum] = { 0, }; // 폭탄마다 시간 저장

	short BombLocationArr[ScreenYSize][ScreenXSize] = {0,};
	short BombNumCount = 0; // 설치된 폭탄 개수

	// 플레이어 좌표
	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;

	// 맵 출력 시 구조물 구분 숫자
	const short EmptySpaceIconNum = 0;
	const short WallIconNum = 1;
	const short InstalledWallIconNum = 2;
	const short BombIconNum = 5;
	const short BombAnimCount = 2;

	while (true)
	{
		// 화면 초기화
		system("cls");

		for (short y = 0; y < ScreenYSize; y++)
		{
			for (short x = 0; x < ScreenXSize; x++)
			{
				if (MapDataArr[y][x] >= BombIconNum)
				{
					if (BombTimerArr[BombLocationArr[y][x]] == 1)
					{
						if (MapDataArr[y][x] == BombIconNum)
						{
							MapDataArr[y - 1][x] = BombIconNum + (BombAnimCount * 2) + 1;
							MapDataArr[y + 1][x] = BombIconNum + (BombAnimCount * 2) + 1;
							MapDataArr[y][x - 1] = BombIconNum + (BombAnimCount * 2) + 1;
							MapDataArr[y][x + 1] = BombIconNum + (BombAnimCount * 2) + 1;
						}
						else if (MapDataArr[y][x] == BombIconNum + BombAnimCount)
						{
							MapDataArr[y - 2][x] = BombIconNum + (BombAnimCount * 2) + 1;
							MapDataArr[y + 2][x] = BombIconNum + (BombAnimCount * 2) + 1;
							MapDataArr[y][x - 2] = BombIconNum + (BombAnimCount * 2) + 1;
							MapDataArr[y][x + 2] = BombIconNum + (BombAnimCount * 2) + 1;
						}
						else if (MapDataArr[y][x] == BombIconNum + (BombAnimCount * 2))
						{
							BombTimerArr[BombLocationArr[y][x]] = 0;

							MapDataArr[y][x] = 0;
							MapDataArr[y - 2][x] = 0;
							MapDataArr[y - 1][x] = 0;
							MapDataArr[y + 1][x] = 0;
							MapDataArr[y + 2][x] = 0;

							MapDataArr[y][x - 2] = 0;
							MapDataArr[y][x - 1] = 0;
							MapDataArr[y][x + 1] = 0;
							MapDataArr[y][x + 2] = 0;
						}
						if (MapDataArr[y][x] != 0)
						{
							MapDataArr[y][x]++;
						}
					}
				}
			}
		}

		// 화면 출력
		for (short y = 0; y < ScreenYSize; y++)
		{
			for (short x = 0; x < ScreenXSize; x++)
			{
				if (x == PlayerX && y == PlayerY)
				{
					printf_s("●");
				}
				else {
					switch (MapDataArr[y][x])
					{
					case EmptySpaceIconNum:
						printf_s("  ");
						break;

					case WallIconNum:
						printf_s("■");
						break;

					case InstalledWallIconNum:
						printf_s("▣");
						break;

					case BombIconNum:
						printf_s("δ");
						break;

					default:
						printf_s("★");
						break;
					}
				}
			}
			printf_s("\n");
		}

		// 실시간 폭탄 개수 카운트
		BombNumCount = 0;
		for (short i = 0; i < MaxBombNum; i++)
		{
			if (BombTimerArr[i] > 0)
			{
				BombNumCount++;
			}
		}

		// 폭탄 시간 출력 화면
		if (Window == 1)
		{
			// 폭탄시간 배열 출력
			for (short i = 0; i < MaxBombNum; i++)
			{
				printf_s("%2d ", BombTimerArr[i]);
			}
			printf_s("\n설치된 폭탄 수 : %d", BombNumCount);
		}
		
		// 키를 누르지 않을 때 작업
		if (0 == _kbhit())
		{
			Sleep(ScreenFrame);

			// 키 입력 없을 시 폭탄 시간 감소
			BombTimeCounting(BombTimerArr, MaxBombNum);

			continue;
		}

		char Ch = _getch();

		// 키 입력 중 폭탄 시간 감소
		BombTimeCounting(BombTimerArr, MaxBombNum);

		// 키 입력
		switch (Ch)
		{
		case 'w':
		case 'W':
			if (MapDataArr[PlayerY - 1][PlayerX] == 1 || MapDataArr[PlayerY - 1][PlayerX] == 2)
			{
				break;
			}
			else
			{
				--PlayerY;
			}
			break;

		case 's':
		case 'S':
			if (MapDataArr[PlayerY + 1][PlayerX] == 1 || MapDataArr[PlayerY + 1][PlayerX] == 2)
			{
				break;
			}
			else
			{
				++PlayerY;
			}
			break;

		case 'a':
		case 'A':
			if (MapDataArr[PlayerY][PlayerX - 1] == 1 || MapDataArr[PlayerY][PlayerX - 1] == 2)
			{
				break;
			}
			else
			{
				--PlayerX;
			}
			break;

		case 'd':
		case 'D':
			if (MapDataArr[PlayerY][PlayerX + 1] == 1 || MapDataArr[PlayerY][PlayerX + 1] == 2)
			{
				break;
			}
			else
			{
				++PlayerX;
			}
			break;

		// 장애물 설치
		case 'g':  
		case 'G':
			if (MapDataArr[PlayerY][PlayerX] != 0)
			{
				break;
			}
			MapDataArr[PlayerY][PlayerX] = 2;
			break;

		// 폭탄
		case 'f':
		case 'F':

			// 폭탄은 빈 공간일 경우에만 설치 가능하다.
			// 폭탄의 최대 설치 수 제한
			if(MapDataArr[PlayerY][PlayerX] != 0 || BombNumCount == MaxBombNum)
			{
				break;
			}
			
			MapDataArr[PlayerY][PlayerX] = BombIconNum;


			// 위치 저장
			
			for (short i = 0; i < MaxBombNum; i++)
			{
				if (BombTimerArr[i] == 0)
				{
					BombLocationArr[PlayerY][PlayerX] = i;
					BombTimerArr[i] = TimeOfBomb;
					break;
				}
			}

			break;
		case 'm':
		case 'M':
			if (Window == 0)
			{
				Window++;
			}
			else {
				Window--;
			}
			
		default:
			break;
		}

		Sleep(ScreenFrame);
	}
}
