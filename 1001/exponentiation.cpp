#include <iostream>
#include <string>

using namespace std;

int* add(string s1, string s2);
int* sub(string s1, string s2);
int* mul(string s1, string s2);
void output(int *c);

int main()
{
	string s1, s2;
	int *c;

	while(cin>>s1>>s2){

	c = add(s1, s2);
//	c = sub(s1, s2);
//    c = mul(s1, s2);

    cout<<"----------------"<<endl;
	}
	return 0;
}

int* add(string s1, string s2)
{
    int a[100], b[100];
     // store num
    a[0] = s1.size();
	for (int i=1; i<=a[0]; ++i){
		a[i] = s1[a[0]-i] - '0';
	}
	b[0] = s2.size();
	for(int i = 1; i<=b[0]; ++i){
        b[i] = s2[b[0]-i] - '0';
	}

	int i=1, x=0;
	int *c;
	c = new int[200];
	int m = a[0]>b[0] ? a[0] : b[0];
//	cout<<"max"<<m<<endl;

	while( i <= m ){
        if(i>a[0]){
            a[i] = 0;
        }
        if(i>b[0]){
            b[i] = 0;
        }
		c[i] = a[i] + b[i] + x;
		x = c[i] / 10;
		c[i] %= 10;
		++i;
	}

	c[0] = m;
	if(x == 1){
		c[i] = 1;
		c[0] = c[0] + 1;
	}
	// output
	int flag = 0;
	for (int m = c[0]; m>=1; --m){
        if(c[m] != 0 || flag == 1){
            cout<<c[m];
        }
	}
	cout<<endl;

	return c;
}

int* sub(string s1, string s2)
{
    int c[200] = {0};
    int flag = 1; // 1结果是正数 | -1结果是负数

    // judge which larger
    string tmp;
    if(s1.size() < s2.size()){
        tmp = s1;
        s1 = s2;
        s2 = tmp;
        flag = -1;
    }else if(s1.size() == s2.size()){
        if(s1 < s2){
            tmp = s1;
            s1 = s2;
            s2 = tmp;
            flag = -1;
        }
    }

 //   return c;

    int a[100], b[100];
     // store num
    a[0] = s1.size();
	for (int i=1; i<=a[0]; ++i){
		a[i] = s1[a[0]-i] - '0';
	}
	b[0] = s2.size();
	for(int i = 1; i<=b[0]; ++i){
        b[i] = s2[b[0]-i] - '0';
	}

	int j=1;
	// a[0] is the largest
	while(j<=a[0]){
        if(j > b[0]){
            b[j] = 0;
        }
        if (a[j] < b[j]){
            a[j] += 10;
            a[j+1] -= 1;
        }
        c[j] = a[j] - b[j];
        ++j;
	}
    c[0] = a[0];

    if(flag == -1){
        cout<<'-';
    }
    int f = 0;
    for(int i=c[0]; i>=1; --i){
        if(f==0 && c[i]==0){

        }else{
            f = 1;
            cout<<c[i];
        }

    }
    cout<<endl;
    return c;
}

int* mul(string s1, string s2)
{
    int a[100] = {0}, b[100] = {0};
    a[0] = s1.size();
    for(int i = 1; i <= a[0]; ++i){
        a[i] = s1[a[0]-i] - '0';
    }
    b[0] = s2.size();
    for(int i = 1; i <= b[0]; ++i){
        b[i] = s2[b[0]-i] - '0';
    }

    int c[200] = {0};
    int x = 0;
    int i = 1, j = 1;
    for(i = 1; i <= a[0]; ++i){
        for(j = 1; j <= b[0]; ++j){
            c[i+j-1] = c[i+j-1 ] + a[i] * b[j] + x;
            x = c[i+j-1] / 10;
            c[i+j-1] %= 10;
        }
    }
    if(x==1){
        c[a[0]+b[0]] = x;
        c[0] = a[0] + b[0];
    }else{
        c[0] = a[0] + b[0] - 1;
    }
    int flag = 0;
    for(int m = c[0]; m >= 1; --m){
        if(c[m] != 0 || flag == 1){
            cout<<c[m];
        }
    }
    cout<<endl;

    return 0;
}
