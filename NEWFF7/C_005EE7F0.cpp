/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- 3d models?

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
struct t_coaster_unused_28 *D_00C5BF58;//always 0?
struct t_coaster_Model D_00C5BF60[0x8c];//check
int D_00C5D0E0;//read triangles index
struct t_coaster_ModelInfo *D_00C5D0E4;
struct t_coaster_Triangle *D_00C5D0E8;
int D_00C5D0EC;
struct t_coaster_Model *D_00C5D0F0[0x8c];//or is it 0x64?
int D_00C5D320;//read ______ index
////////////////////////////////////////
//init this module
void C_005EE7F0() {
	D_00C5D0E0 = 0;
	D_00C5D320 = 0;
	D_00C5D0EC = 0;
	D_00C5D0E8 = (struct t_coaster_Triangle *)D_00C3F738.getStream_inline(0xa);
	D_00C5BF58 = (struct t_coaster_unused_28 *)D_00C3F738.getStream_inline(0x10);
	D_00C5D0E4 = (struct t_coaster_ModelInfo *)D_00C3F738.getStream_inline(1);
}

struct t_coaster_Model *C_005EE9C2(void);//allocate model?
struct t_coaster_Triangle *C_005EE9EC(int);//read triangles?
struct t_coaster_unused_28 *C_005EEA19(int);//read ______?

//load/make model?
struct t_coaster_Model *C_005EE8CF(int wModelId/*bp08*/) {
	struct {
		struct t_coaster_Model *pModel;//local_3
		int dwNum___;//local_2
		int dwNumTri;//local_1
	}lolo;

	lolo.pModel = C_005EE9C2();//allocate model?
	lolo.dwNumTri = D_00C5D0E4[wModelId].wNumTri;
	lolo.dwNum___ = D_00C5D0E4[wModelId].wNum___;
	//-- those are unused --
	//-- sBoundingBox is generated with same info --
	lolo.pModel->f_16 = D_00C5D0E4[wModelId].f_04.f_00; lolo.pModel->f_14 = D_00C5D0E4[wModelId].f_0c.f_00;
	lolo.pModel->f_1a = D_00C5D0E4[wModelId].f_04.f_04; lolo.pModel->f_18 = D_00C5D0E4[wModelId].f_0c.f_04;
//	lolo.pModel->f_1e = D_00C5D0E4[wModelId].f_04.f_08; lolo.pModel->f_1c = D_00C5D0E4[wModelId].f_0c.f_08;//??
	//-- --
	lolo.pModel->f_02 = 0;
	lolo.pModel->wNumTri = lolo.dwNumTri;
	lolo.pModel->wNum___ = lolo.dwNum___;
	lolo.pModel->f_08 = 0;
	lolo.pModel->f_00 = lolo.dwNumTri + lolo.dwNum___;
	lolo.pModel->pTriangles = C_005EE9EC(lolo.dwNumTri);//read triangles?
	lolo.pModel->p_________ = C_005EEA19(lolo.dwNum___);//read ______?

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
struct t_coaster_Triangle *C_005EE9EC(int bp08) {
	struct t_coaster_Triangle *local_1;

	local_1 = D_00C5D0E8 + D_00C5D0E0;
	D_00C5D0E0 += bp08;

	return local_1;
}

//read ______?
struct t_coaster_unused_28 *C_005EEA19(int bp08) {
	struct t_coaster_unused_28 *local_1;

	local_1 = D_00C5BF58 + D_00C5D320;
	D_00C5D320 += bp08;

	return local_1;
}
