/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __COASTER_DATA_H__
#define __COASTER_DATA_H__

////////////////////////////////////////
struct t_coaster_LinkedList {//size 4
	/*00*/unsigned short wPrev;
	/*02*/unsigned short wNext;
};

struct t_coaster_ModelInfo {//size 0x14
	/*00*/short wNumTri;
	/*02*/short wNum___;//[unused]
	/*04*/struct SVECTOR f_04,f_0c;//some bounding info
};

struct t_coaster_unused_28 {//size 0x28
	/*00*/char __00[0x28];
};

struct t_coaster_Triangle {//size 0x24
	/*00*/struct SVECTOR f_00[3];
	/*18*/tRGBA f_18[3];
};

struct t_coaster_RenderInfo {//size 0x10
	/*00*/struct t_coaster_Triangle *pTriangles;
	/*04*/char __04[8];
	/*0c*/struct t_coaster_Model *pModel;
};

struct t_coaster_Model {//size 0x20
	/*00*/short f_00;//[unused]wNumTri + wNum___
	/*02*/short f_02;//[unused]set to 0
	/*04*/short wNumTri;
	/*06*/short wNum___;//[unused]
	/*08*/short f_08;//[unused]set to 0
	/*0a*/char __0a[2];//padding?
	/*0c*/struct t_coaster_Triangle *pTriangles;
	/*10*/struct t_coaster_unused_28 *p_________;//[unused]
	/*14*/short f_14,f_16;//[unused]left,right boundind?
	/*18*/short f_18,f_1a;//[unused]bottom, top boundind?
	/*1c*/char __1c[4];//could it be z-axis bounding?
};

struct t_coaster_Node {//size 0x38
	/*00*/struct t_coaster_Model *pModel;
	/*04*/struct MATRIX sMatrixWorld; char __22[2];
	/*24*/struct t_coaster_Node *pParentNode;
	/*28*/short wModelId;
	/*2a*/short wIndex;
	/*2c*/short wDepth;
	/*2e*/char __2e[2];
	/*30*/struct t_coaster_Node *pPrev;
	/*34*/struct t_coaster_Node *pNext;
};

struct t_coaster_ObjectState {//size 0xa0
	/*00*/int dwType;
	/*04*/int dwIsHit;
	/*08*/int dwModelId;
	/*0c*/int dwHP;
	/*10*/int dwMustInit;
	/*14*/int dwFrameCount;
	/*18*/int dwPathIndex;
	/*1c*/int dwSpeed;
	/*20*/char __20[8];
	/*28*/int f_28;
	/*2c*/int f_2c;
	/*30*/int f_30;
	/*34*/int f_34;
	/*38*/char __38[0x18];
	/*50*/int f_50[0x14];//some scratch memory?
};

struct t_coaster_GameObject {//size 0x13c
	/*000*/struct VECTOR sPos;//00C3FB68
	/*010*/char __010[8];//00C3FB78
	/*018*/struct SVECTOR sRot;//00C3FB80
	/*020*/char __020[8];//00C3FB88
	/*028*/struct t_coaster_ObjectState f_028;//00C3FB90
	/*0c8*/int dwPathLength;//00C3FC30
	/*0cc*/struct SVECTOR *pPath;//00C3FC34
	/*0d0*/char __0d0[4];//00C3FC38
	/*0d4*/struct t_coaster_Node *pNode;//00C3FC3C
	/*0d8*/short wObjIndex;//00C3FC40
	/*0da*/short wIsActive;//00C3FC42
	/*0dc*/struct SVECTOR sBoundingBox[8];//00C3FC44
	/*11c*/int aBoundingYX[8];//projected bounding box[(y<<16)|x]
};

class psxdata_c {//size 0x14
public:
	/*00*//*00C3F738*/void *pData;//"xbin.bin"
	/*04*//*00C3F73C*/int dwDataSize;
	/*08*//*00C3F740*/int dwPSXOffset;
	/*0c*//*00C3F744*/int *pOffset;//"xbinadr.bin"
	/*10*//*00C3F748*/int dwStatus;
	//-- --
	/*C_005EE620*/int init(const char *, const char *);
	/*C_005EE6CC*/void clean(void);
	__inline psxdata_c(void):pData(0),dwStatus(0) {}
	/*C_005EE730*/~psxdata_c(void);
	/*C_005EE743*/void *load(const char *, int *);
	//-- --
	__inline unsigned char *getStream_inline(int dwIndex/*bp08*/) {
		int dwOffset;
		
		dwOffset = this->pOffset[dwIndex];
		if(dwOffset >= this->dwDataSize)
			return 0;

		return (unsigned char *)this->pData + dwOffset;
	}
};

//renderer class?
class Class_coaster_D8 {//size 0xd8
private:
	/*00*/D3DMATRIX sD3DMatrixWorldView;
	/*40*/D3DMATRIX sD3DMatrixTransform;//world+projection
	/*80*/LPD3DMATRIX pD3DMatrixWorldView;
	/*84*/LPD3DMATRIX pD3DMatrixTransform;//[pointer]world+projection
	//-- for objects --
	/*88*/struct t_dx_sfx_e0 *f_88;
	/*8c*/struct t_dx_sfx_e0 *f_8c;
	/*90*/struct t_dx_sfx_xxx_08 *f_90;
	//-- for objects(transparent) --
	/*94*/struct t_dx_sfx_e0 *f_94;
	/*98*/struct t_dx_sfx_e0 *f_98;
	/*9c*/struct t_dx_sfx_xxx_08 *f_9c;
	//-- for tracks --
	/*a0*/struct t_dx_sfx_e0 *f_a0;
	/*a4*/struct t_dx_sfx_e0 *f_a4;
	/*a8*/struct t_dx_sfx_xxx_08 *f_a8;
	//-- for sight --
	/*ac*/struct t_dx_sfx_e0 *f_ac;
	//-- for beam --
	/*b0*/struct t_dx_sfx_e0 *f_b0;
	/*b4*/struct t_dx_sfx_e0 *f_b4[3];
	//-- for 2D infos --
	/*c0*/struct t_dx_sfx_e0 *f_c0;
	/*c4*/struct t_dx_sfx_e0 *f_c4;
	/*c8*/struct t_dx_sfx_e0 *f_c8;
	/*cc*/struct t_dx_sfx_e0 *f_cc;
	/*d0*/struct t_dx_sfx_e0 *f_d0;
	//-- for alpha quad --
	/*d4*/struct t_dx_sfx_e0 *f_d4;
	//-- --
public:
	Class_coaster_D8(void);//::005EF4D0
	~Class_coaster_D8(void);//::005EF728
	struct t_dx_sfx_e0 *C_005EF89D(int, int, const char *, int);

	void C_005EF95A(struct SVECTOR *, int *);//projection:cube?
	void C_005EF9CA(struct SVECTOR *, int *);//projection:triangle?
	void C_005EFA3A(struct t_coaster_RenderInfo *);//render object
	void C_005EFACA(struct t_coaster_RenderInfo *);//render object[for score]
	void C_005EFB5A(struct SVECTOR *, struct SVECTOR *);
	void C_005F0482(struct t_coaster_Triangle *);//render triangle[static]
	void C_005F04D7(struct t_coaster_Triangle *, struct t_dx_sfx_e0 *, struct t_dx_sfx_e0 *, struct t_dx_sfx_e0 *, struct t_dx_sfx_e0 *, struct t_dx_sfx_xxx_08 *, struct t_dx_sfx_xxx_08 *);//render triangle[most of the 3D models]
	void C_005F09C4(void);//render "sight"
	void C_005F0C81(void);//render "shoot beams"
	void C_005F15C7(void);//render "shoot gauge"
	void C_005F1838(void);//render "waku"
	void C_005F1A71(void);//render "status box"
	void C_005F1CB5(void);//render "pause"
	void C_005F1F00(void);//render "score"
	void C_005F2119(int, short, short, short);//render number
	void C_005F2417(unsigned char );//render alpha quad
	void C_005F2639(struct SVECTOR *, LPD3DMATRIX, struct tVECTOR_F4 *);//vector x matrix + normalize?
	int C_005F26EB(struct SVECTOR *, LPD3DMATRIX, struct t_g_drv_0c *);//vector x matrix?
	float C_005F2759(struct SVECTOR *, LPD3DMATRIX);//dot product with matrix column 3
	void C_005F27BF(struct MATRIX *);//set world matrix
	float C_005F2838(float);//get light ratio
	unsigned C_005F2897(tRGBA *, float);//apply light ratio to color(from tRGBA to tBGRA)?
	void C_005F2924(void);//"refresh" graphics
};
////////////////////////////////////////
extern void C_005E91B5(void);
extern void C_005E92D8(void);//release psxdata_c/sounds
extern void C_005E938D(void);//start music/rail sound
extern void C_005E9436(void);//fade out music/sfx
extern void C_005E94E5(short);//play SFX
extern void C_005E96DA(short);//set laser SFX volume
extern void C_005E9802(void);//refresh laser/rail SFX volumes
extern void C_005E988B(void);//stop music/sfx
extern void C_005E98E0(void);//coaster:begin
extern void C_005E99FB(struct t_coaster_Node *, struct t_coaster_GameObject *);//render objects + hit test
extern void C_005E9CB5(struct t_coaster_Node *);//render "car"/compute "beams" projection?
extern void C_005E9E7E(void);//render background
extern void C_005E9F33(void);//render track
extern void C_005E9FB3(struct MATRIX *);//update transform matrix for track
extern void C_005E9FED(struct MATRIX *, struct MATRIX *, struct MATRIX *);
extern struct MATRIX *C_005EA099(struct SVECTOR *, struct MATRIX *);//"RotMatrixZXY"?
extern void C_005EA194(int, int, struct VECTOR *, struct SVECTOR *);//compute camera pos/rot vectors?
extern void C_005EA5FD(short, int, int, int);//render "last shoot score"
extern void C_005EA77E(unsigned char);//draw alpha quad
extern void C_005EA79B(void);//render "sight"
extern void C_005EA7B4(void);//refresh "shoot beams"
extern void C_005EA7D0(void);//render 2D infos
extern void C_005EA80A(void);//coaster:in pause
extern void C_005EA82E(void);//coaster:"refresh" graphics
extern void C_005EA847(void);//coaster:end
extern void C_005EA8C0(void);//init this module
extern void C_005EA973(void);//track matrix related
extern void C_005EAAF3(int);//prepare data from stream #4?
extern void C_005EAB70(void);//init this module
extern void C_005EB5CF(void);//refresh game objects?
extern void C_005ED8F0(void);//init track/background lists
extern void C_005EDC59(int);//prepare track/background lists
extern void C_005EDD82(void);//"clean" track/background lists
extern void C_005EE150(void);//refresh input for coaster
extern void C_005EE7F0(void);//(3d models)init this module
extern struct t_coaster_Model *C_005EE8CF(int);//load/make model?
extern void C_005EEA50(void);//coaster.hit:init?
extern int C_005EECB5(struct VECTOR *);//coaster.hit:check some direction?
extern void C_005EF1C0(void);//init this module
extern struct t_coaster_Node *C_005EF31E(short, struct t_coaster_Node *, int, int, int, short, short, short);//allocate "Node"
extern void C_005EF3BF(struct t_coaster_Node *);//release "Node"
////////////////////////////////////////
extern int D_0090147C;
extern int D_00901480;
extern int D_009014A8;

extern short D_00C3F6F4;//last shoot score
extern int D_00C3F6F8;
extern short D_00C3F724;//blink counter for "last shoot score"
extern struct SVECTOR D_00C3F728;//rotation for "score model"
extern char D_00C3F730;
extern psxdata_c D_00C3F738;
extern int D_00C3F74C;//score
extern int D_00C3F750;
extern int D_00C3F754;
extern int D_00C3F75C;
extern char D_00C3F760;//pause mode
extern char D_00C3F764;
extern int D_00C3F768;
extern short D_00C3F76C;
extern char D_00C3F774;
extern int D_00C3F778;
extern int D_00C3F77C;
extern int D_00C3F780;
extern int D_00C3F784;
extern int D_00C3F788;
extern char D_00C3F890;
extern int D_00C3F894;
extern struct MATRIX D_00C3F8A0;
extern unsigned char *D_00C3F8D0;
extern struct VECTOR D_00C3F8D8;
extern struct VECTOR D_00C3F8E8;
extern struct VECTOR D_00C3F908;
extern short D_00C3F918;
extern int D_00C3F91C;
extern short D_00C3F920;
extern short D_00C3F924;
extern short D_00C3F928;
extern char D_00C3FA70;
extern char D_00C3FA74;
extern short D_00C3FA78;
extern short D_00C3FA7C;
extern short D_00C3FB48;
extern short D_00C3FB4C;
extern short D_00C3FB50;
extern short D_00C3FB58,D_00C3FB5C;//cursor X,Y

extern char D_00C476DC;
extern struct t_coaster_LinkedList D_00C476F0[/*0x2328*/];//track elements
extern unsigned short D_00C5039C;

extern unsigned short D_00C503A4;
extern unsigned short D_00C503A8;
extern struct t_coaster_LinkedList D_00C503B0[/*0x2ee0*/];//background elements
extern unsigned short D_00C5BF44;
extern struct t_coaster_ModelInfo *D_00C5D0E4;
extern struct t_coaster_Model *D_00C5D0F0[];

extern struct t_coaster_Node D_00C60150;//TOP NODE

#endif
