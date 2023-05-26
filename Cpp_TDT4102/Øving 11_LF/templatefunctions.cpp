#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
void shuffle(std::vector<T>& vec){
    for (size_t i = 0; i < vec.size() - 1; i++){
        int j = rand() % (vec.size() - i);
        std::swap(vec[i], vec[i + j]);
    }
}

template<typename T>
T maximum(T a, T b){
    if (b < a){
        return a;
    }
    return b;
    // Alternativt: Ternary operator
    // return b < a ? a : b;
}


void testTemplateFunctions(){
    std::cout << "Template functions:\n";
    srand(time(nullptr));

    std::cout << "maximum(1, 2) = " << maximum(1, 2) << '\n';
    std::cout << "maximum(1.0, 2.3) = " << maximum(1.0, 2.3) << '\n';
    std::cout << "maximum('X', 'Y') = " << maximum('X', 'Y') << '\n';
    std::cout << "maximum(string(\"tre\"), string(\"fire\")) = " << maximum(std::string("tre"), std::string("fire")) << '\n';

    std::vector<int> a{1,2,3,4,5,6,7};
    shuffle(a);
    for (auto x : a) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    std::vector<double> b{1.1, 2.2, 3.3, 4.4};
    shuffle(b);
    for (auto x : b) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    std::vector<std::string> c{"one", "two", "three", "four"};
    shuffle(c);
    for (const auto& x : c){
        std::cout << x << " ";
    }
    std::cout << "\n\n";
}
