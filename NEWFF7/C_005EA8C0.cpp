/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster --

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
//this module or another ?
struct MATRIX __009014B0 = {
	{
		{0x1000, 0, 0},
		{0, 0x1000, 0},
		{0, 0, 0x1000}
	},
	{0, 0, 0}
};
//00 00
struct MATRIX __009014D0 = {
	{
		{0x1000, 0, 0},
		{0, 0x1000, 0},
		{0, 0, 0x1000}
	},
	{0, 0, 0}
};
//00 00
////////////////////////////////////////
char D_00C3F890;//devel/release mode
int D_00C3F894;
int *D_00C3F898;//offsets in "getStream_inline(4)"
//00C3F89C
struct MATRIX D_00C3F8A0;//start of a structure?
int *D_00C3F8C0;
//00C3F8C4
unsigned char *D_00C3F8D0;
//00C3F8D4
struct VECTOR D_00C3F8D8;
struct VECTOR D_00C3F8E8;//for starfield
struct VECTOR D_00C3F8F8;//[unused]
struct VECTOR D_00C3F908;//[unused]
////////////////////////////////////////
//init this module
void C_005EA8C0() {
	D_00C3F8C0 = (int *)D_00C3F738.getStream_inline(6);
	D_00C3F898 = (int *)D_00C3F738.getStream_inline(5);
	D_00C3F8F8.f_00 = 0; D_00C3F8F8.f_04 = -7030; D_00C3F8F8.f_08 = 200;
	C_005EAAF3(0);//prepare data from stream #4?
	D_00C3F890 = 1;//release mode
}

//track matrix related
void C_005EA973() {
	struct {
		struct VECTOR vCamPos;//local_17
		struct MATRIX local_13; char _ocal_13[2];
		struct SVECTOR vCamRot;//local_5
		struct SVECTOR local_3;
		int dwGravity;//local_1
	}lolo;

	//-- identity --
	lolo.local_13.f_00[0][0] = 0x1000; lolo.local_13.f_00[0][1] = 0; lolo.local_13.f_00[0][2] = 0;
	lolo.local_13.f_00[1][0] = 0; lolo.local_13.f_00[1][1] = 0x1000; lolo.local_13.f_00[1][2] = 0;
	lolo.local_13.f_00[2][0] = 0; lolo.local_13.f_00[2][1] = 0; lolo.local_13.f_00[2][2] = 0x1000;
	lolo.local_13.f_12[0] = 0;
	lolo.local_13.f_12[1] = 0;
	lolo.local_13.f_12[2] = 0;
	//-- --
	C_005EA194(D_00C3F778, -100, &lolo.vCamPos, &lolo.vCamRot);//compute camera pos/rot vectors?
	D_00C3F778 += D_00C3F768;

	D_00C3F8D8 = D_00C3F8E8 = lolo.vCamPos;

	if(lolo.vCamRot.f_00 < 0)
		lolo.vCamRot.f_00 += 0x1000;
	//-- gravity? --
	lolo.dwGravity = psx_rsin(lolo.vCamRot.f_00) / 15;
	if(lolo.dwGravity > 0 && D_00C3F768 > 43000)
		D_00C3F768 -= lolo.dwGravity;
	if(lolo.dwGravity < 0 && D_00C3F768 < 120000)
		D_00C3F768 -= lolo.dwGravity;
	//-- --
	lolo.local_3.f_00 = -lolo.vCamRot.f_00;
	lolo.local_3.f_02 = -lolo.vCamRot.f_02;
	lolo.local_3.f_04 = -lolo.vCamRot.f_04;
	psx_RotMatrixYXZ(&lolo.local_3, &lolo.local_13);
	C_005E9FED(&lolo.local_13, &D_00C3F8A0, &D_00C3F8A0);
}

//prepare data from stream #4?
void C_005EAAF3(int bp08) {
	int dwOffset;

	dwOffset = D_00C3F898[bp08 & 0xff];
	D_00C3F8D0 = D_00C3F738.getStream_inline(4) + dwOffset;
	D_00C3F894 = *D_00C3F8C0;
}

void __005EAB5E() {
}
