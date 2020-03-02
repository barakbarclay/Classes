/*
 * Barak Barclay
 * CS1150.002
 * FileIOAndExceptions
 * 5/2/17
 * This program gets the filename, number of students, student's names, and 
 * scores from the user. It does an InputMismatchException for all. It sorts and
 * prints the arrays in descending order of the scores to the user and the file.
 * It catches FileNotFound Exceptions, IOExceptions and Exceptions as well.
 */
import java.io.*;
import java.util.*;
import java.util.Scanner;

public class FileIOAndExceptions {

    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        String fileName = null;
        String tempStudentName = null;
        int numOfStudents = 0;
        boolean continueInput = true;
        boolean continueProgram = true;
        double tempScore = 0;

        //print welcome and description
        System.out.printf("Welcome to Barak's Scores Program\nThis program "
                + "will create a file, and print the scores and last names of "
                + "your students in descending score order to that file.\n");

        //catches FileNotFoundException, IOException, and Exception1
        //InputMismatchException handled within
        do {
            try {
                //get file name from user checking for InputMismatchException
                do {
                    try {
                        continueInput = true;
                        System.out.printf("Enter file name:");
                        fileName = input.next();
                        continueInput = false;
                    } catch (InputMismatchException ex) {
                        System.out.printf("Invalid Input. Try Again.\n");
                        input.nextLine();
                    }
                } while (continueInput);

                //writes to file
                File file = new File(fileName + ".txt");
                PrintWriter output = new PrintWriter(file);

                //gets number of students from user checking for 
                //InputMismatchException
                do {
                    try {
                        continueInput = true;
                        System.out.printf("Enter the number of students:");
                        numOfStudents = input.nextInt();
                        continueInput = false;
                    } catch (InputMismatchException ex) {
                        System.out.printf("Invalid Input. Try Again.\n");
                        input.nextLine();
                    }
                } while (continueInput);

                //creates arrays
                double[] score = new double[numOfStudents];
                String[] studentName = new String[numOfStudents];

                //gets names and scores from user checking for 
                //InputMismatchException
                for (int i = 0; i < numOfStudents; i++) {
                    do {
                        try {
                            continueInput = true;
                            System.out.printf("Enter student's last name:");
                            studentName[i] = input.next();
                            continueInput = false;
                        } catch (InputMismatchException ex) {
                            System.out.printf("Invalid Input. Try Again.\n");
                            input.nextLine();
                        }
                    } while (continueInput);
                    do {
                        try {
                            continueInput = true;
                            System.out.printf("Enter student's score:");
                            score[i] = input.nextDouble();
                            continueInput = false;
                        } catch (InputMismatchException ex) {
                            System.out.printf("Invalid Input. Try Again.\n");
                            input.nextLine();
                        }
                    } while (continueInput);
                }

                //sorts arrays
                for (int i = 0; i < numOfStudents - 1; i++) {
                    for (int j = 0; j < numOfStudents - 1; j++) {
                        if (score[j] < score[j + 1]) {
                            tempScore = score[j];
                            score[j] = score[j + 1];
                            score[j + 1] = tempScore;
                            tempStudentName = studentName[j];
                            studentName[j] = studentName[j + 1];
                            studentName[j + 1] = tempStudentName;
                        }
                    }
                }

                //prints arrays to file and user
                for (int i = 0; i < numOfStudents; i++) {
                    output.printf("%s ", studentName[i]);
                    output.printf("%.2f\n", score[i]);
                    System.out.printf("%s ", studentName[i]);
                    System.out.printf("%.2f\n", score[i]);
                }

                //closes file
                output.close();

                //stops the program
                continueProgram = false;
            } catch (FileNotFoundException ex) {
                System.out.printf("Invalid file name. Try again.\n");
                fileName = input.next();
            } catch (IOException ex) {
                System.out.printf("Something went wrong with the file IO %s \n",
                        ex);
            } catch (Exception ex) {
                System.out.printf("Something went terribly wrong %s \n", ex);
                System.exit(1);
            }
        } while (continueProgram);
    }
}
