//
// Created by Varun Gangadharan on 4/5/21.
//
#pragma once

#ifndef NAIVE_BAYES_MODEL_H
#define NAIVE_BAYES_MODEL_H


#include <istream>
#include <sstream>
#include "image.h"

namespace naivebayes{
    class model {
    public:
        static size_t image_size_;

        static std::vector<image> images;
        /**
       * This constructor takes in attributes for the model
       * @param label, display
       */
        model(size_t size_input);
        //AMA video
     /**
      * This function overloads >> to take input and set up images vector
      * @param std::istream& input, model& model
      */
        friend std::istream &operator>>(std::istream& input, model& model ) {
         std::vector<std::vector<char>> display_input_(image_size_, std::vector<char>(image_size_));
         std::string line;
         int label_input_;
         size_t count_ = 0;
         size_t line_number_ = 0;
         while (std::getline(input, line)) {
             line_number_ = count_ % (image_size_ + 1);
             if (line_number_ == 0) {
                 //geeksforgeeks.org
                 label_input_ = stoi(line);
                 count_++;
                 continue;
             }
             for (size_t column = 0; column < image_size_; column++) {
                 display_input_[line_number_ - 1][column] = line[column];
             }
             if (line_number_ == image_size_) {
                 image new_img(label_input_, display_input_);
                 images.push_back(new_img);
             }
             count_++;
         }
         return input;
     }

     /**
      * This function overloads << to properly write to another file
      * @param std::ostream&os, model &model
      */
        friend std::ostream& operator << (std::ostream&os, model &model);

     /**
      * This function calls helper functions to initialize all parts of the model and load it
      */
        void initializeModel();
     /**
          * This function returns vector of images
          */
        std::vector<image> getImages();

        std::vector<std::vector<std::vector<std::vector<float>>>> getProbList();
        std::vector<float> getPriorsList();


        /**
          * This function calculates all the probability values for each pixel and updates the 4D array
          */
        void calculateProbabilities();

        /**
          * This function runs through the vector of images and calculates all the prior values
          */
        void getPriors();

        /**
          * This function initializes an empty 4d array to map all the probabilities
          */
        void createProbabilityList();

        /**
          * This function converts the char from display input for image into an int that says whether shaded or not
          */
        int CharToInt(char input);

    private:
        static const size_t kNumClasses = 10;

        static const size_t kNumStates = 2;

        static const size_t kSmoothConstant = 1;

        static const char kShadeCharOne = '#';

        static const char kShadeCharTwo = '#';

        std::vector<float> priors_list_ = std::vector<float>(kNumClasses, 0.0);

        std::vector<size_t> image_count_list = std::vector<size_t>(kNumClasses, 0);

        std::vector<std::vector<std::vector<std::vector<float>>>> prob_list_ = std::vector<std::vector<std::vector<std::vector<float>>>>
                (image_size_, std::vector<std::vector<std::vector<float>>>(image_size_, std::vector<std::vector<float>>(kNumStates, std::vector<float>(kNumStates))));

    };
}


#endif //NAIVE_BAYES_MODEL_H
