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

void CreateClassifier(Model &model) {
    Model class_model = Model();
    RunModel(class_model);
    std::cout << "What is the image file you would like evaluated?" << std::endl;
    Classifier classify = Classifier();
    std::cin >> classify;
    CreateList(evaluation_images, evaluation_file);
}

void RunClassifier() {
    Model class_model = Model();
    CreateClassifier(class_model);
    for (int image_count = 0; image_count < evaluation_images.size(); image_count++) {
        image_results.push_back(AnalyzeImages(image_count, class_model));
    }
}

int AnalyzeImages(int index, Model &model) {
    double posterior_prob[kNumClasses] ;
    for (int current = 0; current < kNumClasses; current++) {
        for (int row = 0; row < kImageSize; row++) {
            for (int col = 0; col < kImageSize; col++) { // Gets a summation of the logs of each probability
                int shade = GetShadeValue(evaluation_images[index], row, col);
                posterior_prob[current] += log(model.probs_[row][col][shade][current]);
            }
        }
    }

    // Finds the class number with the highest probability of it occurring.
    int class_max = 0;
    double current_prob = 0;
    for (int max = 0; max < kNumClasses; max++) {
        if (posterior_prob[max] > current_prob) {
            class_max = max;
            current_prob = posterior_prob[max];
        }
    }
    return class_max;
}

// testing purposes.
void PrintResults() {
    for (int image_result : image_results) {
        std::cout << image_result << std::endl;
    }
}

istream& operator>>(istream &input, Classifier &classifier) {
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

