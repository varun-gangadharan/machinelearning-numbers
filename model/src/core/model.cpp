//
// Created by Varun Gangadharan on 4/5/21.
//
#include <core/model.h>

namespace naivebayes {

    size_t model::image_size_;
    std::vector<image> model::images;

    model::model(size_t size_input) {
        image_size_ = size_input;
    }

    std::vector<image> model::getImages() {
        return images;
    }

    int model::CharToInt(char input) {
        if (input == kShadeCharOne || input == kShadeCharTwo) {
            return 1;
        } else {
            return 0;
        }
    }
    void model::getPriors() {
        size_t image_total_ = 0;
        for(image img: images) {
            priors_list_[img.get_label()]++;
            image_count_list[img.get_label()]++;
            image_total_++;
        }
        for(float &val: priors_list_) {
            val = val / image_total_;
        }
    }
    void model::calculateProbabilities() {
        for(size_t label = 0; label < kNumClasses; label++) {
            for(size_t shaded = 0; shaded < kNumStates; shaded++){
                for (size_t x = 0; x < image_size_; x++) {
                    for (size_t y = 0; y < image_size_; y++) {
                        prob_list_[x][y][label][shaded] = (kSmoothConstant + prob_list_[x][y][shaded][label]) /
                                                          (kSmoothConstant * shaded + image_count_list[label]);;
                    }
                }
            }
        }
    }

    void model::createProbabilityList() {
        for (image img: images) {
            for(size_t shaded = 0; shaded < kNumStates; shaded++){
                for (size_t x = 0; x < image_size_; x++) {
                    for (size_t y = 0; y < image_size_; y++) {
                        if (shaded == CharToInt(img.GetDisplay()[x][y])) {
                            int ting = CharToInt(img.GetDisplay()[x][y]);
                            ting *= 1;
                            prob_list_[x][y][shaded][img.get_label()]++;
                        }
                    }
                }
            }
        }
    }

    void model::initializeModel() {
        getPriors();
        createProbabilityList();
        calculateProbabilities();
    }

    std::vector<std::vector<std::vector<std::vector<float>>>>  model::getProbList() {
        return prob_list_;
    }

    std::vector<float>  model::getPriorsList() {
        return priors_list_;
    }

    std::ostream& operator << (std::ostream& os, model &mod) {
        os << 'm';
        for (size_t label = 0; label < mod.kNumClasses; label++) {
            os << label << '\n';
            for (size_t shaded = 0; label < mod.kNumStates; label++) {
                os << shaded << '\n';
                for (size_t x = 0; x < model::image_size_; x++) {
                    os << '\n';
                    for (size_t y = 0; y < model::image_size_; y++) {
                        os << mod.prob_list_[x][y][label][shaded] << ' ';
                    }
                }
            }
            os << mod.getPriorsList()[label] << '\n';
        }
        return os;
    }

}  // namespace naivebayes
#include "core/model.h"
