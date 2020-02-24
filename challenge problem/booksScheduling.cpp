#include<bits/stdc++.h>
#define PRI pair<int,int>
#define VPI vector<PRI>
#define VVPI vector<VPI>
#define VII vector<int>
#define VVII vector<VII>
#define ll long long int
#define pb push_back

using namespace std;
//for sorting in desending order
bool comp(const PRI &a, const PRI &b){
    return (a.first > b.first);
}
//for sorting in assending order
bool compincr(const PRI &a, const PRI &b){
    return (a.first < b.first);
}
//printing the vector of pairs
void printvct(const VPI &vct){
    for(int i=0; i<vct.size();i++){
        cout<<vct[i].first<<" "<<vct[i].second<<"\n";
    }
}
//finding minimum value between two long long type values. (a,b*c)
int minval(const ll &a , const ll &b,const ll &c){
    ll temp= b*c;
    if(a<temp){
        return a;
    }else return temp;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int b,l,d,si;   //b->books,l->libraries,d->total days,si->(s0,s1....s(b-1))
    cin >>b>>l>>d;
    VPI vctpr;      //maintain vector pair of (score book i,index of book i) so that we can sort them later
    VII vct;        //preserving the hash of (books id's v/s their scores)
    vct.resize(b);
    for(int i=0; i<b;i++){
        cin >>si;
        vct[i] = si;
        vctpr.pb({si,i});
    }
    sort(vctpr.begin(),vctpr.end(),comp);
    VPI Ti;         //maintaining vector pair for (no. of signup days taken by library id j, jth id of library) , we have to sort according to signup day in increaseing order
    VPI TMli;       //maintaining vector pair for (no. of signup days taken by library id j,number of books that can be shipped from library j)
    VVPI NbookidINli;//maintaining 2d vector row's are libraries and column are pairs of(books score,books id's) in that library , we have to sort books score in decreasing order
    NbookidINli.resize(l);
    int n,t,m,ni;
    for(int j = 0; j<l; j++){
        cin >>n>>t>>m;//no. of books,no. of signup days,no. of books can shipped per day
        Ti.pb({t,j});
        TMli.pb({t,m});
        for(int k=0; k<n; k++){
            cin >>ni;
            NbookidINli[j].pb({vct[ni],ni});
        }
        sort(NbookidINli[j].begin(),NbookidINli[j].end(),comp);
    }
    sort(Ti.begin(),Ti.end(),compincr);
    ///output portion then try to tune it
    int ii=0,A =0;

    for(int day=0; day<d && ii<l; ){
        int tempd = Ti[ii].first;//mindays taken to signup by library
        day += tempd;
        if(day >= d) break;
        A++;    //total no. of libraries finally processed
        ii++;
    }
    cout<<A;
    ii = 0;
    for(int day=0; day<d && ii<l; ){
        // cout<<ii<<" "<<day<<endl;
        int tempd = Ti[ii].first;       //mindays taken to signup by library
        int lib = Ti[ii].second;        //library id
        int bookpd = TMli[Ti[ii].second].second;// no. of books per day process by signedup library.
        day += tempd;
        // cout<<NbookidINli[lib].size()<<" "<<int(abs(d-day)*bookpd)<<endl;
        if(day >= d) break;
        int k = minval((NbookidINli[lib].size()),(d-day),bookpd);//maximum books can be processed from library lib
        cout<<"\n"<<lib<<" "<<k<<"\n";
        cout<<NbookidINli[lib][0].second;

        for(int kk=1; kk<k;kk++){
            cout<<" "<<NbookidINli[lib][kk].second;
        }

        ii++;
    }
    
}