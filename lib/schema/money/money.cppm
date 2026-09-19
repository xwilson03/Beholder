module;
#include <cstdint>
export module beholder.types.Money;

export namespace beholder::types {

struct Money
{
    std::uint32_t copper = 0;
    std::uint32_t silver = 0;
    std::uint32_t electrum = 0;
    std::uint32_t gold = 0;
    std::uint32_t platinum = 0;

    bool operator==(const Money&) const = default;
};

} // namespace beholder::types
