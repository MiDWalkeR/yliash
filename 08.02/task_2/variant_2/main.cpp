#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//!< Print content of vector
//!< param[in] reference to vector
//
//!< \return None 
void print_out(vector<int> const &vector_to_display)
{
    for(auto const &i: vector_to_display)
    {
        cout << i << ' ';
    }

    cout << endl;
}

int main()
{
    vector<int> test_vector = {1, 2, 3, 4, 5, 6};
    print_out(test_vector);

    //!< Move first k elements to the end
    //!< param[in] reference to vector
    //!< param[in] k -- how much elements to move
    //
    //!< \return None 
    auto generateKVector =
        [] (vector<int> &vector_in, const size_t k) {
            assert(vector_in.size() >= k);

            for(size_t i = 0; i < k; ++i)
            {
                vector_in.push_back(vector_in[i]);
            }

            vector_in.erase(vector_in.begin(), next(vector_in.begin(), k));
        };
    
    generateKVector(test_vector, 2);

    print_out(test_vector);

    return 0;
}
