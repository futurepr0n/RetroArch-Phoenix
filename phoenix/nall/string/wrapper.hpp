#ifndef NALL_STRING_WRAPPER_HPP
#define NALL_STRING_WRAPPER_HPP

namespace nall {

unsigned string::length() const { return strlen(data); }

bool string::equals(const char *str) const { return !strcmp(data, str); }
bool string::iequals(const char *str) const { return !istrcmp(data, str); }

bool string::wildcard(const char *str) const { return nall::wildcard(data, str); }
bool string::iwildcard(const char *str) const { return nall::iwildcard(data, str); }

bool string::beginswith(const char *str) const { return strbegin(data, str); }
bool string::ibeginswith(const char *str) const { return istrbegin(data, str); }

bool string::endswith(const char *str) const { return strend(data, str); }
bool string::iendswith(const char *str) const { return istrend(data, str); }

string& string::lower() { nall::strlower(data); return *this; }
string& string::upper() { nall::strupper(data); return *this; }
string& string::qlower() { nall::qstrlower(data); return *this; }
string& string::qupper() { nall::qstrupper(data); return *this; }
string& string::transform(const char *before, const char *after) { nall::strtr(data, before, after); return *this; }

template<unsigned limit> string& string::ltrim(const char *key) { nall::ltrim<limit>(data, key); return *this; }
template<unsigned limit> string& string::rtrim(const char *key) { nall::rtrim<limit>(data, key); return *this; }
template<unsigned limit> string& string::trim(const char *key, const char *rkey) { nall::trim <limit>(data, key, rkey); return *this; }

optional<unsigned> string::position(const char *key) const { return strpos(data, key); }
optional<unsigned> string::iposition(const char *key) const { return istrpos(data, key); }
optional<unsigned> string::qposition(const char *key) const { return qstrpos(data, key); }
optional<unsigned> string::iqposition(const char *key) const { return iqstrpos(data, key); }

}

#endif
