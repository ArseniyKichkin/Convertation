#include "Kepler.hpp"
#include "overloads.hpp"

template<typename T>
std::vector<T> vector_product(const std::vector<T> &first, const std::vector<T> &second) {
    std::vector<T> result(3);
    result.at(0) = first.at(1) * second.at(2) - first.at(2) * second.at(1);
    result.at(1) = first.at(2) * second.at(0) - first.at(0) * second.at(2);
    result.at(2) = first.at(0) * second.at(1) - first.at(1) * second.at(0);
    return result;
}

class Position {
private:
    double x, y, z, vx, vy, vz;
    double a; // semi-major axis
    double e; // eccentricity
    double w; // argument of periapsis
    double LAN; // longitude of ascending node
    double i; // inclination
    double M; // mean anomaly
    std::vector<double> r;
    std::vector<double> v;

    double mu = 1.32712440018E+20; // standard gravitational parameter (for the Sun)

public:
    Position(double x, double y, double z, double vx, double vy, double vz) : x(x), y(y), z(z), vx(vx), vy(vy), vz(vz) {
        r = {x, y, z};
        v = {vx, vy, vz};
    }

    Position(double d) {
        // Orbital elements of Mars
        LAN = 49.5574 + 2.11081E-5 * d;
        i = 1.8497 - 1.78E-8 * d;
        w = 286.5016 + 2.92961E-5 * d;
        a = 1.523688 * 149.6E9;
        e = 0.093405 + 2.516E-9 * d;
        M = 18.6021 + 0.5240207766 * d;
    }

    double get_e(){
        return e;
    }

    double calc_e() {
        std::vector<double> h(3);
        h = vector_product(r, v);
        std::vector<double> e_vect(3);
        e_vect = (1 / mu) * vector_product(v, h) - r * (1 / norm(r));
        return norm(e_vect);
    }
};

