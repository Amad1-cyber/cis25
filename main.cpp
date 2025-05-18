#include <windows.h>
#include <string>
#include <sstream>

#define TIMER_ID 1
#define TIMER_INTERVAL 16 // ~60 FPS

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

const int BLOCK_SIZE = 50;
const int GROUND_Y = 500;
const float GRAVITY = 0.5f;
const float JUMP_FORCE = -12.0f;

int score = 0;
float posY = GROUND_Y;
float velocityY = 0.0f;
bool onGround = true;

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void DrawScene(HDC hdc) {
    // Background
    HBRUSH bgBrush = CreateSolidBrush(RGB(20, 20, 20));
    RECT bg = { 0,0,WIN_WIDTH,WIN_HEIGHT };
    FillRect(hdc, &bg, bgBrush);
    DeleteObject(bgBrush);

    // Block
    HBRUSH blockBrush = CreateSolidBrush(RGB(0, 120, 255));
    RECT blockRect = {
        WIN_WIDTH / 2 - BLOCK_SIZE / 2,
        (int)posY,
        WIN_WIDTH / 2 + BLOCK_SIZE / 2,
        (int)posY + BLOCK_SIZE
    };
    FillRect(hdc, &blockRect, blockBrush);
    DeleteObject(blockBrush);
}

void Update(HWND hwnd) {
    velocityY += GRAVITY;
    posY += velocityY;

    if (posY >= GROUND_Y) {
        if (!onGround) {
            score++;
            onGround = true;
        }
        posY = GROUND_Y;
        velocityY = 0;
    }

    std::wstringstream ss;
    ss << L"Jump Block Game | Score: " << score;
    SetWindowText(hwnd, ss.str().c_str());
    InvalidateRect(hwnd, NULL, FALSE);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    hInst = hInstance;
    const wchar_t CLASS_NAME[] = L"JumpBlockWindow";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"Jump Block Game", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, WIN_WIDTH, WIN_HEIGHT,
        NULL, NULL, hInstance, NULL);

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    SetTimer(hwnd, TIMER_ID, TIMER_INTERVAL, NULL);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_TIMER:
        if (wParam == TIMER_ID)
            Update(hwnd);
        break;

    case WM_KEYDOWN:
        if (wParam == VK_SPACE && onGround) {
            velocityY = JUMP_FORCE;
            onGround = false;
        }
        break;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        DrawScene(hdc);
        EndPaint(hwnd, &ps);
        break;
    }

    case WM_DESTROY:
        KillTimer(hwnd, TIMER_ID);
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
