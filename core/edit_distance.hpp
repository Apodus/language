
#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace {

int editDistance(const std::string& a, const std::string& b) {
	std::vector<std::vector<int>> m;
	m.resize(a.size() + 1);
	for(int i=0; i<m.size(); ++i) {
		std::vector<int>& internal = m[i];
		internal.resize(b.size() + 1, 0);
	}

	for(size_t i = 1; i < m.size(); ++i) m[i][0] = i;
	for(size_t i = 1; i < m[0].size(); ++i) m[0][i] = i;

	for(size_t i = 1; i < m.size(); ++i) {
		for(size_t k = 1; k < m[0].size(); ++k) {
			if(a[i-1] == b[k-1]) {
				m[i][k] = m[i-1][k-1];
			}
			else {
				int min = std::min(m[i-1][k]+1, m[i][k-1]+1);
				min = std::min(min, m[i-1][k-1]+1);
				m[i][k] = min;
			}
		}
	}

	return m.back().back();
}

}
