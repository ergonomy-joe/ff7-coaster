/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#define __FF7FILE__ "C:\\FF7\\coaster\\psxdata_c.cpp"

#include "ff7.h"
#include "coaster_data.h"
////////////////////////////////////////
/*C_005EE620*/int psxdata_c::init(const char *bp08, const char *bp0c) {
	struct {
		int i;//local_2
		unsigned local_1;
	}lolo;

	if(this->dwStatus == 0) {
		lolo.local_1 = 0;
		this->pData = this->load(bp0c, &(this->dwDataSize));
		//
		//
		this->pOffset = (int *)this->load(bp08, (int *)&lolo.local_1);
		//
		//
		//
		//
		//
		//
		this->dwPSXOffset = this->pOffset[0];
		for(lolo.i = 0; lolo.i < lolo.local_1 / sizeof(unsigned); lolo.i ++)
			this->pOffset[lolo.i] -= this->dwPSXOffset;
		this->dwStatus = 1;
	}

	return this->dwStatus;
}

/*C_005EE6CC*/void psxdata_c::clean() {
	//
	//
	//
	{
		if(this->pOffset)
			C_0065FB40(this->pOffset, __FF7FILE__, 0x46);
		if(this->pData)
			C_0065FB40(this->pData, __FF7FILE__, 0x48);
	}
	this->pOffset = 0;
	this->pData = 0;
	this->dwStatus = 0;
}

psxdata_c::~psxdata_c() {//C_005EE730
	this->clean();
}

/*C_005EE743*/void *psxdata_c::load(const char *bp08, int *bp0c) {
	void *local_2;
	int local_1;

	local_1 = 0;
	local_2 = 0;
	local_1 = C_006759D2(bp08, ARCHIVE_09);//is_lib:get entry offset?
	if(local_1) {
		*bp0c = C_006762EA(local_1, ARCHIVE_09);//is_lib:get entry size
		if(*bp0c) {
			local_2 = C_0065FDA1(*bp0c, __FF7FILE__, 0x64);
			if(local_2) {
				if(C_0067633E(local_1, ARCHIVE_09, local_2, *bp0c) == 0) {//is_lib:load entry
					free(local_2);
					local_2 = 0;
				}
			}
		}
	}

	return local_2;
}
