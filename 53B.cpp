#include<bits/stdc++.h>
#define ll long LLONG_MAX
using namespace std;

int n;
map<int,int> books;

void findBookNo(){

    int q;
    int top = 0;

    for(int i=0;i<n;i++){
        scanf("%d",&q);
        if(top>books[q])
            printf("0 ");
        else{
            printf("%d ",books[q]- top + 1);
            top = books[q] + 1;
        }
    }
    printf("\n");
}

int main(){

    scanf("%d",&n);
    int a;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        books[a] = i;
    }

    findBookNo();

}
