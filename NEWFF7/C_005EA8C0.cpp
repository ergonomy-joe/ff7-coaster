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
	0x1000, 0, 0,
	0, 0x1000, 0,
	0, 0, 0x1000,
	0, 0, 0
};
struct MATRIX __009014D0 = {
	0x1000, 0, 0,
	0, 0x1000, 0,
	0, 0, 0x1000,
	0, 0, 0
};
////////////////////////////////////////
char D_00C3F890;//devel/release mode
int D_00C3F894;
int *D_00C3F898;//offsets in "getStream_inline(4)"
//00C3F89C
struct MATRIX D_00C3F8A0;
int *D_00C3F8C0;
//00C3F8C4
unsigned char *D_00C3F8D0;
//00C3F8D4
struct VECTOR D_00C3F8D8;//for view transform?
struct VECTOR D_00C3F8E8;//for starfield
struct VECTOR D_00C3F8F8;//[unused]
struct VECTOR D_00C3F908;//[unused]for debug?
////////////////////////////////////////
//init this module
void C_005EA8C0() {
	D_00C3F8C0 = (int *)D_00C3F738.getStream_inline(6);
	D_00C3F898 = (int *)D_00C3F738.getStream_inline(5);
	setVector(&D_00C3F8F8, 0, -7030, 200);
	C_005EAAF3(0);//prepare data from stream #4?
	D_00C3F890 = 1;//release mode
}

//update track pos/star pos/view matrix
void C_005EA973() {
	struct {
		struct VECTOR vCamPos;//local_17
		DECL_struct_MATRIX(sMatrixRot);//local_13
		struct SVECTOR vCamRot;//local_5
		struct SVECTOR sRot;//local_3
		int dwGravity;//local_1
	}lolo;

	//-- identity --
	lolo.sMatrixRot.m[0][0] = 0x1000; lolo.sMatrixRot.m[0][1] = 0; lolo.sMatrixRot.m[0][2] = 0;
	lolo.sMatrixRot.m[1][0] = 0; lolo.sMatrixRot.m[1][1] = 0x1000; lolo.sMatrixRot.m[1][2] = 0;
	lolo.sMatrixRot.m[2][0] = 0; lolo.sMatrixRot.m[2][1] = 0; lolo.sMatrixRot.m[2][2] = 0x1000;
	lolo.sMatrixRot.t[0] = 0;
	lolo.sMatrixRot.t[1] = 0;
	lolo.sMatrixRot.t[2] = 0;
	//-- --
	C_005EA194(D_00C3F778, -100, &lolo.vCamPos, &lolo.vCamRot);//compute camera pos/rot vectors?
	D_00C3F778 += D_00C3F768;

	D_00C3F8D8 = D_00C3F8E8 = lolo.vCamPos;

	if(lolo.vCamRot.vx < 0)
		lolo.vCamRot.vx += 0x1000;
	//-- gravity? --
	lolo.dwGravity = psx_rsin(lolo.vCamRot.vx) / 15;
	if(lolo.dwGravity > 0 && D_00C3F768 > 43000)
		D_00C3F768 -= lolo.dwGravity;
	if(lolo.dwGravity < 0 && D_00C3F768 < 120000)
		D_00C3F768 -= lolo.dwGravity;
	//-- --
	lolo.sRot.vx = -lolo.vCamRot.vx;
	lolo.sRot.vy = -lolo.vCamRot.vy;
	lolo.sRot.vz = -lolo.vCamRot.vz;
	psx_RotMatrixYXZ(&lolo.sRot, &lolo.sMatrixRot);
	C_005E9FED(&lolo.sMatrixRot, &D_00C3F8A0, &D_00C3F8A0);//combine rot and trans for view matrix?
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
