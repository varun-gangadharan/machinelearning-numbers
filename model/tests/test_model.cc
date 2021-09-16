#include <catch2/catch.hpp>

#include <core/rename_this_file.h>
#include <core/model.h>
#include <core/image.h>
#include <fstream>

TEST_CASE("checking model reading files") {
    std::ifstream input_file(
            "/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/data.txt");
    naivebayes::model mod(3);
    input_file >> mod;
    SECTION("test first image") {
        REQUIRE(mod.getImages()[0].GetDisplay()[0][0] == '#');
        REQUIRE(mod.getImages()[0].GetDisplay()[0][1] == '#');
        REQUIRE(mod.getImages()[0].GetDisplay()[0][2] == '+');
        REQUIRE(mod.getImages()[0].GetDisplay()[1][0] == ' ');
        REQUIRE(mod.getImages()[0].GetDisplay()[1][1] == '+');
        REQUIRE(mod.getImages()[0].GetDisplay()[1][2] == ' ');
        REQUIRE(mod.getImages()[0].GetDisplay()[2][0] == '#');
        REQUIRE(mod.getImages()[0].GetDisplay()[2][1] == ' ');
        REQUIRE(mod.getImages()[0].GetDisplay()[2][2] == ' ');
    }SECTION("test second image") {
        REQUIRE(mod.getImages()[1].GetDisplay()[0][0] == '+');
        REQUIRE(mod.getImages()[1].GetDisplay()[0][1] == '#');
        REQUIRE(mod.getImages()[1].GetDisplay()[0][2] == '#');
        REQUIRE(mod.getImages()[1].GetDisplay()[1][0] == ' ');
        REQUIRE(mod.getImages()[1].GetDisplay()[1][1] == '+');
        REQUIRE(mod.getImages()[1].GetDisplay()[1][2] == '+');
        REQUIRE(mod.getImages()[1].GetDisplay()[2][0] == '#');
        REQUIRE(mod.getImages()[1].GetDisplay()[2][1] == '#');
        REQUIRE(mod.getImages()[1].GetDisplay()[2][2] == '#');
    }SECTION("test third image") {
        REQUIRE(mod.getImages()[2].GetDisplay()[0][0] == '#');
        REQUIRE(mod.getImages()[2].GetDisplay()[0][1] == ' ');
        REQUIRE(mod.getImages()[2].GetDisplay()[0][2] == '+');
        REQUIRE(mod.getImages()[2].GetDisplay()[1][0] == '+');
        REQUIRE(mod.getImages()[2].GetDisplay()[1][1] == '#');
        REQUIRE(mod.getImages()[2].GetDisplay()[1][2] == '#');
        REQUIRE(mod.getImages()[2].GetDisplay()[2][0] == ' ');
        REQUIRE(mod.getImages()[2].GetDisplay()[2][1] == ' ');
        REQUIRE(mod.getImages()[2].GetDisplay()[2][2] == '#');
    }SECTION("test fourth image") {
        REQUIRE(mod.getImages()[3].GetDisplay()[0][0] == '#');
        REQUIRE(mod.getImages()[3].GetDisplay()[0][1] == '#');
        REQUIRE(mod.getImages()[3].GetDisplay()[0][2] == '+');
        REQUIRE(mod.getImages()[0].GetDisplay()[1][0] == ' ');
        REQUIRE(mod.getImages()[0].GetDisplay()[1][1] == '+');
        REQUIRE(mod.getImages()[0].GetDisplay()[1][2] == ' ');
        REQUIRE(mod.getImages()[0].GetDisplay()[2][0] == '#');
        REQUIRE(mod.getImages()[0].GetDisplay()[2][1] == ' ');
        REQUIRE(mod.getImages()[0].GetDisplay()[2][2] == ' ');
    }SECTION("Tests Correct Labels for All Images") {
        REQUIRE(mod.getImages()[0].get_label() == 7);
        REQUIRE(mod.getImages()[1].get_label() == 3);
        REQUIRE(mod.getImages()[2].get_label() == 4);
        REQUIRE(mod.getImages()[3].get_label() == 7);
        REQUIRE(mod.getImages()[4].get_label() == 4);
        REQUIRE(mod.getImages()[5].get_label() == 1);
        REQUIRE(mod.getImages()[6].get_label() == 3);
        REQUIRE(mod.getImages()[7].get_label() == 0);
        REQUIRE(mod.getImages()[8].get_label() == 0);
    }
}

TEST_CASE("testing math") {
    std::ifstream input_file(
            "/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/data.txt");
    naivebayes::model mod(3);
    input_file >> mod;
    SECTION("Testing the probabilities") {
        REQUIRE(mod.getProbList()[0][0][0][0] == Approx(0.01).margin(0.01));
        REQUIRE(mod.getProbList()[0][1][0][0] == Approx(0.01).margin(0.01));

    }
    SECTION("Testing priors") {
        REQUIRE(mod.getPriorsList()[0] == Approx(0.01).margin(0.01));
        REQUIRE(mod.getPriorsList()[1] == Approx(0.01).margin(0.01));
    }
}

TEST_CASE("save the model in separate file") {std::ifstream input_file("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/data.txt");
    naivebayes::model mod(3);
    input_file >> mod;
    std::ofstream output_file("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/modelstorage.txt");
    output_file << mod;
    SECTION("Test that file w output exists"){
        std::ifstream is("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/modelstorage.txt");

    };
    SECTION("Test output lines") {

    }

}

/*

You can (and should) create more test files; this project is too big
for all tests to be in the same file. Remember that, for each file (foo.cc)
containing non-trivial code, you should have a corresponding test file
(foo_test.cc)

Make sure to add any files that you create to CMakeLists.txt.

*/
