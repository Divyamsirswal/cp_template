void build(vi &v,ll s,ll e,vi &tree,ll idx){
    if(s==e){
        tree[idx]=v[s];
        return;
    }
    ll m=(s+e)/2;
    build(v,s,m,tree,2*idx);
    build(v,m+1,e,tree,2*idx+1);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
}

ll query(vi &tree,ll s,ll e,ll qs,ll qe,ll idx){
    if(s>=qs and e<=qe){
        return tree[idx];
    }
    if(qe<s or qs>e){
        return inf;
    }
    ll m=(s+e)/2;
    ll left=query(tree,s,m,qs,qe,2*idx);
    ll right=query(tree,m+1,e,qs,qe,2*idx+1);   
    return min(left,right);
}   

void pointUpdate(vi &tree,ll s,ll e,ll i,ll val,ll idx){
    if(i>e or i<s){
        return;
    }
    if(s==e){
        tree[idx]+=val;
        return;
    }
    ll m=(s+e)/2;
    pointUpdate(tree,s,m,i,val,2*idx);
    pointUpdate(tree,m+1,e,i,val,2*idx+1);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
}

void rangeUpdate(vi &tree,ll s,ll e,ll l,ll r,ll val,ll idx){
    if(s<l or r<e){
        return;
    }
    if(s==e){
        tree[idx]+=val;
        return;
    }
    ll m=(s+e)/2;
    rangeUpdate(tree,s,m,l,r,val,2*idx);
    rangeUpdate(tree,m+1,e,l,r,val,2*idx+1);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
}   

ll lazy[1000000]={0};
void lazyRangeUpdate(vi &tree,ll s,ll e,ll l,ll r,ll val,ll idx){
    if(lazy[idx]!=0){
        tree[idx]+=lazy[idx];
        if(s!=e){
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(s>r or l>e){
        return;
    }
    if(s>=l and e<=r){
        tree[idx]+=val; 
        if(s!=e){
            lazy[2*idx]+=val;
            lazy[2*idx+1]+=val;
        }
        return;
    }
    ll m=(s+e)/2;
    lazyRangeUpdate(tree,s,m,l,r,val,2*idx);
    lazyRangeUpdate(tree,m+1,e,l,r,val,2*idx+1);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
}

ll lazyQuery(vi &tree,ll s,ll e,ll l,ll r,ll idx){
    if(lazy[idx]!=0){
        tree[idx]+=lazy[idx];
        if(s!=e){
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(s>r or e<l){
        return inf;
    }
    if(s>=l and e<=r){
        return tree[idx];
    }
    ll m=(s+e)/2;
    ll left=lazyQuery(tree,s,m,l,r,2*idx);
    ll right=lazyQuery(tree,m+1,e,l,r,2*idx+1);
    return min(left,right);
}
