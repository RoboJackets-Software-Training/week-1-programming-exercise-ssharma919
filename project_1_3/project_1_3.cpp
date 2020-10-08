#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========
  int packing_size = (w.size() - 1) / 2;
  for (int i = 0; i < x.size(); i++) {
  	double output_value = 0;
  	for (int j = 0; j < w.size(); j++) {
	  	if (i + j - packing_size >= 0 && i + j - packing_size < x.size()) {
	  		output_value += x[i + j - packing_size] * w[j];
	  	}
	  	else if (!pack_with_zeros && i + j - packing_size < 0) {
	  		output_value += x[0] * w[j];
	  	}
	  	else if (!pack_with_zeros && i + j - packing_size >= x.size()) {
	  		output_value += x[x.size() - 1] * w[j];
	  	}
  	}
  	y.push_back(output_value);
  }

  std::cout << "{" << y[0];
  for(int i = 1; i < y.size(); i++) {
    std::cout << ", " << y[i];
  }
  std::cout << "}" << std::endl;


  // =========== END ===========

  return 0;
}

