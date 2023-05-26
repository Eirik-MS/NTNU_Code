#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <set>

void replace(std::vector<std::string> &vec, const std::string& old, std::string replacement){
    // it has type vector<string>::iterator
    for(auto it = vec.begin(); it != vec.end(); ++it){	// Iterates through the vector
        if(*it == old){				// When a matching string is found
            it = vec.erase(it);		// it is erased
            it = vec.insert(it, replacement);	// and the new string is inserted at the current position
        }
    }
    // Alternativt <algorithm>
    // std::replace(vec.begin(), vec.end(), old, replacement);
}

void replace(std::set<std::string>& s, const std::string& old, std::string replacement) {
    // it has type set<string>::iterator
    for(auto it = s.begin(); it != s.end(); ++it){	// Iterates through the set
        if(*it == old){				// When a matching string is found
            it = s.erase(it);		// it is erased
            it = s.insert(it, replacement);	// and the new string is inserted at the current position
        }
    }
    // Alternativt med medlemsfunksjoner:
    // s.erase(old);
    // s.insert(replacement);
}

void iterators_vec(){
    std::cout << "Vector iterators:\n";
    std::vector<std::string> v;
    v.push_back("C++");
    v.push_back("and");
    v.push_back("iterators");
    v.push_back("are");
    v.push_back("power");

    // vit has type vector<string>::iterator
    for (auto vit = v.begin(); vit != v.end(); ++vit)
        std::cout << *vit << " ";

    // Alternativt <algorithm>
    // std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));

    std::cout << '\n';

    // rit has type vector<string>::reverse_iterator
    for (auto rit=v.rbegin(); rit != v.rend(); ++rit){
        std::cout << *rit << " ";
    }

    // Alternativt <algorithm>
    // std::copy(v.rbegin(), v.rend(), std::ostream_iterator<std::string>(std::cout, " "));

    std::cout << '\n';

    replace(v, "are", "is");

    for (auto rit=v.rbegin(); rit < v.rend(); ++rit ){
        std::cout << *rit << " ";
    }
    std::cout << "\n\n";

}

void iterators_set() {
    std::cout << "Set iterators:\n";
    std::set<std::string> s;
    s.insert("Lorem");
    s.insert("Ipsum");
    s.insert("Dolor");
    s.insert("Sit");
    s.insert("Amet");

    // sit has type set<string>::iterator
    for (auto sit = s.begin(); sit != s.end(); ++sit)
        std::cout << *sit << " ";

    // Alternativt <algorithm>
    // std::copy(s.begin(), s.end(), std::ostream_iterator<std::string>(std::cout, " "));

    std::cout << '\n';

    // rit has type set<string>::reverse_iterator
    for (auto rit=s.rbegin(); rit != s.rend(); ++rit){
        std::cout << *rit << " ";
    }

    // Alternativt <algorithm>
    // std::copy(s.rbegin(), s.rend(), std::ostream_iterator<std::string>(std::cout, " "));

    std::cout << '\n';

    replace(s, "Lorem", "Latin");

    for (auto rit=s.rbegin(); rit != s.rend(); ++rit){
        std::cout << *rit << " ";
    }
    std::cout << "\n\n";
}
