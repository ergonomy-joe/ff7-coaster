/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- Class_coaster_D8

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
Class_coaster_D8::Class_coaster_D8() {//::005EF4D0
	//local_1 this
	//-- for 2D infos --
	this->f_c0 = this->C_005EF89D(DX_SFX_TYPE_0C, 4, "score.tim", SWRENDERFLAG_00000080);
	this->f_c4 = this->C_005EF89D(DX_SFX_TYPE_0C, 4, "co1.tim", SWRENDERFLAG_00000080);
	this->f_cc = this->C_005EF89D(DX_SFX_TYPE_0A, 4, 0, 0);
	this->f_d0 = this->C_005EF89D(DX_SFX_TYPE_0C, 4, "waku2.tim", SWRENDERFLAG_00000080);
	this->f_c8 = this->C_005EF89D(DX_SFX_TYPE_0C, 4, "pause.tim", SWRENDERFLAG_00000080);
	//-- for objects --
	this->f_88 = this->C_005EF89D(DX_SFX_TYPE_02, 4, 0, 0);//not clipped
	this->f_8c = this->C_005EF89D(DX_SFX_TYPE_03, 4, 0, 0);//partially clipped
	this->f_90 = new t_dx_sfx_xxx_08;
	//-- for objects(transparent) --
	this->f_94 = this->C_005EF89D(DX_SFX_TYPE_02, 1, 0, 0);//not clipped
	this->f_98 = this->C_005EF89D(DX_SFX_TYPE_03, 1, 0, 0);//partially clipped
	this->f_9c = new t_dx_sfx_xxx_08;
	//-- for tracks --
	this->f_a0 = this->C_005EF89D(DX_SFX_TYPE_0C, 4, "rail.tim", 0);//not clipped
	this->f_a4 = this->C_005EF89D(DX_SFX_TYPE_0D, 4, "rail.tim", 0);//partially clipped
	this->f_a8 = new t_dx_sfx_xxx_08;
	//-- for sight --
	this->f_ac = this->C_005EF89D(DX_SFX_TYPE_0C, 4, "sight.tim", SWRENDERFLAG_00000080);
	//-- for beam --
	this->f_b4[0] = this->C_005EF89D(DX_SFX_TYPE_0C, 1, "beam1.tim", 0);
	this->f_b4[1] = this->C_005EF89D(DX_SFX_TYPE_0C, 1, "beam2.tim", 0);
	this->f_b4[2] = this->C_005EF89D(DX_SFX_TYPE_0C, 1, "beam3.tim", 0);
	this->f_b0 = this->f_b4[0];
	//-- for alpha quad --
	this->f_d4 = this->C_005EF89D(DX_SFX_TYPE_08, 0, 0, SWRENDERFLAG_00004000);
	//-- --
	this->pD3DMatrixWorldView = &(this->sD3DMatrixWorldView);
	this->pD3DMatrixTransform = &(this->sD3DMatrixTransform);
	fast_MatrixSetIdentity(this->pD3DMatrixWorldView);
	fast_MatrixSetIdentity(this->pD3DMatrixTransform);
}

Class_coaster_D8::~Class_coaster_D8() {//::005EF728
	//local_4 this
	//-- for objects --
	C_00670FD3(this->f_88);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_8c);//dx_sfx:release "struct t_dx_sfx_e0 *"
	//-- for objects(transparent) --
	C_00670FD3(this->f_94);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_98);//dx_sfx:release "struct t_dx_sfx_e0 *"
	//-- for tracks --
	C_00670FD3(this->f_a0);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_a4);//dx_sfx:release "struct t_dx_sfx_e0 *"
	//-- for sight --
	C_00670FD3(this->f_ac);//dx_sfx:release "struct t_dx_sfx_e0 *"
	//-- for beam --
	C_00670FD3(this->f_b4[0]);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_b4[1]);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_b4[2]);//dx_sfx:release "struct t_dx_sfx_e0 *"
	//-- for 2D infos --
	C_00670FD3(this->f_c0);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_c4);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_cc);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_d0);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_c8);//dx_sfx:release "struct t_dx_sfx_e0 *"
	//-- for alpha quad --
	C_00670FD3(this->f_d4);//dx_sfx:release "struct t_dx_sfx_e0 *"
	//-- --
	delete this->f_90;
	delete this->f_9c;
	delete this->f_a8;
}

struct t_dx_sfx_e0 *Class_coaster_D8::C_005EF89D(int dwPolygonType/*bp08*/, int dwBlendMode/*bp0c*/, const char *bp10/*texture*/, int dwSWRenderFlags/*bp14*/) {
	struct {
		//local_32 this
		struct t_rsd_74 local_31;
		struct t_aa0 *local_2;
		struct t_dx_sfx_e0 *local_1;
	}lolo;

	lolo.local_2 = C_00676578();
	lolo.local_1 = 0;
	memset(&lolo.local_31, 0, sizeof(struct t_rsd_74));
	C_006745E6(dwBlendMode, &lolo.local_31);//rsd:init with blend mode?
	lolo.local_31.szDir = C_00407851();//minigame path(4)?
	if(dwBlendMode != 4)
		C_00674659(dwBlendMode, &lolo.local_31);//rsd:set blend mode?
	lolo.local_31.dwUsePSXResources = 0;
	lolo.local_31.f_40.dwUseArchive = 1;
	lolo.local_31.f_40.dwArchiveId = ARCHIVE_09;
	lolo.local_31.f_40.f_0c = 0;
	lolo.local_31.f_70 |= dwSWRenderFlags;
	lolo.local_1 = C_006710AC(1, dwPolygonType, &lolo.local_31, bp10, lolo.local_2->f_910);//dx_sfx:alloc/create?
	if(lolo.local_1)
		lolo.local_1->f_34 |= BIT(1);//LH/RH related?

	return lolo.local_1;
}

//projection:cube?
void Class_coaster_D8::C_005EF95A(struct SVECTOR *bp08, int *pYX/*bp0c*/) {
	struct {
		//local_6 this
		struct tVECTOR_F4 local_5;
		int i;//local_1
	}lolo;

	for(lolo.i = 0; lolo.i < 8; lolo.i ++) {
		this->C_005F2639(&(bp08[lolo.i]), this->pD3DMatrixTransform, &lolo.local_5);//vector x transform + normalize
		pYX[lolo.i] = ((int)lolo.local_5.y << 16) | ((int)lolo.local_5.x & 0xffff);
	}//end for
}

//projection:triangle?
void Class_coaster_D8::C_005EF9CA(struct SVECTOR *bp08, int *pYX/*bp0c*/) {
	struct {
		//local_6 this
		struct tVECTOR_F4 local_5;
		int i;//local_1
	}lolo;

	for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
		this->C_005F2639(&(bp08[lolo.i]), this->pD3DMatrixTransform, &lolo.local_5);//vector x transform + normalize
		pYX[lolo.i] = ((int)lolo.local_5.y << 16) | ((int)lolo.local_5.x & 0xffff);
	}//end for
}

//render object
void Class_coaster_D8::C_005EFA3A(struct t_coaster_RenderInfo *bp08) {
	struct {
		//local_4 this
		int i;//local_3
		DECL_short(wNumTri);//local_2
		struct t_coaster_Triangle *pTriangle;//local_1
	}lolo;

	lolo.pTriangle = bp08->pTriangles;
	lolo.wNumTri = bp08->pModel->wNumTri;
	for(lolo.i = lolo.wNumTri; lolo.i > 0; lolo.i --) {
		this->C_005F04D7(lolo.pTriangle, this->f_88, this->f_8c, this->f_94, this->f_98, this->f_90, this->f_9c);//render 1 triangle
		lolo.pTriangle ++;
	}//end for
}

//render object[for score]
void Class_coaster_D8::C_005EFACA(struct t_coaster_RenderInfo *bp08) {
	struct {
		//local_4 this
		int i;//local_3
		DECL_short(wNumTri);//local_2
		struct t_coaster_Triangle *pTriangle;//local_1
	}lolo;

	lolo.pTriangle = bp08->pTriangles;
	lolo.wNumTri = bp08->pModel->wNumTri;
	for(lolo.i = lolo.wNumTri; lolo.i > 0; lolo.i --) {
		this->C_005F04D7(lolo.pTriangle, this->f_88, this->f_8c, this->f_94, this->f_98, this->f_90, this->f_9c);//render 1 triangle
		lolo.pTriangle ++;
	}//end for
}

//u,v related
float D_00901550[4][2] = {
	{1.0f,0.0f},
	{1.0f,1.0f},
	{0.0f,0.0f},
	{0.0f,1.0f}
};
float D_00901570[4][2] = {
	{0.0f,0.0f},
	{0.0f,1.0f},
	{1.0f,0.0f},
	{1.0f,1.0f}
};

//render track element
void Class_coaster_D8::C_005EFB5A(struct SVECTOR *pTrackLeft/*bp08*/, struct SVECTOR *pTrackRight/*bp0c*/) {
	struct {
		//local_55 this
		int i_bis;//local_54
		struct t_dx_sfx_84 *local_53;
		struct t_dx_rend_vertex_20 *local_52[4];
		struct t_dx_rend_vertex_20 *local_48[4];
		struct tVECTOR_F4 aVert[4];//local_44
		float fDotProduct;//local_28
		int dwLight;//local_27
		float fLight;//local_26
		float (*pUV)[2];//local_25
		unsigned aColor[4];//local_24
		int dwHas1VertexIn;//local_20
		int i;//local_19
		struct SVECTOR *local_18[4];//bp_48
		D3DVECTOR aClipVert[4];//local_14
		int dwHas1VertexOut;//local_2
		unsigned dwSpecular;//local_1
	}lolo;

	lolo.dwSpecular = 0xffffffff;
	lolo.pUV = (0)?D_00901550:D_00901570;
	lolo.dwHas1VertexOut = 0;
	lolo.dwHas1VertexIn = 0;
	lolo.local_18[0] = &(pTrackLeft[0]);
	lolo.local_18[1] = &(pTrackRight[1]);
	lolo.local_18[2] = &(pTrackLeft[8]);
	lolo.local_18[3] = &(pTrackRight[9]);
	for(lolo.i = 0; lolo.i < 4; lolo.i ++) {
		lolo.fDotProduct = this->C_005F2759(lolo.local_18[lolo.i], this->pD3DMatrixWorldView);//dot product with matrix column 3
		if(lolo.fDotProduct < 0)
			lolo.dwHas1VertexOut = 1;
		if(lolo.fDotProduct > 0)
			lolo.dwHas1VertexIn = 1;
		lolo.fLight = this->C_005F2838(lolo.fDotProduct);//get light ratio
		lolo.dwLight = (int)(lolo.fLight * 255.0f);
		lolo.aColor[lolo.i] = (0xff << 24) | ((lolo.dwLight << 16)) | (lolo.dwLight << 8) | lolo.dwLight;
	}//end for
	if(lolo.dwHas1VertexIn) {//else 005F047B
		if(lolo.dwHas1VertexOut == 0) {//else 005F0189
			//-- not clipped --
			C_0066E272(2, this->f_a0);
			this->C_005F2639(&(pTrackLeft[0]), this->pD3DMatrixTransform, &(lolo.aVert[3]));//vector x transform + normalize
			this->C_005F2639(&(pTrackRight[1]), this->pD3DMatrixTransform, &(lolo.aVert[2]));//vector x transform + normalize
			this->C_005F2639(&(pTrackLeft[8]), this->pD3DMatrixTransform, &(lolo.aVert[1]));//vector x transform + normalize
			this->C_005F2639(&(pTrackRight[9]), this->pD3DMatrixTransform, &(lolo.aVert[0]));//vector x transform + normalize
			MK_VERTEX(&(this->f_a0->f_70.asVertex[0]), lolo.local_48[3], lolo.aVert[3].x, lolo.aVert[3].y, lolo.aVert[3].z, lolo.aVert[3].w, lolo.aColor[0], lolo.dwSpecular, D_00901550[0][0], D_00901550[0][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[2]), lolo.local_48[2], lolo.aVert[2].x, lolo.aVert[2].y, lolo.aVert[2].z, lolo.aVert[2].w, lolo.aColor[1], lolo.dwSpecular, D_00901550[1][0], D_00901550[1][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[1]), lolo.local_48[1], lolo.aVert[1].x, lolo.aVert[1].y, lolo.aVert[1].z, lolo.aVert[1].w, lolo.aColor[2], lolo.dwSpecular, D_00901550[2][0], D_00901550[2][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[3]), lolo.local_48[0], lolo.aVert[0].x, lolo.aVert[0].y, lolo.aVert[0].z, lolo.aVert[0].w, lolo.aColor[3], lolo.dwSpecular, D_00901550[3][0], D_00901550[3][1]);
			this->f_a0->f_70.asUnsignedChar += this->f_a0->f_40;
			MK_VERTEX(&(this->f_a0->f_70.asVertex[0]), lolo.local_52[3], lolo.aVert[3].x, lolo.aVert[3].y, lolo.aVert[3].z, lolo.aVert[3].w, lolo.aColor[0], lolo.dwSpecular, lolo.pUV[0][0], lolo.pUV[0][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[1]), lolo.local_52[2], lolo.aVert[2].x, lolo.aVert[2].y, lolo.aVert[2].z, lolo.aVert[2].w, lolo.aColor[1], lolo.dwSpecular, lolo.pUV[1][0], lolo.pUV[1][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[2]), lolo.local_52[1], lolo.aVert[1].x, lolo.aVert[1].y, lolo.aVert[1].z, lolo.aVert[1].w, lolo.aColor[2], lolo.dwSpecular, lolo.pUV[2][0], lolo.pUV[2][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[3]), lolo.local_52[0], lolo.aVert[0].x, lolo.aVert[0].y, lolo.aVert[0].z, lolo.aVert[0].w, lolo.aColor[3], lolo.dwSpecular, lolo.pUV[3][0], lolo.pUV[3][1]);
			//goto 005F047B
		} else {
			//-- partially clipped --
			lolo.local_53 = 0;
			this->C_005F26EB(&(pTrackLeft[0]), this->pD3DMatrixWorldView, &(lolo.aClipVert[0]));//vector x matrix(rot|trans)
			this->C_005F26EB(&(pTrackRight[1]), this->pD3DMatrixWorldView, &(lolo.aClipVert[1]));//vector x matrix(rot|trans)
			this->C_005F26EB(&(pTrackLeft[8]), this->pD3DMatrixWorldView, &(lolo.aClipVert[2]));//vector x matrix(rot|trans)
			this->C_005F26EB(&(pTrackRight[9]), this->pD3DMatrixWorldView, &(lolo.aClipVert[3]));//vector x matrix(rot|trans)
			//-- --
			C_00672C61(this->f_a8, this->f_a4);//dx_sfx:start quad/triangle(2)?
			fast_MatrixSetIdentity(this->f_a8->f_00);
			lolo.local_53 = this->f_a8->f_04;
			for(lolo.i = 0; lolo.i < 4; lolo.i ++) {
				lolo.local_53->f_0c[lolo.i].x = lolo.aClipVert[lolo.i].x;
				lolo.local_53->f_0c[lolo.i].y = lolo.aClipVert[lolo.i].y;
				lolo.local_53->f_0c[lolo.i].z = lolo.aClipVert[lolo.i].z;
				lolo.local_53->f_5c[lolo.i].bgra = lolo.aColor[lolo.i];
				lolo.local_53->f_6c[lolo.i] = 0.5f;
				lolo.local_53->f_3c[lolo.i].f_00 = lolo.pUV[lolo.i][0];
				lolo.local_53->f_3c[lolo.i].f_04 = lolo.pUV[lolo.i][1];
			}//end for
			//-- --
			C_00672C61(this->f_a8, this->f_a4);//dx_sfx:start quad/triangle(2)?
			fast_MatrixSetIdentity(this->f_a8->f_00);
			lolo.local_53 = this->f_a8->f_04;
			for(lolo.i = 0; lolo.i < 4; lolo.i ++) {
				//-- --
				lolo.i_bis = lolo.i;
				if(lolo.i == 1)
					lolo.i_bis = 2;
				else if(lolo.i == 2)
					lolo.i_bis = 1;
				//-- --
				lolo.local_53->f_0c[lolo.i_bis].x = lolo.aClipVert[lolo.i].x;
				lolo.local_53->f_0c[lolo.i_bis].y = lolo.aClipVert[lolo.i].y;
				lolo.local_53->f_0c[lolo.i_bis].z = lolo.aClipVert[lolo.i].z;
				lolo.local_53->f_5c[lolo.i_bis].bgra = lolo.aColor[lolo.i];
				lolo.local_53->f_6c[lolo.i_bis] = 0.5f;
				lolo.local_53->f_3c[lolo.i_bis].f_00 = D_00901550[lolo.i][0];
				lolo.local_53->f_3c[lolo.i_bis].f_04 = D_00901550[lolo.i][1];
			}//end for
		}
	}
}

//render 1 triangle(static objects)
void Class_coaster_D8::C_005F0482(struct t_coaster_Triangle *pTriangle/*bp08*/) {
	this->C_005F04D7(pTriangle, this->f_88, this->f_8c, this->f_94, this->f_98, this->f_90, this->f_9c);//render 1 triangle
}

//u,v related
float D_00901590[4][2] = {
	{1.0f,0.0f},
	{1.0f,1.0f},
	{0.0f,0.0f},
	{0.0f,1.0f}
};
float D_009015B0[4][2] = {
	{0.0f,0.0f},
	{0.0f,1.0f},
	{1.0f,0.0f},
	{1.0f,1.0f}
};

//render 1 triangle
//(most of the 3D models)
void Class_coaster_D8::C_005F04D7(
	struct t_coaster_Triangle *pTriangle/*bp08*/,
	struct t_dx_sfx_e0 *bp0c,//solid
	struct t_dx_sfx_e0 *bp10,//solid/partially clipped
	struct t_dx_sfx_e0 *bp14,//transparent
	struct t_dx_sfx_e0 *bp18,//transparent/partially clipped
	struct t_dx_sfx_xxx_08 *bp1c,
	struct t_dx_sfx_xxx_08 *bp20
) {
	struct {
		//local_44 this
		struct t_dx_rend_vertex_20 *local_43[3];
		struct tVECTOR_F4 aVert_2;//local_40
		struct tVECTOR_F4 aVert_1;//local_36
		struct tVECTOR_F4 aVert_0;//local_32
		float fDotProduct;//local_28
		float (*pUV)[2];//local_27
		struct t_dx_sfx_e0 *local_26;
		int dwHas1VertexIn;//local_25
		int i;//local_24
		struct t_dx_sfx_xxx_08 *local_23;
		struct t_dx_sfx_e0 *local_22;
		struct SVECTOR *local_21[3];//bp_54
		D3DVECTOR aClipVert[3];//local_18
		unsigned aColor[3];//local_9
		struct t_dx_sfx_84 *local_6;
		int dwHas1VertexOut;//local_5
		float fAlpha[3];//local_4
		unsigned dwSpecular;//local_1
	}lolo;

	lolo.dwSpecular = 0xffffffff;
	lolo.dwHas1VertexOut = 0;
	lolo.dwHas1VertexIn = 0;
	lolo.pUV = (0)?D_00901590:D_009015B0;
	lolo.local_6 = 0;
	lolo.local_21[0] = &(pTriangle->svect0);
	lolo.local_21[1] = &(pTriangle->svect1);
	lolo.local_21[2] = &(pTriangle->svect2);
	for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
		lolo.fDotProduct = this->C_005F2759(lolo.local_21[lolo.i], this->pD3DMatrixWorldView);//dot product with matrix column 3
		if(lolo.fDotProduct < -100.0f)
			lolo.dwHas1VertexOut = 1;
		if(lolo.fDotProduct > 0)
			lolo.dwHas1VertexIn = 1;
		lolo.fAlpha[lolo.i] = this->C_005F2838(lolo.fDotProduct);//get light ratio
	}//end for
	if(lolo.dwHas1VertexIn) {
		//-- --
		if(pTriangle->color0.c.a & 2) {
			//transparent
			lolo.local_22 = bp14;//not clipped
			lolo.local_26 = bp18;//partially clipped
			lolo.local_23 = bp20;//partially clipped
		} else {
			//solid
			lolo.local_22 = bp0c;//not clipped
			lolo.local_26 = bp10;//partially clipped
			lolo.local_23 = bp1c;//partially clipped
		}
		//-- --
		if(lolo.dwHas1VertexOut == 0) {
			//-- not clipped --
			C_0066E272(1, lolo.local_22);
			this->C_005F2639(&(pTriangle->svect0), this->pD3DMatrixTransform, &(lolo.aVert_0));//vector x transform + normalize
			this->C_005F2639(&(pTriangle->svect1), this->pD3DMatrixTransform, &(lolo.aVert_1));//vector x transform + normalize
			this->C_005F2639(&(pTriangle->svect2), this->pD3DMatrixTransform, &(lolo.aVert_2));//vector x transform + normalize
			lolo.aColor[0] = this->C_005F2897(&(pTriangle->color0), lolo.fAlpha[0]);//apply light intensity to color(from tRGBA to tBGRA)?
			lolo.aColor[1] = this->C_005F2897(&(pTriangle->color1), lolo.fAlpha[1]);//apply light intensity to color(from tRGBA to tBGRA)?
			lolo.aColor[2] = this->C_005F2897(&(pTriangle->color2), lolo.fAlpha[2]);//apply light intensity to color(from tRGBA to tBGRA)?
			MK_VERTEX(&(lolo.local_22->f_70.asVertex[0]), lolo.local_43[2], lolo.aVert_0.x, lolo.aVert_0.y, lolo.aVert_0.z, lolo.aVert_0.w, lolo.aColor[0], lolo.dwSpecular, 0, 0);
			MK_VERTEX(&(lolo.local_22->f_70.asVertex[2]), lolo.local_43[1], lolo.aVert_1.x, lolo.aVert_1.y, lolo.aVert_1.z, lolo.aVert_1.w, lolo.aColor[1], lolo.dwSpecular, 0, 0);
			MK_VERTEX(&(lolo.local_22->f_70.asVertex[1]), lolo.local_43[0], lolo.aVert_2.x, lolo.aVert_2.y, lolo.aVert_2.z, lolo.aVert_2.w, lolo.aColor[2], lolo.dwSpecular, 0, 0);
		} else {
			//-- partially clipped --
			this->C_005F26EB(&(pTriangle->svect0), this->pD3DMatrixWorldView, &(lolo.aClipVert[0]));//vector x matrix(rot|trans)
			this->C_005F26EB(&(pTriangle->svect1), this->pD3DMatrixWorldView, &(lolo.aClipVert[2]));//vector x matrix(rot|trans)
			this->C_005F26EB(&(pTriangle->svect2), this->pD3DMatrixWorldView, &(lolo.aClipVert[1]));//vector x matrix(rot|trans)
			lolo.aColor[0] = this->C_005F2897(&(pTriangle->color0), lolo.fAlpha[0]);//apply light intensity to color(from tRGBA to tBGRA)?
			lolo.aColor[2] = this->C_005F2897(&(pTriangle->color1), lolo.fAlpha[1]);//apply light intensity to color(from tRGBA to tBGRA)?
			lolo.aColor[1] = this->C_005F2897(&(pTriangle->color2), lolo.fAlpha[2]);//apply light intensity to color(from tRGBA to tBGRA)?
			C_00672C61(lolo.local_23, lolo.local_26);//dx_sfx:start quad/triangle(2)?
			fast_MatrixSetIdentity(lolo.local_23->f_00);
			lolo.local_6 = lolo.local_23->f_04;
			for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
				lolo.local_6->f_0c[lolo.i].x = lolo.aClipVert[lolo.i].x;
				lolo.local_6->f_0c[lolo.i].y = lolo.aClipVert[lolo.i].y;
				lolo.local_6->f_0c[lolo.i].z = lolo.aClipVert[lolo.i].z;
				lolo.local_6->f_5c[lolo.i].bgra = lolo.aColor[lolo.i];
				lolo.local_6->f_6c[lolo.i] = 0.5f;
				lolo.local_6->f_3c[lolo.i].f_00 = lolo.pUV[lolo.i][0];
				lolo.local_6->f_3c[lolo.i].f_04 = lolo.pUV[lolo.i][1];
			}//end for
		}
	}
}

//render "sight"
void Class_coaster_D8::C_005F09C4() {
	struct {
		//local_6 this;
		struct t_dx_rend_vertex_20 *local_5[4];
		unsigned dwColor;//local_1
	}lolo;

	lolo.dwColor = 0xffffffff;
	if(C_0066E272(1, this->f_ac)) {
		MK_VERTEX(&(this->f_ac->f_70.asVertex[0]), lolo.local_5[3], (float)(D_00C3FB58 * D_0090147C - D_00C3F6F8 / 2) + D_00C3F784, (float)(D_00C3FB5C * D_00901480 - D_00C3F6F8 / 2) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_ac->f_70.asVertex[1]), lolo.local_5[2], (float)(D_00C3FB58 * D_0090147C - D_00C3F6F8 / 2) + D_00C3F784, (float)(D_00C3FB5C * D_00901480 + D_00C3F6F8 / 2) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_ac->f_70.asVertex[2]), lolo.local_5[1], (float)(D_00C3FB58 * D_0090147C + D_00C3F6F8 / 2) + D_00C3F784, (float)(D_00C3FB5C * D_00901480 - D_00C3F6F8 / 2) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_ac->f_70.asVertex[3]), lolo.local_5[0], (float)(D_00C3FB58 * D_0090147C + D_00C3F6F8 / 2) + D_00C3F784, (float)(D_00C3FB5C * D_00901480 + D_00C3F6F8 / 2) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 1.0f);
	}
}

//render "shoot beams"
void Class_coaster_D8::C_005F0C81() {
	struct {
		//local_19 this
		struct t_dx_rend_vertex_20 *local_18[4];
		struct t_dx_rend_vertex_20 *local_14[4];
		struct t_dx_rend_vertex_20 *local_10[4];
		struct t_dx_rend_vertex_20 *local_6[4];
		int local_2;
		unsigned dwColor;//local_1
	}lolo;

	lolo.dwColor = 0xffffffff;
	this->f_b0 = this->f_b4[D_00C476DC];
	lolo.local_2 = D_00C3FB50 >> 3;
	C_0066E62C(this->f_b0);//dx_spr:reset something?
	if(C_0066E272(4, this->f_b0)) {
		//-- right beam --
		//-- [0 1 2 3] --
		MK_VERTEX(&(this->f_b0->f_70.asVertex[0]), lolo.local_6[3], (float)D_00C3F918 + lolo.local_2, (float)D_00C3F928, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[1]), lolo.local_6[2], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[2]), lolo.local_6[1], (float)D_00C3F918 - lolo.local_2, (float)D_00C3F928, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[3]), lolo.local_6[0], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 1.0f);
		this->f_b0->f_70.asUnsignedChar += this->f_b0->f_40;
		//-- [0 2 1 3] --
		MK_VERTEX(&(this->f_b0->f_70.asVertex[0]), lolo.local_10[3], (float)D_00C3F918 + lolo.local_2, (float)D_00C3F928, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[2]), lolo.local_10[2], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[1]), lolo.local_10[1], (float)D_00C3F918 - lolo.local_2, (float)D_00C3F928, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[3]), lolo.local_10[0], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 1.0f);
		this->f_b0->f_70.asUnsignedChar += this->f_b0->f_40;
		//-- left beam --
		//-- [0 1 2 3] --
		MK_VERTEX(&(this->f_b0->f_70.asVertex[0]), lolo.local_14[3], (float)D_00C3FB4C + lolo.local_2, (float)D_00C3FB48, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[1]), lolo.local_14[2], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[2]), lolo.local_14[1], (float)D_00C3FB4C - lolo.local_2, (float)D_00C3FB48, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[3]), lolo.local_14[0], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 1.0f);
		this->f_b0->f_70.asUnsignedChar += this->f_b0->f_40;
		//-- [0 2 1 3] --
		MK_VERTEX(&(this->f_b0->f_70.asVertex[0]), lolo.local_18[3], (float)D_00C3FB4C + lolo.local_2, (float)D_00C3FB48, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[2]), lolo.local_18[2], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[1]), lolo.local_18[1], (float)D_00C3FB4C - lolo.local_2, (float)D_00C3FB48, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[3]), lolo.local_18[0], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 1.0f);
		//-- --
	}
}

//render "shoot gauge"
void Class_coaster_D8::C_005F15C7() {
	struct {
		//local_7 this
		struct t_dx_rend_vertex_20 *local_11[4];
		int dwY0;//local_2
		int dwTint;//local_1
	}lolo;

	lolo.dwTint = (D_00C3FB50 << 7) >> 7;
	lolo.dwY0 = D_00901480 * 220 - D_00C3FB50 * D_00901480 + D_00C3F788;
	if(C_0066E272(1, this->f_cc)) {
		MK_VERTEX(&(this->f_cc->f_70.asVertex)[0], lolo.local_11[3], (float)(D_0090147C * 20) + D_00C3F784, (float)lolo.dwY0, 0, 1.0f, (0xff << 24) | ((0x80 - lolo.dwTint) << 16) | (lolo.dwTint << 8), 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_cc->f_70.asVertex)[1], lolo.local_11[2], (float)(D_0090147C * 20) + D_00C3F784, (float)(D_00901480 * 220) + D_00C3F788, 0, 1.0f, 0xff800000, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_cc->f_70.asVertex)[2], lolo.local_11[1], (float)(D_0090147C * 28) + D_00C3F784, (float)lolo.dwY0, 0, 1.0f, (0xff << 24) | ((0x80 - lolo.dwTint) << 16) | (lolo.dwTint << 8), 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_cc->f_70.asVertex)[3], lolo.local_11[0], (float)(D_0090147C * 28) + D_00C3F784, (float)(D_00901480 * 220) + D_00C3F788, 0, 1.0f, 0xff800000, 0xff000000, 0.0f, 0.0f);
	}
}

//render "waku"
void Class_coaster_D8::C_005F1838() {
	struct {
		//local_6 this
		struct t_dx_rend_vertex_20 *local_5[4];
		unsigned dwColor;//local_1
	}lolo;

	lolo.dwColor = 0xffffffff;
	if(C_0066E272(1, this->f_d0)) {
		MK_VERTEX(&(this->f_d0->f_70.asVertex)[0], lolo.local_5[3], (float)(D_0090147C * 18) + D_00C3F784, (float)(D_00901480 * 86) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_d0->f_70.asVertex)[1], lolo.local_5[2], (float)(D_0090147C * 18) + D_00C3F784, (float)(D_00901480 * 226) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_d0->f_70.asVertex)[2], lolo.local_5[1], (float)(D_0090147C * 30) + D_00C3F784, (float)(D_00901480 * 86) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_d0->f_70.asVertex)[3], lolo.local_5[0], (float)(D_0090147C * 30) + D_00C3F784, (float)(D_00901480 * 226) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 1.0f);
	}
}

//render "status box"
void Class_coaster_D8::C_005F1A71() {
	struct {
		//local_8 this
		struct t_dx_rend_vertex_20 *local_7[4];
		int dwX1;//local_3
		unsigned dwColor;//local_2
		int dwX0;//local_1
	}lolo;

	lolo.dwX0 = D_0090147C * 200 + D_00C3F784;
	lolo.dwX1 = D_00901480 * 311 + D_00C3F784;
	//-- make larger for score >= 9999 --
	if(D_00C3F74C >= 9999)
		lolo.dwX1 += D_0090147C * 15 + D_00C3F784;
	//-- --
	lolo.dwColor = 0xffffffff;
	if(C_0066E272(1, this->f_c4)) {
		MK_VERTEX(&(this->f_c4->f_70.asVertex[0]), lolo.local_7[3], (float)lolo.dwX0, (float)(D_00901480 * 192) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_c4->f_70.asVertex[1]), lolo.local_7[2], (float)lolo.dwX0, (float)(D_00901480 * 223) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_c4->f_70.asVertex[2]), lolo.local_7[1], (float)lolo.dwX1, (float)(D_00901480 * 192) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_c4->f_70.asVertex[3]), lolo.local_7[0], (float)lolo.dwX1, (float)(D_00901480 * 223) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 1.0f);
	}
}

//render "pause"
void Class_coaster_D8::C_005F1CB5() {
	struct {
		//local_6 this
		struct t_dx_rend_vertex_20 *local_5[4];
		unsigned dwColor;//local_1
	}lolo;

	lolo.dwColor = 0xffffffff;
	if(C_0066E272(1, this->f_c8)) {
		MK_VERTEX(&(this->f_c8->f_70.asVertex)[0], lolo.local_5[3], (float)(D_0090147C * 200) + D_00C3F784, (float)(D_00901480 * 192) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_c8->f_70.asVertex)[1], lolo.local_5[2], (float)(D_0090147C * 200) + D_00C3F784, (float)(D_00901480 * 224) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_c8->f_70.asVertex)[2], lolo.local_5[1], (float)(D_0090147C * 311) + D_00C3F784, (float)(D_00901480 * 192) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_c8->f_70.asVertex)[3], lolo.local_5[0], (float)(D_0090147C * 311) + D_00C3F784, (float)(D_00901480 * 224) + D_00C3F788, 0, 1.0f, lolo.dwColor, 0xff000000, 1.0f, 1.0f);
	}
}

//render "score"
void Class_coaster_D8::C_005F1F00() {
	struct {
		//local_10 this
		struct t_dx_rend_vertex_20 *local_9[4];
		int dwX1;//local_5
		unsigned dwColor;//local_4
		int dwY1;//local_3
		int dwX0;//local_2
		int dwY0;//local_1
	}lolo;

	//-- "SCORE" --
	lolo.dwColor = 0xffffffff;
	lolo.dwX0 = D_0090147C * 204 + D_00C3F784;
	lolo.dwX1 = D_0090147C * 243 + D_00C3F784;
	lolo.dwY0 = D_00901480 * 200 + D_00C3F788;
	lolo.dwY1 = D_00901480 * 232 + D_00C3F788;
	C_0066E272(1, this->f_c0);
	MK_VERTEX(&(this->f_c0->f_70.asVertex[0]), lolo.local_9[3], (float)lolo.dwX0, (float)lolo.dwY0, 0, 1.0f, lolo.dwColor, 0xff000000, (0.0f/255.0f), 0.0f);
	MK_VERTEX(&(this->f_c0->f_70.asVertex[1]), lolo.local_9[2], (float)lolo.dwX0, (float)lolo.dwY1, 0, 1.0f, lolo.dwColor, 0xff000000, (0.0f/255.0f), 1.0f);
	MK_VERTEX(&(this->f_c0->f_70.asVertex[2]), lolo.local_9[1], (float)lolo.dwX1, (float)lolo.dwY0, 0, 1.0f, lolo.dwColor, 0xff000000, (47.0f/255.0f), 0.0f);
	MK_VERTEX(&(this->f_c0->f_70.asVertex[3]), lolo.local_9[0], (float)lolo.dwX1, (float)lolo.dwY1, 0, 1.0f, lolo.dwColor, 0xff000000, (47.0f/255.0f), 1.0f);
	//-- --
	this->C_005F2119(D_00C3F74C, D_0090147C * 236, D_00901480 * 200, 0);//render number
}

//render number
void Class_coaster_D8::C_005F2119(int dwVal/*bp08*/, short x/*bp0c*/, short y/*bp10*/, short wPadWith0/*bp14*/) {
	struct {
		//local_16 this
		struct t_dx_rend_vertex_20 *local_15[4];
		float fu_1;//local_11
		float fu_0;//local_10
		float fy;//local_9
		float fx;//local_8
		int dwDigitIndex;//local_7
		int local_6;
		int dwRemain;//local_5
		unsigned dwColor;//local_4
		int i;//local_3
		int dwCurPower;//local_2
		int dwMaxDigits;//local_1
	}lolo;

	lolo.dwMaxDigits = 4;
	lolo.dwCurPower = 1000;
	lolo.dwColor = 0xffffffff;
	lolo.local_6 = 1;
	lolo.dwRemain = dwVal + 1;
	if(dwVal > 9999) {
		lolo.dwMaxDigits = 5;
		lolo.dwCurPower = 10000;
	}
	for(lolo.i = 0; lolo.i < lolo.dwMaxDigits; lolo.i ++) {
		lolo.dwDigitIndex = 0;
		while(lolo.dwRemain > lolo.dwCurPower) {
			lolo.dwDigitIndex ++;
			lolo.dwRemain -= lolo.dwCurPower;
		}
		if(lolo.dwDigitIndex)
			lolo.local_6 = 0;
		if(dwVal == 0 && lolo.dwCurPower == 1)
			lolo.local_6 = 0;
		if(wPadWith0 == 1 || lolo.dwDigitIndex || lolo.local_6 == 0) {//else 005F23FE
			lolo.fx = (float)(x + lolo.i * (D_0090147C * 13)) + D_00C3F784;
			lolo.fy = (float)(y) + D_00C3F788;
			lolo.fu_0 = (float)(lolo.dwDigitIndex * 16 + 48) / 255.0f;
			lolo.fu_1 = (float)(lolo.dwDigitIndex * 16 + 64) / 255.0f;
			C_0066E272(1, this->f_c0);
			MK_VERTEX(&(this->f_c0->f_70.asVertex[0]), lolo.local_15[3], lolo.fx                           , lolo.fy                           , 0, 1.0f, lolo.dwColor, 0xff000000, lolo.fu_0, 0.0f);
			MK_VERTEX(&(this->f_c0->f_70.asVertex[1]), lolo.local_15[2], lolo.fx                           , lolo.fy + (float)(D_00901480 * 29), 0, 1.0f, lolo.dwColor, 0xff000000, lolo.fu_0, 1.0f);
			MK_VERTEX(&(this->f_c0->f_70.asVertex[2]), lolo.local_15[1], lolo.fx + (float)(D_0090147C * 15), lolo.fy                           , 0, 1.0f, lolo.dwColor, 0xff000000, lolo.fu_1, 0.0f);
			MK_VERTEX(&(this->f_c0->f_70.asVertex[3]), lolo.local_15[0], lolo.fx + (float)(D_0090147C * 15), lolo.fy + (float)(D_00901480 * 29), 0, 1.0f, lolo.dwColor, 0xff000000, lolo.fu_1, 1.0f);
		}
		lolo.dwCurPower /= 10;
	}//end for
}

//render alpha quad
void Class_coaster_D8::C_005F2417(unsigned char bAlpha/*bp08*/) {
	struct {
		//local_6 this
		struct t_dx_rend_vertex_20 *local_5[4];
		tBGRA sColor;//local_1
	}lolo;

	lolo.sColor.c.b = 0;
	lolo.sColor.c.g = 0;
	lolo.sColor.c.r = 0;
	lolo.sColor.c.a = bAlpha;
	C_0066E272(1, this->f_d4);
	MK_VERTEX(&(this->f_d4->f_70.asVertex[0]), lolo.local_5[3], (float)(D_0090147C * 0) + D_00C3F784, (float)(D_00901480 * 0)   + D_00C3F788, 0, 1.0f, lolo.sColor.bgra, 0xff000000, 0.0f, 0.0f);
	MK_VERTEX(&(this->f_d4->f_70.asVertex[1]), lolo.local_5[2], (float)(D_0090147C * 0) + D_00C3F784, (float)(D_00901480 * 240) + D_00C3F788, 0, 1.0f, lolo.sColor.bgra, 0xff000000, 0.0f, 1.0f);
	MK_VERTEX(&(this->f_d4->f_70.asVertex[2]), lolo.local_5[1], (float)(D_0090147C * 320) + D_00C3F784, (float)(D_00901480 * 0)   + D_00C3F788, 0, 1.0f, lolo.sColor.bgra, 0xff000000, 1.0f, 0.0f);
	MK_VERTEX(&(this->f_d4->f_70.asVertex[3]), lolo.local_5[0], (float)(D_0090147C * 320) + D_00C3F784, (float)(D_00901480 * 240) + D_00C3F788, 0, 1.0f, lolo.sColor.bgra, 0xff000000, 1.0f, 1.0f);
}

//vector x transform + normalize
void Class_coaster_D8::C_005F2639(struct SVECTOR *bp08, LPD3DMATRIX bp0c, struct tVECTOR_F4 *bp10) {
	struct {//local_5 this
		D3DVECTOR local_4;
		float fHW;//local_1
	}lolo;

	lolo.local_4.x = (float)bp08->vx;
	lolo.local_4.y = (float)bp08->vy;
	lolo.local_4.z = (float)bp08->vz;
	fast_multVectorByTransform(bp0c, &lolo.local_4, bp10);
	//-- normalize --
	if(bp10->w == 0.0f)
		bp10->w = 0.1f;
	lolo.fHW = 1.0f / bp10->w;
	bp10->x *= lolo.fHW;
	bp10->y *= lolo.fHW;
	bp10->z *= lolo.fHW;
	bp10->w = lolo.fHW;
}

//vector x matrix(rot|trans)
int Class_coaster_D8::C_005F26EB(struct SVECTOR *bp08, LPD3DMATRIX bp0c, LPD3DVECTOR bp10) {
	//local_4 this
	D3DVECTOR local_3;

	local_3.x = (float)bp08->vx;
	local_3.y = (float)bp08->vy;
	local_3.z = (float)bp08->vz;
	fast_multVectorByRotTrans(bp0c, &local_3, bp10);
	if(bp10->z > 0)
		return 1;

	return 0;
}

//dot product with matrix column 3
float Class_coaster_D8::C_005F2759(struct SVECTOR *bp08, LPD3DMATRIX bp0c) {
	struct {
		//local_5 this
		float local_4;
		D3DVECTOR local_3;
	}lolo;

	lolo.local_3.x = (float)bp08->vx;
	lolo.local_3.y = (float)bp08->vy;
	lolo.local_3.z = (float)bp08->vz;
	lolo.local_4 = bp0c->_13 * lolo.local_3.x + bp0c->_23 * lolo.local_3.y + bp0c->_33 * lolo.local_3.z + bp0c->_43;

	return lolo.local_4;
}

//set world matrix
void Class_coaster_D8::C_005F27BF(struct MATRIX *pMatrixWorld/*bp08*/) {
	struct {
		//local_20 this
		LPD3DMATRIX pD3DMatrixView;//local_19
		struct t_aa0 *local_18;
		D3DMATRIX sD3DMatrixWorld;//local_17
		LPD3DMATRIX pD3DMatrixProj;//local_1
	}lolo;

	//note: for COASTER, the global view matrix is identity, which means that
	//pMatrixWorld parameter contains the view transformation already.
	lolo.local_18 = C_00676578();
	lolo.pD3DMatrixView = lolo.local_18->f_2fc;//(identity for coaster)
	lolo.pD3DMatrixProj = &(lolo.local_18->f_890);//projection matrix?
	C_006611FB(pMatrixWorld, &lolo.sD3DMatrixWorld);//psx:transformation to D3DMATRIX(1)
	fast_MatrixMultiplication4x4(&lolo.sD3DMatrixWorld, lolo.pD3DMatrixView, this->pD3DMatrixWorldView);
	fast_MatrixMultiplication4x4(this->pD3DMatrixWorldView, lolo.pD3DMatrixProj, this->pD3DMatrixTransform);
	//note: pD3DMatrixWorldView seems to be used for clipping too
}

//get light ratio
float Class_coaster_D8::C_005F2838(float bp08) {
	//local_1 this
	if(D_00C3F750 > bp08)
		return 1.0f;
	if(D_00C3F754 < bp08)
		return 0.0f;

	return 1.0f - (bp08 - D_00C3F750) / (D_00C3F754 - D_00C3F750);
}

//apply light intensity to color(from tRGBA to tBGRA)?
unsigned Class_coaster_D8::C_005F2897(tRGBA *bp08, float fIntensity/*bp0c*/) {
	//local_2 this
	tRGBA local_1;

	local_1 = *bp08;
	local_1.c.r *= fIntensity;
	local_1.c.g *= fIntensity;
	local_1.c.b *= fIntensity;

	return (0xff << 24) | (local_1.c.r << 16) | (local_1.c.g << 8) | local_1.c.b;
}

//"refresh" graphics
void Class_coaster_D8::C_005F2924() {
	//local_2 this
	struct t_aa0 *local_1;

	local_1 = C_00676578();
	//-------------
	//-- LAYER 0 --
	//-------------
	//objects:not clipped
	C_0066E641(this->f_88, local_1);//dx_spr:render
	C_0066E62C(this->f_88);//dx_spr:reset something?
	//objects:partially clipped
	C_00660E6A(this->f_8c, local_1);//G_DRV_80:render "struct t_dx_sfx_e0 *"(through "G_DRV_78")?
	C_0066E62C(this->f_8c);//dx_spr:reset something?
	//-------------
	//-- LAYER 1 --
	//-------------
	C_00660E95(1, local_1);//G_DRV_84:change_layer?
	//objects(transparent):not clipped
	C_0066E641(this->f_94, local_1);//dx_spr:render
	C_0066E62C(this->f_94);//dx_spr:reset something?
	//objects(transparent):partially clipped
	C_00660E6A(this->f_98, local_1);//G_DRV_80:render "struct t_dx_sfx_e0 *"(through "G_DRV_78")?
	C_0066E62C(this->f_98);//dx_spr:reset something?
	//beam
	C_0066E641(this->f_b0, local_1);//dx_spr:render
	C_0066E62C(this->f_b0);//dx_spr:reset something?
	//-------------
	//-- LAYER 0 --
	//-------------
	C_00660E95(0, local_1);//G_DRV_84:change_layer?
	//tracks:not clipped
	C_0066E641(this->f_a0, local_1);//dx_spr:render
	C_0066E62C(this->f_a0);//dx_spr:reset something?
	//tracks:partially clipped
	C_00660E6A(this->f_a4, local_1);//G_DRV_80:render "struct t_dx_sfx_e0 *"(through "G_DRV_78")?
	C_0066E62C(this->f_a4);//dx_spr:reset something?
	//sight
	C_0066E641(this->f_ac, local_1);//dx_spr:render
	C_0066E62C(this->f_ac);//dx_spr:reset something?
	//gauge+waku
	C_0066E641(this->f_cc, local_1);//dx_spr:render
	C_0066E62C(this->f_cc);//dx_spr:reset something?
	C_0066E641(this->f_d0, local_1);//dx_spr:render
	C_0066E62C(this->f_d0);//dx_spr:reset something?
	//gauge+waku(why 2 times?)
	C_0066E641(this->f_cc, local_1);//dx_spr:render
	C_0066E62C(this->f_cc);//dx_spr:reset something?
	C_0066E641(this->f_d0, local_1);//dx_spr:render
	C_0066E62C(this->f_d0);//dx_spr:reset something?
	//status box
	C_0066E641(this->f_c4, local_1);//dx_spr:render
	C_0066E62C(this->f_c4);//dx_spr:reset something?
	C_0066E641(this->f_c0, local_1);//dx_spr:render
	C_0066E62C(this->f_c0);//dx_spr:reset something?
	//pause
	C_0066E641(this->f_c8, local_1);//dx_spr:render
	C_0066E62C(this->f_c8);//dx_spr:reset something?
	//-------------
	//-- LAYER 1 --
	//-------------
	C_00660E95(1, local_1);//G_DRV_84:change_layer?
	//alpha quad
	C_0066E641(this->f_d4, local_1);//dx_spr:render
	C_0066E62C(this->f_d4);//dx_spr:reset something?
}
