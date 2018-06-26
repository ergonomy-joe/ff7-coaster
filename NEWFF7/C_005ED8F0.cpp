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
unsigned short *D_00C50390;//"add background elements" script
unsigned D_00C50394;//curent script/rail position
unsigned short *D_00C50398;//"remove background elements" script
unsigned short D_00C5039C;//# elements in D_00C503B0
unsigned D_00C503A0;//current script/rail distance
unsigned short D_00C503A4;//head of D_00C476F0
unsigned short D_00C503A8;//tail of D_00C503B0
struct t_coaster_LinkedList D_00C503B0[0x2ee0];//background elements
unsigned short D_00C5BF30;//# elements in D_00C476F0
unsigned char D_00C5BF34;
unsigned short D_00C5BF38;//tail of D_00C476F0
unsigned short *D_00C5BF3C;//"add track elemens" script
unsigned D_00C5BF40;//previous script/rail position
unsigned short D_00C5BF44;//head of D_00C503B0
////////////////////////////////////////
//init track/background elements lists
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
	}
	D_00C5039C = 0;
	//-- --
	for(i = 0; i < 0x2328; i ++) {
		local_2 = &(D_00C476F0[i]);
		local_2->wPrev = 0xffff;
		local_2->wNext = 0xffff;
	}
	D_00C5BF30 = 0;
	//-- --
	D_00C5BF34 = 1;
}

void C_005EDE71(unsigned short);//add background element
void C_005EDF18(unsigned short);//remove background element
void C_005EDFE7(unsigned short);//add track element
void C_005EE09A(unsigned short);//remove track element

void __005EDA91(int bp08) {
	struct {
		unsigned short bp_18; char _p_18[2];
		int bp_14;
		unsigned short bp_10; char _p_10[2];
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
			lolo.bp_10 = *(D_00C50390 ++);
			if(lolo.bp_10 == 0xffff)
				break;
			C_005EDE71(lolo.bp_10);//add background element
		}
		while(1) {
			lolo.bp_10 = *(D_00C50398 ++);
			if(lolo.bp_10 == 0xffff)
				break;
			C_005EDF18(lolo.bp_10);//remove background element
		}
	}
	for(lolo.i = 0; lolo.i < lolo.bp_08; lolo.i ++) {
		while(1) {
			lolo.bp_18 = *(D_00C5BF3C ++);
			if(lolo.bp_18 == 0xffff)
				break;
			C_005EDFE7(lolo.bp_18);//add track element
		}
		while(1) {
			lolo.bp_18 = *(D_00C476E8 ++);
			if(lolo.bp_18 == 0xffff)
				break;
			C_005EE09A(lolo.bp_18);//remove track element
		}
	}
	if(D_00C5BF34 == 1)
		D_00C5BF34 = 0;
}

//prepare track/background elements lists
void C_005EDC59(int bp08) {
	struct {
		unsigned short bp_14; char _p_14[2];
		int bp_10;
		unsigned short bp_0c; char _p_0c[2];
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
			lolo.bp_0c = *(D_00C50390 ++);
			if(lolo.bp_0c == 0xffff)
				break;
			C_005EDE71(lolo.bp_0c);//add background element
		}
	}
	for(lolo.i = 0; lolo.i < D_00C503A0; lolo.i ++) {
		while(1) {
			lolo.bp_14 = *(D_00C5BF3C ++);
			if(lolo.bp_14 == 0xffff)
				break;
			C_005EDFE7(lolo.bp_14);//add track element
		}
	}
}

//"clean" track/background elements lists
void C_005EDD82() {
	struct {
		unsigned short bp_0c; char _p_0c[2];
		unsigned short bp_08; char _p_08[2];
		unsigned i;//bp_04
	}lolo;

	for(lolo.i = 0; lolo.i < D_00C503A0 + D_00C5BF34; lolo.i ++) {
		while(1) {
			lolo.bp_08 = *(D_00C50398 ++);
			if(lolo.bp_08 == 0xffff)
				break;
			C_005EDF18(lolo.bp_08);//remove background element
		}
	}
	for(lolo.i = 0; lolo.i < D_00C503A0; lolo.i ++) {
		while(1) {
			lolo.bp_0c = *(D_00C476E8 ++);
			if(lolo.bp_0c == 0xffff)
				break;
			C_005EE09A(lolo.bp_0c);//remove track element
		}
	}
	if(D_00C5BF34 == 1)
		D_00C5BF34 = 0;
}

//add background element
void C_005EDE71(unsigned short bp08) {
	unsigned short local_2;
	unsigned short local_1;

	local_1 = D_00C503B0[bp08].wPrev;
	local_2 = D_00C503B0[bp08].wNext;
	if(D_00C5039C == 0) {
		D_00C5BF44 = bp08;
		D_00C503A8 = bp08;
		D_00C5039C = 1;
	} else {
		D_00C503B0[bp08].wPrev = D_00C503A8;
		D_00C503B0[D_00C503A8].wNext = bp08;
		D_00C503A8 = bp08;
		D_00C5039C ++;
	}
}

//remove background element
void C_005EDF18(unsigned short bp08) {
	unsigned short local_2;
	unsigned short local_1;

	local_1 = D_00C503B0[bp08].wPrev;
	local_2 = D_00C503B0[bp08].wNext;
	if(local_1 != 0xffff)
		D_00C503B0[local_1].wNext = local_2;
	else
		D_00C5BF44 = local_2;
	if(local_2 != 0xffff)
		D_00C503B0[local_2].wPrev = local_1;
	else
		D_00C503A8 = local_1;
	D_00C503B0[bp08].wPrev = 0xffff;
	D_00C503B0[bp08].wNext = 0xffff;
	D_00C5039C --;
}

//add track element
void C_005EDFE7(unsigned short bp08) {
	if(D_00C5BF30 == 0) {
		D_00C503A4 = bp08;
		D_00C476F0[bp08].wPrev = 0xffff;
		D_00C476F0[bp08].wNext = 0xffff;
		D_00C5BF38 = bp08;
		D_00C5BF30 = 1;
	} else {
		D_00C476F0[bp08].wPrev = D_00C5BF38;
		D_00C476F0[bp08].wNext = 0xffff;
		D_00C476F0[D_00C5BF38].wNext = bp08;
		D_00C5BF38 = bp08;
		D_00C5BF30 ++;
	}
}

//remove track element
void C_005EE09A(unsigned short bp08) {
	unsigned short local_2;
	unsigned short local_1;

	local_1 = D_00C476F0[bp08].wPrev;
	local_2 = D_00C476F0[bp08].wNext;
	if(local_1 != 0xffff)
		D_00C476F0[local_1].wNext = local_2;
	else
		D_00C503A4 = local_2;
	if(local_2 != 0xffff)
		D_00C476F0[local_2].wPrev = local_1;
	else
		D_00C5BF38 = local_1;
	D_00C5BF30 --;
}
