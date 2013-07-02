
#include <string>
#include <vector>

class utf8 {
public:
	static bool seemsLegit(const std::string& str);
	int length() const;
	int size() const {return length();}
	
	utf8(const std::string& str);
	const int& operator[] (int index) const;
	int& operator[] (int index);

	friend std::ostream& operator << (std::ostream& out, const utf8& str);
	
private:
	std::vector<int> string;
};
