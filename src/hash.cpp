#include <cstdio>
#include <iostream>
#include <string>

class Hash {
    public:
    int hash_length;

    Hash(const string data, const uint block_size, bool debug: False) {
        const uint data_length = data.length();
        list<uint> data_array = list<uint>();
        short int length_padding;

        // convert the string data into quadrants
        for (int i = 0; i < data_length; i+=block_size) {
            data_array.push_back(data.substr(i, block_size));
        }
        if(debug == True)
            printf("%s\n", data_array);

        // convert all quadrants to their ordinal counterparts.
        for (int i = 0; i < data_array.length(); i++) {
            uint* current_quad = &data_array[i];

            for (int j = 0; j < ((str)*current_quad).length(); j++) {
                *current_quad[j] = (uint)*current_quad[j];
            }
        }
        if (debug == True)
            printf("%s\n", data_array);

        // convert all ordinal quadrants into hexadecimal values
        for (int i = 0; i < data_array.length(); i++) {
            uint* current_quad = &data_array[i];

            *current_quad = std::hex << *current_quad;
        }
        if (debug == True)
            printf("%s\n", data_array);

        // combine all hexadecimal quadrants into one long unsigned integer value.
        string combined_string = "";
        for (int n = 0; n < data_array.length(); n++) {
            combined_string += data_array[n];
        }

        // append the length padding and return
        length_padding == (short int)data_array.length();
        length_padding |= 1 << sizeof(length_padding);

        (string)data_array += (string)length_padding;

        int result = (data_array.length() > 0) ? &data_array : 1;

        return result;
    }

    ~Hash() {
        return 0;
    }
    private:
    int hash_length(int hash) {
        return hash.toString().length();
    }
};