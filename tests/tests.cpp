#include <print>

int main() {
    auto const failure_count = stl_tests::tests();
    std::print("stl failure count: {}", failure_count);
    return failure_count != 0;
}