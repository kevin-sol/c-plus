class Solution {
public:
    int romanToInt(string s) {
        int number=0,num0,num1=9999,num;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case 'I':
                    num0=1;break;
                case 'V':
                    num0=5;break;
                case 'X':
                num0=10;break;
                case 'L':
                num0=50;break;
                case 'C':
                num0=100;break;
                case 'D':
                num0=500;break;
                case 'M':
                num0=1000;break;
            }
            if(num1<num0){
                num=num0-num1*2;
            }
            else{
                num=num0;
            }
            number+=num;
            num1=num0;
        }
        return number;
    }
};