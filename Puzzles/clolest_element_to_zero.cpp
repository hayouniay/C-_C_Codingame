#ifdef CPP
	#include <vector>
	#include <algorithm>
	#include <iostream>

	using namespace std;

	/* clolest element to an integer C++ code */
	int clolest_tozero(vector<int> ts, int x) {
		sort(ts.begin(), ts.end());
		auto iter_geq = std::lower_bound(
			ts.begin(), 
			ts.end(), 
			x
		);

		if (iter_geq == ts.begin()) {
			return 0;
		}

		int a = *(iter_geq - 1);
		int b = *(iter_geq);

		if (abs(x - a) < abs(x - b)) {
			return ts[iter_geq - ts.begin() - 1];
		}

		return ts[iter_geq - ts.begin()];
}

#else
	/* clolest element to zero C code */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>

	int clolest_tozero(int ts[], int size){
		int clolest = ts[0];
		int current = 0;

		//sorting
		for(int i=0; i<size;i++){
			for(int j=0; j<size; j++){
				if(ts[j]>ts[i]){
					int tmp = ts[i];
					ts[i]=ts[j];
					ts[j]=tmp;
				}
			}
		}

		for(int i=0; i<size; i++){
			current = ts[i]*ts[i];
			if(current <= (clolest*clolest)){
				clolest = ts[i];
			}
		}

		return clolest;
	}

#endif
