#include <catch2/catch.hpp>

#include <core/rename_this_file.h>
#include <core/model.h>
#include <core/classifier.h>
#include <core/image.h>
#include <fstream>

TEST_CASE("test a smaller image") {
    std::ifstream input_file("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/data.txt");
    naivebayes::model mod_test(3);
    input_file >> mod_test;
    std::ifstream input("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/modelstorage.txt");
    naivebayes::model mod(3);
    input >> mod;
    mod.initializeModel();
    naivebayes::classifier classif = naivebayes::classifier(mod);
    size_t prediction_first = classif.compareLikelihoods();
    REQUIRE(mod_test.getImages()[0].get_label() == prediction_first);
    REQUIRE(classif.getClassifications()[0] == Approx(-6.45321f));
    REQUIRE(classif.getClassifications()[1] == Approx(-3.21531f));
}

TEST_CASE("test that prediction actually matches the classes labels") {
    SECTION("test basic") {
        std::ifstream input_file("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/testimagesandlabels.txt");
        naivebayes::model test_mod(28);
        input_file >> test_mod;
        std::ifstream input("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/trainingimagesandlabels.txt");
        naivebayes::model mod_(28);
        input_file >> mod_;
        test_mod.initializeModel();
        naivebayes::classifier classif = naivebayes::classifier(mod_);
        float counter = 0;
        for (naivebayes::image img: test_mod.getImages()) {
            int class_num = img.get_label();
            int class_prediction = classif.compareLikelihoods();
            if (class_num == class_prediction) {
                counter++;
            }
        }
        REQUIRE(counter/1000 >= 0.7f);

    }
}



/*

You can (and should) create more test files; this project is too big
for all tests to be in the same file. Remember that, for each file (foo.cc)
containing non-trivial code, you should have a corresponding test file
(foo_test.cc)

Make sure to add any files that you create to CMakeLists.txt.

*/
