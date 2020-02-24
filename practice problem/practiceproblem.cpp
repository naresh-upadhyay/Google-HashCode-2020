#include<bits/stdc++.h>
typedef long long int ll;
#define VLL vector<ll>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m,n;
    cin>>m>>n;
    ll sum=0,max=0;
    VLL vct,indexes,vctcopy;
    vct.resize(n);
    indexes.resize(n);
    for(int k=0;k<n;k++){
        cin>>vct[k];
    }
    // VLL vctcopy(vct);
    vctcopy = vct;
    fill(indexes.begin(),indexes.end(),0);
    int total=0,j=0;
    for(int i=0;i<vct.size();i++){
        sum +=vct[i];
        indexes[j] = 1;
        j++;
        total++;
        if(sum > m){
            // cout<<" "<<i<<endl;
            ll temp = sum-m;
            auto posval = lower_bound(vct.begin(),vct.end(),temp);
            // cout<<*posval<<" "<<endl;
            if(vct[i] >= *posval && posval != vct.end()){
                auto pos = lower_bound(vctcopy.begin(),vctcopy.end(),*posval);
                // cout<<*pos<<" "<<indexes[pos-vct<<endl;
                int t=0;
                while(((pos-vctcopy.begin())+t) < j && indexes[(pos-vctcopy.begin())+t]==0 ){
                    // cout<<"while "<<i<<endl;
                    t++;
                }
                indexes[(pos-vctcopy.begin())+t] = 0;
                sum = sum-*posval;
                // cout<<((pos-vctcopy.begin())+t) <<" "<<sum<<" "<<*posval<<endl;
                total--;
                // cout<<" "<<i<<endl;
                vct.erase(posval);
                // cout<<" "<<i<<endl;
                i--;
            }
        }
    }
    cout<<total<<"\n";
    for(int j=0;j<n;j++){
        if(indexes[j]){
            cout<<j<<" ";
        }
    }
}