// Copyright 2020 [Your Name]. All rights reserved.

#include <bayes/classifier.h>
#include <bayes/image.h>
#include <bayes/model.h>
#include <nlohmann/json.hpp>
#include <vector>

namespace bayes {
std::string evaluation_file;
std::vector<int> image_results;
std::vector<Image> evaluation_images;
void ExtractImages() {

}
void CreateClassifier(Model &model) {
    Model class_model = Model();
    RunModel(class_model);
    std::cout << "What is the image file you would like evaluated?" << std::endl;
    std::cin >> class_model;
    CreateList(evaluation_images, evaluation_file);
}

void RunClassifier() {
    Model class_model = Model();
    CreateClassifier(class_model);
    for (int image_count = 0; image_count < evaluation_images.size(); image_count++) {
        AnalyzeImages(image_count);
    }
}

void AnalyzeImages(int index) {
    for (int row = 0; row < kImageSize; row++) {
        for (int col = 0; col < kImageSize; col++) {
            if (GetShadeValue(evaluation_images[index], row, col) == 1) {

            }
        }
    }
}
istream& operator>>(istream &input, Model &model) {
    std::string file_name;
    std::ifstream file;
    input >> file_name;

    file.open(file_name);
    if (file.fail()) {
        std::cout << "Not valid file" << std::endl;
    }

    std::string file_data;
    char c;
    while (file.get(c)) {
        file_data += c;
    }
    file.close();

    evaluation_file = file_data;
    return input;
}
}  // namespace bayes

