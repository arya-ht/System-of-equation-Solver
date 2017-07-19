#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)

double roundoff(double x, int n);

int main() {

	int n = 0;

	printf("enter n:");
	scanf("%d", &n);

	double Cx1 = 0.1036, Cx2 = 0.2081, Cy1 = 0.2122, Cy2 = 0.4247;
	double ans1 = 0.7381, ans2 = 0.9327;

	double newcx1 = Cx2 / Cx1, tmpCx1 = Cx1*newcx1;
	double tmpCy1 = Cy1*newcx1;
	double tmp_ans1 = ans1*newcx1;

	double tmpCx2 = Cx2 - tmpCx1, tmpCy2 = Cy2 - tmpCy1;
	double tmp_ans2 = ans2 - tmp_ans1;

	double y = (tmp_ans2 - tmpCx2) / tmpCy2;
	double x = (ans1 - (Cy1*y)) / Cx1;

	printf("\nRounded X = %f\n\nRounded Y = %lf\n", x, y);

	double Ry = roundoff(y, n), Rx = roundoff(x, n);

	printf("\nX = %.*f\n", n, Rx);
	printf("\nY = %.*f\n", n, Ry);

	printf("\n\nError in X: %lf, error in Y: %lf\n", x - Rx, y - Ry);
	system("pause");
	return 0;
}
double roundoff(double x, int n) {
	x = round(x * pow(n, 10)) / pow(n, 10);
	return x;
}