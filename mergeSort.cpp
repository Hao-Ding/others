/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Wed  9/10 10:59:24 2014
 * Filename		: mergeSort.cpp
 * Description	: 
 * ******************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	void myMerge(vector<int> &src){
		divide(src, 0, src.size() - 1);		
	}
	void divide(vector<int> &src, int first, int last) {
        if (first < last) {
            int mid = (first + last) / 2;
            divide(src, first, mid);
            divide(src, mid + 1, last);
            merge(src, first, mid, last);
        }
	}
	void merge(vector<int> &va, int first, int mid, int last) {
		vector<int> res;
		int i = first, j = mid + 1;
		while (i <= mid && j <= last) {
			if (va.at(i) < va.at(j)) {
				res.push_back(va.at(i++));
			}
			else {
				res.push_back(va.at(j++));
			}
		}
		while (i <= mid) {
			res.push_back(va.at(i++));
		}
		while (j <= last) {
			res.push_back(va.at(j++));
		}
		for (int i = first; i <= last; ++i) {
			va.at(i) = res.at(i - first);
		}
	}
};

int main(int argc, char **argv) {
	vector<int> src;
	src.push_back(2);
	src.push_back(4);
	src.push_back(1);
	src.push_back(5);
	src.push_back(3);
	src.push_back(0);
	Solution *sol = new Solution();
	sol->myMerge(src);
	for (int i = 0; i < src.size(); ++i) {
		cout << src.at(i) << endl;
	}
	return 0;
}

