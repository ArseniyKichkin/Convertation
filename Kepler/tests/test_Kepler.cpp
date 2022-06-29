#include "googletest-master/googletest/include/gtest/gtest.h"
#include "../Kepler.hpp"

TEST(PositionTests, MercuryTest) {
    const double d = 367 * 2022 - 7 * (2022 + (6 + 9) / 12) / 4 + 275 * 6 / 9 + 27 - 730530;
    Position First = Position();
    std::vector<double> elements = {0.387098 * 1.49597870700E+11,
                                    0.205635 + 5.59E-10 * d,
                                    (M_PI / 180.0) * (29.1241 + 1.01444E-5 * d),
                                    (M_PI / 180.0) * (48.3313 + 3.24587E-5 * d),
                                    (M_PI / 180.0) * (7.0047 + 5.00E-8 * d),
                                    (M_PI / 180.0) * 174, 795884};
    First.Position_Keplerian(elements[0], elements[1], elements[2],
                             elements[3], elements[4], elements[5]);
    std::vector<double> Cartesian = First.Cartesian();

    First.Position_Cartesian(Cartesian[0], Cartesian[1], Cartesian[2], Cartesian[3], Cartesian[4],
                             Cartesian[5]);
    std::vector<double> Keplerian = First.Keplerian();


    std::cout.setf(std::ios::right);
    std::cout.width(15);
    std::cout << "Initial Keplerian elements";
    std::cout.width(62);
    std::cout << "Keplerian elements computed through Cartesian coordinates" << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cout.width(15);
        std::cout << elements[i] << "|";
        std::cout.width(25);
        std::cout << Keplerian[i] << "|" << std::endl;

    }

    for (int i = 0; i < 6; ++i) {
        ASSERT_TRUE(std::abs(Keplerian[i] - elements[i]) < std::abs(0.01 * elements[i]));
    }

    Position Second;
    Second.Position_Cartesian(Cartesian[0], Cartesian[1], Cartesian[2], Cartesian[3], Cartesian[4],
                              Cartesian[5]);
    std::vector<double> kepler = Second.Keplerian();
    Second.Position_Keplerian(kepler[0], kepler[1], kepler[2],
                              kepler[3], kepler[4], kepler[5]);
    std::vector<double> cartesian = Second.Cartesian();

    std::cout << std::endl;
    std::cout.setf(std::ios::left);
    std::cout.width(15);
    std::cout << "Starting Cartesian elements";
    std::cout.width(56);
    std::cout << "Cartesian elements computed through Keplerian elements" << std::endl;

    for (int i = 0; i < 6; ++i) {
        std::cout.width(15);
        std::cout << Cartesian[i] << "|";
        std::cout.width(25);
        std::cout << cartesian[i] << "|" << std::endl;

    }


    for (int i = 0; i < 6; ++i) {
        ASSERT_TRUE(std::abs(Cartesian[i] - cartesian[i]) < std::abs(0.01 * Cartesian[i]));
    }


}

TEST(PositionTests, MarsTest) {
    const double d = 367 * 2022 - 7 * (2022 + (6 + 9) / 12) / 4 + 275 * 6 / 9 + 27 - 730530;
    Position Mars;
    std::vector<double> elements = {1.523688 * 1.49597870700E+11,
                                    0.093405 + 2.516E-9 * d,
                                    (M_PI / 180.0) * (286.5016 + 2.92961E-5 * d),
                                    (M_PI / 180.0) * (49.5574 + 2.11081E-5 * d),
                                    (M_PI / 180.0) * (1.8497 - 1.78E-8 * d),
                                    (M_PI / 180.0) * 18.6021};
    Mars.Position_Keplerian(elements[0], elements[1], elements[2],
                            elements[3], elements[4], elements[5]);
    std::vector<double> Cartesian = Mars.Cartesian();
    Mars.Position_Cartesian(Cartesian[0], Cartesian[1], Cartesian[2], Cartesian[3], Cartesian[4],
                            Cartesian[5]);
    std::vector<double> Keplerian = Mars.Keplerian();


    std::cout.setf(std::ios::right);
    std::cout.width(15);
    std::cout << "Initial Keplerian elements";
    std::cout.width(62);
    std::cout << "Keplerian elements computed through Cartesian coordinates" << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cout.width(15);
        std::cout << elements[i] << "|";
        std::cout.width(25);
        std::cout << Keplerian[i] << "|" << std::endl;
    }

    for (int i = 0; i < 6; ++i) {
        ASSERT_TRUE(std::abs(Keplerian[i] - elements[i]) < std::abs(0.01 * elements[i]));
    }

    Position Mars_2;
    Mars_2.Position_Cartesian(Cartesian[0], Cartesian[1], Cartesian[2], Cartesian[3], Cartesian[4],
                              Cartesian[5]);
    std::vector<double> kepler = Mars_2.Keplerian();
    Mars_2.Position_Keplerian(kepler[0], kepler[1], kepler[2],
                              kepler[3], kepler[4], kepler[5]);
    std::vector<double> cartesian = Mars_2.Cartesian();

    std::cout << std::endl;
    std::cout.setf(std::ios::left);
    std::cout.width(15);
    std::cout << "Starting Cartesian elements";
    std::cout.width(56);
    std::cout << "Cartesian elements computed through Keplerian elements" << std::endl;

    for (int i = 0; i < 6; ++i) {
        std::cout.width(15);
        std::cout << Cartesian[i] << "|";
        std::cout.width(25);
        std::cout << cartesian[i] << "|" << std::endl;

    }


    for (int i = 0; i < 6; ++i) {
        ASSERT_TRUE(std::abs(Cartesian[i] - cartesian[i]) < std::abs(0.01 * Cartesian[i]));
    }


}