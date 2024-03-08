class DisjointSet{
	private:
	std::vector<int> size;
	std::vector<int> parent;
	public:
    int extra;
	DisjointSet(int size1){
		this->size.resize(size1, 1);
		parent.resize(size1, 0);
		for(int i = 0; i < size1; i++){
			parent[i] = i;
		}
        extra = 0;
	}
	int parentTop(int n){
		if(parent[n] == n){
			return n;
		}
		parent[n] = parentTop(parent[n]);
		return parent[n];
	}
	void unioner(int x, int y){
		int u = parentTop(x);
		int v = parentTop(y);
		if(u == v){
            extra++;
			return;
		}
		if(size[u] > size[v]){
			parent[v] = u;
			size[u] += size[v];
		}
		else if(size[v] >= size[u]){
			parent[u] = v;
			size[v] += size[u];
		}
	}
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        for(std::vector<int> i:connections){
            ds.unioner(i[0], i[1]);
        }
        int answer = 0;
        for(int i = 1; i < n; i++){
            int z = ds.parentTop(0);
            int ith = ds.parentTop(i);
            if(z != ith){
                ds.unioner(0, i);
                ds.extra--;
                answer++;
            }
            if(ds.extra < 0){
                return -1;
            }
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();