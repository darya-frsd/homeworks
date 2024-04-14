#include <iostream>
#include <iomanip>
#include <limits>

void invert_bits(unsigned char* ptr, size_t first_byte, size_t len_bytes, size_t step) {
    for (size_t i = first_byte; i < first_byte + len_bytes; ++i) {
        for (size_t j = 0; j < sizeof(unsigned char) * 8; ++j) {
            if (j % step == 0) {
                ptr[i] ^= (static_cast<unsigned char>(1) << j);
            }
        }
    }
}

void print_bits(const unsigned char* ptr, size_t size_bytes) {
    for (size_t i = 0; i < size_bytes; ++i) {
        for (size_t j = 0; j < 8; ++j) {
            std::cout << ((ptr[i] >> (7 - j)) & 1);
        }
        std::cout << " ";
    }
    std::cout << "\n";
}

int main() {
    const size_t array_size = 16;
    unsigned char a[array_size] = {0x12, 0x34, 0x56, 0x71, 0xFB, 0xC0, 0x00, 0x45};

    int len_bytes, first_byte, step;

    do {
        std::cout << "Enter the byte position from which you want to start inverting (0-" << array_size - 1 << "): ";
        if (!(std::cin >> first_byte) || first_byte < 0 || first_byte >= array_size) {
            std::cout << "Invalid input. Please enter a number between 0 and " << array_size - 1 << "." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);

    do {
        std::cout << "Enter length in bytes: ";
        if (!(std::cin >> len_bytes) || len_bytes <= 0 || len_bytes > array_size) {
            std::cout << "Invalid input. Please enter a positive number less than or equal to " << array_size << "." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);

    do {
        std::cout << "Select which bits you want to invert (integers are acceptable and will be the step): ";
        if (!(std::cin >> step) || step <= 0) {
            std::cout << "Invalid input. Please enter a positive number." << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);

    std::cout << "Initial bits for a: ";
    print_bits(a, array_size);

    invert_bits(a, first_byte, len_bytes, step);

    std::cout << "Inverted bits for a: ";
    print_bits(a, array_size);

    return 0;
}
