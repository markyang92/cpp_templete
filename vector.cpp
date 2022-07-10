#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > map;
vector< vector<int> > visited;
int N;


int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void getGroup(int r,int c,int seq_visited){
    for(int i=0;i<4;i++){
        int nx=r+dx[i];
        int ny=c+dy[i];
        if ((nx>=0 && nx<N) && (ny>=0 && ny<N) && (map[nx][ny] != -1) && (visited[nx][ny] == 0)){
            visited[nx][ny]=seq_visited;
            getGroup(nx,ny,seq_visited);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int highest = 1;
    //freopen("./input/input.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int t=0; t< tc; t++){
        cin >> N;
        map.resize(N);
        visited.resize(N);
        for(int i=0; i<N; i++){
            map[i].resize(N);
            visited[i].resize(N);
            for(int j=0; j<N; j++){
                cin>>map[i][j];
                if(highest<map[i][j])
                    highest=map[i][j];
            }
        }
        int all_element=N*N;
        int k_element=0;
        int seq_visited;
        int height_visited=0;
        for(int k=0; k <= highest; k++){
            seq_visited=0;
            k_element=0;

            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(map[i][j]<=k){
                        map[i][j]=-1;
                        k_element++;
                    }
                }
            }
            if(all_element == k_element){
                break;
            }

            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(map[i][j]==-1)
                        continue;
                    if (visited[i][j] != 0)
                        continue;
                    seq_visited++;
                    if(seq_visited > height_visited)
                        height_visited=seq_visited;
                    visited[i][j]=seq_visited;
                    getGroup(i,j,seq_visited);
                }
            }
            for(int i=0;i<N;i++){
                fill(visited[i].begin(),visited[i].end(),0);
            }
        }
        cout << "#"<<t+1<<' '<<height_visited<<'\n';
    }
    return 0;
}