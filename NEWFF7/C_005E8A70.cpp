/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- launcher

#include "ff7.h"
#include "coaster_data.h"
#include "loadmenu.h"
////////////////////////////////////////
int D_0090140C = 1;//must init timestamp

LARGE_INTEGER D_00C3F6E0;
float D_00C3F6E8;//next frame
float D_00C3F6EC;//frame counter
////////////////////////////////////////
//[unused]display debug info
void __005E8A70(int dwX/*bp08*/, int dwY/*bp0c*/, const char *lpText/*bp10*/, struct t_aa0 *bp14) {
	HDC hdc;

	bp14->f_07c[1]->GetDC(&hdc);
	SetBkColor(hdc, RGB(0,0,0));
	SetTextColor(hdc, RGB(255,255,0));
	TextOut(hdc, dwX, dwY, lpText, lstrlen(lpText));
	bp14->f_07c[1]->ReleaseDC(hdc);
}

void C_005E8BDE(struct t_aa0 *);//init viewport[coaster]

//init viewport/projection[coaster]
void C_005E8AEC(struct t_aa0 *bp08) {
	struct {
		D3DMATRIX local_32;
		D3DMATRIX local_16;
	}lolo;

	bp08->f_99c = 45.0f;//field of view
	bp08->f_9a0 = 10.0f;//near
	bp08->f_9a4 = 14300.0f;//far
	bp08->f_9a8 = 0;//x

	C_005E8BDE(bp08);//init viewport[coaster]

	bp08->f_9ac = (float)D_00901480 * 40.0f;//y
	//-- reset world/view matrix --
	C_0066C4F0(&lolo.local_32);//set matrix to identity?
	C_0067CBF1(&lolo.local_32, bp08);//dx_mat:set "struct t_aa0::f_2fc"
	//-- reset view matrix --
	C_0066C4F0(&lolo.local_16);//set matrix to identity?
	C_0067CC6C(&lolo.local_16, bp08);//dx_mat:set view matrix?
	//-- --
	C_0067CCDE(bp08->f_99c, bp08->f_9a0, bp08->f_9a4, bp08->f_9a8, bp08->f_9ac, (float)bp08->f_850, (float)bp08->f_854, bp08);//dx_mat:projection matrix related?
}

//init viewport[coaster]
void C_005E8BDE(struct t_aa0 *bp08) {
	int local_1;

	local_1 = C_00404D80();//Get "Graphics/Mode" Key
	switch(local_1) {
		case 0:
			C_0066067A(0, 0, 320, 240, bp08);//G_DRV_1C:Viewport
			D_0090147C = D_00901480 = 1;
		break;
		case 1:
			C_0066067A(160, 120, 320, 240, bp08);//G_DRV_1C:Viewport
			D_0090147C = D_00901480 = 1;
		break;
		case 2:
			C_0066067A(0, 0, 640, 480, bp08);//G_DRV_1C:Viewport
			D_0090147C = D_00901480 = 2;
		break;
		default:
			C_0066067A(0, 0, 320, 240, bp08);//G_DRV_1C:Viewport
			D_0090147C = D_00901480 = 1;
	}//end switch
	D_00C3F784 = bp08->f_848;
	D_00C3F788 = bp08->f_84c;
	D_00C3F6F8 = D_0090147C * 32;
}

//coaster:clear buffers
void C_005E8D03(float fRed, float fGreen, float fBlue, float fAlpha) {
	struct {
		struct fBGRA local_5;
		struct t_aa0 *local_1;
	}lolo;

	lolo.local_1 = C_00676578();
	lolo.local_5.r = fRed;
	lolo.local_5.g = fGreen;
	lolo.local_5.b = fBlue;
	lolo.local_5.a = fAlpha;
	C_0066075C(&lolo.local_5, lolo.local_1);//G_DRV_20:ClearColor
	C_00660626(lolo.local_1);//G_DRV_18:ClearAll
}

//coaster[BEGIN][callback]
void C_005E8D49(struct t_aa0 *bp08) {
	int i;//local_1

	C_00661966(0);//psx:set LH/RH flag?
	C_005E8AEC(bp08);//init viewport/projection[coaster]
	for(i = 0; i < 0x16; i ++)
		C_00660C3A(i, 0, bp08);//G_DRV_64?
	C_00660C3A(G_DRV_STATE_0F, 1, bp08);//G_DRV_64?
	C_00660C3A(G_DRV_STATE_10, 1, bp08);//G_DRV_64?
	C_00660C3A(G_DRV_STATE_09, 1, bp08);//G_DRV_64?
	C_00660C3A(G_DRV_STATE_03, 1, bp08);//G_DRV_64?
	C_005E98E0();//coaster:begin
}

//coaster[END][callback]
void C_005E8DD8(struct t_aa0 *bp08) {
	C_00660626(bp08);//G_DRV_18:ClearAll
	C_0066059C(bp08);//G_DRV_10:Flip
	C_00660626(bp08);//G_DRV_18:ClearAll
	C_005EA847();//coaster:end
}

//<empty>
void C_005E8E06() {
}

//to mainDispatcher for coaster
void C_005E8E0B(struct t_aa0 *bp08) {
	struct tMainCallbacks local_7;

	//-- save score --
	D_00DC0A3E = D_00C3F74C & 0xff;
	D_00DC0A3F = (D_00C3F74C >> 8) & 0xff;
	//-- --
	D_00CC0D84 = 0x0b;
	D_00CBF9DC = 0x01;

	local_7.f_10 = C_004090E6;//MainDispatcher[UPDATE][callback]
	local_7.f_14 = C_00409DF1;//MainDispatcher[ONMOUSE][callback]
	local_7.f_18 = C_00409E39;//MainDispatcher[ONKEY][callback]
	local_7.f_08 = C_00408FA6;//MainDispatcher[BEGIN][callback]
	local_7.f_0c = C_004090C7;//MainDispatcher[END][callback]
	C_00666CF2(&local_7, bp08);//set main loop callbacks?
}

void C_005E8F9B(struct t_aa0 *);//coaster.next_frame
void C_005E9051(struct t_aa0 *);//coaster.refresh

//coaster[UPDATE][callback]
void C_005E8E7E(struct t_aa0 *bp08) {
	C_005E8D03(0, 0, 0, 1.0f);//coaster:clear buffers
	//%%% check ending condition? %%%
	if(D_00C3F75C * 4  > D_00C3F894 - 0x10 || D_00C3F774 == 1) {//else 005E8ECB
		C_005E988B();//stop music/sfx
		C_005E8E0B(bp08);//to mainDispatcher for coaster

		return;
	}
	//%%% %%%
	C_005E8F9B(bp08);//coaster.next_frame
	PAD_refresh(bp08);
	if(C_00660EC0(0, bp08)) {//G_DRV_88:BeginScene
		C_00666DA3(bp08);//calls "instance:reset"
		C_00666DC0(bp08);//calls "dx_sfx:reset heaps"
		C_00666DDD(bp08);//reset "transparent heap"
		//-- refresh without display --
		while(D_00C3F6EC + 1.0f < D_00C3F6E8) {
			D_009014A8 = 0;
			C_005E9051(bp08);//coaster.refresh
			D_00C3F6EC += 1.0f;
		}//end while
		//-- refresh with display --
		D_009014A8 = 1;
		C_005E9051(bp08);//coaster.refresh
		D_00C3F6EC += 1.0f;
		//-- --
		C_00660EEB(bp08);//G_DRV_8C:EndScene
	}
	C_005E8E06();//<empty>
#if 0
	char text[256];
	sprintf(text, "pos:   %04x:%04x", D_00C3F778 >> 16, D_00C3F778 & 0xffff);
	__005E8A70(8, 10, text, bp08);
	sprintf(text, "speed: %04x:%04x", D_00C3F768 >> 16, D_00C3F768 & 0xffff);
	__005E8A70(8, 28, text, bp08);
#endif
}

//coaster.next_frame
//(coaster, highway and snobo tempo are very close)
void C_005E8F9B(struct t_aa0 *bp08) {
#pragma pack(1)
	struct {
		float local_7;
		double dDelay;//local_6
		LARGE_INTEGER sDiff;//local_4
		LARGE_INTEGER sNow;//local_2
	}lolo;
#pragma pack()

	//-- init timestamp --
	if(D_0090140C) {
		TS_getCPUTimeStamp(&D_00C3F6E0);
		D_00C3F6E8 = 0;
		D_00C3F6EC = 0;
		D_0090140C = 0;

		return;
	}
	//-- --
	TS_getCPUTimeStamp(&lolo.sNow);
	TS_diff(&lolo.sNow, &D_00C3F6E0, &lolo.sDiff);
	lolo.dDelay = TS_toDouble(&lolo.sDiff) / bp08->f_030;
	lolo.local_7 = (float)(lolo.dDelay * 60.0);
	if(lolo.local_7 >= 32.0f)
		lolo.local_7 = 32.0f;
	D_00C3F6E8 += lolo.local_7;
	D_00C3F6E0 = lolo.sNow;
	//could use some "Sleep" here
}

//coaster.refresh
void C_005E9051(struct t_aa0 *bp08) {
	C_005EE150();//refresh input for coaster
	if(D_00C3F760 == 0) {//else 005E90D8
		//-- in game --
		C_005E9FB3(&D_00C3F8A0);//reset view matrix[set trans]
		C_005EA973();//update track pos/star pos/view matrix

		C_005EDC59(D_00C3F768);//prepare track/background lists
		C_005E9F33();//render track
		C_005E9E7E();//render background
		C_005EA5FD(D_00C3F76C, 5, 40, 0);//render "last shoot score"
		C_005EDD82();//"clean" track/background lists

		C_005EB5CF();//refresh game objects?

		C_005EA7D0();//render 2D infos

		if(D_00C3F768 < 0x4000)
			D_00C3F77C = 0;
		else
			D_00C3F77C = 0x7f;
	} else {
		//-- pause --
		C_005EA80A();//coaster:in pause
		D_00C3F77C = 0;
		D_00C3F780 = 0;
	}
	//-- --
	C_005E9802();//refresh laser/rail SFX volumes
	if(D_00C3F764)
		C_005EA82E();//coaster:"refresh" graphics
}

//coaster[ONMOUSE][callback]
void C_005E9108(int uMsg, int wParam, int lParam, struct t_aa0 *_p14) {
#if 0	//test mouse support -- by joe
	//-- shoot --
	extern int MAIN_inputMask;
	if(wParam & MK_LBUTTON) {
		MAIN_inputMask |= 0x20;
	} else {
		MAIN_inputMask &= ~0x20;
	}
	//-- position --
	D_00C3FB58 = LOWORD(lParam);
	D_00C3FB5C = HIWORD(lParam);
#endif
}

//coaster[ONKEY][callback]
void C_005E910D(int uMsg, int wParam, int lParam, struct t_aa0 *_p14) {
	struct {
		char local_2; char _ocal_2[3];
		int local_1;
	}lolo;

	switch(uMsg) {
		case WM_KEYDOWN://0x100
			lolo.local_1 = wParam;
			switch(lolo.local_1) {
				case 0x00: break;
			}
		break;
		case WM_CHAR://0x102
			lolo.local_2 = wParam;
		break;
	}//end switch
}
