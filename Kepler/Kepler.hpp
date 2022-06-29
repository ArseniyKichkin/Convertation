#include "vector"
#include "iostream"
#include "cmath"


class Position {
    /*** @brief This class stores Cartesian coordinates
     * and Keplerian elements of a celestial body,
     * as well as implements conversion from Cartesian coordinates
     * to Keplerian elements and vice versa.
     * @param x, y, z -- Cartesian coordinates
     * @param vx, vy, vz -- velocity components in rectangular Cartesian coordinate system
     * @param a -- semi-major axis
     * @param e -- eccentricity
     * @param w -- argument of periapsis
     * @param N -- longitude of ascending node
     * @param i -- inclination
     * @param M -- mean Anomaly
     * @param r -- vector of Cartesian coordinates
     * @param v -- velocity vector
     * @param mu -- standard gravitational parameter (for the Sun as a central body)
    */
private:
    double x, y, z, vx, vy, vz;
    double a;
    double e;
    double w;
    double N;
    double i;
    double M;
    std::vector<double> r;
    std::vector<double> v;

    double mu = 1.32712440018E+20;


public:

    Position() = default;

    void Position_Cartesian(double, double, double, double, double, double);
    /*** @brief A method that sets Cartesian coordinates of a celestial body
         * Returns nothing
         * @params -- Cartesian coordinates and velocity components
    */

    void Position_Keplerian(double, double, double, double, double, double);
    /*** @brief A method that sets Keplerian elements of a celestial body.
         * Returns nothing
         * @params -- Keplerian elements
    */

    std::vector<double> Keplerian();
    /*** @brief A method that computes Keplerian elements by given Cartesian coordinates
         * and velocity components.
         * Returns a vector of computed Keplerian elements
    */

    double Newton_Raphson(double, double);
    /*** @brief A method that solves Kepler's equation numerically
         * @param e -- eccentricity
         * @param M -- mean anomaly
         * Returns the calculated magnitude of eccentric anomaly E
    */

    std::vector<double> Cartesian();
    /*** @brief A method that computes Cartesian coordinates
         * and velocity components by given Keplerian elements
         * Returns a vector of computed values
    */

};