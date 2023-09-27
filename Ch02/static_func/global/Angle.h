#include <math.h>
#include <stdio.h>

extern const double pi;

class Angle {
public:
	Angle(double degress) {
		r = degress * pi / 180.0;
	}
	void print() {
		printf("radians = %f\n", r);
	}
private:
	double r;
};
