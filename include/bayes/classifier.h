// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef BAYES_CLASSIFIER_H_
#define BAYES_CLASSIFIER_H_

#include "image.h"
#include "model.h"
#include <iostream>
#include <istream>


namespace bayes {
using std::istream;
void CreateClassifier(Model &model);
void RunClassifier();
void AnalyzeImages(int index);
istream& operator>>(istream &input, Model &model);
}  // namespace bayes

#endif  // BAYES_CLASSIFIER_H_

