/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//coaster --

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
struct t_coaster_Node D_00C5D360[0xa];//Tails(right)
struct t_coaster_Node D_00C5D590[0xc8];//Nodes pool
struct t_coaster_Node D_00C60150;//TOP NODE
short D_00C60188;//last attributed index
short D_00C60190[0xc8];//indexes pool
struct t_coaster_Node D_00C60320[0xa];//Heads(left)
////////////////////////////////////////
void C_005EF281(struct t_coaster_Node *, short);//init node(called for TOP only)

//init this module
void C_005EF1C0() {
	int i;//local_1

	C_005EF281(&D_00C60150, 0);//init node(called for TOP only)
	D_00C60150.wDepth = 0;
	D_00C60188 = 0;
	for(i = 0; i < 0xc8; i ++)
		D_00C60190[i] = i + 1;
	for(i = 0; i < 0xa; i ++) {
		//-- --
		D_00C60320[i].pPrev = 0;
		D_00C60320[i].pNext = &(D_00C5D360[i]);
		//-- --
		D_00C5D360[i].pPrev = &(D_00C60320[i]);
		D_00C5D360[i].pNext = 0;
	}
}

//init node(called for TOP only)
void C_005EF281(struct t_coaster_Node *pNode/*bp08*/, short wIndex/*bp0c*/) {
	pNode->f_04.f_12[0] = 0;
	pNode->f_04.f_12[1] = 0;
	pNode->f_04.f_12[2] = 0;

	pNode->f_04.f_00[0][0] = 0x1000; pNode->f_04.f_00[0][1] = 0; pNode->f_04.f_00[0][2] = 0;
	pNode->f_04.f_00[1][0] = 0; pNode->f_04.f_00[1][1] = 0x1000; pNode->f_04.f_00[1][2] = 0;
	pNode->f_04.f_00[2][0] = 0; pNode->f_04.f_00[2][1] = 0; pNode->f_04.f_00[2][2] = 0x1000;

	pNode->pParentNode = &D_00C60150;
	pNode->wIndex = wIndex;
	pNode->pPrev = 0;
	pNode->pNext = 0;
}

short C_005EF3E0(void);//generate index
void C_005EF42F(struct t_coaster_Node *, struct t_coaster_Node *);//insert in list

//allocate "Node"
struct t_coaster_Node *C_005EF31E(short wModelId/*bp08*/, struct t_coaster_Node *pParentNode/*bp0c*/, int dwX/*bp10*/, int dwY/*bp14*/, int dwZ/*bp18*/, short wAlpha/*bp1c*/, short wBeta/*bp20*/, short wGamma/*bp24*/) {
	struct {
		struct SVECTOR sRot;//local_4
		struct t_coaster_Node *pNode;//local_2
		short wIndex; char _ocal_1[2];//local_1
	}lolo;

	lolo.wIndex = C_005EF3E0();//generate index
	lolo.pNode = &(D_00C5D590[lolo.wIndex]);
	C_005EF42F(lolo.pNode, pParentNode);//insert in list
	//-- --
	lolo.pNode->pModel = D_00C5D0F0[wModelId];
	lolo.pNode->wModelId = wModelId;
	//-- --
	lolo.pNode->wIndex = lolo.wIndex;
	//-- rotate --
	lolo.sRot.f_00 = wAlpha;
	lolo.sRot.f_02 = wBeta;
	lolo.sRot.f_04 = wGamma;
	C_00662CD2(&lolo.sRot, &(lolo.pNode->f_04));//psx:xyz_rotate(3)
	//-- translate --
	lolo.pNode->f_04.f_12[0] = dwX;
	lolo.pNode->f_04.f_12[1] = dwY;
	lolo.pNode->f_04.f_12[2] = dwZ;

	return lolo.pNode;
}

void C_005EF40C(short);//release index
void C_005EF49E(struct t_coaster_Node *);//remove from list

//release "Node"
void C_005EF3BF(struct t_coaster_Node *pNode/*bp08*/) {
	C_005EF49E(pNode);//remove from list
	C_005EF40C(pNode->wIndex);//release index
}

//generate index
short C_005EF3E0() {
	short wIndex;//local_1

	wIndex = D_00C60188;
	D_00C60188 = D_00C60190[D_00C60188];

	return wIndex;
}

//release index
void C_005EF40C(short wIndex/*bp08*/) {
	D_00C60190[wIndex] = D_00C60188;
	D_00C60188 = wIndex;
}

//insert in list
void C_005EF42F(struct t_coaster_Node *pNode/*bp08*/, struct t_coaster_Node *pParentNode/*bp0c*/) {
	short wDepth;//local_1

	pNode->pParentNode = pParentNode;
	wDepth = pParentNode->wDepth + 1;
	pNode->wDepth = wDepth;
	pNode->pPrev = D_00C5D360[wDepth].pPrev;
	pNode->pNext = pNode->pPrev->pNext;
	D_00C5D360[wDepth].pPrev->pNext = pNode;
	D_00C5D360[wDepth].pPrev = pNode;
}

//remove from list
void C_005EF49E(struct t_coaster_Node *pNode/*bp08*/) {
	pNode->pPrev->pNext = pNode->pNext;
	pNode->pNext->pPrev = pNode->pPrev;
}
