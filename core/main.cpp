
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

#include "output.hpp"
#include "verb.hpp"
#include "util/edit_distance.hpp"
#include "userSettings.hpp"

void editTest(const std::string& a, const std::string& b) {
	std::cout << a << " <-> " << b << " : " << editDistance(a, b) << std::endl;
}

int main(int argc, char** argv) {
	
	if(argc >= 3) {
		int currentArgument = 0;
		std::string userID = argv[++currentArgument];
		std::string secondArg = argv[++currentArgument];

		std::vector<std::string> settings;
		loadSettings(userID, settings);

		if(secondArg == "HAS_SETTING") {
			std::string askedSetting = argv[++currentArgument];
			for(size_t i=0; i<settings.size(); ++i) {
				if(askedSetting == settings[i]) {
					std::cout << "checked";
					return 0;
				}
			}
			return 0;
		}
		else if(secondArg == "GET_SCORE") {
			std::cout << loadScore(userID);
			return 0;
		}

		std::vector<Verb> verbs;

		{
			std::string line;
			std::ifstream in("data/verbs.list");
			while(in.good() && !in.eof()) {
				getline(in, line);
				if(line == "VERB_BEGIN") {
					Verb v;
					if(v.read(in, settings))
						verbs.push_back(v);
				}
			}
		}

		
		if(secondArg == "PUZZLE1") {
			// get some simple puzzles
			std::cout << "<form action=\"index.php\" method=\"post\">\n";
			srand(static_cast<unsigned>(time(0)));

			for(int i=0; i<5; ++i) {
				int index = rand() % verbs.size();
				Verb& v = verbs[index];

				if(v.values.size() < 2)
					break;

				int propertyIndex = rand() % v.values.size();
				auto it = v.values.begin();
				for(int i=0; i<propertyIndex; ++i) ++it;
				std::string property = it->first;
				std::string value = it->second;

				int propertyIndex2 = rand() % (v.values.size()-1);
				if(propertyIndex2 >= propertyIndex) ++propertyIndex2;
				auto it2 = v.values.begin();
				for(int i=0; i<propertyIndex2; ++i) ++it2;
				outputSinglePuzzle(index, property, value, it2->first);
			}
			std::cout << "<table><tr><th>Submit:</th><td><input type=\"submit\"></td></tr></table>\n";
			std::cout << "</form>\n";
		}
		else if(secondArg == "GRADE1") {
			// grade opponent's answer to a single puzzle!
			std::stringstream ss(argv[++currentArgument]);
			int index;
			ss >> index;
			std::string propertyName = argv[++currentArgument];
			std::string propertyValue = argv[++currentArgument];

			const Verb& v = verbs[index];
			const std::string& val = v.values.find(propertyName)->second;
			
			long long userScore = loadScore(userID);
			int score = outputSingleGrade(v, propertyName, val, propertyValue);
			if(score > 0)
				userScore += score;
			else
				userScore /= 2;
			saveScore(userID, userScore);
			std::cout << " score: " << userScore << "<br/>" << std::endl;
		}
		else if(secondArg == "FIND") {
			std::string findStr = argv[++currentArgument];
			for(int i=3; i<argc; ++i) {
				findStr += " ";
				findStr += argv[i];
			}
			outputFindWord(verbs, findStr);
		}
		else if(secondArg == "SETTINGS") {
			std::vector<std::string> user_settings;
			while(currentArgument+1 < argc) {
				user_settings.push_back(std::string(argv[++currentArgument]));
			}

			saveSettings(userID, user_settings);
			std::cout << "<h2>Settings Saved!</h2>\n";
		}
	}
	
	return 0;
}