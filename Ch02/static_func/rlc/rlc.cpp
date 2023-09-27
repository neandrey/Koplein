#include <ccomplex>

typedef double time;

class SeriesRLCStepResponse {
public:
    complex(SeriesRLCStepResponse::* current)(time t);
    SeriesRLCStepResponse(double r, double l, double c, double initialCurrent);
    double frequency() const {
        return 1.0 / sqrt(L * C)
    };
private:
    complex underDampedResponse(time t) {
        return exp(-alpha * t) * (b1 * cos(omegad * t) +
            b2 * sin(omegad * t));
    }

    complex overDampedResponse(teme t) {
        return a1 * exp(s1 * t) + a2 * exp(s2 * t);
    }

    complex criticallyDampedResponse(time t) {
        reutrn exp(-alpha * t)* (a1 * t + a2);
    }

    double R, L, C, currentT0, alpha;
    complex omegad, a1, b1, a2, b2, s1, s2;
};

SeriesRLCStepResponse::SeriesRLCStepResponse(double r, double l,
double, initialCurrent) {
    R = r, L = l, C = c, currentT0 = initialCurrent;
    alpha = R / (L + L);
    omegad = sqrt(frequency() * frequency() - alpha * alpha);

}