// Copyright 2020 [Your Name]. All rights reserved.

#include <bayes/model.h>
#include <nlohmann/json.hpp>
#include <vector>
#include <istream>
#include <iostream>


namespace bayes {
using std::vector;
using std::ifstream;
using std::istream;

vector<Image> image_vector;
vector<int> image_class;
vector<double> class_priors;
std::string image_file;
std::string label_file;

void CreateList(vector<Image> &vector, std::string &file) {
    int count = file.size() / (kImageSize * kImageSize);

    for (int current = 0; current < count; current++) {
        Image image = Image();
        int char_count = 0;
        for (int row = 0; row < kImageSize; row++) {
            for (int col = 0; col < kImageSize; col++) {
                image.SetPixel(row, col, file[char_count]);
                char_count++;
            }
        }
        file.erase(0,kImageSize*kImageSize);
        vector.push_back(image);
    }
}

void CreateLabelList() {
    for (char current : label_file) {
        image_class.push_back(current - '0');
    }
}

void RunModel(Model &model) {
    std::cout << "What is the training image file?" << std::endl;
    std::cin >> model;
    std::cout << "What is the training label file?" << std::endl;
    std::cin >> model;
    CreateList(image_vector, image_file);
    CreateLabelList();
    CalculatePriors();

    // Iterates through each image to calculate the probability of a shade occurring given the class number.
    for (int image_count = 0; image_count < image_vector.size(); image_count++) {
        for (int row = 0; row < kImageSize; row++) {
            for (int col = 0; col < kImageSize; col++) {
                for (int shade = 0; shade < kNumShades; shade++) {
                    int image_num = image_class[image_count];
                    if (image_vector[image_count].GetPixel(row, col) == shade) {
                        int class_total = CalculateNumAppearances(image_num, image_count);
                        // Implementation of Bayes Theorem as well as Laplace smoothing
                        model.probs_[row][col][shade][image_num] =
                                (kSmoothValue + (model.probs_[row][col][shade][image_num] * (class_total - 1))
                                + GetShadeValue(image_vector[image_count], row, col)) /
                                ((kSmoothValue*2) + class_total);
                    }
                }
            }
        }
    }
}

int CalculateNumAppearances(int num_class, int current_index) {
    int count = 0;
    for (int current = 0; current < current_index; current++) {
        if (image_class[current] == num_class) {
            count++;
        }
    }
    return count;
}

void CalculatePriors() {
    for (int current = 0; current < kNumClasses; current++) {
        class_priors.push_back(CalculateNumAppearances(current, image_class.size() - 1)
                / image_class.size());
    }
}

int GetShadeValue(Image &image, int row_index, int col_index) {
    char pixel_shade = image.GetPixel(row_index, col_index);
    if (pixel_shade == ' ') {
        return 0;
    } else {
        return 1;
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
    if (file_data.find('#') != std::string::npos || file_data.find('+') != std::string::npos) {
        image_file = file_data;
    } else {
        label_file = file_data;
    }
    return input;
}

// for testing
void Print() {
    for (int a = 0; a < kImageSize; a++) {
        for (int b = 0; b < kImageSize; b++) {
            std::cout << image_vector[4].GetPixel(a, b);
        }
    }
}

// for testing
void GetNum() {
    std::cout << image_class[0];
}
}  // namespace bayes

