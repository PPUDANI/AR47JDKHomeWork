// WindowTestProject.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowTestProject.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING] = L"Window_Test";            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 윈도우가 내 프로그램의 부여된 번호
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance); // 참조안했다는 경고 없애려는 잔꾀
    UNREFERENCED_PARAMETER(lpCmdLine); // 참조안했다는 경고 없애려는 잔꾀

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    // szTitle: 프로젝트 이름
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); // 윈도우창 위에 프로젝트 이름 출력
    LoadStringW(hInstance, IDC_WINDOWTESTPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 단축키를 사용하기위한 핸들
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWTESTPROJECT));

    MSG msg;

    // 기본 메시지 루프입니다:
    // 윈도우가 켜지있는 동안 계속 프로그램이 켜져있게 만들려고 while문으로 막은 것이다.
    // GetMessage는 윈도우에 무슨 일이 생길 때만 리턴되는 함수이다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // 단축키를 누른 메세지인지 체크하는것
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    // 크기 바꾸면 다시 그리는 설정
    wcex.style          = CS_HREDRAW | CS_VREDRAW;

    // 윈도우에서 무슨일이 생기면 너대신 그 행동을 해줄게
    wcex.lpfnWndProc    = WndProc; // 함수포인터 (UI에서 자주 사용되는것이 함수포인터, 콘솔에서 _getch()와 비슷한 느낌)

    // 기본설정(잘은 모름)
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;

    // 이 윈도우 클래스를 등록하려는 프로그램이 누구인지 설정 (※ 중요 ※)
    wcex.hInstance      = hInstance;

    // 윈도우 기본 아이콘
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWTESTPROJECT));

    // 마우스 커서를 정한다 (기본 마우스 커서 디자인을 쓰는 게임은 없다.)
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); // ex) IDC_ARROW : 화살표, IDC_CROSS : 십자 , etc.

    // 윈도우 색깔 (게임 배경으로 덮을거기 때문에 의미가 없다.)
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);

    //윈도우창 맨 위 작업표시줄
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWTESTPROJECT);

    // 윈도우를 만들 때 선택할 수 있는 윈도우 형식 등록 (※ 중요 ※)
    // 현재 형식 이름은 "Window_Test"
    // 이유 -> 12LINE 전역변수 : szWindowClass = L"Window_Test"
    wcex.lpszClassName  = szWindowClass;

    // 
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    // 윈도우 형식을 최종적으로 등록하는 함수
    // 메뉴를 사용하지 않아.
    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   // 윈도우를 만드는 함수
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   HWND hWnd1 = CreateWindowW(
       szWindowClass,  // "WindowTest" 형식으로 윈도우를 만든다.
       L"가나다abc123", // 타이틀 이름
       WS_OVERLAPPEDWINDOW, // 윈도우 스타일
       CW_USEDEFAULT, // 시작점 위치 X
       0, // 시작점 위치 Y
       CW_USEDEFAULT, // 크기 X
       0,  // 크기 Y
       nullptr, // 몰라요
       nullptr, // 몰라요 
       hInstance, // 윈도우 제작을 누가 요청했는가(보안)
       nullptr);

   if (!hWnd || !hWnd1)
   {
      return FALSE;
   }

   // API 구조는 개발자가 따로 기능을 만드는것이 아닌 Window가 개발자가 원하는 핸들을 제공하여
   // 그 핸들을 용도에 맞게 사용는 것이다.

   // 윈도우 출력
   ShowWindow(hWnd, nCmdShow);
   ShowWindow(hWnd1, nCmdShow);

   // 윈도우 갱신
   UpdateWindow(hWnd);
   UpdateWindow(hWnd1);
   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

// CALLBACK(__stdcall) : 함수가 끝아면  stack영역에서 메모리를 지워주는 것.
// __cdecl : 일반적인 전역함수를 만들면 암묵적 변환이 됨.
// __stdcall : 윈도유 함수에서 많이 사용함.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // message : 윈도우에서 벌어진 일의 종류 (윈도우가 선택됬다, 윈도우 크기가 바뀌었다 등등)
    // wParam, lParam 윈도우 크기
    // hWnd: 윈도우를 

    // 윈도우의 여러 메세지를 처리한다.
    switch (message)
    {
    case WM_CREATE: // 윈도우가 생성될 때
    {
        int a = 0;
        break;
    }
    case WM_SETFOCUS: // 윈도우가 생성될 때
    {
        int a = 0;
        break;
    }
    case WM_KILLFOCUS: // 윈도우가 생성될 때
    {
        int a = 0;
        break;
    }
    case WM_COMMAND: // 커맨드가 들어올 때
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                // 커맨드가 너무 많기 때문이 이외의 메세지는 기본적인 방식으로 처리하는것이 아래코드.
                // 안해놓으면 위험함
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT: // 화면에 그릴 때
        {
            PAINTSTRUCT ps;

            // 윈도우 화면에 무언가를 그리기 위한 권한.
            HDC hdc = BeginPaint(hWnd, &ps);

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            Rectangle(hdc, 100, 100, 10, 10);


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY: // 윈도우 파괴할 때
        PostQuitMessage(0); // GetMessage() 함수에서 0을 리턴하게 만든다.
        break;
    default:
        // 메세지가 너무 많기 때문이 이외의 메세지는 기본적인 방식으로 처리하는것이 아래코드
        // 안해놓으면 위험함
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
