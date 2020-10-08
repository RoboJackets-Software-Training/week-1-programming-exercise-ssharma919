#include <iostream>

int main()
{
    // Part 2: Palindrome Check

    // Input string from command-line
    std::string str;
    std::cout << "Enter String:" << std::endl;
    std::cin >> str;

    // Palindrome Check
    // WRITE YOUR PALINDROME CHECK HERE
    bool is_palindrome = true;
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
    	if (str[start] != str[end]) {
    		is_palindrome = false;
    		break;
    	}
    	start++;
    	end--;
    }
    if (is_palindrome) {
      std::cout << str << " is a palindrome" << std::endl;
  	}
    else {
      std::cout << str << " is NOT a palindrome" << std::endl;
    }


    return 0;
}
