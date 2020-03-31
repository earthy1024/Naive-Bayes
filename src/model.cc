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

void CreateList(std::string input) {
    int count = input.size() / (kImageSize * kImageSize);
    Image image = Image();
    for (int current = 0; current < count; current++) {
        int char_count = 0;
        for (int row = 0; row < kImageSize; row++) {
            for (int col = 0; col < kImageSize; col++) {
                image.SetPixel(row, col, input[char_count]);
                char_count++;
            }
        }
        input.erase(0,kImageSize*kImageSize);
        image_vector.push_back(image);
    }
}

void RunModel(Model &model) {
    for (int image_count = 0; image_count < image_vector.size(); image_count++) {
        for (int row = 0; row < kImageSize; row++) {
            for (int col = 0; col < kImageSize; col++) {
                for (int shade = 0; shade < kNumShades; shade++) {
                    int image_num = image_class[image_count];
                    if (image_vector[image_count].GetPixel(row, col) == shade) {
                        model.probs_[row][col][shade][image_num] = ((model.probs_[row][col][shade][image_num] * (image_count - 1)) + GetShadeValue(image_vector[image_count], row, col) / image_count);
                    }
                }
            }
        }
    }
}

double GetShadeValue(Image &image, int row_index, int col_index) {
    char pixel_shade = image.GetPixel(row_index, col_index);
    if (pixel_shade == ' ') {
        return 0;
    } else {
        return 1;
    }
}

istream& operator>>(istream &input, Model &model) {
    std::string file_name;
    input >> file_name;
    std::ifstream file;
    file.open(file_name);
    if (file.fail()) {
        std::cout << "Not valid file" << std::endl;
    }
    std::string file_data;
    while (!file.eof()) {
        std::string file_line;
        file >> file_line;
        file_data += file_line;
    }
    file.close();

    CreateList(file_data);
}

}  // namespace bayes

