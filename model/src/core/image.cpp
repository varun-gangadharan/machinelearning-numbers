//
// Created by Varun Gangadharan on 4/5/21.
//

#include <core/image.h>

namespace naivebayes {
image::image(size_t label, std::vector<std::vector<char>> display) {
    label_ = label;
    display_ = display;
}

size_t image::get_label(){
    return label_;
}

std::vector<std::vector<char>> image::GetDisplay() {
    return display_;
}


}  // namespace naivebayes
#include "core/image.h"
