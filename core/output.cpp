
#include "output.hpp"
#include "util/edit_distance.hpp"

#include <iostream>

bool isTense(const std::string& tense, const std::string& p) {
	if(tense.length() > p.length()) return false;
	bool ok = true;
	for(int i=0; i<tense.length(); ++i) {
		ok &= (tense[i] == p[i]);
	}
	return ok;
}

std::string getTimeString(const std::string& p) {
	if(isTense("PRESENT", p)) return "Present";
	if(isTense("IMPARFAIT", p)) return "Imperfect";
	if(isTense("CONDITIONAL", p)) return "Conditional";
	if(isTense("FUTURE", p)) return "Future";
	if(isTense("IMPERATIVE", p)) return "Imperative";
	return "";
}

std::string getPersonString(const std::string& p) {
	if(p[p.size()-1] == '1' && p[p.size()-2] == 'S') return "1st singular";
	if(p[p.size()-1] == '2' && p[p.size()-2] == 'S') return "2nd singular";
	if(p[p.size()-1] == '3' && p[p.size()-2] == 'S') return "3rd singular";
	if(p[p.size()-1] == '1' && p[p.size()-2] == 'P') return "1st plural";
	if(p[p.size()-1] == '2' && p[p.size()-2] == 'P') return "2nd plural";
	if(p[p.size()-1] == '3' && p[p.size()-2] == 'P') return "3rd plural";
	return "";
}

std::string outputProperty(const std::string& p) {
	if(p == "ENGLISH") return "English Infinitive";
	if(p == "INFINITIVE") return "Infinitive";
	if(p == "PASTPARTICIPLE") return "Past participle";
	return getTimeString(p) + " " + getPersonString(p);
}

std::string outputPronom(const std::string& p) {
	if(p[p.size()-1] == '1' && p[p.size()-2] == 'S') return "je";
	if(p[p.size()-1] == '2' && p[p.size()-2] == 'S') return "tu";
	if(p[p.size()-1] == '3' && p[p.size()-2] == 'S') return "il/elle";
	if(p[p.size()-1] == '1' && p[p.size()-2] == 'P') return "nous";
	if(p[p.size()-1] == '2' && p[p.size()-2] == 'P') return "vous";
	if(p[p.size()-1] == '3' && p[p.size()-2] == 'P') return "ils";
	return "";
}

void outputSinglePuzzle(int index, const std::string& property, const std::string& value, const std::string& propertyAsked) {
	std::cout << "<input type=\"hidden\" name=\"INDEX[]\" value=\"" << index << "\">\n";
	std::cout << "<input type=\"hidden\" name=\"PROPERTY[]\" value=\"" << propertyAsked << "\">\n";
	std::cout << "<table id=\"marginTable\">\n";
	std::cout << "<tr><th width=\"165px\">" << outputProperty(property) << "</th><td width=\"50px\"><center>" << outputPronom(property) << "</center></td><td><center>" << value << "</center></td></tr>\n";
	std::cout << "<tr><th width=\"165px\">" << outputProperty(propertyAsked) << "</th><td width=\"50px\"><center>" << outputPronom(propertyAsked) << "</center></td><td><input type=\"text\" name=\"ANSWER[]\">\n";
	std::cout << "</table>\n";
}


int outputSingleGrade(const Verb& v, const std::string& propertyName, const std::string& propertyValue, const std::string& guess) {
	int distance = editDistance(propertyValue, guess);
	std::cout << guess << " is ";

	if(propertyValue == guess) {
		 std::cout << "<font color=\"green\"><strong>correct! +5 points!</strong></font>\n";
		 return +5;
	}
	else if(distance == 1) {
		std::cout << "<font color=\"#728C00\"><strong>almost correct, +3 points</strong></font> correct answer: " << propertyValue << "\n";
		return +3;
	}
	else if(distance == 2) {
		std::cout << "<font color=\"orange\"><strong>right direction, +1 point</strong></font>, correct answer: " << propertyValue << "\n";
		return +1;
	}
	else {
		std::cout << "<font color=\"red\">wrong! half of your score is lost!</font> :(  right answer: " << propertyValue << "\n";
		return -1;
	}
}

void outputFindWord(const std::vector<Verb>& verbs, const std::string& findStr) {
	int minDistance = 100000000;
	int verbIndex = -1;
	for(size_t i=0; i<verbs.size(); ++i) {
		for(auto it = verbs[i].values.begin(); it != verbs[i].values.end(); ++it) {
			int dist = editDistance(findStr, it->second);
			if(dist < minDistance) {
				minDistance = dist;
				verbIndex = i;
			}
		}
	}
	std::cout << "<div style=\"padding-top:25px\">\n";
	std::cout << "<table>\n";
	Verb v = verbs[verbIndex];
	for(auto it = v.values.begin(); it != v.values.end(); ++it) {
		std::cout << "<tr><th align=\"left\">" << outputProperty(it->first) << "</th><td align=\"center\" width=\"50px\">" << outputPronom(it->first) << "</td><td align=\"center\">" << it->second << "</td></tr>\n";
	}
	std::cout << "</table>\n";
	std::cout << "</div>\n";
}