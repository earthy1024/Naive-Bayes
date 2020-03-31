// Copyright 2020 [Your Name]. All rights reserved.

#include <bayes/classifier.h>
#include <bayes/image.h>
#include <bayes/model.h>
#include <nlohmann/json.hpp>


namespace bayes {
void Create() {
    Model class_model = Model();
    RunModel(class_model);
}
}  // namespace bayes

