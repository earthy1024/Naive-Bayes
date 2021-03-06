// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef BAYES_CLASSIFIER_H_
#define BAYES_CLASSIFIER_H_

#include "image.h"
#include "model.h"
#include <iostream>
#include <istream>
#include <ostream>


namespace bayes {
using std::istream;
using std::ostream;

class Classifier {
};

/**
 * Creates the aspects of the model.cc file for use in classification
 * @param model
 */
Classifier CreateClassifier(Model &model);

/**
 * The main function in classifier.
 * Executes the functionality and determines the class belonging to each image in a file
 */
void RunClassifier();

/**
 * Takes in the index of the current image in the image vector.
 * Performs the maximum a posteriori classification
 * @param index
 * @param model
 * @return class number
 */
int AnalyzeImages(int index, Model &model);

std::string ConvertVector();

/**
 * Prints out the list of labels for the given images
 */
void PrintResults();

istream& operator>>(istream &input, Classifier &classifier);
ostream& operator<<(ostream &output,Classifier &classifier);

}  // namespace bayes


#endif  // BAYES_CLASSIFIER_H_

