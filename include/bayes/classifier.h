// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef BAYES_CLASSIFIER_H_
#define BAYES_CLASSIFIER_H_

#include "image.h"
#include "model.h"
#include <iostream>
#include <istream>


namespace bayes {
using std::istream;
class Classifier {

};

void CreateClassifier(Model &model);
void RunClassifier();
int AnalyzeImages(int index, Model &model);
void PrintResults();
istream& operator>>(istream &input, Classifier &classifier);
}  // namespace bayes

#endif  // BAYES_CLASSIFIER_H_

