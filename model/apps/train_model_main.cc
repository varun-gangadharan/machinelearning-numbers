#include <iostream>

#include <core/rename_this_file.h>
#include <fstream>
#include <core/model.h>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.

  std::ifstream input_file("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/trainingimagesandlabels.txt");
  naivebayes::model mod(28);
  input_file >> mod;
  mod.initializeModel();
  std::ofstream output_file("/Applications/Cinder/cinder_0.9.2_mac/my-projects/naive-bayes-varungangadharan/data/modelstorage.txt");
  output_file << mod;

  return 0;
}
