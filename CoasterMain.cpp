/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#include "NEWFF7/ff7.h"
#include "NEWFF7/loadmenu.h"

#include <assert.h>
////////////////////////////////////////
const char D_007B6658[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Graphics";
const char D_007B6698[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Sound";
const char D_007B66D0[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Midi";
const char D_007B6708[] = "DD_GUID";
const char D_007B6710[] = "MIDI_DeviceID";
const char D_007B6720[] = "Sound_GUID";
////////////////////////////////////////
int MAIN_inputMask_prev = 0;
int MAIN_inputMask = 0;
int MAIN_triggerMask = 0;
int MAIN_inputMask2 = 0;
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
//currently inserted CD #?
int C_00404A7D() {
	//TODO
	return 1;
}
////////////////////////////////////////
//main:open main archives?
int C_004082BF() {
	struct {
		int local_129;
		char local_128[256];
		char local_64[256];
	} lolo;

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
		int local_132;
		//...
		int local_130;
		//...
		char local_129[256];
		//...
		char local_64[256];
	}lolo;

	//TODO
	if(C_0067806E(bp08)) {//graphic driver:START?
		//-- init sound system --
		if(D_009A06A0) {
			if(C_00744400(D_009A06A8, D_009A06A4, bp08->f_05c) == 0) {//sound_init?
				D_00CBF9DC = 0x13;
				return 0;
			}
			C_00745CF3(0x2b, 0);//sound:load/prepare SFX?
		}
		//-- init midi system --
		if(D_009A06B0)
			C_00741780(D_009A06AC, bp08->f_05c);//MIDI:init
		//...
		//-- --
		if(C_004082BF() == 0)//main:open main archives?
			return 0;
		//-- --
		//...
		lolo.local_132 = CoInitialize(0);
		if(lolo.local_132 < 0)
			C_00414EE0("Failed to initialize COM (0x%8.8X)\n", lolo.local_132);//movie related debug printf?<empty>
#if 0
	//---------
	//-- gil --
	//---------
	D_00DC08B4 = 9999999;
#endif
	}

	return 1;
}

//MainDispatcher[MAIN_CLEAN][callback]
void C_00408EDC(struct t_aa0 *bp08) {
	//TODO
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
#if 1
	if(uMsg == WM_KEYDOWN && (HIWORD(lParam) & KF_REPEAT)) {
		return;
	}
	int mask = 0;
	int mask2 = 0;
	switch(wParam) {
		case VK_NUMPAD7: mask = 0x0001; break;
		case VK_NUMPAD1: mask = 0x0002; break;
		case VK_NUMPAD9: mask = 0x0004; break;
		case VK_NUMPAD3: mask = 0x0008; break;
		case VK_ADD: mask = 0x0010; break;
		case VK_RETURN: mask = 0x0020; break;
		case VK_NUMPAD0: mask = 0x0040; break;
		case VK_DECIMAL: mask = 0x0080; break;
		case VK_SUBTRACT: mask = 0x0100; break;
		case VK_NUMPAD5: mask = 0x0800; break;
		case VK_NUMPAD8: mask = 0x1000; break;
		case VK_NUMPAD6: mask = 0x2000; break;
		case VK_NUMPAD2: mask = 0x4000; break;
		case VK_NUMPAD4: mask = 0x8000; break;
		//-- --
		case 'A': mask2 = 0x0001; break;
		case 'B': mask2 = 0x0002; break;
		case 'C': mask2 = 0x0004; break;
		case 'D': mask2 = 0x0008; break;
		case 'E': mask2 = 0x0010; break;
		case 'F': mask2 = 0x0020; break;
		case 'G': mask2 = 0x0040; break;
		case 'H': mask2 = 0x0080; break;
		case 'I': mask2 = 0x0100; break;
		case 'J': mask2 = 0x0200; break;
		case 'K': mask2 = 0x0400; break;
		case 'L': mask2 = 0x0800; break;
		case VK_UP: mask2 = 0x1000; break;
		case VK_RIGHT: mask2 = 0x2000; break;
		case VK_DOWN: mask2 = 0x4000; break;
		case VK_LEFT: mask2 = 0x8000; break;

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
#endif
	C_005E910D(uMsg, wParam, lParam, bp14);//coaster[ONKEY][callback]
}

void C_006C0E2D(struct t_aa0 *);//on "Exit box"?[callback]

//main:some base init/config?
void C_0040A091(int unused1, int unused2) {
	struct {
		STARTUPINFO local_104;
		DWORD local_87;
		PROCESS_INFORMATION local_86;
		char local_82[256];
		HKEY hKey;//local_18
		DWORD local_17;
		MEMORYSTATUS local_16;
		DWORD dwType;//local_8
		int is_ok;//local_7
		struct t_aa0 *local_6;
		DWORD cbData;//local_5
		char local_4[16];
	} lolo;

	lolo.is_ok = 1;
	C_006602C1(D_009A06D0);//mem:set debug on/off?
	C_00406D10();//initpath:start?
	//-- we need 50000000 bytes --
	GlobalMemoryStatus(&lolo.local_16);
	if(lolo.local_16.dwAvailPageFile < 50000000L) {
		MessageBox(0, "There is insufficient swap space to play FF7.", "No Swap Space", MB_ICONHAND/*0x10*/);
		C_004073F7();//initpath:clean?
		D_00CBF9DC = 0x13;
	}
	//-- check Graphics."DD_GUID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6658, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {//else 0040A148
		lolo.cbData = 0x10;
		if(RegQueryValueEx(lolo.hKey, D_007B6708, 0, &lolo.dwType, (LPBYTE)lolo.local_4, &lolo.cbData) == 0 && lolo.cbData == 0)
			lolo.is_ok = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.is_ok = 0;
	}
	//-- check Midi."MIDI_DeviceID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B66D0, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {
		lolo.cbData = 4;
		if(RegQueryValueEx(lolo.hKey, D_007B6710, 0, &lolo.dwType, (LPBYTE)&lolo.local_17, &lolo.cbData) == 0 && lolo.local_17 == -1)
			lolo.is_ok = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.is_ok = 0;
	}
	//-- check Sound."Sound_GUID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6698, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {
		lolo.cbData = 0x10;
		if(RegQueryValueEx(lolo.hKey, D_007B6720, 0, &lolo.dwType, (LPBYTE)lolo.local_4, &lolo.cbData) == 0 && lolo.cbData == 0)
			lolo.is_ok = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.is_ok = 0;
	}
	//--        if error       --
	//-- lanch "ff7config.exe" --
	if(lolo.is_ok == 0) {//else 0040A34E
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
			D_00CBF9DC = 0x13;
	}
	//-- --
	if(C_00404A7D() == 0) {//currently inserted CD #?
		MessageBox(0, "Please insert FF7 Game Disc 1, 2, or 3 and try again.", "Insert Game Disc", MB_ICONHAND/*0x10*/);
		C_004073F7();//initpath:clean?
		D_00CBF9DC = 0x13;
	}
	//-- --
	lolo.local_6 = C_00676E7E();//directx:init some game object?
	if(lolo.local_6) {//else 0040A459
		lolo.local_6->f_99c = 90.0f;
		lolo.local_6->f_9a0 = 125.0f;
		lolo.local_6->f_9a4 = 50000.0f;
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

//Refresh input driver?
void C_0041A21E(struct t_aa0 *bp08) {
	//TODO
	int diff = MAIN_inputMask_prev ^ MAIN_inputMask;
	MAIN_triggerMask = MAIN_inputMask & diff;
	MAIN_inputMask_prev = MAIN_inputMask;
}

//test input mask[pressed]?
unsigned int C_0041AB67(unsigned bp08) {
	//TODO
	return MAIN_inputMask & bp08;
}

//movie related debug printf?<empty>
int C_00414EE0(const char *format, ...) {
	return 0;
}

//on "Exit box"?[callback]
void C_006C0E2D(struct t_aa0 *) {
	//TODO
}

//set SFX&MIDI volumes[menu related]?
void C_006C4946(int,int) {}


