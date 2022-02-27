#include "stdafx.h"
#include "Timer.h"
#include <crtdbg.h>
#include "Config.h"
#include "CommonFunction.h"
#include "MainGame.h"

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#define _CRTDBG_MAP_ALLOC


// ��������
HINSTANCE	g_hInstance;
HWND		g_hWnd;
LPSTR		g_lpszClass = (LPSTR)TEXT("Pokemon_Gold");
MainGame	g_mainGame;

POINT		g_maxSize;




LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance,
	LPSTR _lpszCmdParam, int nCmdShow)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(1465);
	//_CrtSetBreakAlloc(185);
	_CrtMemDumpAllObjectsSince(0);
	_CrtDumpMemoryLeaks();

#endif

	// �����츦 �����ϱ� ���� �⺻ ����
	g_hInstance = _hInstance;
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // �ڵ�����ȯ
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = _hInstance;
	wndClass.lpfnWndProc = WndProc;				// �Լ�������(�ݹ��Լ�)
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = g_lpszClass;
	wndClass.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;	// bit����

	// ������ Ŭ���� ���
	RegisterClass(&wndClass);


	// ������ ����
	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass, WS_OVERLAPPEDWINDOW,
		WIN_START_POS_X, WIN_START_POS_Y, g_maxSize.x, g_maxSize.y,
		NULL, NULL, _hInstance, NULL);


	// ���ΰ��� �ʱ�ȭ
	g_mainGame.Init();


	// ������ ���
	ShowWindow(g_hWnd, nCmdShow);

	// �޽��� ť�� �ִ� �޽��� ó��

	MSG msg;

	while (TRUE)
	{
		if (PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (Timer::CanUpdate())
			{
				Input::Update();
				g_mainGame.Update();
				HDC hdc = GetDC(g_hWnd);
				g_mainGame.Render(hdc);
			}
		}
	}

	// ���ΰ��� ����
	g_mainGame.Release();

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	
	switch (iMessage)
	{
	case WM_DESTROY:	// �ݱ� ��ư �޽���ó�� (���α׷� ����)
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
