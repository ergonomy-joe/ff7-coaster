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
		- ((u).vx * ((x) >> 2)) \
		- ((u).vy * ((y) >> 2)) \
		- ((u).vz * ((z) >> 2))

#define local_HalfSpace(u, d, x, y, z) \
		+ (u).vx * ((x) >> 2) \
		+ (u).vy * ((y) >> 2) \
		+ (u).vz * ((z) >> 2) \
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
	setVector(&lolo.vLeftUp_div4, lolo.vLeftUp.vx >> 2, lolo.vLeftUp.vy >> 2, lolo.vLeftUp.vz >> 2);
	setVector(&lolo.vLeftDown_div4, lolo.vLeftDown.vx >> 2, lolo.vLeftDown.vy >> 2, lolo.vLeftDown.vz >> 2);

	setVector(&lolo.vRightUp_div4, lolo.vRightUp.vx >> 2, lolo.vRightUp.vy >> 2, lolo.vRightUp.vz >> 2);
	setVector(&lolo.vRightDown_div4, lolo.vRightDown.vx >> 2, lolo.vRightDown.vy >> 2, lolo.vRightDown.vz >> 2);

	psx_OuterProduct0(&lolo.vLeftUp_div4, &lolo.vLeftDown_div4, &D_00C5D328.sLNormal);
	psx_OuterProduct0(&lolo.vRightUp_div4, &lolo.vRightDown_div4, &D_00C5D328.sRNormal);
	//-- compute distance from origin(always 0) --
	D_00C5D328.dwLDistance = local_minusDotProduct(D_00C5D328.sLNormal, lolo.vLeftUp.vx, lolo.vLeftUp.vy, lolo.vLeftUp.vz);
	D_00C5D328.dwRDistance = local_minusDotProduct(D_00C5D328.sRNormal, lolo.vRightUp.vx, lolo.vRightUp.vy, lolo.vRightUp.vz);
	//-- --
	D_00C5D328.dwLHelper = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, lolo.vRightUp.vx, lolo.vRightUp.vy, lolo.vRightUp.vz);
	D_00C5D328.dwRHelper = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, lolo.vLeftUp.vx, lolo.vLeftUp.vy, lolo.vLeftUp.vz);
	//-- compute normals length --
	D_00C5D328.dwLNormalLength = psx_SquareRoot0(D_00C5D328.sLNormal.vx * D_00C5D328.sLNormal.vx + D_00C5D328.sLNormal.vy * D_00C5D328.sLNormal.vy + D_00C5D328.sLNormal.vz * D_00C5D328.sLNormal.vz);
	D_00C5D328.dwRNormalLength = psx_SquareRoot0(D_00C5D328.sRNormal.vx * D_00C5D328.sRNormal.vx + D_00C5D328.sRNormal.vy * D_00C5D328.sRNormal.vy + D_00C5D328.sRNormal.vz * D_00C5D328.sRNormal.vz);
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
	lolo.dwHSLeft = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, bp08->vx, bp08->vy, bp08->vz);
	lolo.dwHSRight = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, bp08->vx, bp08->vy, bp08->vz);
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
	lolo.dwHSLeft = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, bp08->vx, bp08->vy, bp08->vz);
	lolo.dwHSRight = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, bp08->vx, bp08->vy, bp08->vz);
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
	lolo.dwHSLeft = local_HalfSpace(D_00C5D328.sLNormal, D_00C5D328.dwLDistance, bp08->vx, bp08->vy, bp08->vz);
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
	lolo.dwHSRight = local_HalfSpace(D_00C5D328.sRNormal, D_00C5D328.dwRDistance, bp08->vx, bp08->vy, bp08->vz);
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
