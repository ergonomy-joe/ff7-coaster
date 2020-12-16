/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- input module

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
int D_00C5BF48;//(unused)
int D_00C5BF4C;//direction(unused)
int D_00C5BF50;
int D_00C5BF54;
////////////////////////////////////////
/*D_00C5BF4C "direction mask" value's meaning:

+---+---+---+
| 7 | 8 | 9 |
+---+---+---+
| 4 | . | 6 |
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+*/

//refresh input for coaster
void C_005EE150() {
	if(D_00C3F760 == 0) {//skip if paused//else 005EE5BB
		D_00C5BF4C = 0;
		D_00C5BF48 = 0;
		//-- left --
		if(C_0041AB67(PAD_15))//test input mask[pressed]?
			D_00C5BF4C = 4;
		//-- right --
		if(C_0041AB67(PAD_13))//test input mask[pressed]?
			D_00C5BF4C = 6;
		//-- up --
		if(C_0041AB67(PAD_12)) {//test input mask[pressed]?
			D_00C5BF4C = 8;
			//-- up left --
			if(C_0041AB67(PAD_15))//test input mask[pressed]?
				D_00C5BF4C = 7;
			//-- up right --
			if(C_0041AB67(PAD_13))//test input mask[pressed]?
				D_00C5BF4C = 9;
		}
		//-- down --
		if(C_0041AB67(PAD_14)) {//test input mask[pressed]?
			D_00C5BF4C = 2;
			//-- down left--
			if(C_0041AB67(PAD_15))//test input mask[pressed]?
				D_00C5BF4C = 1;
			//-- down right --
			if(C_0041AB67(PAD_13))//test input mask[pressed]?
				D_00C5BF4C = 3;
		}
		//%%%%%%%%%%%%%%%%%%
		//%% release mode %%
		if(D_00C3F890 == 1) {//else 005EE41D
			//-- down --
			if(C_0041AB67(PAD_14))//test input mask[pressed]?
				D_00C3FB5C += 10;
			//-- up --
			if(C_0041AB67(PAD_12))//test input mask[pressed]?
				D_00C3FB5C -= 10;
			//-- left --
			if(C_0041AB67(PAD_15))//test input mask[pressed]?
				D_00C3FB58 -= 10;
			//-- right --
			if(C_0041AB67(PAD_13))//test input mask[pressed]?
				D_00C3FB58 += 10;
			//-- button 3 -- shoot
			D_00C3FA70 = 0;
			if(C_0041AB67(PAD_05)) {//test input mask[pressed]?//else 005EE388
				//-- shooting --
				C_005E96DA(D_00C3FB50);//set laser SFX volume
				D_00C5BF54 = 1;
				if(D_00C3FB50 > 8)
					D_00C3FB50 --;
				if(D_00C3FA74 == 0) {
					D_00C3FA74 = 1;
					D_00C3FA70 = 1;
					(++ D_00C476DC) %= 3;
				} else {
					D_00C3FA74 --;
				}
			} else {
				//-- not shooting --
				if(D_00C5BF54) {
					C_005E96DA(0);//set laser SFX volume
					D_00C5BF54 = 0;
				}
				if(D_00C3FB50 < 0x80)
					D_00C3FB50 ++;
			}
			//-- clamp cursor x,y --
			if(D_00C3FB58 > 320)
				D_00C3FB58 = 320;
			if(D_00C3FB58 < 0)
				D_00C3FB58 = 0;
			if(D_00C3FB5C > 240)
				D_00C3FB5C = 240;
			if(D_00C3FB5C < 0)
				D_00C3FB5C = 0;
		}
		//%%%%%%%%%%%%%%%%
		//%% devel mode %%
		if(D_00C3F890 == 0) {//else 005EE5BB
			//-- down -- "light top threshold"
			if(C_0041AB67(PAD_14))//test input mask[pressed]?
				D_00C3F754 -= 10;
			//-- up -- "light top threshold"
			if(C_0041AB67(PAD_12))//test input mask[pressed]?
				D_00C3F754 += 10;
			//-- left -- "light bottom threshold"
			if(C_0041AB67(PAD_15))//test input mask[pressed]?
				D_00C3F750 -= 10;
			//-- right -- "light bottom threshold"
			if(C_0041AB67(PAD_13))//test input mask[pressed]?
				D_00C3F750 += 10;
			//-- button 2[Ins] -- [unused]
			if(C_0041AB67(PAD_06))//test input mask[pressed]?
				D_00C3F908.f_08 -= 100;
			//-- button 4[NUMPAD +] -- [unused]
			if(C_0041AB67(PAD_04))//test input mask[pressed]?
				D_00C3F908.f_08 += 100;
			//-- button 1[Del] -- [unused]
			if(C_0041AB67(PAD_07))//test input mask[pressed]?
				D_00C3F908.f_00 -= 100;
			//-- button 3[Enter] -- [unused]
			if(C_0041AB67(PAD_05))//test input mask[pressed]?
				D_00C3F908.f_00 += 100;
			//-- button 6[PgDn] -- [unused]
			if(C_0041AB67(PAD_03))//test input mask[pressed]?
				D_00C3F908.f_04 -= 100;
			//-- button 8[End] -- [unused]
			if(C_0041AB67(PAD_01))//test input mask[pressed]?
				D_00C3F908.f_04 += 100;
			//-- button 5[PgUp] -- speed up
			if(C_0041AB67(PAD_02))//test input mask[pressed]?
				D_00C3F768 += 0x400;
			//-- button 7[Home] -- speed down
			if(C_0041AB67(PAD_00))//test input mask[pressed]?
				if(D_00C3F768 > 0x3ff)
					D_00C3F768 -= 0x400;
			//-- button 10[NUMPAD_5] -- speed 0
			if(C_0041AB67(PAD_11))//test input mask[pressed]?
				D_00C3F768 = 0;
		}
		//%%   %%
		//%%%%%%%
	}
	//-- button 10 -- pause?
	if(C_0041AB67(PAD_11))//test input mask[pressed]?
		D_00C5BF50 ++;
	else
		D_00C5BF50 = 0;
	//-- manage pause state ?--
	if(D_00C5BF50 == 1) {
		if(D_00C3F760 == 1)
			D_00C3F760 = 0;
		else
			D_00C3F760 = 1;
		//-- --
		C_005E94E5(0x03b/*beep*/);//play SFX
	}
}
