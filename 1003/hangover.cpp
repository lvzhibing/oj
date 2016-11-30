#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<float> arr;
	float tmp;

	while(cin>>tmp){
		if(tmp == 0){
			break;
		}

		arr.push_back(tmp);

	}


	for(vector<int>::size_type ix = 0; ix < arr.size(); ++ix){
        int n = 1;
        float s = 0;
        while(s < arr[ix]){
            s = (float) 1/(n+1) + s;
            ++n;
        }

		cout << n-1 <<" card(s)" <<endl;
	}

	return 0;
}

