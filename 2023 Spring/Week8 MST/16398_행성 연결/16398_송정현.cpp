#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct KS{
    int from, to, val;
};

vector<KS> Edges;
int parent[100001];
long result=0;

bool comp(KS k1, KS k2){    // 오름차순 정렬
    return k1.val < k2.val;
}

int find(int num){  // find : parent 찾기
    if(num == parent[num])  return num;
    return parent[num] = find(parent[num]);
}
bool Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){ // 사이클
        return false;
    } else {
        parent[a] = b;
        return true;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            KS ks;
            cin >> ks.val;
            ks.from = i;
            ks.to = j;
            Edges.push_back(ks);
        }
    }
    sort(Edges.begin(), Edges.end(), comp);

    for(int i=0; i<n*n; i++){ // 가장 낮은 가중치의 간선부터
        int f = find(Edges[i].from);    // 간선의 출발점과
        int t = find(Edges[i].to);  // 간선의 도착점을

        if(Union(f, t)){    // 사이클 없는 경우에
            result += Edges[i].val; // 간선의 가중치를 더해주고 그 간선 추가
        }
    }
    cout << result << "\n";

    return 0;
}