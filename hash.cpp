#include <cstdio>
#include <iostream>
#include <string>

class hash {
    public:
    int hash_length;

    hash(string data) {
        string ord_values[] = {};
        string ord_string = "";

        // convert characters to ordinal values
        for (int i = 0; i < data.length(); i++) {
            ord_values[i] = int(char(data[i]));
        }

        // convert the ordinal values to a long string
        for (int i = 0; i < ord_values.length(); i++) {
            ord_string += char(ord_values[i]);
        }

        int ord_nums = int(ord_string) % data.length();
        int to_ret << std::hex << ord_nums;
        
        this -> hash_length = this -> hash_length(to_ret);
        return to_ret;
    }

    ~hash() {
        return 0;
    }
    private:
    int hash_length(int hash) {
        return hash.toString().length();
    }
};

int hash(string data) {
    
}