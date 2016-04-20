#include <stdio.h>
#include "XB_PORT.H"

void calc_behavior(uns **res)
{
	uns *ml; // memory list
	uns n;	 // number of objects

	uns *lv; // local variables
	uns *h;	 // help

	lv = h = NULL;

	XBML(&ml);
	n = LIA(&ml, ML_CODE);

	GET_ML(5, &h);
	COPYOBJ(&h, &lv);
	COPYOBJ(&h, res);

	for (uns i = 6; i <= n; i++)
	{
		h = NULL;
		GET_ML(i, &h);
		SV_UNI(&lv, &h, &lv);
		ISC(res, &h, res);
	}
	for (uns i = 1; i <= 4; i++)
	{
		h = NULL;
		GET_ML(i, &h);
		SV_DIF(&lv, &h, &lv);
	}
	MAXK(res, &lv, res);
	OBB(res, res);

	DELOBJ(&lv);
	if (h != NULL) DELOBJ(&h);
	return;
}

int main()
{
	uns *behavior;

	behavior = NULL;

	LDS("fsm.sdt");

	calc_behavior(&behavior);

	OUT_TVL(&behavior);
	DELOBJ(&behavior);

	return 0;
}

