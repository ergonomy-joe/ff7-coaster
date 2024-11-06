/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- "static" objects

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
unsigned short *D_00C476E8;//"remove track elements" script
struct t_coaster_LinkedList D_00C476F0[0x2328];//track elements
unsigned short *D_00C50390;//"add background triangles" script
unsigned D_00C50394;//curent script/rail position
unsigned short *D_00C50398;//"remove background triangles" script
unsigned short D_00C5039C;//# elements in D_00C503B0
unsigned D_00C503A0;//current script/rail distance
unsigned short D_00C503A4;//head of D_00C476F0
unsigned short D_00C503A8;//tail of D_00C503B0
struct t_coaster_LinkedList D_00C503B0[0x2ee0];//background triangles
unsigned short D_00C5BF30;//# elements in D_00C476F0
unsigned char D_00C5BF34;
unsigned short D_00C5BF38;//tail of D_00C476F0
unsigned short *D_00C5BF3C;//"add track elemens" script
unsigned D_00C5BF40;//previous script/rail position
unsigned short D_00C5BF44;//head of D_00C503B0
////////////////////////////////////////
//init track/background lists
void C_005ED8F0() {
	struct t_coaster_LinkedList *local_2;
	int i;//local_1

	D_00C50394 = 0xfffe;
	D_00C5BF40 = 0;
	D_00C50390 = (unsigned short *)D_00C3F738.getStream_inline(8);
	D_00C50398 = (unsigned short *)D_00C3F738.getStream_inline(9);
	D_00C5BF3C = (unsigned short *)D_00C3F738.getStream_inline(2);
	D_00C476E8 = (unsigned short *)D_00C3F738.getStream_inline(3);
	//-- --
	for(i = 0; i < 0x2ee0; i ++) {
		local_2 = &(D_00C503B0[i]);
		local_2->wPrev = 0xffff;
		local_2->wNext = 0xffff;
	}//end for
	D_00C5039C = 0;
	//-- --
	for(i = 0; i < 0x2328; i ++) {
		local_2 = &(D_00C476F0[i]);
		local_2->wPrev = 0xffff;
		local_2->wNext = 0xffff;
	}//end for
	D_00C5BF30 = 0;
	//-- --
	D_00C5BF34 = 1;
}

void C_005EDE71(unsigned short);//add background triangle
void C_005EDF18(unsigned short);//remove background triangle
void C_005EDFE7(unsigned short);//add track element
void C_005EE09A(unsigned short);//remove track element

void __005EDA91(int bp08) {
	struct {
		DECL_unsigned_short(wIdTrack);//bp_18
		int bp_14;
		DECL_unsigned_short(wIdTriangle);//bp_10
		int bp_0c;
		unsigned bp_08;
		unsigned i;//bp_04
	}lolo;

	D_00C5BF40 = D_00C50394;
	D_00C50394 += bp08;
	lolo.bp_0c = D_00C5BF40 >> 0x12;
	lolo.bp_14 = D_00C50394 >> 0x12;
	lolo.bp_08 = lolo.bp_14 - lolo.bp_0c;
	//-- D_00C3F75C incremented here --
	D_00C3F75C += lolo.bp_08;
	//--
	for(lolo.i = 0; lolo.i < lolo.bp_08 + D_00C5BF34; lolo.i ++) {
		while(1) {
			lolo.wIdTriangle = *(D_00C50390 ++);
			if(lolo.wIdTriangle == 0xffff)
				break;
			C_005EDE71(lolo.wIdTriangle);//add background triangle
		}
		while(1) {
			lolo.wIdTriangle = *(D_00C50398 ++);
			if(lolo.wIdTriangle == 0xffff)
				break;
			C_005EDF18(lolo.wIdTriangle);//remove background triangle
		}
	}//end for
	for(lolo.i = 0; lolo.i < lolo.bp_08; lolo.i ++) {
		while(1) {
			lolo.wIdTrack = *(D_00C5BF3C ++);
			if(lolo.wIdTrack == 0xffff)
				break;
			C_005EDFE7(lolo.wIdTrack);//add track element
		}
		while(1) {
			lolo.wIdTrack = *(D_00C476E8 ++);
			if(lolo.wIdTrack == 0xffff)
				break;
			C_005EE09A(lolo.wIdTrack);//remove track element
		}
	}//end for
	//-- --
	if(D_00C5BF34 == 1)
		D_00C5BF34 = 0;
	//-- --
}

//prepare track/background lists
void C_005EDC59(int bp08) {
	struct {
		DECL_unsigned_short(wIdTrack);//bp_14
		int bp_10;
		DECL_unsigned_short(wIdTriangle);//bp_0c
		unsigned bp_08;
		unsigned i;//bp_04
	}lolo;

	D_00C5BF40 = D_00C50394;
	D_00C50394 += bp08;
	lolo.bp_08 = D_00C5BF40 >> 0x12;
	lolo.bp_10 = D_00C50394 >> 0x12;
	D_00C503A0 = lolo.bp_10 - lolo.bp_08;
	//-- D_00C3F75C incremented here --
	D_00C3F75C += D_00C503A0;
	//--
	for(lolo.i = 0; lolo.i < D_00C503A0 + D_00C5BF34; lolo.i ++) {
		while(1) {
			lolo.wIdTriangle = *(D_00C50390 ++);
			if(lolo.wIdTriangle == 0xffff)
				break;
			C_005EDE71(lolo.wIdTriangle);//add background triangle
		}
		//
		//
		//
		//
		//
		//
	}//end for
	for(lolo.i = 0; lolo.i < D_00C503A0; lolo.i ++) {
		while(1) {
			lolo.wIdTrack = *(D_00C5BF3C ++);
			if(lolo.wIdTrack == 0xffff)
				break;
			C_005EDFE7(lolo.wIdTrack);//add track element
		}
		//
		//
		//
		//
		//
		//
	}//end for
}

//"clean" track/background lists
void C_005EDD82() {
	struct {
		DECL_unsigned_short(wIdTrack);//bp_0c
		DECL_unsigned_short(wIdTriangle);//bp_08
		unsigned i;//bp_04
	}lolo;

	for(lolo.i = 0; lolo.i < D_00C503A0 + D_00C5BF34; lolo.i ++) {
		//
		//
		//
		//
		//
		//
		while(1) {
			lolo.wIdTriangle = *(D_00C50398 ++);
			if(lolo.wIdTriangle == 0xffff)
				break;
			C_005EDF18(lolo.wIdTriangle);//remove background triangle
		}
	}//end for
	for(lolo.i = 0; lolo.i < D_00C503A0; lolo.i ++) {
		//
		//
		//
		//
		//
		//
		while(1) {
			lolo.wIdTrack = *(D_00C476E8 ++);
			if(lolo.wIdTrack == 0xffff)
				break;
			C_005EE09A(lolo.wIdTrack);//remove track element
		}
	}//end for
	//-- --
	if(D_00C5BF34 == 1)
		D_00C5BF34 = 0;
	//-- --
}

//add background triangle
void C_005EDE71(unsigned short wIdTriangle/*bp08*/) {
	struct {
		DECL_unsigned_short(wNext_unused);//local_2
		DECL_unsigned_short(wPrev_unused);//local_1
	}lolo;

	//-- --
	lolo.wPrev_unused = D_00C503B0[wIdTriangle].wPrev;
	lolo.wNext_unused = D_00C503B0[wIdTriangle].wNext;
	//-- --
	if(D_00C5039C == 0) {
		//list is empty
		D_00C5BF44 = wIdTriangle;
		//
		//
		D_00C503A8 = wIdTriangle;
		D_00C5039C = 1;
	} else {
		//insert at tail
		D_00C503B0[wIdTriangle].wPrev = D_00C503A8;
		//
		D_00C503B0[D_00C503A8].wNext = wIdTriangle;
		D_00C503A8 = wIdTriangle;
		D_00C5039C ++;
	}
}

//remove background triangle
void C_005EDF18(unsigned short wIdTriangle/*bp08*/) {
	struct {
		DECL_unsigned_short(wNext);//local_2
		DECL_unsigned_short(wPrev);//local_1
	}lolo;

	lolo.wPrev = D_00C503B0[wIdTriangle].wPrev;
	lolo.wNext = D_00C503B0[wIdTriangle].wNext;
	if(lolo.wPrev != 0xffff)
		D_00C503B0[lolo.wPrev].wNext = lolo.wNext;
	else
		D_00C5BF44 = lolo.wNext;
	if(lolo.wNext != 0xffff)
		D_00C503B0[lolo.wNext].wPrev = lolo.wPrev;
	else
		D_00C503A8 = lolo.wPrev;
	D_00C503B0[wIdTriangle].wPrev = 0xffff;
	D_00C503B0[wIdTriangle].wNext = 0xffff;
	D_00C5039C --;
}

//add track element
void C_005EDFE7(unsigned short wIdTrack/*bp08*/) {
	if(D_00C5BF30 == 0) {
		//list is empty
		D_00C503A4 = wIdTrack;
		D_00C476F0[wIdTrack].wPrev = 0xffff;
		D_00C476F0[wIdTrack].wNext = 0xffff;
		D_00C5BF38 = wIdTrack;
		D_00C5BF30 = 1;
	} else {
		//insert at tail
		D_00C476F0[wIdTrack].wPrev = D_00C5BF38;
		D_00C476F0[wIdTrack].wNext = 0xffff;
		D_00C476F0[D_00C5BF38].wNext = wIdTrack;
		D_00C5BF38 = wIdTrack;
		D_00C5BF30 ++;
	}
}

//remove track element
void C_005EE09A(unsigned short wIdTrack/*bp08*/) {
	struct {
		DECL_unsigned_short(wNext);//local_2
		DECL_unsigned_short(wPrev);//local_1
	}lolo;

	lolo.wPrev = D_00C476F0[wIdTrack].wPrev;
	lolo.wNext = D_00C476F0[wIdTrack].wNext;
	if(lolo.wPrev != 0xffff)
		D_00C476F0[lolo.wPrev].wNext = lolo.wNext;
	else
		D_00C503A4 = lolo.wNext;
	if(lolo.wNext != 0xffff)
		D_00C476F0[lolo.wNext].wPrev = lolo.wPrev;
	else
		D_00C5BF38 = lolo.wPrev;
	//
	//
	D_00C5BF30 --;
}
