//
// Created by Varun Gangadharan on 4/5/21.
//
#pragma once

#ifndef NAIVE_BAYES_IMAGE_H
#define NAIVE_BAYES_IMAGE_H

#include <string>
#include <vector>

namespace naivebayes{
class image {
public:
    /**
   * This constructor takes in attributes for the image
   * @param label, display
   */
    image(size_t label, std::vector<std::vector<char>> display);
    /**
  * This method returns the label int for an image object
  */
    size_t get_label();
    /**
  * This method returns the display 2d vector for an image object
  */
    std::vector<std::vector<char>> GetDisplay();

private:
    std::vector<std::vector<char>> display_;
    size_t label_;
};
}



#endif //NAIVE_BAYES_IMAGE_H
