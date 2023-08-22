class Solution {
public:
    string convertToTitle(int columnNumber) {
        // char as=0;
        // int cnt1=0,cnt2=0,total=0;
        // for(char i='A';i<'Z';i++){
        //     cnt1++;
        //     for(char j='A';j<'Z';j++){
        //         cnt2++;
        //         total=cnt1+cnt2;
        //         if(total==columnNumber){
        //             // as=strcat(i,j);
        //             as=i+j;
        //             return as;
        //         }
        //     }
        // }
        // return ;
        string result="";
        while(columnNumber>0){
            int rem=(columnNumber-1)%26;
            result=char('A'+rem)+result;
            columnNumber=(columnNumber-1)/26;
        }
        return result;
    }
};