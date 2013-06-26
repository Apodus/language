
#pragma once

#include <string>
#include <vector>
#include <fstream>

namespace {
	void loadSettings(const std::string& userID, std::vector<std::string>& settings) {
		std::string fileName = std::string("users/") + userID;
		std::ifstream in(fileName);
		while(in.good() && !in.eof()) {
			std::string line;
			getline(in, line);
			if(line != "")
				settings.push_back(line);
		}
	}

	void saveSettings(const std::string& userID, const std::vector<std::string>& settings) {
		std::string fileName = std::string("users/") + userID;
		std::ofstream out(fileName);
		for(size_t i=0; i<settings.size(); ++i) {
			out << settings[i] << std::endl;
		}
	}

	long long loadScore(const std::string& userID) {
		long long score = 0;
		std::string fileName = std::string("users/score_") + userID;
		std::ifstream in(fileName);
		in >> score;
		return score;
	}

	void saveScore(const std::string& userID, long long score) {
		std::string fileName = std::string("users/score_") + userID;
		std::ofstream out(fileName);
		out << score;
	}
}