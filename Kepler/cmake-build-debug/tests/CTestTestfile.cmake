# CMake generated Testfile for 
# Source directory: /home/arsenii/Kepler/tests
# Build directory: /home/arsenii/Kepler/cmake-build-debug/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[run_test_Kepler]=] "/home/arsenii/Kepler/cmake-build-debug/tests/run_test_Kepler")
set_tests_properties([=[run_test_Kepler]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/arsenii/Kepler/tests/CMakeLists.txt;21;add_test;/home/arsenii/Kepler/tests/CMakeLists.txt;0;")
subdirs("googletest-master")
