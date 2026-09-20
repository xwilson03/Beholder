#include <regex>
#include <sstream>

#include <rfl.hpp>
#include <rfl/yaml.hpp>

import beholder.types.Money;

using beholder::types::Money;


namespace rfl {

template <>
struct Reflector<Money> {

    using ReflType = std::string;
    static inline const std::regex pattern {R"(((\d+)\s*([csegp])p))"};

    static Money to(const ReflType& v) noexcept {

        auto words_begin = std::sregex_iterator(v.begin(), v.end(), pattern);
        auto words_end = std::sregex_iterator();

        Money out {};
        for (auto i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;

            std::uint32_t count = std::stoul(match[1]);
            char type = match[2].str()[0];

            switch(type){
                case 'c': out.copper   += count;
                case 's': out.silver   += count;
                case 'e': out.electrum += count;
                case 'g': out.gold     += count;
                case 'p': out.platinum += count;
            }
        }

        return out;
    }

    static ReflType from(const Money& m) {

        std::stringstream ss;
        
        if (m.platinum > 0) ss << m.platinum << "pp ";
        if (m.gold > 0)     ss << m.gold     << "gp ";
        if (m.electrum > 0) ss << m.electrum << "ep ";
        if (m.silver > 0)   ss << m.silver   << "sp ";
        if (m.copper > 0)   ss << m.copper   << "cp ";
        
        if (ss.tellp() == 0) return "0gp";

        std::string out = ss.str();
        out.pop_back();
        return out;
    }

};

} // namespace rfl
