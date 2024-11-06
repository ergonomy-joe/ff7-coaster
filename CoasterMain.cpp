/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#include "NEWFF7/ff7.h"
#include "NEWFF7/loadmenu.h"

#include <assert.h>
////////////////////////////////////////
//#define KEYINPUT_ASYNC
#ifndef KEYINPUT_ASYNC
int MAIN_inputMask_prev = 0;
int MAIN_inputMask = 0;
int MAIN_triggerMask = 0;
int MAIN_inputMask2 = 0;//for some cheat mode in chocobo
#endif
////////////////////////////////////////
const char D_007B6658[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Graphics";
const char D_007B6698[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Sound";
const char D_007B66D0[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Midi";
const char D_007B6708[] = "DD_GUID";
const char D_007B6710[] = "MIDI_DeviceID";
const char D_007B6720[] = "Sound_GUID";
////////////////////////////////////////
#ifndef KEYINPUT_ASYNC
void patch_RefreshInput(int uMsg, int wParam, int lParam) {
	if(uMsg == WM_KEYDOWN && (HIWORD(lParam) & KF_REPEAT)) {
		return;
	}
	int mask = 0;
	int mask2 = 0;
	switch(wParam) {
		case VK_NUMPAD7: mask = PAD_00; break;
		case VK_NUMPAD1: mask = PAD_01; break;
		case VK_NUMPAD9: mask = PAD_02; break;
		case VK_NUMPAD3: mask = PAD_03; break;
		case VK_ADD: mask = PAD_04; break;
		case VK_RETURN: mask = PAD_05; break;
		case VK_NUMPAD0: mask = PAD_06; break;
		case VK_DECIMAL: mask = PAD_07; break;
		case VK_SUBTRACT: mask = PAD_08; break;
		case VK_NUMPAD5: mask = PAD_11; break;
		case VK_NUMPAD8: mask = PAD_UP; break;
		case VK_NUMPAD6: mask = PAD_RIGHT; break;
		case VK_NUMPAD2: mask = PAD_DOWN; break;
		case VK_NUMPAD4: mask = PAD_LEFT; break;
		//-- --
		case 'A': mask2 = PAD_00; break;
		case 'B': mask2 = PAD_01; break;
		case 'C': mask2 = PAD_02; break;
		case 'D': mask2 = PAD_03; break;
		case 'E': mask2 = PAD_04; break;
		case 'F': mask2 = PAD_05; break;
		case 'G': mask2 = PAD_06; break;
		case 'H': mask2 = PAD_07; break;
		case 'I': mask2 = PAD_08; break;
		case 'J': mask2 = PAD_09; break;
		case 'K': mask2 = PAD_10; break;
		case 'L': mask2 = PAD_11; break;
		case VK_UP: mask2 = PAD_UP; break;
		case VK_RIGHT: mask2 = PAD_RIGHT; break;
		case VK_DOWN: mask2 = PAD_DOWN; break;
		case VK_LEFT: mask2 = PAD_LEFT; break;

		//default:
	}
	if(mask) {
		switch(uMsg) {
			case WM_KEYDOWN: MAIN_inputMask |= mask; break;
			case WM_KEYUP: MAIN_inputMask &= ~mask; break;
			case WM_CHAR: break;
			default:
				assert(0);
		}
	}
	if(mask2) {
		switch(uMsg) {
			case WM_KEYDOWN: MAIN_inputMask2 |= mask2; break;
			case WM_KEYUP: MAIN_inputMask2 &= ~mask2; break;
			case WM_CHAR: break;
			default:
				assert(0);
		}
	}
}
#endif
////////////////////////////////////////
void patch_setGil(unsigned dwGil) {
	D_00DBFD38.dwGIL = dwGil;
}
////////////////////////////////////////
int D_009A06D0;//debug memory flag[ON/OFF]?

short D_00CBF9DC;
short D_00CC0D84;
struct t_loadmenu_10f4 D_00DBFD38;
////////////////////////////////////////
//====---- coaster ----====
extern void C_005E8E7E(struct t_aa0 *);//coaster[UPDATE][callback]
extern void C_005E9108(int, int, int, struct t_aa0 *);//coaster[ONMOUSE][callback]
extern void C_005E910D(int, int, int, struct t_aa0 *);//coaster[ONKEY][callback]
extern void C_005E8D49(struct t_aa0 *);//coaster[BEGIN][callback]
extern void C_005E8DD8(struct t_aa0 *);//coaster[END][callback]
////////////////////////////////////////
extern void C_006C0E2D(struct t_aa0 *);//on "Exit box"?[callback]
////////////////////////////////////////
//currently inserted CD #?
int C_00404A7D() {
	//TODO
	return 1;
}
////////////////////////////////////////
//from main.cpp
////////////////////////////////////////
//main:open main archives?
int C_004082BF() {
	struct {
		int local_129;
		char local_128[256];
		char local_64[256];
	} lolo;

	lolo.local_129 = 0;
	//...
	lolo.local_129 = 1;

	return lolo.local_129;
}

//MainDispatcher[MAIN_INIT][callback]
int C_004089C5(struct t_aa0 *bp08) {
	struct {
		char bp_42c[256];
		char bp_32c[256];
		//
		HRESULT hResult;//local_132
		//...
		int local_130;
		char local_129[256];
		//...
		char local_64[256];
	}lolo;

	//...
	lolo.local_130 = 0;
	if(C_0067806E(bp08)) {//graphic driver:START?
		lolo.hResult = 0;
		//...
		PAD_init(bp08);//start input driver?
		//...
		PAD_setRepeatParams(200, 50);
		//-- init sound system --
		if(D_009A06A0) {
			if(C_00744400(D_009A06A8, D_009A06A4, bp08->hWnd) == 0) {//sound:init?
				D_00CBF9DC = MAIN_STATE_13;
				return 0;
			}
			sound_load(0x02b, 0);
		}
		//-- init midi system --
		if(D_009A06B0)
			C_00741780(D_009A06AC, bp08->hWnd);//MIDI:init
		//...
		//-- --
		if(C_004082BF() == 0)//main:open main archives?
			return 0;
		//-- --
		//...
		lolo.hResult = CoInitialize(0);
		if(FAILED(lolo.hResult))
			C_00414EE0("Failed to initialize COM (0x%8.8X)\n", lolo.hResult);//movie related debug printf?<empty>
		//...
		C_004075B0();//initpath:get music&sfx volume?
		//...
		//patch_setGil(9999999);
	}
#if 1
	bp08->f_834 = 1;//log to console only
#endif

	return 1;
}

//MainDispatcher[MAIN_CLEAN][callback]
void C_00408EDC(struct t_aa0 *bp08) {
	//...
	C_004073F7();//initpath:clean?
	C_00676064();//is_lib:clean?
	//-- clean sound system --
	if(D_009A06A0) {
		sound_unload(0x02b, 0xf);
		C_007446D7();//sound:sound_clean?
	}
	//-- clean midi system --
	if(D_009A06B0)
		C_00741F5F();//midi1:reset midi?
	//-- --
	PAD_clean();//Stop input driver?
	//...
	C_00679864(bp08);//directx:graphic driver:STOP?
	//...
	CoUninitialize();
	//...
	if(D_009A06D0) {
		C_006602EC();//mem:USAGE(2)?
		C_006602D9();//mem:USAGE(1)?
	}
}

//MainDispatcher[BEGIN][callback]
void C_00408FA6(struct t_aa0 *bp08) {
	//TODO
	C_005E8D49(bp08);//coaster[BEGIN][callback]
}

//MainDispatcher[END][callback]
void C_004090C7(struct t_aa0 *bp08) {
	//TODO
	C_005E8DD8(bp08);//coaster[END][callback]
}

//MainDispatcher[UPDATE][callback]
void C_004090E6(struct t_aa0 *bp08) {
	//TODO
	C_005E8E7E(bp08);//coaster[UPDATE][callback]
}

//on WM_ACTIVATE[callback]
void C_00409CF2(int wParam/*bp08*/, struct t_aa0 *bp0c) {
	//TODO
}

//on WM_DEVICECHANGE[callback]
void C_00409D66(int wParam/*bp08*/, int lParam/*bp0c*/, struct t_aa0 *bp10) {
	//TODO
}

//on <CTRL+Q>?[callback]
int C_00409D7B(struct t_aa0 *bp08) {
	//TODO
	return 1;
}

//MainDispatcher[ONMOUSE][callback]
void C_00409DF1(int uMsg, int wParam, int lParam, struct t_aa0 *bp14) {
	//TODO
	C_005E9108(uMsg, wParam, lParam, bp14);//coaster[ONMOUSE][callback]
}

//MainDispatcher[ONKEY][callback]
void C_00409E39(int uMsg, int wParam, int lParam, struct t_aa0 *bp14) {
	//TODO
#ifndef KEYINPUT_ASYNC
	patch_RefreshInput(uMsg, wParam, lParam);
#endif
	C_005E910D(uMsg, wParam, lParam, bp14);//coaster[ONKEY][callback]
}

//main:some base init/config?
void C_0040A091(int dwUnused1, int dwUnused2) {
	struct {
		STARTUPINFO local_104;
		DWORD local_87;
		PROCESS_INFORMATION local_86;
		char local_82[256];
		HKEY hKey;//local_18
		DWORD local_17;
		MEMORYSTATUS local_16;
		DWORD dwType;//local_8
		int dwSuccess;//local_7
		struct t_aa0 *local_6;
		DWORD cbData;//local_5
		char local_4[16];
	} lolo;

	lolo.dwSuccess = 1;
	C_006602C1(D_009A06D0);//mem:set debug on/off?
	C_00406D10();//initpath:start?
	//-- we need 50000000 bytes --
	GlobalMemoryStatus(&lolo.local_16);
	if(lolo.local_16.dwAvailPageFile < 50000000L) {
		MessageBox(0, "There is insufficient swap space to play FF7.", "No Swap Space", MB_ICONHAND/*0x10*/);
		C_004073F7();//initpath:clean?
		D_00CBF9DC = MAIN_STATE_13;
	}
	//-- check Graphics."DD_GUID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6658, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {//else 0040A148
		lolo.cbData = 0x10;
		if(RegQueryValueEx(lolo.hKey, D_007B6708, 0, &lolo.dwType, (LPBYTE)lolo.local_4, &lolo.cbData) == 0 && lolo.cbData == 0)
			lolo.dwSuccess = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.dwSuccess = 0;
	}
	//-- check Midi."MIDI_DeviceID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B66D0, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {
		lolo.cbData = 4;
		if(RegQueryValueEx(lolo.hKey, D_007B6710, 0, &lolo.dwType, (LPBYTE)&lolo.local_17, &lolo.cbData) == 0 && lolo.local_17 == -1)
			lolo.dwSuccess = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.dwSuccess = 0;
	}
	//-- check Sound."Sound_GUID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6698, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {
		lolo.cbData = 0x10;
		if(RegQueryValueEx(lolo.hKey, D_007B6720, 0, &lolo.dwType, (LPBYTE)lolo.local_4, &lolo.cbData) == 0 && lolo.cbData == 0)
			lolo.dwSuccess = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.dwSuccess = 0;
	}
	//--        if error       --
	//-- lanch "ff7config.exe" --
	if(lolo.dwSuccess == 0) {//else 0040A34E
		lolo.local_104.cb = 0; memset(&(lolo.local_104.lpReserved), 0, sizeof(STARTUPINFO) - 4);//STARTUPINFO local_104 = {0};
		lolo.local_86.hProcess = 0; memset(&(lolo.local_86.hThread), 0, sizeof(PROCESS_INFORMATION) - 4);//PROCESS_INFORMATION local_86 = {0};

		lolo.local_104.cb = sizeof(STARTUPINFO);//0x44
		lolo.local_104.lpReserved = 0;
		lolo.local_104.lpReserved2 = 0;
		lolo.local_104.cbReserved2 = 0;
		lolo.local_104.lpDesktop = 0;
		lolo.local_104.dwFlags = 0;

		strcpy(lolo.local_82, D_009A0698);
		strcat(lolo.local_82, "ff7config.exe");

		CreateProcess(0, lolo.local_82, 0, 0, TRUE, NORMAL_PRIORITY_CLASS/*0x20*/, 0, 0, &lolo.local_104, &lolo.local_86);
		WaitForSingleObject(lolo.local_86.hProcess, -1);
		GetExitCodeProcess(lolo.local_86.hProcess, &lolo.local_87);
		if(lolo.local_87)
			D_00CBF9DC = MAIN_STATE_13;
	}
	//-- --
	if(C_00404A7D() == 0) {//currently inserted CD #?
		MessageBox(0, "Please insert FF7 Game Disc 1, 2, or 3 and try again.", "Insert Game Disc", MB_ICONHAND/*0x10*/);
		C_004073F7();//initpath:clean?
		D_00CBF9DC = MAIN_STATE_13;
	}
	//-- --
	lolo.local_6 = C_00676E7E();//directx:init some game object?
	if(lolo.local_6) {//else 0040A459
		lolo.local_6->fFOV = 90.0f;
		lolo.local_6->fNear = 125.0f;
		lolo.local_6->fFar = 50000.0f;
		C_004069FD(lolo.local_6);//prepare graphic driver?
		//-- set some major callbacks --
		lolo.local_6->f_9f0.f_00 = C_004089C5;//MainDispatcher[MAIN_INIT][callback]
		lolo.local_6->f_9f0.f_10 = C_004090E6;//MainDispatcher[UPDATE][callback]
		lolo.local_6->f_9f0.f_04 = C_00408EDC;//MainDispatcher[MAIN_CLEAN][callback]
		lolo.local_6->f_9f0.f_08 = C_00408FA6;//MainDispatcher[BEGIN][callback]
		lolo.local_6->f_9f0.f_0c = C_004090C7;//MainDispatcher[END][callback]
		lolo.local_6->f_a28 = C_00409CF2;//on WM_ACTIVATE[callback]
		lolo.local_6->f_a2c = C_00409D66;//on WM_DEVICECHANGE[callback]
		lolo.local_6->f_a58 = C_006C0E2D;//on "Exit box"?[callback]
		lolo.local_6->f_a5c = C_00409D7B;//on <CTRL+Q>?[callback]
		lolo.local_6->f_9f0.f_14 = C_00409DF1;//MainDispatcher[ONMOUSE][callback]
		lolo.local_6->f_9f0.f_18 = C_00409E39;//MainDispatcher[ONKEY][callback]
		C_0067656B(lolo.local_6);//directx:set some game object?
	}
}

////////////////////////////////////////
//
////////////////////////////////////////
//movie related debug printf?<empty>
int C_00414EE0(const char *format, ...) {
	return 0;
}

//on "Exit box"?[callback]
void C_006C0E2D(struct t_aa0 *) {
	//TODO
}

//set SFX&MIDI volumes[menu related]?
void C_006C4946(int dwMusicVol, int dwSFXVol) {
	C_0074934A(dwMusicVol);//sound:set MUSIC volume?
	C_00742EDA(dwMusicVol);//"MIDI set master volume"
	C_0074933D(dwSFXVol);//sound:set SFX volume?
}

////////////////////////////////////////
//Mock "Pad library"
//you may implement it with your own code
//if you want
////////////////////////////////////////
/*C_0041A1B0*/void PAD_init(struct t_aa0 *bp08) {
	//TODO
}

/*C_0041A214*/void PAD_clean() {
	//TODO
}

/*C_0041A21E*/void PAD_refresh(struct t_aa0 *bp08) {
	//TODO
	int diff = MAIN_inputMask_prev ^ MAIN_inputMask;
	MAIN_triggerMask = MAIN_inputMask & diff;
	MAIN_inputMask_prev = MAIN_inputMask;
}

//test input mask[pressed]?
/*C_0041AB67*/unsigned PAD_test(unsigned bp08) {
	//TODO
	return MAIN_inputMask & bp08;
}

/*C_0041B0D8*/void PAD_setRepeatParams(int bp08, int bp0c) {
	//TODO
}
