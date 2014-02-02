/*
* Test if a point is inside a triangle.
* Julian Saknussemm
*
* Given Three points of a triangle, and another arbitrary point this program determines if that point lies inside
* the triangle.
*
* This is determined by satisfying the following rule:
* A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
* iff
* P is on the same side of the line AB as C
* P is on the same side of the line BC as A
* and
* P is on the same side of the line AC as B
*
* A special case exits for a vertical line (inf gradient) when testing the side of the line
*/

#include <stdio.h>

int test2(double pointToCheckx, double pointToChecky, double m, double b);
int test1(double pointToCheckx, double pointToChecky, double m, double b, double lx, double ly);
int tritest(double vertexAx, double vertexAy, double vertexBx, double vertexBy, double vertexCx, double vertexCy, double pointToCheckx, double pointToChecky);

int main(int argc, char* argv[]) {
	
	double vertexAx, vertexAy, vertexBx, vertexBy, vertexCx, vertexCy;
	double pointToCheckx, pointToChecky;

	int scanfsReturnValueAggregatedOverAllScanfs = 0;

	// get input
	printf("Triangle Vertex A (x,y): "); scanfsReturnValueAggregatedOverAllScanfs += scanf("%lf,%lf", &vertexAx, &vertexAy);
	printf("Triangle Vertex  B (x,y): "); scanfsReturnValueAggregatedOverAllScanfs += scanf("%lf,%lf", &vertexBx, &vertexBy);
	printf("Triangle Vertex  C (x,y): "); scanfsReturnValueAggregatedOverAllScanfs += scanf("%lf,%lf", &vertexCx, &vertexCy);
	printf("Test Point (x,y): "); scanfsReturnValueAggregatedOverAllScanfs += scanf("%lf,%lf", &pointToCheckx, &pointToChecky);

	// print error
	if (scanfsReturnValueAggregatedOverAllScanfs != 8) {
		printf("You're stupid and didn't put in the right inputs!\n");
		return 1;
	}

	// print answer
	printf("Point (%.2lf,%.2lf) is ", pointToCheckx, pointToChecky);
	if (tritest(vertexAx, vertexAy, vertexBx, vertexBy, vertexCx, vertexCy, pointToCheckx, pointToChecky)) printf("inside");
	else printf("outside");
	printf(" the Triangel\n");

	// return 0
	return 0;
}

int test2(double pointToCheckx, double pointToChecky, double m, double b)
{
	if (pointToChecky < m * pointToCheckx + b) {
		return -1; // point is under line
	}
	else if (pointToChecky == m * pointToCheckx + b){
		return 0;
	}
	else {
		return 1; // over
	}
}

// two points lie on the same side of a line
int test1(double pointToCheckx, double pointToChecky, double m, double b, double lx, double ly) {
	return (test2(pointToCheckx, pointToChecky, m, b) == test2(lx, ly, m, b));
}
int tritest(double vertexAx, double vertexAy, double vertexBx, double vertexBy, double vertexCx, double vertexCy, double pointToCheckx, double pointToChecky)
{

	int line1, line2, line3;
	// line eqns

	double m01 = (vertexBy - vertexAy) / (vertexBx - vertexAx);
	// b: y - y1 = m( x - x1 ), x = 0
	double b01 = m01 * -vertexBx + vertexBy;
	double m02, m12, b02, b12;
	m02 = (vertexCy - vertexAy) / (vertexCx - vertexAx);
	m12 = (vertexCy - vertexBy) / (vertexCx - vertexBx);
	b02 = m02 * -vertexCx + vertexCy;
	b12 = m12 * -vertexCx + vertexCy;

	// vertical line checks
	if (vertexBx == vertexAx) {
		line1 = ((pointToCheckx <= vertexAx) == (vertexCx <= vertexAx));
	}
	else {
		line1 = test1(pointToCheckx, pointToChecky, m01, b01, vertexCx, vertexCy);
	}

	if (vertexBx == vertexCx) {
		line2 = ((pointToCheckx <= vertexCx) == (vertexAx <= vertexCx));
	}
	else {
		line2 = test1(pointToCheckx, pointToChecky, m12, b12, vertexAx, vertexAy);
	}

	if (vertexCx == vertexAx) {
		line3 = ((pointToCheckx <= vertexAx) == (vertexBx <= vertexAx));
	}
	else {
		line3 = test1(pointToCheckx, pointToChecky, m02, b02, vertexBx, vertexBy);
	}

	return line1 && line2 && line3;

}
