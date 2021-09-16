#include <core/classifier.h>
#include <core/model.h>

namespace naivebayes {

    model classifier::mod_ = model(0);
    std::vector<size_t> classifier::classifications;

    classifier::classifier(model model_input) {
        mod_ = model_input;
    }
    std::vector<size_t> classifier::getClassifications() {
        return classifications;
    }
    size_t classifier::calculateLikelihoods(size_t class_input, image new_img) {
        int shade_at_pixel = -1;
        size_t to_return = 0;
        for (size_t x = 0; x < mod_.image_size_; x++) {
            for (size_t y = 0; y < mod_.image_size_; y++) {
                shade_at_pixel = mod_.CharToInt(new_img.GetDisplay()[x][y]);
                to_return += log(mod_.getProbList()[x][y][shade_at_pixel][class_input]) + mod_.getPriorsList()[class_input];
            }
        }
        classifications[class_input] = to_return;
        return to_return;
    }

    size_t classifier::compareLikelihoods() {
        size_t likelihood_check = 0;
        size_t class_return = -1;
        for (image img: mod_.images) {
            for(size_t class_num = 0; class_num < kNumClasses; class_num++) {
                if (likelihood_check < calculateLikelihoods(class_num, img)) {
                    likelihood_check = calculateLikelihoods(class_num, img);
                    class_return = class_num;
                }
            }
        }
        return class_return;
    }

}  // namespace naivebayes
#include "core/classifier.h"