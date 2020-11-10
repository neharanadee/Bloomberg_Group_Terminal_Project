package com.company;

import java.time.LocalDate;
import java.util.Date;

public class User
{
    private String fname;
    private String email;
    private String phone_number;
    private LocalDate joinDate;

    public User(String fnameVal, String emailVal, String phone_numberVal, LocalDate joiningDate){
        fname = fnameVal;
        email = emailVal;
        phone_number = phone_numberVal;
        joinDate = joiningDate;
    }

    void setFname(String nameChange){
        this.fname = nameChange;
    }

    void setEmail(String emailChange){
        this.email = emailChange;
    }

    void setPhone_number(String phone_number_change){
        this.phone_number = phone_number_change;
    }

    String getFname(){
        return fname;
    }

    String getEmail(){
        return email;
    }

    String getPhone_number(){
        return phone_number;
    }

    LocalDate getJoinDate(){
        return joinDate;
    }
}
