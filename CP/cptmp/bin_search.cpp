#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'

// ---------------- NOTES ----------------
// 1️⃣ Binary Search Patterns:
//    a) Find minimum value that satisfies condition
//    b) Find maximum value that satisfies condition
//    c) Search in sorted array
// 2️⃣ Lambda 'ok' is used for condition checks
// 3️⃣ mid = l + (r - l)/2 to avoid overflow

// 1️⃣ Find minimum value that satisfies condition
void binary_search_min_satisfy(){
    
    auto ok=[&](ll mid){
        return true;
    };

    ll l=0,r=1e9,mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}

// 2️⃣ Find maximum value that satisfies condition
void binary_search_max_satisfy(){
    
    auto ok=[&](ll mid){
        return true;
    };
    ll l=1,r=1e9,mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(ok(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}

// 3️⃣ Search in a sorted array
void binary_search_array_satisfy(vll &a,ll target){
    ll l=0,r=(ll)a.size()-1,mid;
    bool found=false;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]==target){
            found=true;
            break;
        }else if(a[mid]<target){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(found) cout<<"Target found at index "<<mid<<endl;
    else cout<<"Target not found"<<endl;
}

// ---------------- MAIN ----------------
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"--- Binary Search Min Satisfy ---"<<endl;
    binary_search_min_satisfy();
    cout<<"--- Binary Search Max Satisfy ---"<<endl;
    binary_search_max_satisfy();
    cout<<"--- Binary Search Array Satisfy ---"<<endl;
    vll a={1,3,5,7,9};
    ll target=5;
    binary_search_array_satisfy(a,target);
    return 0;
}


