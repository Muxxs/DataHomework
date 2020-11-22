//
// Created by Muxxs on 2020/11/14.
//

#include <iostream>
using namespace std;

typedef struct NTNode
{
    int weight;
    int parent, lchild, rchild;
} NTNode, *HuffmanTree;

typedef char **HuffmanCode;

void CreateHuffmanTree(HuffmanTree HT, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(NTNode));
    for (int i = 1; i <= m; i++)
    {
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }
    for (int k = 0; k < n; ++k)
    {
        cin >> HT[k].weight;
    }
}

int main()
{
    return 0;
}