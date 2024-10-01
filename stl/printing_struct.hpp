#pragma once

#include <iostream>
#include <type_traits>
#include "types.hpp"

namespace stl {
 template <class T> struct printing_struct {
  T v;

  printing_struct() requires(std::is_default_constructible_v<T>) : v{} {
   std::cout << "printing_struct()\n";
  }
  printing_struct(u64 const v) requires(std::is_copy_constructible_v<T>) : v{v} {
   std::cout << "printing_struct(u64)\n";
  }
  printing_struct(printing_struct const& s) requires(std::is_copy_constructible_v<T>) : v{s.v} {
   std::cout << "printing_struct(const&)\n";
  }
  printing_struct(printing_struct&& s) requires(std::is_move_constructible_v<T>) : v{s.v} {
   std::cout << "printing_struct(&&)\n";
  }
  ~printing_struct() requires(std::is_destructible_v<T>) {
   std::cout << "~printing_struct()\n";
  }

  void operator=(printing_struct const& s) requires(std::is_copy_assignable_v<T>) {
   std::cout << "printing_struct::=(const&)\n";
   this->v = s.v;
  }
  void operator=(printing_struct&& s) requires(std::is_move_assignable_v<T>) {
   std::cout << "printing_struct::=(&&)\n";
   this->v = s.v;
  }
  printing_struct operator+(printing_struct const& s) requires IsAddableWithSelf<T> {
   std::cout << "printing_struct::+(const&)\n";
   return printing_struct{this->v + s.v};
  }
  printing_struct operator+(printing_struct const& s) const requires IsAddableWithSelf<T> {
   std::cout << "printing_struct::+(const&)const\n";
   return printing_struct{this->v + s.v};
  }
  printing_struct operator-(printing_struct const& s) requires IsSubtractableWithSelf<T> {
   std::cout << "printing_struct::-(const&)\n";
   return printing_struct{this->v - s.v};
  }
  printing_struct operator-(printing_struct const& s) const requires IsSubtractableWithSelf<T> {
   std::cout << "printing_struct::-(const&)const\n";
   return printing_struct{this->v - s.v};
  }
  printing_struct operator*(printing_struct const& s) requires IsMultipliableWithSelf<T> {
   std::cout << "printing_struct::*(const&)\n";
   return printing_struct{this->v * s.v};
  }
  printing_struct operator*(printing_struct const& s) const requires IsMultipliableWithSelf<T> {
   std::cout << "printing_struct::*(const&)const\n";
   return printing_struct{this->v * s.v};
  }
  printing_struct operator/(printing_struct const& s) requires IsDividableWithSelf<T> {
   std::cout << "printing_struct::/(const&)\n";
   return printing_struct{this->v / s.v};
  }
  printing_struct operator/(printing_struct const& s) const requires IsDividableWithSelf<T> {
   std::cout << "printing_struct::/(const&)const\n";
   return printing_struct{this->v / s.v};
  }
  printing_struct operator%(printing_struct const& s) requires IsModableWithSelf<T> {
   std::cout << "printing_struct::%(const&)\n";
   return printing_struct{this->v % s.v};
  }
  printing_struct operator%(printing_struct const& s) const requires IsModableWithSelf<T> {
   std::cout << "printing_struct::%(const&)const\n";
   return printing_struct{this->v % s.v};
  }
  printing_struct operator|(printing_struct const& s) requires IsORableWithSelf<T> {
   std::cout << "printing_struct::|(const&)\n";
   return printing_struct{this->v | s.v};
  }
  printing_struct operator|(printing_struct const& s) const requires IsORableWithSelf<T> {
   std::cout << "printing_struct::|(const&)const\n";
   return printing_struct{this->v | s.v};
  }
  printing_struct operator&(printing_struct const& s) requires IsANDableWithSelf<T> {
   std::cout << "printing_struct::&(const&)\n";
   return printing_struct{this->v & s.v};
  }
  printing_struct operator&(printing_struct const& s) const requires IsANDableWithSelf<T> {
   std::cout << "printing_struct::&(const&)const\n";
   return printing_struct{this->v & s.v};
  }
  printing_struct operator>>(printing_struct const& s) requires IsRightShiftableWithSelf<T> {
   std::cout << "printing_struct::>>(const&)\n";
   return printing_struct{this->v >> s.v};
  }
  printing_struct operator>>(printing_struct const& s) const requires IsRightShiftableWithSelf<T> {
   std::cout << "printing_struct::>>(const&)const\n";
   return printing_struct{this->v >> s.v};
  }
  printing_struct operator<<(printing_struct const& s) requires IsLeftShiftableWithSelf<T> {
   std::cout << "printing_struct::<<(const&)\n";
   return printing_struct{this->v << s.v};
  }
  printing_struct operator<<(printing_struct const& s) const requires IsLeftShiftableWithSelf<T> {
   std::cout << "printing_struct::<<(const&)const\n";
   return printing_struct{this->v << s.v};
  }
  printing_struct& operator+=(printing_struct const& s) requires IsAddAssignableWithSelf<T> {
   std::cout << "printing_struct::+=(const&)\n";
   this->v += s.v;
   return *this;
  }
  printing_struct& operator-=(printing_struct const& s) requires IsSubtractAssignableWithSelf<T> {
   std::cout << "printing_struct::-=(const&)\n";
   this->v -= s.v;
   return *this;
  }
  printing_struct& operator*=(printing_struct const& s) requires IsMultiplyAssignableWithSelf<T> {
   std::cout << "printing_struct::*=(const&)\n";
   this->v *= s.v;
   return *this;
  }
  printing_struct& operator/=(printing_struct const& s) requires IsDivideAssignableWithSelf<T> {
   std::cout << "printing_struct::/=(const&)\n";
   this->v /= s.v;
   return *this;
  }
  printing_struct& operator%=(printing_struct const& s) requires IsModAssignableWithSelf<T> {
   std::cout << "printing_struct::%=(const&)\n";
   this->v %= s.v;
   return *this;
  }
  printing_struct& operator|=(printing_struct const& s) requires IsORAssignableWithSelf<T> {
   std::cout << "printing_struct::|=(const&)\n";
   this->v |= s.v;
   return *this;
  }
  printing_struct& operator&=(printing_struct const& s) requires IsANDAssignableWithSelf<T> {
   std::cout << "printing_struct::&=(const&)\n";
   this->v &= s.v;
   return *this;
  }
 };
}