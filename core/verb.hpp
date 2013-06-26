
#pragma once

#include <map>
#include <sstream>
#include <iostream>
#include <fstream>

struct Verb {
	std::map<std::string, std::string> values;
	bool read(std::ifstream& in, const std::vector<std::string>& settings) {
		std::string line;
		bool accepted = false;
		while(in.good() && !in.eof()) {
			getline(in, line);
			if(line == "VERB_END")
				break;

			std::stringstream ss(line);
			std::string propertyName;
			std::string propertyValue;
			ss >> propertyName;

			if(propertyName == "CATEGORY") {
				ss >> propertyValue;
				for(size_t i=0; i<settings.size(); ++i) {
					if(settings[i] == propertyValue) {
						accepted = true;
					}
				}
				continue;
			}

			for(size_t i=0; i<settings.size(); ++i) {
				if(settings[i].size() <= propertyName.size()) {
					int counter = 0;
					for(size_t k=0; k<settings[i].size(); ++k) {
						if(settings[i][k] == propertyName[k]) {
							++counter;
						}
					}
					if(counter == settings[i].size()) {
						// read it!
						while(ss.peek() == ' ')
							ss.ignore(1);
						getline(ss, propertyValue);
						if(propertyValue != "")
							values[propertyName] = propertyValue;
					}
				}
			}
		}

		return accepted;
	}
};