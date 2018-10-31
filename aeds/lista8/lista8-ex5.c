#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Area (Triangulo tr){
	float CxBy, ByAx, BxAy, AyBx, AyCx, BxCy;
	CxBy = tr.C.x*tr.B.y;
	ByAx = tr.B.y*tr.A.x;
	BxAy = tr.B.x*tr.A.y;
	AyBx = tr.A.y*tr.B.x;
	AyCx = tr.A.y*tr.C.x;
	BxCy = tr.B.x*tr.C.y;

	return mod(CxBy+ByAx+BxAy+AyBx+AyCx+BxCy)/2.0;
}
