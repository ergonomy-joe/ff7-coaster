/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- 3d models?

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
struct t_coaster_Quad *D_00C5BF58;//from stream 0x10(null)
struct t_coaster_Model D_00C5BF60[0x8c];//check
int D_00C5D0E0;//read triangles index
struct t_coaster_ModelInfo *D_00C5D0E4;//from stream 1
struct t_coaster_Triangle *D_00C5D0E8;//from stream 0xa
int D_00C5D0EC;
struct t_coaster_Model *D_00C5D0F0[0x8c];//or is it 0x64?
int D_00C5D320;//read quads index
////////////////////////////////////////
//(3d models)init this module
void C_005EE7F0() {
	D_00C5D0E0 = 0;
	D_00C5D320 = 0;
	D_00C5D0EC = 0;
	D_00C5D0E8 = (struct t_coaster_Triangle *)D_00C3F738.getStream_inline(0xa);
	D_00C5BF58 = (struct t_coaster_Quad *)D_00C3F738.getStream_inline(0x10);
	D_00C5D0E4 = (struct t_coaster_ModelInfo *)D_00C3F738.getStream_inline(1);
}

struct t_coaster_Model *C_005EE9C2(void);//allocate model?
struct t_coaster_Triangle *C_005EE9EC(int);//read triangles?
struct t_coaster_Quad *C_005EEA19(int);//read quads?

//load/make model?
struct t_coaster_Model *C_005EE8CF(int wModelId/*bp08*/) {
	struct {
		struct t_coaster_Model *pModel;//local_3
		int dwNumQua;//local_2
		int dwNumTri;//local_1
	}lolo;

	lolo.pModel = C_005EE9C2();//allocate model?
	lolo.dwNumTri = D_00C5D0E4[wModelId].wNumTri;
	lolo.dwNumQua = D_00C5D0E4[wModelId].wNumQua;
	//-- those are unused --
	//-- sBoundingBox is generated with same info --
	lolo.pModel->f_16 = D_00C5D0E4[wModelId].f_04.vx; lolo.pModel->f_14 = D_00C5D0E4[wModelId].f_0c.vx;
//	lolo.pModel->f___ = D_00C5D0E4[wModelId].f_04.vy; lolo.pModel->f___ = D_00C5D0E4[wModelId].f_0c.vy;//??
	lolo.pModel->f_1a = D_00C5D0E4[wModelId].f_04.vz; lolo.pModel->f_18 = D_00C5D0E4[wModelId].f_0c.vz;
	//-- --
	lolo.pModel->f_02 = 0;
	lolo.pModel->wNumTri = lolo.dwNumTri;
	lolo.pModel->wNumQua = lolo.dwNumQua;
	lolo.pModel->f_08 = 0;
	lolo.pModel->wNumPoly = lolo.dwNumTri + lolo.dwNumQua;
	lolo.pModel->pTriangles = C_005EE9EC(lolo.dwNumTri);//read triangles?
	lolo.pModel->pQuads = C_005EEA19(lolo.dwNumQua);//read quads?

	return lolo.pModel;
}

//allocate model?
struct t_coaster_Model *C_005EE9C2() {
	struct t_coaster_Model *local_1;

	local_1 = &(D_00C5BF60[D_00C5D0EC]);
	D_00C5D0EC ++;

	return local_1;
}

//read triangles?
struct t_coaster_Triangle *C_005EE9EC(int dwNumTri/*bp08*/) {
	struct t_coaster_Triangle *local_1;

	local_1 = D_00C5D0E8 + D_00C5D0E0;
	D_00C5D0E0 += dwNumTri;

	return local_1;
}

//read quads?
struct t_coaster_Quad *C_005EEA19(int dwNumQua/*bp08*/) {
	struct t_coaster_Quad *local_1;

	local_1 = D_00C5BF58 + D_00C5D320;
	D_00C5D320 += dwNumQua;

	return local_1;
}
