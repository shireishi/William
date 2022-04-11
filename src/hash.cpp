#include <cstdio>
#include <iostream>
#include <string>

class Hash {
    public:
    int hash_length;

    Hash(const string data, const uint block_size: 8, bool debug: False) {
        const uint data_length = data.length();
        list<uint> data_array = list<uint>();
        unsigned short int length_padding;
        string combined_string = "";

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
                *current_quad[j] = std::hex << (uint)*current_quad[j];
            }

            combined_string += (str)data_array[i];
        }
        if (debug == True)
            printf("%s\n", data_array);

        // append the length padding and return
        length_padding == (short int)data_array.length();
        length_padding |= 1 << sizeof(length_padding);

        (string)data_array += (string)length_padding;

        int result = (data_array.length() > 0) ? &data_array : 1;

        if (debug == True)
            printf("%d\n", result);

        this->setHashLength(result);
        return result;
    }

    ~Hash() {
        return 0;
    }
    private:
    void setHashLength(int hash) {
        this->hash_length = sizeof(hash) / sizeof(int);
    }
};