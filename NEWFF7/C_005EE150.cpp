//coaster -- input module

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
int D_00C5BF48;//(unused)
int D_00C5BF4C;//direction(unused)
int D_00C5BF50;
int D_00C5BF54;
////////////////////////////////////////
//refresh input for coaster
void C_005EE150() {
	if(D_00C3F760 == 0) {//skip if paused//else 005EE5BB
		D_00C5BF4C = 0;
		D_00C5BF48 = 0;
		//-- left --
		if(C_0041AB67(0x00008000))//test input mask[pressed]?
			D_00C5BF4C = 4;
		//-- right --
		if(C_0041AB67(0x00002000))//test input mask[pressed]?
			D_00C5BF4C = 6;
		//-- up --
		if(C_0041AB67(0x00001000)) {//test input mask[pressed]?
			D_00C5BF4C = 8;
			//-- up left --
			if(C_0041AB67(0x00008000))//test input mask[pressed]?
				D_00C5BF4C = 7;
			//-- up right --
			if(C_0041AB67(0x00002000))//test input mask[pressed]?
				D_00C5BF4C = 9;
		}
		//-- down --
		if(C_0041AB67(0x00004000)) {//test input mask[pressed]?
			D_00C5BF4C = 2;
			//-- down left--
			if(C_0041AB67(0x00008000))//test input mask[pressed]?
				D_00C5BF4C = 1;
			//-- down right --
			if(C_0041AB67(0x00002000))//test input mask[pressed]?
				D_00C5BF4C = 3;
		}
		//%%%%%%%%%%%%%%%%%%
		//%% release mode %%
		if(D_00C3F890 == 1) {//else 005EE41D
			//-- down --
			if(C_0041AB67(0x00004000))//test input mask[pressed]?
				D_00C3FB5C += 0xa;
			//-- up --
			if(C_0041AB67(0x00001000))//test input mask[pressed]?
				D_00C3FB5C -= 0xa;
			//-- left --
			if(C_0041AB67(0x00008000))//test input mask[pressed]?
				D_00C3FB58 -= 0xa;
			//-- right --
			if(C_0041AB67(0x00002000))//test input mask[pressed]?
				D_00C3FB58 += 0xa;
			//-- button 3 -- shoot
			D_00C3FA70 = 0;
			if(C_0041AB67(0x00000020)) {//test input mask[pressed]?//else 005EE388
				//-- shooting --
				C_005E96DA(D_00C3FB50);//sound related(4)
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
					C_005E96DA(0);//sound related(4)
					D_00C5BF54 = 0;
				}
				if(D_00C3FB50 < 0x80)
					D_00C3FB50 ++;
			}
			//-- clamp cursor x,y --
			if(D_00C3FB58 > 0x140)
				D_00C3FB58 = 0x140;
			if(D_00C3FB58 < 0)
				D_00C3FB58 = 0;
			if(D_00C3FB5C > 0xf0)
				D_00C3FB5C = 0xf0;
			if(D_00C3FB5C < 0)
				D_00C3FB5C = 0;
		}
		//%%%%%%%%%%%%%%%%
		//%% devel mode %%
		if(D_00C3F890 == 0) {//else 005EE5BB
			//-- down --
			if(C_0041AB67(0x00004000))//test input mask[pressed]?
				D_00C3F754 -= 0xa;
			//-- up --
			if(C_0041AB67(0x00001000))//test input mask[pressed]?
				D_00C3F754 += 0xa;
			//-- left --
			if(C_0041AB67(0x00008000))//test input mask[pressed]?
				D_00C3F750 -= 0xa;
			//-- right --
			if(C_0041AB67(0x00002000))//test input mask[pressed]?
				D_00C3F750 += 0xa;
			//-- button 2 --
			if(C_0041AB67(0x00000040))//test input mask[pressed]?
				D_00C3F910 -= 0x64;
			//-- button 4 --
			if(C_0041AB67(0x00000010))//test input mask[pressed]?
				D_00C3F910 += 0x64;
			//-- button 1 --
			if(C_0041AB67(0x00000080))//test input mask[pressed]?
				D_00C3F908 -= 0x64;
			//-- button 3 --
			if(C_0041AB67(0x00000020))//test input mask[pressed]?
				D_00C3F908 += 0x64;
			//-- button 6 --
			if(C_0041AB67(0x00000008))//test input mask[pressed]?
				D_00C3F90C -= 0x64;
			//-- button 8 --
			if(C_0041AB67(0x00000002))//test input mask[pressed]?
				D_00C3F90C += 0x64;
			//-- button 5 -- speed up
			if(C_0041AB67(0x00000004))//test input mask[pressed]?
				D_00C3F768 += 0x400;
			//-- button 7 -- speed down
			if(C_0041AB67(0x00000001))//test input mask[pressed]?
				if(D_00C3F768 > 0x3ff)
					D_00C3F768 -= 0x400;
			//-- button 0xa -- speed 0
			if(C_0041AB67(0x00000800))//test input mask[pressed]?
				D_00C3F768 = 0;
		}
		//%%   %%
		//%%%%%%%
	}
	//-- button 10 -- pause?
	if(C_0041AB67(0x00000800))//test input mask[pressed]?
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
		C_005E94E5(0x3b);//sound related(3)
	}
}
