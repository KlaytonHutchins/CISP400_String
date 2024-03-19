#include "string.h"
#include <cstring>

namespace String {
        string::string() {
                // cout << "Constructing empty string" << endl;
        }

        string::string(const char s[]) {
                // cout << "Constructing \"" << s << "\"" << endl;
        }

        string::string(const string& other) {
                // cout << "Copying \"" << other << "\"" << endl;
        }

        string& string::operator=(const string& other) {
                // cout << "Assigning \"" << other << "\" to \"" << *this << "\"" << endl;
        }

        string::~string() {
                // cout << "Destroying \"" << *this << "\"" << endl;
        }

        int string::length() const {
        }

        int string::size() const {
                return strlen(buffer);
        }

        char& string::operator[](int i) {
                return buffer[i];
        }

        const char& string::operator[](int i) const {
                return buffer[i];
        }

        string string::operator+(const string& other) const {
        }

        string string::operator+(const char& ch) const {
        }

        bool string::operator==(const string& other) const {
        }

        int string::find(const char* s, int pos) const {
        }

        //string string::substr(int start, int length) const {}

        void string::print(ostream& out) const {
        }

        ostream& operator<<(ostream& out, const string& str) {
        }

        istream& operator>>(istream& in, string& str) {
        }

        bool operator!=(const string& s, const string& t) {
        }

        bool operator>(const string& lhs, const string& rhs) {
        }
}
