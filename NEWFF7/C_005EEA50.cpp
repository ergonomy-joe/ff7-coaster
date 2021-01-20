/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- half space test?

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
struct {
	/*00*/int dwLDistance,dwRDistance;//distance from origin//00C5D328/00C5D32C
	/*08*/struct VECTOR sLNormal,sRNormal;//00C5D330/00C5D340
	/*28*/int dwLHelper,dwRHelper;//00C5D350/00C5D354
	/*30*/int dwLNormalLength,dwRNormalLength;//00C5D358/00C5D35C
}D_00C5D328;
////////////////////////////////////////
#define local_minusDotProduct(u, x, y, z) \
		- ((u).f_00 * ((x) >> 2)) \
		- ((u).f_04 * ((y) >> 2)) \
		- ((u).f_08 * ((z) >> 2))

#define local_HalfSpace(u, d, x, y, z) \
		+ (u).f_00 * ((x) >> 2) \
		+ (u).f_04 * ((y) >> 2) \
		+ (u).f_08 * ((z) >> 2) \
		+ (d)
////////////////////////////////////////
//X axis:from left to right
//Y axis:from top to bottom
//Z axis:from near to far
////////////////////////////////////////
//coaster.hit:init?
void C_005EEA50() {
	struct {
		struct VECTOR vRightDown;// = { 160,  120, 256};//local_32
		struct VECTOR vRightUp;//   = { 160, -120, 256};//local_28
		struct VECTOR vLeftDown;//  = {-160,  120, 256};//local_24
		struct VECTOR vLeftUp;//    = {-160, -120, 256};//local_20
		struct VECTOR vRightUp_div4;//local_16
		struct VECTOR vRightDown_div4;//local_12
		struct VECTOR vLeftUp_div4;//local_8
		struct VECTOR vLeftDown_div4;//local_4
	}lolo;

	VECTOR_init(lolo.vLeftDown,  -160,  120, 256);
	VECTOR_init(lolo.vRightDown,  160,  120, 256);
	VECTOR_init(lolo.vLeftUp,    -160, -120, 256);
	VECTOR_init(lolo.vRightUp,    160, -120, 256);
	//-- compute left and right plane normals --
	lolo.vLeftUp_div4.f_00 = lolo.vLeftUp.f_00 >> 2; lolo.vLeftUp_div4.f_04 = lolo.vLeftUp.f_04 >> 2; lolo.vLeftUp_div4.f_08 = lolo.vLeftUp.f_08 >> 2;
	lolo.vLeftDown_div4.f_00 = lolo.vLeftDown.f_00 >> 2; lolo.vLeftDown_div4.f_04 = lolo.vLeftDown.f_04 >> 2; lolo.vLeftDown_div4.f_08 = lolo.vLeftDown.f_08 >> 2;

	lolo.vRightUp_div4.f_00 = lolo.vRightUp.f_00 >> 2; lolo.vRightUp_div4.f_04 = lolo.vRightUp.f_04 >> 2; lolo.vRightUp_div4.f_08 = lolo.vRightUp.f_08 >> 2;
	lolo.vRightDown_div4.f_00 = lolo.vRightDown.f_00 >> 2; lolo.vRightDown_div4.f_04 = lolo.vRightDown.f_04 >> 2; lolo.vRightDown_div4.f_08 = lolo.vRightDown.f_08 >> 2;

	psx_OuterProduct0(&lolo.vLeftUp_div4, &lolo.vLeftDown_div4, &D_00C5D328.sLNormal);
	psx_OuterProduct0(&lolo.vRightUp_div4, &lolo.vRightDown_div4, &D_00C5D328.sRNormal);
	//-- compute distance from origin(always 0) --
	D_00C5D328.dwLDistance = local_minusDotProduct(D_00C5D328.sLNormal, lolo.vLeftUp.f_00, lolo.vLeftUp.f_04, lolo.vLeftUp.f_08);
	D_00C5D328.dwRDistance = local_minusDotProduct(D_00C5D328.sRNormal, lolo.vRightUp.f_00, lolo.vRightUp.f_04, lolo.vRightUp.f_08);
	//-- --
	D_00C5D328.dwLHelper = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, lolo.vRightUp.f_00, lolo.vRightUp.f_04, lolo.vRightUp.f_08);
	D_00C5D328.dwRHelper = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, lolo.vLeftUp.f_00, lolo.vLeftUp.f_04, lolo.vLeftUp.f_08);
	//-- compute normals length --
	D_00C5D328.dwLNormalLength = psx_SquareRoot0(D_00C5D328.sLNormal.f_00 * D_00C5D328.sLNormal.f_00 + D_00C5D328.sLNormal.f_04 * D_00C5D328.sLNormal.f_04 + D_00C5D328.sLNormal.f_08 * D_00C5D328.sLNormal.f_08);
	D_00C5D328.dwRNormalLength = psx_SquareRoot0(D_00C5D328.sRNormal.f_00 * D_00C5D328.sRNormal.f_00 + D_00C5D328.sRNormal.f_04 * D_00C5D328.sRNormal.f_04 + D_00C5D328.sRNormal.f_08 * D_00C5D328.sRNormal.f_08);
}

//coaster.hit:check some direction?
int C_005EECB5(struct VECTOR *bp08) {
	struct {
		int dwHSLeft;//local_4
		int dwRightOk;//local_3
		int dwLeftOk;//local_2
		int dwHSRight;//local_1
	}lolo;

	lolo.dwRightOk = lolo.dwLeftOk = 0;
	lolo.dwHSLeft = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, bp08->f_00, bp08->f_04, bp08->f_08);
	lolo.dwHSRight = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, bp08->f_00, bp08->f_04, bp08->f_08);
	//-- check against left plane --
	if(lolo.dwHSLeft > 0 && D_00C5D328.dwLHelper > 0)
		lolo.dwLeftOk = 1;
	if(lolo.dwHSLeft < 0 && D_00C5D328.dwLHelper < 0)
		lolo.dwLeftOk = 1;
	//-- check against right plane --
	if(lolo.dwHSRight > 0 && D_00C5D328.dwRHelper > 0)
		lolo.dwRightOk = 1;
	if(lolo.dwHSRight < 0 && D_00C5D328.dwRHelper < 0)
		lolo.dwRightOk = 1;
	//-- --

	return lolo.dwLeftOk & lolo.dwRightOk;
}

//coaster.hit:check some direction(SVECTOR)?
int __005EEDAE(struct SVECTOR *bp08) {
	struct {
		int dwHSLeft;//local_4
		int dwRightOk;//local_3
		int dwLeftOk;//local_2
		int dwHSRight;//local_1
	}lolo;

	lolo.dwRightOk = lolo.dwLeftOk = 0;
	lolo.dwHSLeft = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, bp08->f_00, bp08->f_02, bp08->f_04);
	lolo.dwHSRight = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, bp08->f_00, bp08->f_02, bp08->f_04);
	//-- check against left plane --
	if(lolo.dwHSLeft > 0 && D_00C5D328.dwLHelper > 0)
		lolo.dwLeftOk = 1;
	if(lolo.dwHSLeft < 0 && D_00C5D328.dwLHelper < 0)
		lolo.dwLeftOk = 1;
	//-- check against right plane --
	if(lolo.dwHSRight > 0 && D_00C5D328.dwRHelper > 0)
		lolo.dwRightOk = 1;
	if(lolo.dwHSRight < 0 && D_00C5D328.dwRHelper < 0)
		lolo.dwRightOk = 1;
	//-- --

	return lolo.dwLeftOk & lolo.dwRightOk;
}

//HalfSpace[left]?
int __005EEEAD(int dwX/*bp08*/, int dwY/*bp0c*/, int dwZ/*bp10*/) {
	return local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, dwX, dwY, dwZ);
}

//HalfSpace[right]?
int __005EEEEA(int dwX/*bp08*/, int dwY/*bp0c*/, int dwZ/*bp10*/) {
	return local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, dwX, dwY, dwZ);
}

//[left][right]
int __005EEF27(struct VECTOR *bp08, short wDistance/*bp0c*/) {
	struct {
		int dwLeftOk;//local_5
		int dwHSLeft;//local_4
		int dwRightOk;//local_3
		int dwHSRight;//local_2
		int dwPlaneDistance;//local_1
	}lolo;

	lolo.dwLeftOk = 0; lolo.dwRightOk = 0;
	//-- looks like __005EF071() --
	lolo.dwHSLeft = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, bp08->f_00, bp08->f_04, bp08->f_08);
	if(D_00C5D328.dwLHelper > 0 && lolo.dwHSLeft >= 0)
		lolo.dwLeftOk = 1;
	if(D_00C5D328.dwLHelper < 0 && lolo.dwHSLeft <= 0)
		lolo.dwLeftOk = 1;
	if(lolo.dwLeftOk == 0) {
		lolo.dwPlaneDistance = abs(lolo.dwHSLeft) / D_00C5D328.dwLNormalLength;
		if(lolo.dwPlaneDistance < wDistance)
			lolo.dwLeftOk = 1;
	}
	//-- looks like __005EF114() --
	lolo.dwHSRight = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, bp08->f_00, bp08->f_04, bp08->f_08);
	if(D_00C5D328.dwRHelper > 0 && lolo.dwHSRight >= 0)
		lolo.dwRightOk = 1;
	if(D_00C5D328.dwRHelper < 0 && lolo.dwHSRight <= 0)
		lolo.dwRightOk = 1;
	if(lolo.dwRightOk == 0) {
		lolo.dwPlaneDistance = abs(lolo.dwHSRight) / D_00C5D328.dwRNormalLength;
		if(lolo.dwPlaneDistance < wDistance)
			lolo.dwRightOk = 1;
	}
	//-- --

	return lolo.dwLeftOk & lolo.dwRightOk;
}

//[left]
int __005EF071(int dwX/*bp08*/, int dwY/*bp0c*/, int dwZ/*bp10*/, short wDistance/*bp14*/) {
	struct {
		int dwLeftOk;//local_3
		int dwPlaneDistance;//local_2
		int dwHSLeft;//local_1
	}lolo;

	lolo.dwLeftOk = 0;
	//-- --
	lolo.dwHSLeft = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, dwX, dwY, dwZ);
	if(D_00C5D328.dwLHelper > 0 && lolo.dwHSLeft >= 0)
		lolo.dwLeftOk = 1;
	if(D_00C5D328.dwLHelper < 0 && lolo.dwHSLeft <= 0)
		lolo.dwLeftOk = 1;
	if(lolo.dwLeftOk == 0) {
		lolo.dwPlaneDistance = abs(lolo.dwHSLeft) / D_00C5D328.dwLNormalLength;
		if(lolo.dwPlaneDistance < wDistance)
			lolo.dwLeftOk = 1;
	}
	//-- --

	return lolo.dwLeftOk;
}

//[right]
int __005EF114(int dwX/*bp08*/, int dwY/*bp0c*/, int dwZ/*bp10*/, short wDistance/*bp14*/) {
	struct {
		int dwRightOk;//local_3
		int dwPlaneDistance;//local_2
		int dwHSRight;//local_1
	}lolo;

	lolo.dwRightOk = 0;
	//-- --
	lolo.dwHSRight = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, dwX, dwY, dwZ);
	if(D_00C5D328.dwRHelper > 0 && lolo.dwHSRight >= 0)
		lolo.dwRightOk = 1;
	if(D_00C5D328.dwRHelper < 0 && lolo.dwHSRight <= 0)
		lolo.dwRightOk = 1;
	if(lolo.dwRightOk == 0) {
		lolo.dwPlaneDistance = abs(lolo.dwHSRight) / D_00C5D328.dwRNormalLength;
		if(lolo.dwPlaneDistance < wDistance)
			lolo.dwRightOk = 1;
	}
	//-- --

	return lolo.dwRightOk;
}
