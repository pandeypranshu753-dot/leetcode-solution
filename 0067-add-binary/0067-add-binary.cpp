class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0,sum=0;
        while(i>=0||j>=0){
            sum=carry;
           if(i>=0){
            sum+=a[i]-'0';
            i--;
           }
           if(j>=0){
            sum+=b[j]-'0';
            j--;
           }
           if(sum%2==0){
            result.push_back('0');
           }
           else result.push_back('1');
           if(sum>1)carry=1;
           else carry=0;
        }
        if(carry)result.push_back('1');
        reverse(result.begin(),result.end());
        return result;
        
    }
};