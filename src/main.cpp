#include <format>
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <vector>

auto show_binary(uint8_t *data, size_t size) -> void
{
    auto           row_index   = 0;
    constexpr auto max_columns = 16;

    // print header
    std::cout << "\e[34m";
    std::cout << std::format("{:9}", "Offset");
    for (size_t i = 0; i < max_columns; ++i)
    {
        std::cout << std::format(" +{:01X}", i);
    }
    std::cout << "  ASCII\n";
    std::cout << "\e[0m";

    for (size_t i = 0; i < size; i += max_columns)
    {
        std::cout << std::format("{:08x}  ", row_index);

        // print hex values
        for (size_t j = 0; j < max_columns; ++j)
        {
            if (i + j < size)
            {
                std::cout << std::format("{:02x} ", data[i + j]);
            }
            else
            {
                std::cout << "   ";
            }
        }

        std::cout << " ";

        // print ascii representation
        for (size_t j = 0; j < max_columns; ++j)
        {
            if (i + j < size)
            {
                uint8_t byte = data[i + j];
                if (byte >= 32 && byte <= 126)
                {
                    std::cout << static_cast<char>(byte);
                }
                else
                {
                    std::cout << ".";
                }
            }
        }

        std::cout << "\n";
        row_index += max_columns;
    }
}

auto main(int argc, char *argv[]) -> int
{
    // if path is provided, read from file instead of stdin
    if (argc > 1)
    {
        std::ifstream file(argv[1], std::ios::binary);
        if (!file)
        {
            std::cerr << "Failed to open file: " << argv[1] << "\n";
            return 1;
        }
        auto data = std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
        show_binary(data.data(), data.size());
        return 0;
    }

    auto data = std::vector<uint8_t>(std::istreambuf_iterator<char>(std::cin), {});
    show_binary(data.data(), data.size());

    return 0;
}
