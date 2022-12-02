#include <bits/stdc++.h>
using namespace std;
typedef map<string, pair<string, string>> B_t;

vector <string> my = { "+", "-", "leaf", "depth" };
int get_type(string w) {
	for (int i = 0; i < my.size(); i++) { if (w == my[i]) return(i); }
	return(-1);
}
void pr(B_t m, string n,vector<string> &t) {
	if (m[n].first != ".") { pr(m, m[n].first,t); }
	if (m[n].second != ".") { pr(m, m[n].second,t); }
	if (m[n].first == "." && m[n].second == ".") {t.push_back(n);}
}
void pr2(B_t m, string n, vector<string>& t, int num, int pre) {
	if (pre == num) { t.push_back(n); }
	pre++;
	if (m[n].first != ".") { pr2(m, m[n].first, t, num, pre); }
	if (m[n].second != ".") { pr2(m, m[n].second, t, num, pre); }
	pre--;
}
bool cmp(string& l1, string& l2) {return l1.compare(l2)<0;}
void leaf(B_t BTS,string root,int n,int s,vector<string>& tmp) {
	vector<string> t;
	if(s) pr(BTS, root, t);
	else  pr2(BTS, root, t, n, 1);
	sort(t.begin(), t.end(), cmp);
	for (auto w : t) { tmp.push_back(w+" "); }
	if (t.empty()) { tmp.push_back("NO");}
	tmp.push_back("\n");
}
void make_leaf(B_t& BTS, string& root) {
	string str,t = root; cin >> str;
	if (BTS.empty()) { root = str; BTS[str] = make_pair(".","."); return; }
	while (1) {
		if (t.compare(str) > 0) {
			if (BTS[t].first != ".")	{t = BTS[t].first; continue;}
			else                        { BTS[t].first = str;  BTS[str] = make_pair(".", ".");return;}}
		else if (BTS[t].second != ".")  {t = BTS[t].second; continue;}
		else                            { BTS[t].second = str;  BTS[str] = make_pair(".", ".");return;}}
}
void del_leaf(B_t& BTS,string& r) {
	string del,t,pre,c; cin >> del;
	auto it = BTS.find(del);
	if (it == BTS.end()) return;
	if (BTS[del].first != ".") {
		t = BTS[del].first;
		pre = del;
		while (BTS[t].second != ".") {pre = t; t = BTS[t].second;}
		if (del != pre) BTS[pre].second = BTS[t].first;
		else BTS[pre].first = BTS[t].first;
	}
	else if (BTS[del].second != ".") {
		t = BTS[del].second;
		pre = del;
		while (BTS[t].first != ".") {pre = t; t = BTS[t].first;}
		if(del!=pre) BTS[pre].first = BTS[t].second;
		else BTS[pre].second = BTS[t].second;
	}
	else {t = ".";}
	BTS[t] = it->second;
	if (r == del) {BTS.erase(del);BTS.erase(".");r = t;return;}
	c = r;
	while (1) {
		if (BTS[c].first == del) {BTS[c].first = t;break;}
		if (BTS[c].second == del) {BTS[c].second = t;break;}
		else {if (c.compare(del) > 0) c = BTS[c].first;
			  else c = BTS[c].second;}
	}
	BTS.erase(del);BTS.erase(".");
	return;
}

int main()
{
	int num, ty_n; cin >> num;
	string type,str,root;
	vector<string> t;
	B_t BTS;
	for (int i = 0; i < num; i++) {
		cin >> type;
		ty_n = get_type(type);
		switch (ty_n) {
		case 0:make_leaf(BTS,root);break;
		case 1:del_leaf(BTS, root);break;
		case 2:leaf(BTS,root,ty_n,1,t);break;
		case 3:cin >> ty_n;leaf(BTS,root,ty_n,0,t);break;}
	}
	t.pop_back();
	for (auto w : t) {cout << w;}
}