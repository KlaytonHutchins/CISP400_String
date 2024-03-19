#include "string.h"
#include <cstring>

namespace String {
	string::string() {
		// cout << "Constructing empty string" << endl;
		len = 0;
		buffer = nullptr;
	}

	string::string(const char s[]) {
		// cout << "Constructing \"" << s << "\"" << endl;
		len = strlen(s);
		if (len > 0) {
			buffer = new char[len];
			for (int i = 0; i < len; i++) {
				buffer[i] = s[i];
			}
		} else {
			buffer = nullptr;
		}
	}

	string::string(const string& other) {
		// cout << "Copying \"" << other << "\"" << endl;
		len = other.len;
		if (len > 0) {
			buffer = new char[len];
			for (int i = 0; i < len; i++) {
				buffer[i] = other.buffer[i];
			}
		} else {
			buffer = nullptr;
		}
	}

	string& string::operator=(const string& other) {
		// cout << "Assigning \"" << other << "\" to \"" << *this << "\"" << endl;
		if (this != &other) {
			delete[] buffer;
			len = other.len;
			if (len > 0) {
				buffer = new char[len];
				for (int i = 0; i < len; i++) {
					buffer[i] = other.buffer[i];
				}
			} else {
				buffer = nullptr;
			}
		}
		return *this;
	}

	string::~string() {
		// cout << "Destroying \"" << *this << "\"" << endl;
		delete[] buffer;
	}

	int string::length() const {
		return len;
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
		string result;
		result.len = len + other.len;
		result.buffer = new char[result.len];
		for (int i = 0; i < len; i++) {
			result.buffer[i] = buffer[i];
		}
		for (int i = 0; i < other.len; i++) {
			result.buffer[len + i] = other.buffer[i];
		}
		return result;
	}

	string string::operator+(const char& ch) const {
		string result;
		result.len = len + 1;
		result.buffer = new char[result.len];
		for (int i = 0; i < len; i++) {
			result.buffer[i] = buffer[i];
		}
		result.buffer[len] = ch;
		return result;
	}

	bool string::operator==(const string& other) const {
		if (len != other.len) {return false;}
		for (int i = 0; i < len; i++) {
			if (buffer[i] != other.buffer[i]) {return false;}
		}
		return true;
	}

	int string::find(const char* s, int pos) const {
		if (pos < 0 || pos >= len || !buffer) {return -1;}
		int sLen = strlen(s);
		if (sLen < 0 || pos > len - sLen) {return -1;}
		for (int i = pos; i <= len - sLen; i++) {
			if (buffer[i] == s[0]) {
				bool found = true;
				for (int j = 0; j < sLen; j++) {
					if (buffer[i + j] != s[j]) {
						found = false;
						break;
					}
				}
				if (found) {return i;}
			}
		}
		return -1;
	}

	/*string string::substr(int start, int length) const {
		string result;
		if (length > 0) {
			result.len = length;
			result.buffer = new char[length];
			for (int i = 0; i < length; i++) {
				result.buffer[i] = buffer[start + i];
			}
		} else {
			result.len = 0;
			result.buffer = nullptr;
		}
		return result;
	}*/

	void string::print(ostream& out) const {
	
	}



	ostream& operator<<(ostream& out, const string& str) {
		for (int i = 0; i < str.length(); i++) {
			out << str[i];
		}
		return out;
	}

	istream& operator>>(istream& in, string& str) {
		char c;
		str = "";
		while (in.get(c) && !isspace(c)) {
			str = str + c;
		}
		in >> c;
		return in;
	}

	bool operator!=(const string& s, const string& t) {
		return true;
	}

	bool operator>(const string& lhs, const string& rhs) {
		for (int i = 0; i < lhs.length(); i++) {
			if (lhs[i] == rhs[i]) {
				continue;
			} else if (lhs[i] > rhs[i]) {
				return true;
			} else {
				return false;
			}
		}
		return false;
	}
}
