#include <iostream>
#include <vector>
using namespace std;

int isMirror = 0;
vector<int> pre, post;

void getpost(int root, int tail) {
    if(root > tail) return;
    int i = root + 1, j = tail; //左子树的第一个结点，右子树的最后一个结点
    if(!isMirror) { //非镜像
        while(i <= tail && pre[root] > pre[i]) //仍在左子树序列
			i++;
        while(j > root && pre[root] <= pre[j]) //仍在右子树序列
			j--;
    } else { //镜像
        while(i <= tail && pre[root] <= pre[i]) //寻找左子树边界
			i++;
        while(j > root && pre[root] > pre[j]) //寻找右子树边界
			j--;
    }
    if(i - j != 1) //左右子树边界没有紧挨
		return;
    getpost(root + 1, j); //递归检查 左 子树
    getpost(i, tail); //递归检查 右 子树
    post.push_back(pre[root]); //左右子树都判断过，记录当前的根结点(即后序顺序)
}

int main() {
    int N;
    cin >> N;
    pre.resize(N);
    for(int i = 0; i < N; i++) //读取序列，假设为BST的先序序列
        cin >> pre[i];
    getpost(0, N - 1); //获取先序序列对应的后序序列
    if(post.size() < N) { //无法得到后序序列
        isMirror = 1; //假设为镜像BST的先序序列
        post.clear();
        getpost(0, N - 1); //获取对应的后序序列
    }
    if(post.size() == N) {
		cout << "YES" << endl;
		cout << post[0];
        for(int i = 1; i < N; i++)
            cout << " " << post[i];
    } else {
        cout << "NO" << endl;
    }
    return 0;
}