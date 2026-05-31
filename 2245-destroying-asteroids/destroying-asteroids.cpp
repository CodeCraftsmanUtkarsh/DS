class Solution {
public:

    void merge(vector<int>& a, int l, int mid, int r) {

        int n = mid - l + 1;
        int m = r - mid;

        vector<int> left(n);
        vector<int> right(m);

        for(int i=0;i<n;i++)
            left[i] = a[l+i];

        for(int j=0;j<m;j++)
            right[j] = a[mid+1+j];

        int i=0, j=0;
        int k=l;

        while(i<n && j<m){
            if(left[i] <= right[j]){
                a[k++] = left[i++];
            }
            else{
                a[k++] = right[j++];
            }
        }

        while(i<n)
            a[k++] = left[i++];

        while(j<m)
            a[k++] = right[j++];
    }

    void mergeSort(vector<int>& a, int l, int r){

        if(l >= r)
            return;

        int mid = (l+r)/2;

        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);

        merge(a,l,mid,r);
    }

    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        mergeSort(asteroids,0,asteroids.size()-1);

        long long curr = mass;

        for(int x : asteroids){

            if(x > curr)
                return false;

            curr += x;
        }

        return true;
    }
};