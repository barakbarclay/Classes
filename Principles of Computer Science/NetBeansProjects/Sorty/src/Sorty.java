/*
 * Barak Barclay
 * CS1150.002
 * Sorty
 * due 4-6-2017
 * This program asks the user to input the number of elements they want for 
 * their array, creates the array, calls the loadArray, printArray sortArray, 
 * and again the print array. The loadArray method asks the user the vales of 
 * elements and stores them into the array. The sortArray sorts the array via
 * bubble sort and the printArray prints the array to the user.
 */

import java.util.Scanner;

public class Sorty {

    public static Scanner input = new Scanner(System.in);
    public static int size = 0;

    public static void main(String[] args) {

        int array[];

        //print welcome and description
        System.out.printf("Welcome to Barak's Sorty Program"
                + "\nAfter inputing the number of array elements, and the "
                + "values of the elements, the program will print back your "
                + "array and then print back your array sorted in numerical "
                + "order.\n");

        //creates array
        System.out.printf("Input the number of elements:");
        size = input.nextInt();
        array = new int[size];

        //calls methods
        loadArray(array);
        printArray(array);
        sortArray(array);
        System.out.printf("\n");
        printArray(array);
    }

    //perfroms a bubble sort on array
    public static void sortArray(int array[]) {
        int temp = 0;
        for (int j = 0; j < array.length - 1; j++) {
            for (int i = 0; i < array.length - 1; i++) {
                if (array[i] > array[i + 1]) {
                    temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                }
            }
        }
    }

    //fills array
    public static void loadArray(int array[]) {
        for (int i = 1; i <= size; i++) {
            System.out.printf("Input value:");
            array[i - 1] = input.nextInt();
        }
    }

    //prints array 
    public static void printArray(int array[]) {
        for (int i = 1; i <= size; i++) {
            System.out.printf("%d\t\t", array[i - 1]);
        }
    }
}
