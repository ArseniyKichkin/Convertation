#include "overloads.hpp"


void Position::Position_Cartesian(double x_, double y_, double z_, double vx_, double vy_, double vz_) {
    x = x_;
    y = y_;
    z = z_;
    vx = vx_;
    vy = vy_;
    vz = vz_;
    r = {x_, y_, z_};
    v = {vx_, vy_, vz_};
}

void Position::Position_Keplerian(double a_, double e_, double w_, double N_, double i_, double M_) {
    a = a_;
    e = e_;
    w = w_;
    N = N_;
    i = i_;
    M = M_;
}


std::vector<double> Position::Keplerian() {
    std::vector<double> h(3);
    h = vector_product(r, v);
    std::vector<double> e_vect(3);
    e_vect = (1 / mu) * vector_product(v, h) - r * (1 / norm(r));
    double e_ = norm(e_vect); // eccentricity computed

    std::vector<double> n{0, 0, 1}; // the vector pointing towards the ascending node
    n = vector_product(n, h);
    double i_ = acos(h[2] / norm(h)); // inclination computed


    // computation of longitude of ascending node
    double N_;
    if (n[1] >= 0) {
        N_ = acos(n[0] / norm(n));
    } else {
        N_ = 2 * M_PI - acos(n[0] / norm(n));
    }

    // computation of argument of periapsis
    double w_;
    if (e_vect[2] >= 0) {
        w_ = acos(n * e_vect / (norm(e_vect) * norm(n)));
    } else {
        w_ = 2 * M_PI - acos(n * e_vect / (norm(e_vect) * norm(n)));
    }

    double nu; // true anomaly
    if (r * v >= 0) {
        nu = acos(e_vect * r / (norm(e_vect) * norm(r)));
    } else {
        nu = 2 * M_PI - acos(e_vect * r / (norm(e_vect) * norm(r)));
    }
    double E; // eccentric anomaly
    E = 2 * atan(tan(nu / 2) / sqrt((1 + e_) / (1 - e_)));

    double M_ = E - e_ * sin(E);

    while ((M_ * 180 / M_PI) >= 360.0) {
        M_ -= 2 * M_PI;
    }


    while ((180.0 / M_PI * M_) <= 0) {
        M_ += 2 * M_PI;
    }


    double a_ = 1 / (2 / norm(r) - norm(v) * norm(v) / mu); // semi-major axis

    std::vector<double> result = {a_, e_, w_, N_, i_, M_};
    return result;

}

double Position::Newton_Raphson(double e_, double M_) {
    double E = M_;
    while (std::abs(E - e_ * sin(E) - M_) > 0.0001) {
        E = E - (E - e_ * sin(E) - M_) / (1 - e_ * cos(E));
    }
    return E;
}

std::vector<double> Position::Cartesian() {
    double E = Newton_Raphson(e, M);
    double nu = 2 *
                atan2(std::sqrt(1 + e) * sin(E / 2), std::sqrt(1 - e) *
                                                     cos(E / 2));

    double r_c = this->a * (1 - this->e * cos(E)); // distance to the central body

    std::vector<double> o(3); // position vector in the orbital frame
    std::vector<double> vo(3); // velocity vector in the orbital frame

    o[0] = r_c * cos(nu);
    o[1] = r_c * sin(nu);
    o[2] = 0;

    vo[0] = -(sqrt(mu * this->a) / r_c) * sin(E);
    vo[1] = (sqrt(mu * this->a) / r_c) * (sqrt(1 - e * e) * cos(E));
    vo[2] = 0;

    std::vector<double> r_(3);
    std::vector<double> vr(3);

    r_[0] = o[0] * (cos(w) * cos(N) - sin(w) * sin(N) * cos(i)) -
            o[1] * (sin(w) * cos(N) + cos(w) * cos(i) * sin(N));
    r_[1] = o[0] * (cos(w) * sin(N) + sin(w) * cos(i) * cos(N)) +
            o[1] * (cos(w) * cos(i) * cos(N) - sin(w) * sin(N));
    r_[2] = o[0] * sin(i) * sin(w) + o[1] * cos(w) * sin(i);

    vr[0] = vo[0] * (cos(w) * cos(N) - sin(w) * sin(N) * cos(i)) -
            vo[1] * (sin(w) * cos(N) + cos(w) * cos(i) * sin(N));
    vr[1] = vo[0] * (cos(w) * sin(N) + sin(w) * cos(i) * cos(N)) +
            vo[1] * (cos(w) * cos(i) * cos(N) - sin(w) * sin(N));
    vr[2] = vo[0] * sin(i) * sin(w) + vo[1] * cos(w) * sin(i);

    std::vector<double> result = {r_[0], r_[1], r_[2], vr[0], vr[1], vr[2]};
    return result;


}



