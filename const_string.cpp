#include <string>
using namespace std;

class const_string {
  public:
    // Constructors
    const_string();
    const_string( const string& s );
    const_string( const char* s );
    const_string( const char* s, size_t length );
    const_string( const char* begin, const char* end );

    // Access methods
    const char* data() const { return mStr; }
    size_t      length() const { return mLength; }
    bool        is_empty() const { return mLength == 0; }
    char        operator[]( size_t index ) const { return this->at(index); }
    char        at( size_t index ) const;

  private:
    const char* mStr;
    size_t      mLength;
};

const_string::const_string() {
  mStr    = "";
  mLength = strlen(mStr);
}

const_string::const_string( const string& s ) {
  mStr    = s.c_str();
  mLength = s.length();
}

const_string::const_string( const char* s) {
  if (s) {
    mStr    = s;
    mLength = strlen(mStr);
  }
  else {
    mStr    = "";
    mLength = strlen(mStr);
  }
}

const_string::const_string( const char* s, size_t length ) {
  if (s) {
    mStr    = s;
    mLength = length;
  }
  else {
    mStr    = "";
    mLength = strlen(mStr);
  }
}

const_string::const_string( const char* begin, const char* end ) {
  if (begin && end) {
    mStr    = begin;
    mLength = end - begin;
  }
  else {
    mStr    = "";
    mLength = strlen(mStr);
  }
}

char const_string::at( size_t index ) const {
  if ( index < mLength ) {
    return *(mStr + index);
  }
  else {
    std::out_of_range oor = std::out_of_range( "Index out of range" );
    throw oor;
  }
}

static bool operator==(const const_string &s1, const const_string &s2) {
  return std::strcmp( s1.data(), s2.data() ) == 0;
}

static bool operator!=(const const_string &s1, const const_string &s2) {
  return !(s1 == s2);
}

static std::ostream& operator<<(std::ostream& os, const const_string s) {
  os << s.data();
  return os;
}
