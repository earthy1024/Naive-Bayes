// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <bayes/classifier.h>
#include <bayes/image.h>
#include <bayes/model.h>
#include <gflags/gflags.h>

#include <string>
#include <cstdlib>
#include <iostream>


// TODO(you): Change the code below for your project use case.

DEFINE_string(name, "Clarice", "Your first name");
DEFINE_bool(happy, false, "Whether the greeting is a happy greeting");


int main(int argc, char** argv) {
  bayes::Model model = bayes::Model();
  bayes::RunModel(model);
  bayes::Print();
  bayes::GetNum();
}
