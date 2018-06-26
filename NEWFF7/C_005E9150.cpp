//coaster -- resources/sound?

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
char D_00C3F6F0;//current  channel for "sound related(3)"
short D_00C3F6F4;//last shoot score
//<moved>:int D_00C3F6F8 = D_0090147C * 32;//"sight" size
struct t_sound_related_24 D_00C3F700;
short D_00C3F724;//blink counter for "last shoot score"
struct SVECTOR D_00C3F728;//rotation for "score model"
char D_00C3F730;//"last shoot" render flag
class psxdata_c D_00C3F738;
/*<moved>:*/int D_00C3F6F8 = D_0090147C * 32;//"sight" size[moved because its initializers are after D_00C3F738's]
int D_00C3F74C;//score
int D_00C3F750,D_00C3F754;//light bottom/top thresholds
int D_00C3F758;
int D_00C3F75C;
char D_00C3F760;//pause mode
char D_00C3F764;
int D_00C3F768;//speed?
short D_00C3F76C;
int D_00C3F770;
char D_00C3F774;
int D_00C3F778;//position on track
int D_00C3F77C;
int D_00C3F780;
int D_00C3F784,D_00C3F788;//screen offset x,y?
////////////////////////////////////////
int D_00901410 = 0x7f;
int D_00901414 = 0x7f;
struct t_sound_related_24 *D_00901418 = &D_00C3F700;
//0090141C  00 00 00 00
int D_00901420[0x17] = {
	0x00A,0x018,0x02D,0x045,0x076,0x085,0x08E,0x098,
	0x0BF,0x107,0x10D,0x10E,0x10F,0x11E,0x166,0x177,
	0x195,0x21B,0x22B,0x22D,0x235,0x236,0x2A1
};
int D_0090147C = 2;//screen_ratio_x
int D_00901480 = 2;//screen_ratio_y
////////////////////////////////////////
//__005E9150//static initializer
//__005E915F//__inline constructor
//__005E9178//static cleaner
//__005E918A//calls the destructor
//__005E9199//static initializer
//__005E91A3//__inline constructor

void C_005E9319(void);//prepare psxdata_c/sounds

void C_005E91B5() {
	int i;//local_1

	D_00C3F758 = 0;
	D_00C3F760 = 0;//pause mode off
	C_005E9319();//prepare psxdata_c/sounds
	D_00C3F758 = 0x99;
	C_005ED8F0();//init track/background elements lists
	C_005EF1C0();//init this module
	C_005EE7F0();//init this module
	C_005EA8C0();//init this module
	C_005EAB70();//init this module
	C_005EEA50();//coaster.hit:init?
	for(i = 0; i < 0x64; i ++)
		D_00C5D0F0[i] = C_005EE8CF(i);//load/make model?
	D_00C3F75C = 0;
	D_00C3F778 = 0;
	D_00C3F768 = 10000;
	D_00C3F74C = 0;
	//-- light thresholds --
	D_00C3F750 = 0x28aa;
	D_00C3F754 = 0x37dc;
	//-- --
	D_00C3F764 = 0;
	D_00C3F774 = 0;
	D_00C3F76C = 0;
	D_00C3F730 = 0;
	D_00C3F728.f_00 = 0; D_00C3F728.f_02 = 0; D_00C3F728.f_04 = 0;
	D_00C3F6F0 = 0;
	D_00901410 = 0x7f;
	D_00901414 = 0x7f;
	D_00C3F77C = 0;
	D_00C3F780 = 0;
	D_00C3F724 = 0;
}

//release psxdata_c/sounds
void C_005E92D8() {
	int i;//local_1;

	for(i = 0x16; i >= 0; i --)
		C_00745DBB(D_00901420[i], 0xf);//sound:free SFX?
	D_00C3F738.clean();
}

//prepare psxdata_c/sounds
void C_005E9319() {
	struct t_aa0 *local_2;
	int i;//local_1

	local_2 = C_00676578();
	C_006900FC(C_00407851(), 0);//direct:change directory?
	C_00675511("coaster.lgp", ARCHIVE_09);//is_lib:open archive?
	//-- --
	D_00C3F738.init("xbinadr.bin", "xbin.bin");
	//-- cache sounds? --
	for(i = 0x16; i >= 0; i --)
		C_00745CF3(D_00901420[i], 0);//sound:load/prepare SFX?
}


//sound related(1)
void C_005E938D() {
	C_00742055(0x37, 0, 0x7f);//"MIDI play"

	D_00901418->f_00 = 0xa2;
	D_00901418->f_04[0] = 0;
	C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);

	D_00901418->f_00 = 0x2a;
	D_00901418->f_04[0] = 0x40;
	D_00901418->f_04[1] = 0x177;
	C_00740D80(D_00901418->f_00, D_00901418->f_04[0], D_00901418->f_04[1], 0, 0, 0, 0, 0, 0);
}

//sound related(2)
void C_005E9436() {
	D_00901418->f_00 = 0xc1;
	D_00901418->f_04[0] = 0xf0;
	D_00901418->f_04[1] = 0;
	C_00740D80(D_00901418->f_00, D_00901418->f_04[0], D_00901418->f_04[1], 0, 0, 0, 0, 0, 0);

	D_00901418->f_00 = 0xb9;
	D_00901418->f_04[0] = 0xf0;
	D_00901418->f_04[1] = 0;
	C_00740D80(D_00901418->f_00, D_00901418->f_04[0], D_00901418->f_04[1], 0, 0, 0, 0, 0, 0);
}

//sound related(3)
void C_005E94E5(short bp08) {
	(++ D_00C3F6F0) %= 2;
	if(D_00C3F6F0 == 0) {
		D_00901418->f_00 = 0xb0;
		D_00901418->f_04[0] = 0;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);

		D_00901418->f_00 = 0x28;
		D_00901418->f_04[0] = 0x40;
		D_00901418->f_04[1] = bp08;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], D_00901418->f_04[1], 0, 0, 0, 0, 0, 0);

		D_00901418->f_00 = 0xa0;
		D_00901418->f_04[0] = 0x7f;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);
	}
	if(D_00C3F6F0 == 1) {
		D_00901418->f_00 = 0xb1;
		D_00901418->f_04[0] = 0;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);

		D_00901418->f_00 = 0x29;
		D_00901418->f_04[0] = 0x40;
		D_00901418->f_04[1] = bp08;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], D_00901418->f_04[1], 0, 0, 0, 0, 0, 0);

		D_00901418->f_00 = 0xa1;
		D_00901418->f_04[0] = 0x7f;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);
	}
}

//sound related(4)
void C_005E96DA(short bp08) {
	if(D_00C3F770 == 0 && bp08 > 0) {
		D_00901418->f_00 = 0x2b;
		D_00901418->f_04[0] = 0x40;
		D_00901418->f_04[1] = 0x22b;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], D_00901418->f_04[1], 0, 0, 0, 0, 0, 0);
	}
	if(bp08 > 0) {
		D_00C3F780 = bp08;

		D_00901418->f_00 = 0xb3;
		D_00901418->f_04[0] = bp08;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);

		D_00C3F770 = bp08;
	} else {
		D_00901418->f_00 = 0x2b;
		D_00901418->f_04[0] = 0x40;
		D_00901418->f_04[1] = 0;
		C_00740D80(D_00901418->f_00, D_00901418->f_04[0], D_00901418->f_04[1], 0, 0, 0, 0, 0, 0);

		D_00C3F770 = 0;
	}
}

//sound related(5)
void C_005E9802() {
	D_00901418->f_00 = 0xa2;
	D_00901418->f_04[0] = D_00C3F77C;
	C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);

	D_00901418->f_00 = 0xa3;
	D_00901418->f_04[0] = D_00C3F780;
	C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);
}

//sound related(6)
void C_005E988B() {
	C_00742E2B();//"MIDI stop"

	D_00901418->f_00 = 0xb8;
	D_00901418->f_04[0] = 0;
	C_00740D80(D_00901418->f_00, D_00901418->f_04[0], 0, 0, 0, 0, 0, 0, 0);
}
