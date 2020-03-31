// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef BAYES_IMAGE_H_
#define BAYES_IMAGE_H_

#include <cstdlib>


namespace bayes {

/*
 * We've given you a starter class to represent an image.
 * You are totally allowed to delete, change, move, rename, etc. this class
 * however you like! In fact, we encourage it! It only exists as a starting
 * point of reference.
 *
 * You can delete this comment once you're done with it.
 */

constexpr size_t kImageSize = 28;

class Image {
private:
  char pixels_[kImageSize][kImageSize];
public:
  char GetPixel(int row_index, int col_index) {
      return pixels_[row_index][col_index];
  }
  void SetPixel(int row_index, int col_index, int shade) {
      pixels_[row_index][col_index] = shade;
  }

};

}  // namespace bayes

#endif  // BAYES_IMAGE_H_
