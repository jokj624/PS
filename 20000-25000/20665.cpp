//AC
//BOJ 20665 독서실 거리두기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
int N, T, P;
int timetable[25][60][101];  // s, m, seat

struct Time{
    int startT;
    int startM;
    int endT;
    int endM;
};

bool cmp (const Time &a, const Time &b) {
    if (a.startT == b.startT) {
        if (a.startM == b.startM) {
            if (a.endT == b.endT) {
                return a.endM < b.endM;
            }
            return a.endT < b.endT;
        }
        return a.startM < b.startM;
    }
    return a.startT < b.startT;
}

auto distance(int index, int h, int m) {
    int distance = 987654321;
    int minIndex = 1;
    for (int i = 1; i <= N; i++) {
        if (index == i)  continue;
        if (timetable[h][m][i]) {
            int d = abs(index - i);
            if(distance > d) {
                distance = d;
                minIndex = i;
            }
        }
    }
    return tuple(distance, minIndex);
}

int findSeat (int h, int m) {
    int index = 1;
    int maxDis = 0; 
    for(int i = 1; i<=N; i++) {
        if (!timetable[h][m][i]) {
            auto[md, mi] = distance(i, h, m);
            if(md > maxDis) {
                maxDis = md;
                index = i;
            }
        }
    }
    return index;
}

vector<Time> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, res = 0;
    cin >> N >> T >> P;
    for(int i=0; i<T; i++) {
        cin >> a >> b;
        int sT = a / 100;
        int sM = a % 100;
        int eT = b / 100;
        int eM = b % 100;
        v.push_back({sT, sM, eT, eM});
    }
    sort(v.begin(), v.end(), cmp);
    for (Time t: v) {
        int sT = t.startT;  int sM = t.startM;
        int eT = t.endT;    int eM = t.endM;
        int idx = findSeat(sT, sM);
        for(int i = sT; i <= eT; i++) {
            if(sT == eT) {
                for(int j=sM; j < eM; j++) {
                    timetable[i][j][idx] = 1;
                }
                break;
            }
            if(i == sT) {
                for(int j=sM; j<=59; j++) {
                    timetable[i][j][idx] = 1;
                }
            }
            else if(i == eT) {
                for(int j=0; j<eM; j++) {
                    timetable[i][j][idx] = 1;
                }
            }
            else {
                for(int j=0; j<=59; j++) {
                    timetable[i][j][idx] = 1;
                }
            }
        }
    }
    for (int i = 9; i <= 20; i++) {
        for (int j = 0; j <= 59; j++)  {
            if (!timetable[i][j][P]) {
                res += 1;
            }
        }
    }
    cout << res;
    return 0;
}