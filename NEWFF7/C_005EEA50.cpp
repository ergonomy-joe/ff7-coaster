/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- hit/clip?

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
int D_00C5D328,D_00C5D32C;//??? [left,right]
struct VECTOR D_00C5D330,D_00C5D340;//plane normal[left,right]?
int D_00C5D350,D_00C5D354;//??? [left,right]
int D_00C5D358,D_00C5D35C;//plane normal length[left,right]?
////////////////////////////////////////
__inline int component(int a, int b, int c = 0) {
	return a * (b >> 2) + c;
}

#define someDotProduct_minus(u, v, b) \
		- component((u).f_00, (v).f_00) \
		- component((u).f_04, (v).f_04, b) \
		- component((u).f_08, (v).f_08)
//__inline int someDotProduct_minus(struct VECTOR &u, struct VECTOR &v, int b) {
//	return
//		- component((u).f_00, (v).f_00)
//		- component((u).f_04, (v).f_04, b)
//		- component((u).f_08, (v).f_08)
//	;
//}

//we could use templates to merge those two?
__inline int someDotProduct_inline(struct VECTOR &u, struct VECTOR &v, int b) {
	return
		+ component(u.f_08, v.f_08)
		+ component(u.f_04, v.f_04, b)
		+ component(u.f_00, v.f_00)
	;
}
__inline int someDotProduct_inline(struct VECTOR &u, struct SVECTOR &v, int b) {
	return
		+ component(u.f_08, v.f_04)
		+ component(u.f_04, v.f_02, b)
		+ component(u.f_00, v.f_00)
	;
}
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
	//-- compoute left and right plane normals --
	lolo.vLeftUp_div4.f_00 = lolo.vLeftUp.f_00 >> 2; lolo.vLeftUp_div4.f_04 = lolo.vLeftUp.f_04 >> 2; lolo.vLeftUp_div4.f_08 = lolo.vLeftUp.f_08 >> 2;
	lolo.vLeftDown_div4.f_00 = lolo.vLeftDown.f_00 >> 2; lolo.vLeftDown_div4.f_04 = lolo.vLeftDown.f_04 >> 2; lolo.vLeftDown_div4.f_08 = lolo.vLeftDown.f_08 >> 2;

	lolo.vRightUp_div4.f_00 = lolo.vRightUp.f_00 >> 2; lolo.vRightUp_div4.f_04 = lolo.vRightUp.f_04 >> 2; lolo.vRightUp_div4.f_08 = lolo.vRightUp.f_08 >> 2;
	lolo.vRightDown_div4.f_00 = lolo.vRightDown.f_00 >> 2; lolo.vRightDown_div4.f_04 = lolo.vRightDown.f_04 >> 2; lolo.vRightDown_div4.f_08 = lolo.vRightDown.f_08 >> 2;

	C_00663B32(&lolo.vLeftUp_div4, &lolo.vLeftDown_div4, &D_00C5D330);//psx:OuterProduct0
	C_00663B32(&lolo.vRightUp_div4, &lolo.vRightDown_div4, &D_00C5D340);//psx:OuterProduct0
	//-- compute some nonsense dot products(always 0)? --
	D_00C5D328 = someDotProduct_minus(D_00C5D330, lolo.vLeftUp, 0);
	D_00C5D32C = someDotProduct_minus(D_00C5D340, lolo.vRightUp, 0);
	//-- --
	D_00C5D350 = someDotProduct_inline(D_00C5D330, lolo.vRightUp, D_00C5D328);
	D_00C5D354 = someDotProduct_inline(D_00C5D340, lolo.vLeftUp, D_00C5D32C);
	//-- compute normals length --
	D_00C5D358 = C_00663736(D_00C5D330.f_00 * D_00C5D330.f_00 + D_00C5D330.f_04 * D_00C5D330.f_04 + D_00C5D330.f_08 * D_00C5D330.f_08);//psx:SquareRoot0?
	D_00C5D35C = C_00663736(D_00C5D340.f_00 * D_00C5D340.f_00 + D_00C5D340.f_04 * D_00C5D340.f_04 + D_00C5D340.f_08 * D_00C5D340.f_08);//psx:SquareRoot0?
}

//coaster.hit:check some direction?
int C_005EECB5(struct VECTOR *bp08) {
	struct {
		int local_4;
		int dwRightOk;//local_3
		int dwLeftOk;//local_2
		int local_1;
	}lolo;

	lolo.dwRightOk = lolo.dwLeftOk = 0;
	lolo.local_4 = someDotProduct_inline(D_00C5D330, *bp08, D_00C5D328);
	lolo.local_1 = someDotProduct_inline(D_00C5D340, *bp08, D_00C5D32C);
	//-- check against left plane --
	if(lolo.local_4 > 0 && D_00C5D350 > 0)
		lolo.dwLeftOk = 1;
	if(lolo.local_4 < 0 && D_00C5D350 < 0)
		lolo.dwLeftOk = 1;
	//-- check against right plane --
	if(lolo.local_1 > 0 && D_00C5D354 > 0)
		lolo.dwRightOk = 1;
	if(lolo.local_1 < 0 && D_00C5D354 < 0)
		lolo.dwRightOk = 1;
	//-- --

	return lolo.dwLeftOk & lolo.dwRightOk;
}

//coaster.hit:check some direction(SVECTOR)?
int __005EEDAE(struct SVECTOR *bp08) {
	struct {
		int local_4;
		int dwRightOk;//local_3
		int dwLeftOk;//local_2
		int local_1;
	}lolo;

	lolo.dwRightOk = lolo.dwLeftOk = 0;
	lolo.local_4 = someDotProduct_inline(D_00C5D330, *bp08, D_00C5D328);
	lolo.local_1 = someDotProduct_inline(D_00C5D340, *bp08, D_00C5D32C);
	//-- check against left plane --
	if(lolo.local_4 > 0 && D_00C5D350 > 0)
		lolo.dwLeftOk = 1;
	if(lolo.local_4 < 0 && D_00C5D350 < 0)
		lolo.dwLeftOk = 1;
	//-- check against right plane --
	if(lolo.local_1 > 0 && D_00C5D354 > 0)
		lolo.dwRightOk = 1;
	if(lolo.local_1 < 0 && D_00C5D354 < 0)
		lolo.dwRightOk = 1;
	//-- --

	return lolo.dwLeftOk & lolo.dwRightOk;
}

//check

#if 1
//some dot product[left]?
int __005EEEAD(struct VECTOR bp08) {
	return someDotProduct_inline(D_00C5D330, bp08, D_00C5D328);
}

//some dot product[right]?
int __005EEEEA(struct VECTOR bp08) {
	return someDotProduct_inline(D_00C5D340, bp08, D_00C5D32C);
}

int __005EEF27(struct VECTOR *bp08, short bp0c) {
	struct {
		int dwLeftOk;//local_5
		int local_4;
		int dwRightOk;//local_3
		int local_2;
		int local_1;
	}lolo;

	lolo.dwLeftOk = 0;
	lolo.dwRightOk = 0;
	//-- looks like __005EF071() --
	lolo.local_4 = someDotProduct_inline(D_00C5D330, *bp08, D_00C5D328);
	if(D_00C5D350 > 0 && lolo.local_4 > 0)
		lolo.dwLeftOk = 1;
	if(D_00C5D350 < 0 && lolo.local_4 < 0)
		lolo.dwLeftOk = 1;
	if(lolo.dwLeftOk == 0) {
		lolo.local_1 = abs(lolo.local_4) / D_00C5D358;
		if(bp0c < lolo.local_1)
			lolo.dwLeftOk = 1;
	}
	//-- looks like __005EF114() --
	lolo.local_2 = someDotProduct_inline(D_00C5D340, *bp08, D_00C5D32C);
	if(D_00C5D354 > 0 && lolo.local_2 > 0)
		lolo.dwRightOk = 1;
	if(D_00C5D354 < 0 && lolo.local_2 < 0)
		lolo.dwRightOk = 1;
	if(lolo.dwRightOk == 0) {
		lolo.local_1 = abs(lolo.local_2) / D_00C5D35C;
		if(bp0c < lolo.local_1)
			lolo.dwRightOk = 1;
	}
	//-- --

	return lolo.dwLeftOk | lolo.dwRightOk;
}

int __005EF071(struct VECTOR bp08) {
	struct {
		int dwLeftOk;//local_3
		int local_2;
		int local_1;
	}lolo;

	lolo.dwLeftOk = 0;
	lolo.local_1 = someDotProduct_inline(D_00C5D330, bp08, D_00C5D328);
	if(D_00C5D350 > 0 && lolo.local_1 > 0)
		lolo.dwLeftOk = 1;
	if(D_00C5D350 < 0 && lolo.local_1 < 0)
		lolo.dwLeftOk = 1;
	if(lolo.dwLeftOk == 0) {
		lolo.local_2 = abs(lolo.local_1) / D_00C5D358;
		if(bp08.f_04 < lolo.local_2)
			lolo.dwLeftOk = 1;
	}

	return lolo.dwLeftOk;
}

int __005EF114(struct VECTOR bp08) {
	struct {
		int dwRightOk;//local_3
		int local_2;
		int local_1;
	}lolo;

	lolo.dwRightOk = 0;
	lolo.local_1 = someDotProduct_inline(D_00C5D340, bp08, D_00C5D32C);
	if(D_00C5D354 > 0 && lolo.local_1 > 0)
		lolo.dwRightOk = 1;
	if(D_00C5D354 < 0 && lolo.local_1 < 0)
		lolo.dwRightOk = 1;
	if(lolo.dwRightOk == 0) {
		lolo.local_2 = abs(lolo.local_1) / D_00C5D35C;
		if(bp08.f_04 < lolo.local_2)
			lolo.dwRightOk = 1;
	}

	return lolo.dwRightOk;
}
#endif
