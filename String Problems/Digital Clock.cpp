string convert_to_digital_time(int m){
    //complete this function
    
    int hrs = m/60;
    int sec = m%60;
    
    string se = to_string(sec);
    string temp=se;
    string a = "0";
    if(se.length() == 1){
        temp = a.append(se);
    }
    
    string s = to_string(hrs) +":"+temp;
    return s;
    
}
