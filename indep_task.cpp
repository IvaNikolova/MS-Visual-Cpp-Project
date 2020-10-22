// indep_task.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "indep_task.h"
#include "commctrl.h"
#include <string>
#include <iostream>
//#include "DialogEditors.h"
#include "CommDlg.h"
using namespace std;
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Dialog(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Timer(HWND, UINT, WPARAM, LPARAM);


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_INDEP_TASK, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_INDEP_TASK));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_INDEP_TASK));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_INDEP_TASK);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//

int x=0;
int y=0;
HPEN g_hPen = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDM_A1_A1:
            MessageBox(hWnd, _T("I am A1_A1"), _T("A1_A1"), MB_OK | MB_ICONINFORMATION);
            break;
		case IDM_A2_A2:
            MessageBox(hWnd, _T("I am A2_A2"), _T("A2_A2"), MB_OK | MB_ICONINFORMATION);
            break;
/*			int MessageBox(hDlg, "Message","Title of box", Buttons| Standard Windows)
			-Buttons : {MB_OK, MB_OKCANCEL, MB_YESNO, MB_YESNOCANCEL, MB_RETRYCANCEL, MB_ICONEXCLAMATION }
			-Standard Windows: { MB_ICONERROR,MB_ICONSTOP, MB_ICONINFORMATION, MB_ICONQUESTION }
			for example - MessageBox(hDlg,"Message Box","MSG",MB_YESNOCANCEL | MB_ICONERROR ));
			MessageBox(hDlg,"No","MSG",MB_OK);
			int x; x = MessageBox(hDlg, "Liub4oslav","Popivanoslav", MB_YESNOCANCEL | MB_ICONQUESTION );   */
		case IDM_A3_A1:
		{
					HMENU hMenu = GetMenu(hWnd);
					std::string myString = "A3";
					LPSTR a3 = new char[myString.size() + 1];
					copy(myString.begin(), myString.end(), a3);
					a3[myString.size()] = 0;

					if (GetMenuState(hMenu,IDM_A3_A4 + 4, MF_BYCOMMAND) == -1)
					{
						MENUITEMINFO mii;
						ZeroMemory(&mii, sizeof(mii));
						mii.cbSize = sizeof(mii);
						mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;
						mii.wID = IDM_A3_A4 + 4;
						mii.fType = MFT_STRING;
						mii.dwTypeData = a3;
						mii.fState = MFS_ENABLED;

						InsertMenuItem(hMenu, IDM_A3_A4, FALSE, &mii);
					}
            }
            break;
		case IDM_A3_A2:
		{
			HMENU hMenu = GetMenu(hWnd);
			UINT res = GetMenuState(hMenu, IDM_A3_A1, MF_BYCOMMAND);
			if(res & MF_CHECKED)
			CheckMenuItem(hMenu, IDM_A3_A1, MF_BYCOMMAND | MF_UNCHECKED);
			else
			CheckMenuItem(hMenu, IDM_A3_A1, MF_BYCOMMAND | MF_CHECKED);
			}
			break;
		case ID_CONTEXMENU_A4:
			MessageBox(hWnd, _T("I am A4 - Contex menu"), _T("ContexMenu_A4"), MB_OK | MB_ICONINFORMATION);
			break;
		case IDM_DIALOG_DIALOG:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dialog);
            break;
		case IDM_TIMER_TIMER:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Timer);
			break;
		case IDM_COLOR:
			{
			// DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			CHOOSECOLOR color;
			COLORREF init =RGB(234,16,239);
			static COLORREF Arr[16]={RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239),RGB(234,16,239)};
			memset (&color,0,sizeof(color));
			color.lStructSize=sizeof(color);
			color.hwndOwner=hWnd;
			color.rgbResult=init;
			color.lpCustColors=Arr;
			color.Flags=CC_SOLIDCOLOR|CC_RGBINIT|CC_FULLOPEN;
			if(ChooseColor(&color)){
				//color.rgbResult;
				//HDC hDC = GetDC(hWnd);
				if(g_hPen)
					DeleteObject(g_hPen);
				g_hPen = CreatePen(PS_SOLID, 2, color.rgbResult);
				//hBrush = CreateSolidBrush(color.rgbResult);
				//SelectObject(hDC,hBrush);
				//Rectangle(hDC,0,0,100,100);
				//ReleaseDC(hWnd,hDC);
			}
		}
		break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam); 
		y = HIWORD(lParam); 
		break;
	case WM_MOUSEMOVE: 
		if (wParam == MK_LBUTTON) {
			hdc = GetDC(hWnd);
			COLORREF color=RGB(0x10,0x10,0xF0);
			//HPEN hPen=CreatePen(PS_SOLID, 5, color);
			SelectObject(hdc, g_hPen);
			MoveToEx (hdc, x, y, NULL); // мести GC до т. X,Y
			x=LOWORD(lParam);
			y=HIWORD(lParam);
			LineTo (hdc, x, y);
		}; 
		break;
	case WM_RBUTTONDOWN:
		{
		HMENU hMenu = LoadMenu(hInst, MAKEINTRESOURCE(IDC_INDEP_TASK));
		HMENU hSubMenu = GetSubMenu(hMenu, 0); 
		POINT pt = {LOWORD(lParam), HIWORD(lParam)}; 
		ClientToScreen(hWnd, &pt); 
		TrackPopupMenu(hSubMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hWnd, NULL);
		DestroyMenu(hMenu); 
		}
		break;
	case WM_PAINT:
		{
		hdc = BeginPaint(hWnd, &ps);
		int l = 200;
		int t = 150;
		int r = 300;
		int b = 300;

	//Rectangle
		RECT rt;
		GetClientRect(hWnd, &rt);
		HBRUSH hBrush3 = CreateSolidBrush(RGB(224, 224, 224)); 
		SelectObject(hdc, hBrush3);
		::Rectangle(hdc,l,t,r,b);
		HBRUSH hBrush = CreateHatchBrush( HS_CROSS, RGB(32, 32, 32));
		SelectObject(hdc, hBrush);
		::Rectangle(hdc,l+20,t+20,r-60,b-90);		//prozorci
		::Rectangle(hdc,l+60,t+20,r-20,b-90);
		HBRUSH hBrush7 = CreateHatchBrush( HS_VERTICAL, RGB(102, 51, 0));
		SelectObject(hdc, hBrush7);
		::Rectangle(hdc,l+40,t+85,r-25,b);		//vrata
		HBRUSH hBrush6 = CreateSolidBrush(RGB(102, 0, 0));  //komin
		SelectObject(hdc, hBrush6);
		::Rectangle(hdc,l+10,t-70,r-80,b-170);

	//Ellipse
		HBRUSH hBrush2 = CreateSolidBrush(RGB(0, 153, 153)); 
		SelectObject(hdc, hBrush2);
		Ellipse(hdc,l+25,t+185,r+100,b+135);	//ezero
		HBRUSH hBrush5 = CreateSolidBrush(RGB(0, 0, 0)); 
		SelectObject(hdc, hBrush5);
		Ellipse(hdc,l+15,t-90,l+25,t-80);   //kylbeta ot dim
		Ellipse(hdc,l+5,t-100,l+15,t-90);

	//Triangle- polygon
		HBRUSH hBrush4 = CreateSolidBrush(RGB(153, 0, 0)); 
		SelectObject(hdc, hBrush4);
		POINT pt[3] = { {l-50,t},{l+50,t-80},{l+150,t}};
		Polygon(hdc,&pt[0],3);		//pokriv
			
	//ograda
		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(153, 76, 0));
		SelectObject(hdc, hPen);
		HBRUSH hBrush8 = CreateSolidBrush(RGB(204, 102, 0)); 
		SelectObject(hdc, hBrush8);
		Rectangle(hdc, l-50, t+90, r-145, b);
		Rectangle(hdc, l-40, t+90, r-135, b);	
		Rectangle(hdc, l-30, t+90, r-125, b);
		Rectangle(hdc, l-20, t+90, r-115, b);
		Rectangle(hdc, l-10, t+90, r-105, b);	
		Rectangle(hdc, l+105, t+90, r+10, b);
		Rectangle(hdc, l+115, t+90, r+20, b);	
		Rectangle(hdc, l+125, t+90, r+30, b);
		Rectangle(hdc, l+135, t+90, r+40, b);	
		Rectangle(hdc, l+145, t+90, r+50, b);
		Rectangle(hdc, l+155, t+90, r+60, b);	
		Rectangle(hdc, l+165, t+90, r+70, b);
		Rectangle(hdc, l+175, t+90, r+80, b);	
		Rectangle(hdc, l+185, t+90, r+90, b);
		Rectangle(hdc, l+195, t+90, r+100, b);	

		Rectangle(hdc, l-50, t+110, r-100, b-37);
		Rectangle(hdc, l-50, t+130, r-100,  b-17);
		Rectangle(hdc, l+100, t+110, r+100,  b-37);
		Rectangle(hdc, l+100, t+130, r+100,  b-17);	

		//DeleteObject(hPen);
		DeleteObject(hBrush);
		DeleteObject(hBrush2);
		DeleteObject(hBrush3);
		DeleteObject(hBrush4);
		DeleteObject(hBrush5);
		DeleteObject(hBrush6);
		DeleteObject(hBrush7);
		DeleteObject(hBrush8);
	
		EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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

void calculate(HWND hDlg){
	int a =0, b=0;
	double res=0, c=0.;
	BOOL bTrans = 0;
	TCHAR chBuffer[64]={0};

	a = GetDlgItemInt(hDlg, IDC_A, &bTrans ,TRUE);
	b = GetDlgItemInt(hDlg, IDC_B, &bTrans ,TRUE);
	

	HWND hList= GetDlgItem(hDlg,IDC_C);
	if(!hList){
		MessageBox(hDlg, _T("Invalid control C"), _T("ERROR"), MB_OK | MB_ICONINFORMATION) ;
		return ;
	}

	int sel = SendMessage(hList, LB_GETCURSEL, 0, 0L); 
	if( LB_ERR == sel ){
		MessageBox(hDlg, _T("Select C"), _T("ERROR"), MB_OK | MB_ICONINFORMATION) ;
		return ;
	}
	SendMessage(hList, LB_GETTEXT, (WPARAM)sel, (LPARAM)chBuffer); 


/*
	sel = SendDlgItemMessage(hDlg, IDC_C, LB_GETCURSEL, 0, 0);
	if(sel != LB_ERR)
	{
		SendDlgItemMessage(hDlg, IDC_C, LB_GETTEXT, sel, (LPARAM)chBuffer);
	}
	*/
	c = atof(chBuffer);
	if( IsDlgButtonChecked(hDlg, IDC_RADIO1) == BST_CHECKED ){
		if (0.0 == c) 
			MessageBox(hDlg, _T("Dividing by zero is undefined"), _T("ERROR"), MB_OK | MB_ICONINFORMATION) ;
		else
			res=(a+b)/c;
	}else
		if( IsDlgButtonChecked(hDlg, IDC_RADIO2) == BST_CHECKED )
			res=(a-b)*c;
		
	sprintf(chBuffer, "%.2f", res);
	SetDlgItemText(hDlg,IDC_RES,chBuffer);

				
	//SetDlgItemInt(hDlg,IDC_RES, res, 20);
}

INT_PTR CALLBACK Dialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	char data[60]={0};
    int c_index=0;
	int mID=LOWORD(wParam);

	UNREFERENCED_PARAMETER(lParam);
	switch (message){
	case WM_INITDIALOG:
		
		SendDlgItemMessage(hDlg, IDC_C, LB_ADDSTRING, 0, (LPARAM)_T("2.4"));
        SendDlgItemMessage(hDlg, IDC_C, LB_ADDSTRING, 0, (LPARAM)_T("10.4"));
		SendDlgItemMessage(hDlg, IDC_C, LB_ADDSTRING, 0, (LPARAM)_T("0.0"));
        return (INT_PTR)TRUE;
		

	 case WM_COMMAND:
        if (mID == IDOK || mID == IDCANCEL){
            EndDialog(hDlg, mID);
            return (INT_PTR)TRUE;
        }
		if( mID == IDC_BUTTON1 )
			calculate(hDlg);
		 


		switch( LOWORD( wParam ) ){
		case IDC_EDIT1:

			c_index = 2;
			switch(HIWORD( wParam )){
			case EN_SETFOCUS:
				c_index = 2;
				break;
			case EN_UPDATE:
				c_index = 1;
				break;
			}

		case IDC_COMBO:
			switch(HIWORD( wParam )){
			case CBN_SELCHANGE:
				int pos  = SendDlgItemMessage(hDlg, IDC_COMBO, CB_GETCURSEL, 0, 0);
				SendDlgItemMessage(hDlg, IDC_COMBO, CB_GETLBTEXT, pos, (LPARAM)data);
				SetDlgItemText(hDlg, IDC_EDIT1, data);
				break;
			}
		}

		if( mID == IDC_INSERT ){
			//combo box
			GetDlgItemText(hDlg,IDC_EDIT1,data,59);

			int pos = SendDlgItemMessage(hDlg, IDC_COMBO, CB_ADDSTRING, 0, (LPARAM)data);
			SendDlgItemMessage(hDlg, IDC_COMBO, CB_SETCURSEL, pos, 0);
			//int pos = SendDlgItemMessage(hDlg, IDC_COMBO, CB_ADDSTRING, 0, (LPARAM)data);
			int tt = 0;
			SetDlgItemText(hDlg, IDC_EDIT1, 0);

		}
			
        break;
	}
	return (INT_PTR)FALSE;
}
#define TIMER1 500
#define TIMER2 500

INT_PTR CALLBACK Timer(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int r, step=20;
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETRANGE, 0, MAKELPARAM(0, 1000)); 
        SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, 0, 0);
        SendDlgItemMessage(hDlg, IDC_PROGRESS2, PBM_SETRANGE, 0, MAKELPARAM(0, 1000));
        SendDlgItemMessage(hDlg, IDC_PROGRESS2, PBM_DELTAPOS, 0, 0);
        return (INT_PTR)TRUE;

    case WM_COMMAND:{
			if (LOWORD(wParam) == IDOK) {
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			
			if (LOWORD(wParam) == IDC_START) {
				SetTimer(hDlg, TIMER1, 20, NULL);
				break;
			}
			if (LOWORD(wParam) == IDC_STOP) {
				//PostQuitMessage(0); 
				EndDialog(hDlg,  LOWORD(wParam));
				break;
			}
			if (LOWORD(wParam) == IDC_PAUSE) {
				KillTimer(hDlg, TIMER1);
				break;
			}
			break;
		}		


    case WM_TIMER:
        if (SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0) >= 999)
        {
            if (SendDlgItemMessage(hDlg, IDC_PROGRESS2, PBM_GETPOS, 0, 0) <= 999)
            {
                SendDlgItemMessage(hDlg, IDC_PROGRESS2, PBM_SETSTEP, step, 0);
                SendDlgItemMessage(hDlg, IDC_PROGRESS2, PBM_STEPIT, 0, 0);
            }
            SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, 1000, 0);
            SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, 0, 0);
            break;
        }
        SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETSTEP, step, 0);
        SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
    }
    return (INT_PTR)FALSE;
}
