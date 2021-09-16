//
// Created by Varun Gangadharan on 4/5/21.
//
#pragma once

#ifndef NAIVE_BAYES_CLASSIFIER_H
#define NAIVE_BAYES_CLASSIFIER_H


#include <istream>
#include <sstream>
#include "model.h"
#include "image.h"

namespace naivebayes{
    class classifier {
    public:
        static model mod_;

        static std::vector<size_t> classifications;

      /**
      * This constructor takes in a model instance as a param and sets a variable
      * @param model model_input
      */
        classifier(model model_input);


      /**
      * This method compares the likelihood scores for all the different class values and returns
      * class with highest score
      */
        size_t compareLikelihoods();

      /**
      * This method returns a list of all the likelihood scores for various classes for testing
      */
        std::vector<size_t> getClassifications();

    private:
        static const size_t kNumClasses = 10;

        /**
     * This method takes in class input and image input to calculate likelihood score
     */
        size_t calculateLikelihoods(size_t class_input, image new_img);

    };
}


#endif //NAIVE_BAYES_MODEL_H
