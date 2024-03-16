class Solution {
public:
//min runtime(164 ms.)T(C(N)=O(N)) and S(C(N)=O(N)) as it requires large non conticuous memory dynamic allocation to search total sum of the current and next indx val recursively
//Using Dynamica Programming Logical approach
   long long int findval(vector<int> &s,int i,vector<int> &dp){//findva() funt declare
        if(i>=s.size())return 0;//initalizing the Vector Size
        if(dp[i]!=-1)return dp[i];//Printing the last indx val 
        else{
            long long int out=INT_MIN;//Output Decalre to the large Intger Datatype's Macro size Limited to 2**(-32)btyes
            out=max(out,s[i]-findval(s,i+1,dp));//Maximum output Declare from current indx val to next Index val
            if(i+1<s.size())out=max(out,s[i]+s[i+1]-findval(s,i+2,dp));//Output Declare from [i+1] indx val till vector's size
            if(i+2<s.size())out=max(out,s[i]+s[i+1]+s[i+2]-findval(s,i+3,dp));//Output Declare from [i+1] indx val till vector's size
           return dp[i]=out;} }//Printing output to current [indx] val

    string stoneGameIII(vector<int>& s) {
       vector<int> dp(s.size(),-1);//dp vector size declare
       long long int Alice=findval(s,0,dp);//calling findval function and redclare it new variable
        if(Alice>0)return "Alice";//printing Alice as Winner
        else if (Alice<0)return "Bob";//Prinitng Bob as UNWinner
        else return "Tie";}};//Printing Tie if both wins at same scoring points val

           // out=findval(s[i+1],s[i+2]);
           // if(i<s.size())out=findval(s[i+2],s[i+3]);
