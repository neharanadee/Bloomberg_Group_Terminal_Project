package com.company;

import java.util.HashMap;
import java.util.Scanner;
import java.time.LocalDate;

public class Main {

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);  // Create a Scanner object
        int lastUserId = 0;
        HashMap<Integer, User> useridInfo = new HashMap<>();

        // Asking for user's name
        String userName;
        do {
            System.out.println("Enter name: ");
            userName = myObj.nextLine();
            if (userName.isEmpty()){
                System.out.println("Please make sure you enter your name.");
            }
        } while (userName.isEmpty());
        System.out.println("Username is: " + userName);

        // Asking for user's email
        String email;
        do {
            System.out.println("Enter email address: ");
            email = myObj.nextLine();
            if (email.isEmpty()) {
                System.out.println("Please make sure you enter your email address.");
            }
        } while (email.isEmpty());
        System.out.println("Email address is: " + email);

        // Asking for user's phone number
        String phoneNumber;
        do {
            System.out.println("Enter phone number: ");
            phoneNumber = myObj.nextLine();
            if (phoneNumber.isEmpty()){
                System.out.println("Please make sure you enter your phone number.");
            }
        } while (phoneNumber.isEmpty());
        System.out.println("Phone number is: " + phoneNumber);

        lastUserId = addNewUserProfile(userName, email, phoneNumber, lastUserId, useridInfo);

        displayUserProfile(1, useridInfo);
        changeUserName(1, "Laura", useridInfo);
        changeUserEmail(1, "laura@hiitsme.com", useridInfo);
        changeUserPhoneNumber(1, "98765", useridInfo);
        displayUserProfile(1, useridInfo);
    }

    // Adds a new user to the system. Generates a unique ID and uses the current date for joining date.
    public static int addNewUserProfile(String name, String email, String phoneNumber, int lastUserID, HashMap<Integer, User> userIDInfo){
        LocalDate date = LocalDate.now();
        User user = new User(name, email, phoneNumber, date);
        //System.out.println(user.getFname() + " " + user.getEmail()+ " " + user.getPhone_number());

        int newIDNumber = lastUserID + 1;
        userIDInfo.put(newIDNumber, user);

        return newIDNumber;
    }

    // Prints user information in a nicely formatted way.
    public static void displayUserProfile(int userId, HashMap<Integer, User> userIDInfo){
        if (userIDInfo.get(userId) != null){
            User displayUserInfo = userIDInfo.get(userId);
            System.out.println("\n" + "User ID: " + userId);
            System.out.println("Name: " + displayUserInfo.getFname());
            System.out.println("Email Address: " + displayUserInfo.getEmail());
            System.out.println("Phone number: " + displayUserInfo.getPhone_number());
            System.out.println("Joined on this date: " + displayUserInfo.getJoinDate() + "\n");
        } else {
            System.out.println("User ID does not exist.");
        }
    }

    // Updates username
    public static void changeUserName(int userId, String newUserName, HashMap<Integer, User> userIDInfo){
        if (userIDInfo.get(userId) != null){
            User userChangeName = userIDInfo.get(userId);
            userChangeName.setFname(newUserName);
        } else {
            System.out.println("User ID does not exist.");
        }
    }

    // Updates user email address
    public static void changeUserEmail(int userId, String newEmailAddress, HashMap<Integer, User> userIDInfo){
        if (userIDInfo.get(userId) != null){
            User userChangeEmail = userIDInfo.get(userId);
            userChangeEmail.setEmail(newEmailAddress);
        } else {
            System.out.println("User ID does not exist.");
        }
    }

    // Updates user phone number
    public static void changeUserPhoneNumber(int userId, String newPhoneNumber, HashMap<Integer, User> userIDInfo){
        if (userIDInfo.get(userId) != null){
            User userChangePhoneNumber = userIDInfo.get(userId);
            userChangePhoneNumber.setPhone_number(newPhoneNumber);
        } else {
            System.out.println("User ID does not exist.");
        }
    }
}
