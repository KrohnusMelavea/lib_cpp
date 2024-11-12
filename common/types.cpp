#include "types.hpp"

template <> bool is_datetime<"YYYY-MM-DD hh:mm:ss">(std::string_view const dt) noexcept {
 static constexpr u08 days[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 if (std::size(dt) != 19) [[unlikely]] { return false; }
 if (!is_digit(dt[0]) || !is_digit(dt[1]) || !is_digit(dt[2]) || !is_digit(dt[3])) [[unlikely]] { return false; }
 if (dt[4] != '-') [[unlikely]] { return false; }
 if (!is_digit(dt[5]) || !is_digit(dt[6])) [[unlikely]] { return false; }
 if (dt[7] != '-') [[unlikely]] { return false; }
 if (!is_digit(dt[8]) || !is_digit(dt[9])) [[unlikely]] { return false; }
 if ((dt[5]-'0') * 10 + (dt[6]-'0') == 2 && ((dt[2]-'0') * 10 + (dt[3]-'0')) % 4 == 0 && (dt[8]-'0') * 10 + (dt[9]-'0') > 29) [[unlikely]] { return false; } 
 else if ((dt[8]-'0') * 10 + (dt[9]-'0') > days[(dt[5]-'0') * 10 + (dt[6]-'0') - 1]) [[unlikely]] { return false; }
 if (dt[10] != ' ') [[unlikely]] { return false; }
 if (!is_digit(dt[11]) || !is_digit(dt[12])) [[unlikely]] { return false; }
 if ((dt[11]-'0') * 10 + (dt[12]-'0') >= 24) [[unlikely]] { return false; }
 if (dt[13] != ':') [[unlikely]] { return false; }
 if (!is_digit(dt[14]) || !is_digit(dt[15])) [[unlikely]] { return false; }
 if ((dt[14]-'0') * 10 + (dt[15]-'0') >= 60) [[unlikely]] { return false; }
 if (dt[16] != ':') [[unlikely]] { return false; }
 if (!is_digit(dt[17]) || !is_digit(dt[18])) [[unlikely]] { return false; }
 if ((dt[17]-'0') * 10 + (dt[18]-'0') >= 60) [[unlikely]] { return false; }
 return true;
}