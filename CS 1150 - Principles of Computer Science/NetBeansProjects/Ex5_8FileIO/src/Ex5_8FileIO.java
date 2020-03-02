/*
 * Barak Barclay
 * CS1150.002
 * Excercise 5.8 FileIO (Find the highest score)
 * 04/25/17
 * This program creates a text file, gets the number of students from the user, 
 * goes into a for loop that prints gets the student's names and scores from the
 * user and prints them to the file, closes the file, reads the file to find the
 * max score, closes the file again, and prints the max score to the user.
 */
import java.io.*;
import java.util.Scanner;

public class Ex5_8FileIO {

    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        String name = null;
        int numOfStudents = 0;
        double score = 0;
        String maxName = null;
        double maxScore = 0;

        //print welcome and description
        System.out.printf("Welcome to Barak's FileIO (Find Highest Score) "
                + "Program\nThis program will create text document with the "
                + "names and scores of your students as well as tell you who "
                + "got the highest score.\n");

        //writes to file
        File file = new File("scores.txt");
        PrintWriter output = new PrintWriter(file);

        //gets number of students
        System.out.printf("Enter the number of students:");
        numOfStudents = input.nextInt();

        //for loop that prints gets the names and score from the user and prints
        //them to the file 
        for (int i = 1; i <= numOfStudents; i++) {
            System.out.printf("Enter student's last name:");
            name = input.next();
            System.out.printf("Enter student's score:");
            score = input.nextDouble();
            output.printf("%s ", name);
            output.printf("%.2f", score);
        }

        //closes file
        output.close();

        //Read from the file
        Scanner input = new Scanner(file);

        //read in the entire file
        while (input.hasNext()) {        //checks for EOF (end of file)
            name = input.next();
            score = input.nextDouble();
            if (score > maxScore){
                maxName = name;
                maxScore = score;
            }
        }

        //closes file
        input.close();
        
        //prints max name and score
        System.out.printf("\nName of student with highest score: %s\nHighest "
                + "Score:%.2f", maxName, maxScore);
    }
}
