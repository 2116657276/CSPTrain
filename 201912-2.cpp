/*
 城市里有n处垃圾，给出每个垃圾的坐标(x, y)。政府想在垃圾所在的位置建立“回收站”。但有个严格的条件：
 只有当一个垃圾的 正上、正下、正左、正右 四个相邻位置全都有垃圾时，这个位置才有资格建回收站。
 星级评分：对于有资格的回收站，我们要给它打分。分数等于它的 左上、左下、右上、右下 四个对角线位置的垃圾数量总和（所以满分是4分，最低0分）。
 要求：输出5行数字，分别代表得分为0、1、2、3、4分的回收站数量。
*/
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    vector<pair<int,int>> v;
    set<pair<int,int>> s;

    for (int i = 0;i < n;i++) {
        int x,y;
        cin>>x>>y;
        v.emplace_back(x,y);
        s.insert(make_pair(x,y));
    }
    vector<int> scores(5);
    for (const pair<int,int> & i : v) {
        int x = i.first;
        int y = i.second;
        if (s.find(make_pair(x,y+1)) != s.end() && s.find(make_pair(x,y-1)) != s.end() && s.find(make_pair(x-1,y)) != s.end() && s.find(make_pair(x+1,y)) != s.end()) {
            int score = 0;
            if (s.find(make_pair(x-1,y+1)) != s.end()) score++;
            if (s.find(make_pair(x+1,y+1)) != s.end()) score++;
            if (s.find(make_pair(x-1,y-1)) != s.end()) score++;
            if (s.find(make_pair(x+1,y-1)) != s.end()) score++;
            scores[score]++;
        }
    }
    for (int i = 0;i < 5;i++) {
        cout<<scores[i]<<"\n";
    }
    return 0;
}