/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster -- main?

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
int D_009014A8 = 1;//display on/off flag

char D_00C3F7A8[200];
struct SVECTOR *D_00C3F870;//camera track vectors
struct SVECTOR *D_00C3F874;//left track vectors
struct SVECTOR *D_00C3F878;//right track vectors
//00C3F87C
struct t_coaster_Node *D_00C3F880;//used for "last shoot score"
//00C3F884
class Class_coaster_D8 *D_00C3F888;//renderer?
//00C3F88C
////////////////////////////////////////
//coaster:begin
void C_005E98E0() {
	C_006900FC(C_00407851(), D_00C3F7A8);//direct:change directory?
	C_005E91B5();
	D_00C3F888 = new Class_coaster_D8();
	//-- track camera --
	D_00C3F870 = (struct SVECTOR *)D_00C3F738.getStream_inline(7);
	//-- left track --
	C_005EAAF3(0);//prepare data from stream #4?
	D_00C3F874 = (struct SVECTOR *)D_00C3F8D0;
	//-- right track --
	C_005EAAF3(1);//prepare data from stream #4?
	D_00C3F878 = (struct SVECTOR *)D_00C3F8D0;
	//-- --
	C_005E938D();//start music/rail sound
	//-- used for "last shoot score" --
	D_00C3F880 = C_005EF31E(0x1e, &D_00C60150, 1200, 50, 3000, 0, 1000, 0);//allocate "Node"
}

//render objects + hit test
void C_005E99FB(struct t_coaster_Node *pNode/*bp08*/, struct t_coaster_GameObject *bp0c) {
	struct {
		short wHitTop; char _ocal_34[2];//local_34
		int local_33;
		short wHitLeft; char _ocal_32[2];//local_32
		short proj_Y[8];//bp_7c//local_31
		struct t_coaster_RenderInfo local_27;
		short proj_X[8];//bp_5c//local_23
		struct MATRIX sMatrixTemp; char _ocal_19[2];//local_19
		struct MATRIX sMatrixWorld; char _ocal_11[2];//local_11
		short wHitBottom; char _ocal_3[2];//local_3
		short i; char _ocal_2[2];//local_2
		short wHitRight; char _ocal_1[2];//local_1
	}lolo;

	//-- --
	D_00C3F8A0.f_12[0] =
	D_00C3F8A0.f_12[1] =
	D_00C3F8A0.f_12[2] = 0;
	if(pNode->pParentNode != &D_00C60150) {
		//-- multiply with parent(if any)'s matrix[unused] --
		psx_CompMatrix(&(pNode->pParentNode->sMatrixWorld), &(pNode->sMatrixWorld), &lolo.sMatrixTemp);
		psx_CompMatrix(&lolo.sMatrixTemp, &D_00C3F8A0, &lolo.sMatrixWorld);
	} else {
		psx_CompMatrix(&(pNode->sMatrixWorld), &D_00C3F8A0, &lolo.sMatrixWorld);
	}
	//-- --
	lolo.local_27.pTriangles = pNode->pModel->pTriangles;
	lolo.local_27.pModel = pNode->pModel;
	D_00C3F888->C_005F27BF(&lolo.sMatrixWorld);//set world matrix
	if(D_009014A8)
		D_00C3F888->C_005EFA3A(&lolo.local_27);//render object
	//-- make 2D bounding box --
	D_00C3F888->C_005EF95A(bp0c->sBoundingBox, bp0c->aBoundingYX);//projection:cube?
	lolo.proj_Y[0] = (bp0c->aBoundingYX[0] & 0xffff0000) >> 16;
	lolo.proj_X[0] = bp0c->aBoundingYX[0] & 0x0000ffff;
	lolo.wHitLeft = lolo.proj_X[0];
	lolo.wHitRight = lolo.proj_X[0];
	lolo.wHitTop = lolo.proj_Y[0];
	lolo.wHitBottom = lolo.proj_Y[0];
	for(lolo.i = 1; lolo.i < 6; lolo.i ++) {//else 005E9BFF
		lolo.proj_Y[lolo.i] = (bp0c->aBoundingYX[lolo.i] & 0xffff0000) >> 16;
		lolo.proj_X[lolo.i] = bp0c->aBoundingYX[lolo.i] & 0x0000ffff;
		if(lolo.wHitLeft > lolo.proj_X[lolo.i])
			lolo.wHitLeft = lolo.proj_X[lolo.i];
		if(lolo.wHitRight < lolo.proj_X[lolo.i])
			lolo.wHitRight = lolo.proj_X[lolo.i];
		if(lolo.wHitTop > lolo.proj_Y[lolo.i])
			lolo.wHitTop = lolo.proj_Y[lolo.i];
		if(lolo.wHitBottom < lolo.proj_Y[lolo.i])
			lolo.wHitBottom = lolo.proj_Y[lolo.i];
	}//end for
	//-- check if hit --
	lolo.local_33 = C_005EECB5((struct VECTOR *)lolo.sMatrixWorld.f_12);//coaster.hit:check some direction?
	if(lolo.local_33) {//else 005E9CB1
		bp0c->f_028.dwIsHit = 0;
		if(
			lolo.wHitRight > D_00C3FB58 * D_0090147C + D_00C3F784 && lolo.wHitLeft < D_00C3FB58 * D_0090147C + D_00C3F784 &&
			lolo.wHitBottom > D_00C3FB5C * D_00901480 + D_00C3F788 && lolo.wHitTop < D_00C3FB5C * D_00901480 + D_00C3F788 &&
			D_00C3FA70 == 1
		) {
			bp0c->f_028.dwIsHit = 1;
		}
	}
	//-- --
}

//render "car"/compute "beams" projection?
void C_005E9CB5(struct t_coaster_Node *pNode/*bp08*/) {
	struct {
		struct SVECTOR *local_27;
		struct t_coaster_RenderInfo local_26;
		int aYX[6];//local_22
		struct MATRIX sMatrixTemp; char _ocal_16[2];//local_16
		struct MATRIX sMatrixWorld; char _ocal_8[2];//local_8
	}lolo;

	//-- --
	D_00C3F8A0.f_12[0] =
	D_00C3F8A0.f_12[1] =
	D_00C3F8A0.f_12[2] = 0;
	if(pNode->pParentNode != &D_00C60150) {
		//-- multiply with parent(if any)'s matrix[unused] --
		psx_CompMatrix(&(pNode->pParentNode->sMatrixWorld), &(pNode->sMatrixWorld), &lolo.sMatrixTemp);
		psx_CompMatrix(&lolo.sMatrixTemp, &D_00C3F8A0, &lolo.sMatrixWorld);
	} else {
		psx_CompMatrix(&(pNode->sMatrixWorld), &D_00C3F8A0, &lolo.sMatrixWorld);
	}
	//-- --
	lolo.local_26.pTriangles = pNode->pModel->pTriangles;
	lolo.local_26.pModel = pNode->pModel;
	D_00C3F888->C_005F27BF(&lolo.sMatrixWorld);//set world matrix
	if(D_009014A8)
		D_00C3F888->C_005EFA3A(&lolo.local_26);//render object
	//-- right beam --
	lolo.local_27 = &(D_00C5D0F0[0x4f]->pTriangles[0].svect0);//D_00C5D22C
	D_00C3F888->C_005EF9CA(lolo.local_27, lolo.aYX);//projection:triangle?
	D_00C3F928 = (lolo.aYX[1] & 0xffff0000) >> 16;
	D_00C3F918 = lolo.aYX[1] & 0x0000ffff;
	D_00C3F924 = (lolo.aYX[2] & 0xffff0000) >> 16;
	D_00C3F920 = lolo.aYX[2] & 0x0000ffff;
	//-- left beam --
	lolo.local_27 = &(D_00C5D0F0[0x4f]->pTriangles[1].svect0);//D_00C5D22C
	D_00C3F888->C_005EF9CA(lolo.local_27, lolo.aYX);//projection:triangle?
	D_00C3FB48 = (lolo.aYX[1] & 0xffff0000) >> 16;
	D_00C3FB4C = lolo.aYX[1] & 0x0000ffff;
	D_00C3FA78 = (lolo.aYX[2] & 0xffff0000) >> 16;
	D_00C3FA7C = lolo.aYX[2] & 0x0000ffff;
}

//render object[score]
void C_005E9E37(struct t_coaster_Node *pNode/*bp08*/) {
	struct t_coaster_RenderInfo local_4;

	local_4.pTriangles = pNode->pModel->pTriangles;
	local_4.pModel = pNode->pModel;
	D_00C3F888->C_005F27BF(&(pNode->sMatrixWorld));//set world matrix
	if(D_009014A8)
		D_00C3F888->C_005EFACA(&local_4);//render object[for score]
}

//render background
void C_005E9E7E() {
	struct {
		unsigned short wIdTriangle; char _ocal_3[2];//local_3
		struct t_coaster_Triangle *local_2;
		struct t_coaster_Triangle *pTriangle;//local_1
	}lolo;

	lolo.local_2 = (struct t_coaster_Triangle *)D_00C3F738.getStream_inline(0xa);
	if(D_00C5039C) {
		lolo.wIdTriangle = D_00C5BF44;
		D_00C3F888->C_005F27BF(&D_00C3F8A0);//set world matrix
		do {
			lolo.pTriangle = &(lolo.local_2[lolo.wIdTriangle]);
			if(D_009014A8)
				D_00C3F888->C_005F0482(lolo.pTriangle);//render 1 triangle(static objects)
			lolo.wIdTriangle = D_00C503B0[lolo.wIdTriangle].wNext;
		} while(lolo.wIdTriangle != 0xffff);
	}
}

//render track
void C_005E9F33() {
	unsigned short wIdTrack;

	wIdTrack = D_00C503A4;
	D_00C3F888->C_005F27BF(&D_00C3F8A0);//set world matrix
	do {
		if(D_009014A8)
			D_00C3F888->C_005EFB5A(&(D_00C3F874[wIdTrack]), &(D_00C3F878[wIdTrack]));//render track element
		wIdTrack = D_00C476F0[wIdTrack].wNext;
	} while(wIdTrack != 0xffff);
}

//reset view matrix[set trans]
void C_005E9FB3(struct MATRIX *pMatrix/*bp08*/) {
	C_00661939(pMatrix);//psx:identity
	pMatrix->f_12[0] = -D_00C3F8D8.f_00;
	pMatrix->f_12[1] = -D_00C3F8D8.f_04;
	pMatrix->f_12[2] = -D_00C3F8D8.f_08;
}

//combine rot and trans for view matrix?
void C_005E9FED(struct MATRIX *pMatrixRot/*bp08*/, struct MATRIX *pMatrixTrans/*bp0c*/, struct MATRIX *pMatrix/*bp10*/) {
	struct {
		struct t_g_drv_0c vTrans;//local_23
		struct tVECTOR_F4 local_20;
		D3DMATRIX sD3DMatrixRot;//local_16
	}lolo;

	//-- --
	lolo.vTrans.f_00 = (float)pMatrixTrans->f_12[0];
	lolo.vTrans.f_04 = (float)pMatrixTrans->f_12[1];
	lolo.vTrans.f_08 = (float)pMatrixTrans->f_12[2];
	//-- --
	psx_CompMatrix(pMatrixRot, pMatrixTrans, pMatrix);
	//-- rotate lolo.vTrans --
	C_006611FB(pMatrix, &lolo.sD3DMatrixRot);//psx:transformation to D3DMATRIX(1)
	lolo.sD3DMatrixRot._41 =
	lolo.sD3DMatrixRot._42 =
	lolo.sD3DMatrixRot._43 = 0;
	C_0066CE40(&lolo.sD3DMatrixRot, &lolo.vTrans, &lolo.local_20);//[optimized]still another vector/matrix operation(w=1)
	//-- --
	pMatrix->f_12[0] = (int)lolo.local_20.f_00 + pMatrixRot->f_12[0];
	pMatrix->f_12[1] = (int)lolo.local_20.f_04 + pMatrixRot->f_12[1];
	pMatrix->f_12[2] = (int)lolo.local_20.f_08 + pMatrixRot->f_12[2];
}

//[inspired by psx.c]
//"RotMatrixZXY"?
struct MATRIX *C_005EA099(struct SVECTOR *pRot/*bp08*/, struct MATRIX *bp0c) {
	struct {
		D3DMATRIX pMatRotZX;//local_80
		D3DMATRIX pMatRotX;//local_64
		D3DMATRIX pMatRotZ;//local_48
		D3DMATRIX pMatRotZXY;//local_32
		D3DMATRIX pMatRotY;//local_16
	}lolo;

	//
		C_0067BE13((float)pRot->f_00 * (360.0f / 4096.0f), &lolo.pMatRotX);//dx_mat:x_rotate(1)
		C_0067BE71((float)pRot->f_02 * (360.0f / 4096.0f), &lolo.pMatRotY);//dx_mat:y_rotate(1)
		C_0067BECE((float)pRot->f_04 * (360.0f / 4096.0f), &lolo.pMatRotZ);//dx_mat:z_rotate(1)
		C_0066C56E(&lolo.pMatRotZ, &lolo.pMatRotX, &lolo.pMatRotZX);//[optimized]matrix multiplication 3x3
		C_0066C56E(&lolo.pMatRotZX, &lolo.pMatRotY, &lolo.pMatRotZXY);//[optimized]matrix multiplication 3x3
		C_0066C53C(&lolo.pMatRotZXY);//set matrix to "something"?
		lolo.pMatRotZXY._41 = (float)bp0c->f_12[0];
		lolo.pMatRotZXY._42 = (float)bp0c->f_12[1];
		lolo.pMatRotZXY._43 = (float)bp0c->f_12[2];
		C_0066134B(bp0c, &lolo.pMatRotZXY);//psx:D3DMATRIX to transformation(1)
	//

	return bp0c;
}
/*
[vLTrack_1]--[vTrackMiddle_1]--[vRTrack_1]
     |                              |
     |                              |
     |                              |
 [vLTrack]-[vTrackMiddle_inter]-[vRTrack]
     |                              |
     |                              |
     |                              |
     |                              |
     |                              |
     |                              |
     |                              |
[vLTrack_0]--[vTrackMiddle_0]--[vRTrack_0]
*/
//compute camera pos/rot vectors?
void C_005EA194(int dwIndex/*bp08*/, int dwHeight/*bp0c*/, struct VECTOR *pCamPos/*bp10*/, struct SVECTOR *pCamRot/*bp14*/) {
	struct {
		struct SVECTOR *vLTrack_1;//local_55
		struct VECTOR vTrackMiddle_0;//local_54
		struct VECTOR vTrack_Tangent;//local_50
		struct VECTOR vRTrack_incr;//local_46
		struct SVECTOR *vRTrack_1;//local_42
		struct VECTOR vTrackMiddle_inter;//local_41
		int dwIntPart;//local_37
		struct VECTOR local_36;
		struct SVECTOR *vCam_1;//local_32
		struct VECTOR vRTrack;//local_31
		int dwIncrGamma;//local_27
		int dwIncrBeta;//local_26
		struct SVECTOR *vLTrack_0;//local_25
		struct VECTOR vTrackMiddle_1;//local_24
		int dwIncrAlpha;//local_20
		struct VECTOR vTrack_Normal;//local_19
		struct SVECTOR *vRTrack_0;//local_15
		struct VECTOR vTrack_Binormal;//local_14
		struct SVECTOR *vCam_0;//local_10
		int dwDecPart;//local_9
		struct VECTOR vLTrack;//local_8
		struct VECTOR vLTrack_incr;//local_4
	}lolo;

	lolo.dwIntPart = (dwIndex & 0xffff0000) >> 16;
	lolo.dwDecPart = dwIndex & 0x0000ffff;
	//-- rotation related --
	lolo.vCam_0 = &(D_00C3F870[lolo.dwIntPart]);
	lolo.vCam_1 = &(D_00C3F870[lolo.dwIntPart + 1]);
	lolo.dwIncrAlpha = lolo.vCam_1->f_00 - lolo.vCam_0->f_00;
	lolo.dwIncrBeta = (lolo.vCam_1->f_02 - lolo.vCam_0->f_02) / 32;
	lolo.dwIncrGamma = lolo.vCam_1->f_04 - lolo.vCam_0->f_04;
	if(lolo.dwIncrAlpha > 0x800)
		lolo.dwIncrAlpha -= 0x1000;
	if(lolo.dwIncrBeta > 0x800)
		lolo.dwIncrBeta -= 0x1000;
	if(lolo.dwIncrGamma > 0x800)
		lolo.dwIncrGamma -= 0x1000;
	if(lolo.dwIncrAlpha < -0x800)
		lolo.dwIncrAlpha += 0x1000;
	if(lolo.dwIncrBeta < -0x800)
		lolo.dwIncrBeta += 0x1000;
	if(lolo.dwIncrGamma < -0x800)
		lolo.dwIncrGamma += 0x1000;
	lolo.dwIncrAlpha = lolo.dwDecPart * lolo.dwIncrAlpha;
	lolo.dwIncrBeta = lolo.dwDecPart * lolo.dwIncrBeta;
	lolo.dwIncrGamma = lolo.dwDecPart * lolo.dwIncrGamma;
	lolo.dwIncrAlpha >>= 16;
	lolo.dwIncrBeta >>= 16;
	lolo.dwIncrGamma >>= 16;
	//-- left track --
	lolo.vLTrack_0 = &(D_00C3F874[lolo.dwIntPart]);
	lolo.vLTrack_1 = &(D_00C3F874[lolo.dwIntPart + 1]);
	lolo.vLTrack_incr.f_00 = (lolo.vLTrack_1->f_00 - lolo.vLTrack_0->f_00) * lolo.dwDecPart;
	lolo.vLTrack_incr.f_04 = (lolo.vLTrack_1->f_02 - lolo.vLTrack_0->f_02) * lolo.dwDecPart;
	lolo.vLTrack_incr.f_08 = (lolo.vLTrack_1->f_04 - lolo.vLTrack_0->f_04) * lolo.dwDecPart;
	lolo.vLTrack.f_00 = lolo.vLTrack_0->f_00 + (short)(lolo.vLTrack_incr.f_00 >> 16);
	lolo.vLTrack.f_04 = lolo.vLTrack_0->f_02 + (short)(lolo.vLTrack_incr.f_04 >> 16);
	lolo.vLTrack.f_08 = lolo.vLTrack_0->f_04 + (short)(lolo.vLTrack_incr.f_08 >> 16);
	//-- right track --
	lolo.vRTrack_0 = &(D_00C3F878[lolo.dwIntPart]);
	lolo.vRTrack_1 = &(D_00C3F878[lolo.dwIntPart + 1]);
	lolo.vRTrack_incr.f_00 = (lolo.vRTrack_1->f_00 - lolo.vRTrack_0->f_00) * lolo.dwDecPart;
	lolo.vRTrack_incr.f_04 = (lolo.vRTrack_1->f_02 - lolo.vRTrack_0->f_02) * lolo.dwDecPart;
	lolo.vRTrack_incr.f_08 = (lolo.vRTrack_1->f_04 - lolo.vRTrack_0->f_04) * lolo.dwDecPart;
	lolo.vRTrack.f_00 = lolo.vRTrack_0->f_00 + (short)(lolo.vRTrack_incr.f_00 >> 16);
	lolo.vRTrack.f_04 = lolo.vRTrack_0->f_02 + (short)(lolo.vRTrack_incr.f_04 >> 16);
	lolo.vRTrack.f_08 = lolo.vRTrack_0->f_04 + (short)(lolo.vRTrack_incr.f_08 >> 16);
	//--
	lolo.vTrackMiddle_inter.f_00 = (lolo.vRTrack.f_00 + lolo.vLTrack.f_00) >> 1;
	lolo.vTrackMiddle_inter.f_04 = (lolo.vRTrack.f_04 + lolo.vLTrack.f_04) >> 1;
	lolo.vTrackMiddle_inter.f_08 = (lolo.vRTrack.f_08 + lolo.vLTrack.f_08) >> 1;

	lolo.vTrackMiddle_0.f_00 = (lolo.vRTrack_0->f_00 + lolo.vLTrack_0->f_00) >> 1;
	lolo.vTrackMiddle_0.f_04 = (lolo.vRTrack_0->f_02 + lolo.vLTrack_0->f_02) >> 1;
	lolo.vTrackMiddle_0.f_08 = (lolo.vRTrack_0->f_04 + lolo.vLTrack_0->f_04) >> 1;

	lolo.vTrackMiddle_1.f_00 = (lolo.vRTrack_1->f_00 + lolo.vLTrack_1->f_00) >> 1;
	lolo.vTrackMiddle_1.f_04 = (lolo.vRTrack_1->f_02 + lolo.vLTrack_1->f_02) >> 1;
	lolo.vTrackMiddle_1.f_08 = (lolo.vRTrack_1->f_04 + lolo.vLTrack_1->f_04) >> 1;
	//-- lolo.vTrack_Tangent = lolo.vTrackMiddle_1 - lolo.vTrackMiddle_0
	lolo.vTrack_Tangent.f_00 = lolo.vTrackMiddle_1.f_00 - lolo.vTrackMiddle_0.f_00;
	lolo.vTrack_Tangent.f_04 = lolo.vTrackMiddle_1.f_04 - lolo.vTrackMiddle_0.f_04;
	lolo.vTrack_Tangent.f_08 = lolo.vTrackMiddle_1.f_08 - lolo.vTrackMiddle_0.f_08;
	//--lolo.vTrack_Normal = lolo.vRTrack - lolo.vLTrack
	lolo.vTrack_Normal.f_00 = lolo.vRTrack.f_00 - lolo.vLTrack.f_00;
	lolo.vTrack_Normal.f_04 = lolo.vRTrack.f_04 - lolo.vLTrack.f_04;
	lolo.vTrack_Normal.f_08 = lolo.vRTrack.f_08 - lolo.vLTrack.f_08;
	//-- binormal --
	psx_OuterProduct0(&lolo.vTrack_Tangent, &lolo.vTrack_Normal, &lolo.local_36);
	psx_VectorNormal(&lolo.local_36, &lolo.vTrack_Binormal);
	//-- position --
	pCamPos->f_00 = (short)lolo.vTrackMiddle_inter.f_00 + FIX_MUL(lolo.vTrack_Binormal.f_00, dwHeight);
	pCamPos->f_04 = (short)lolo.vTrackMiddle_inter.f_04 + FIX_MUL(lolo.vTrack_Binormal.f_04, dwHeight);
	pCamPos->f_08 = (short)lolo.vTrackMiddle_inter.f_08 + FIX_MUL(lolo.vTrack_Binormal.f_08, dwHeight);
	//-- rotation --
	pCamRot->f_00 = lolo.vCam_0->f_00 + lolo.dwIncrAlpha;
	pCamRot->f_02 = -lolo.vCam_0->f_02 + lolo.dwIncrBeta;
	pCamRot->f_04 = lolo.vCam_0->f_04 + lolo.dwIncrGamma;
}

//render "last shoot score"
void C_005EA5FD(short wModelId/*bp08*/, int dwIncrAlpha/*bp0c*/, int dwIncrBeta/*bp10*/, int dwIncrGamma/*bp14*/) {
#if 0
	struct MATRIX sMatrixRot = {0};//local_16
	struct MATRIX sMatrixWorld = {//local_8
		{
			0x200, 0, 0,
			0, 0x200, 0,
			0, 0, 0x200
		},
		{130, 0, 400}
	};
#else
	struct {
		struct MATRIX sMatrixRot; char _ocal_16[2];//local_16
		struct MATRIX sMatrixWorld; char _ocal_8[2];//local_8
	}lolo;
	//-- --
	lolo.sMatrixRot.f_00[0][0] = 0; memset(&(lolo.sMatrixRot.f_00[0][1]), 0, sizeof(struct MATRIX) - 2);

	lolo.sMatrixWorld.f_00[0][0] = 0x200; lolo.sMatrixWorld.f_00[0][1] = 0; lolo.sMatrixWorld.f_00[0][2] = 0;
	lolo.sMatrixWorld.f_00[1][0] = 0; lolo.sMatrixWorld.f_00[1][1] = 0x200; lolo.sMatrixWorld.f_00[1][2] = 0;
	lolo.sMatrixWorld.f_00[2][0] = 0; lolo.sMatrixWorld.f_00[2][1] = 0; lolo.sMatrixWorld.f_00[2][2] = 0x200;
	lolo.sMatrixWorld.f_12[0] = 130;
	lolo.sMatrixWorld.f_12[1] = 0;
	lolo.sMatrixWorld.f_12[2] = 400;
	//-- --
#endif
	if(wModelId != 0 && wModelId != 0x5b) {
		D_00C3F880->pModel = D_00C5D0F0[wModelId];
		//-- rotate model --
		D_00C3F728.f_00 += dwIncrAlpha;
		D_00C3F728.f_02 += dwIncrBeta;
		D_00C3F728.f_04 += dwIncrGamma;
		//-- render --
		if(D_00C3F730 == 1) {//else 005EA72E
			psx_RotMatrixYXZ(&D_00C3F728, &lolo.sMatrixRot);
			psx_CompMatrix(&lolo.sMatrixRot, &lolo.sMatrixWorld, &(D_00C3F880->sMatrixWorld));
			C_005E9E37(D_00C3F880);//render object[score]
			if(D_009014A8)
				D_00C3F888->C_005F2119(D_00C3F6F4, 440, 320, 0);//render number
		}
		//-- blink --
		if((-- D_00C3F724) < 50) {//else 005EA765
			if(D_00C3F730 == 0)
				D_00C3F730 = 1;
			else
				D_00C3F730 = 0;
		}
		//-- finished --
		if(D_00C3F724 == 0)
			D_00C3F76C = 0;
	}
}

//draw alpha quad
void C_005EA77E(unsigned char bAlpha/*bp08*/) {
	if(D_009014A8)
		D_00C3F888->C_005F2417(bAlpha);//render alpha quad
}

//render "sight"
void C_005EA79B() {
	if(D_009014A8)
		D_00C3F888->C_005F09C4();//render "sight"
}

//refresh "shoot beams"
void C_005EA7B4() {
	if(D_00C3FA70 == 1)
		D_00C3F888->C_005F0C81();//refresh "shoot beams"
}

//render 2D infos
void C_005EA7D0() {
	if(D_009014A8) {
		D_00C3F888->C_005F15C7();//render "shoot gauge"
		D_00C3F888->C_005F1838();//render "waku"
		D_00C3F888->C_005F1A71();//render "status box"
		D_00C3F888->C_005F1F00();//render "score"
	}
}

//coaster:in pause
void C_005EA80A() {
	if(D_009014A8) {
		D_00C3F888->C_005F1A71();//render "status box"
		D_00C3F888->C_005F1CB5();//render "pause"
	}
}

//coaster:"refresh" graphics
void C_005EA82E() {
	if(D_009014A8)
		D_00C3F888->C_005F2924();//"refresh" graphics
}

//coaster:end
void C_005EA847() {
	delete D_00C3F888;
	C_00675F1D(ARCHIVE_09);//is_lib:close archive
	C_005E92D8();//release psxdata_c/sounds
	C_006900FC(D_00C3F7A8, 0);//direct:change directory?
}
