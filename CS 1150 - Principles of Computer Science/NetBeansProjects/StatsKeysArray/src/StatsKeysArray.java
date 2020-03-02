
import java.util.Scanner;

public class StatsKeysArray {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        String keys[] = {"F#m","D","Db","Eb","D","Dm","Eb","C","G","A","Am","C","Em","Em","F#m","Fm","A","Am","Bm","C","Cm","D","F","B","Bm","C","D","Db","Eb","G","A","A","A","Am","Bm","C","C","Cm","D","E","Em","G","G#m","Gm","Am","B","Bbm","C","C#m","D","A","C","C#m","Cm","Db","F#","Am","Am","Am","B","D","D","Dm","Dm","F","G#m","B","B","Bb","Bm","D","E","E","Eb","Ebm","F","A","Ab","Ab","Ab","Ab","Am","Bm","Cm","D","D","D","Db","E","Eb","Ebm","Em","F","F#","F#m","Fm","G","A","A","A","A","Ab","Ab","Ab","Am","Am","Am","B","Bb","Bb","Bbm","Bm","C","C","Cm","Cm","Cm","Cm","Cm","Cm","Cm","D","D","D","Db","Dm","Dm","Dm","Dm","Dm","E","Eb","Eb","Eb","Ebm","Ebm","Ebm","Em","Em","Em","F","F","F","F#m","G","G","G#m","G#m","Gm","Am","Bb","Bm","Db","Dm","E","E","Em","F","F#","G","Am","Am","Am","B","B","B","C","C","Cm","D","D","D","D","D","Db","Db","E","E","Eb","Eb","F","F","F","F#m","F#m","Fm","Fm","G","G","G#m","G#m","Gm","A","Ab","Am","Am","Bb","Bbm","C","C","C","C","C#m","D","Db","Dm","Eb","Ebm","Ebm","F","F#","F#","F#m","Fm","A","A","A","A","Am","Am","Am","Am","C","C","D","D","D","D","D","Db","Dm","E","Eb","Ebm","F","F#","F#m","G","G#m","G#m","G#m","A","A","Ab","Am","Bb","Bb","Bb","Bm","Bm","C","C","C","C","C#m","Cm","D","D","D","D","Db","Dm","Dm","Dm","E","E","E","E","E","E","Ebm","Ebm","Em","Em","Em","Em","Em","F","F","F#","F#","F#m","Fm","G","G#m","A","Ab","B","B","Bb","Bm","C","C#m","Cm","D","D","E","Eb","F","F","F","F","F","G","Gm","A","A","Ab","Am","Am","Am","B","Bb","Bb","Bbm","C","Cm","D","D","D","D","Db","Dm","Dm","E","E","E","Eb","Em","Em","F","F#","F#","G","G","G#m","Gm","Gm","A","Am","Am","B","Bm","Bm","C","C","C","C","C","C#m","C#m","Cm","Cm","D","D","D","D","D","Dm","E","E","E","E","Eb","Eb","Em","F","Fm","G","G","G","G","G#m","Gm","A","A","Ab","Am","B","Bm","Bm","Bm","C","C","C","C","D","D","E","E","Eb","Eb","Eb","Em","F","F","F#","F#","Gm","Gm","A","A","A","A","A","A","A","A","Ab","Ab","Am","B","B","Bb","Bbm","Bm","Bm","Bm","Bm","C","C","C","C","C","C","C","C","C","C","C#m","Cm","Cm","Cm","Cm","Cm","D","D","D","D","D","D","D","Db","Db","Dm","Dm","Dm","Dm","E","E","E","E","E","Eb","Em","Em","Em","F","F","F#","F#m","F#m","Fm","Fm","G","G","G","G","G#m","Gm","Gm","Gm","Gm","A","A","A","Ab","Am","Bb","Bb","Bbm","C","Cm","Cm","D","D","Db","Dm","Dm","E","E","Eb","Ebm","Ebm","Em","Em","Em","F","F#m","G","G","G#m","Gm","A","A","Am","Bb","Bb","C","C#m","D","D","Db","Db","Dm","Dm","Dm","Dm","Dm","Dm","E","E","E","E","Eb","Ebm","Ebm","Em","Em","F","F#","F#m","G","G#m","Gm","A","A","Am","B","Bb","Bbm","Bbm","C","C","C","Cm","D","Db","Dm","E","E","Eb","Ebm","F","F","F#","G","G","G","G","G#m","Gm","Gm","A","A","Ab","Ab","Ab","Am","Am","Am","B","Bb","Bb","Bbm","Cm","D","Db","Db","E","E","Eb","Eb","Em","F","F","F#","Gm","A","A","A","A","A","Am","Am","Am","Am","B","Bb","Bm","C#m","C#m","Cm","Cm","D","D","D","D","Db","Dm","Dm","E","E","E","E","E","Eb","Eb","Em","Em","Em","F","F","F","F#","Fm","G","G","A","A","A","Ab","Ab","Am","Bb","C","C","Cm","D","D","D","D","D","Db","Db","E","E","E","Eb","Em","Em","F","F#","F#","F#m","F#m","F#m","Fm","G","G","A","A","A","A","A","A","A","Ab","Am","Am","Am","Am","B","B","Bb","Bm","C","C","C","C#m","Cm","D","D","D","D","D","D","D","Db","Db","Dm","E","E","Eb","F","F","F","F","F","Fm","Gm","Gm","A","A","A","A","Ab","Ab","Am","B","B","B","Bb","Bm","Bm","C","C","C#m","D","D","D","D","D","Db","Db","Dm","Dm","E","E","E","E","E","E","E","Em","Em","Em","F","F","F#m","G","G#m","G#m","G#m","Gm","Gm","A","A","A","A","B","C","C","C","C","C#m","Cm","Cm","Cm","D","D","Db","Db","Dm","Dm","Dm","E","Eb","Em","F#m","Fm","A","A","A","Ab","Ab","Ab","Ab","Ab","Am","Am","Am","Am","Bb","Bm","C","C","C","C","C","C","D","D","D","D","E","E","E","Eb","Eb","Em","F#","F#","F#","G","G","G#m","Gm","Gm","A","A","A","A","Bb","Bb","D","Db","Dm","E","E","Eb","Em","Em","Em","Em","Em","Em","Em","Em","F","F","F#","F#m","F#m","G","G","Gm","Gm","A","A","Ab","Ab","Am","Am","Bb","Bb","Bbm","Bbm","Bbm","C","C","C","C","C#m","C#m","C#m","D","Dm","Dm","Dm","E","E","E","E","Ebm","Em","F","G","G","G","G#m","Gm","Gm","A","A","A","A","A","Ab","Am","Am","Am","Bb","Bb","Bb","Bbm","C","C","C","Cm","D","Dm","Dm","Dm","Ebm","Em","F","F#m","G","G","G","A","A","Ab","Ab","Am","B","C","C","C","C","C#m","Cm","D","E","E","E","E","Ebm","F","F","F","F","F#","F#","G","G","G#m","G#m","A","A","A","Ab","Am","B","Bbm","Bm","C","C","C","C","C","Cm","Cm","D","D","D","D","Db","Dm","Dm","E","E","E","E","E","Eb","Eb","Em","Em","Em","F","F#","F#","F#","F#","F#","F#","F#m","G","G","G","G","G","G","G#m","Gm","A","A","Am","Am","B","B","Bbm","Bm","Bm","C","C#m","Cm","D","D","D","Db","Dm","Dm","E","Eb","Ebm","F","F","F#","F#m","G","A","A","Ab","B","Bb","Bbm","Bm","C","C","C#m","Cm","D","Db","E","E","E","Eb","Ebm","F","F#","F#","Fm","G","Gm","Ab","Ab","Ab","Am","C","C","C","C","Cm","D","Db","Ebm","Em","F","F","F","F#","F#m","Fm","G","G","G","G#m","Gm","A","A","A","A","A","Am","Am","B","C","C","C","D","D","D","E","E","Eb","F","F#","F#m","G","Gm","Gm","A","Ab","Ab","Am","Bb","Bbm","Bm","Bm","C","C","C#m","C#m","Cm","Cm","Cm","Cm","D","D","D","D","D","D","Db","Db","Db","Dm","Dm","Dm","Dm","E","E","E","E","E","E","Eb","Eb","Eb","Em","Em","Em","F","F","F","F","F","F#","F#m","F#m","Fm","G","G","G","Gm","A","B","B","Bb","Bbm","Bbm","Bm","C","Cm","Cm","D","D","Db","E","E","Eb","F#","F#m","G","G#m","G#m","G#m","Gm","A","A","Ab","Ab","Ab","B","B","B","B","Bb","C","Cm","D","D","Dm","E","Eb","Em","Em","F#","F#m","F#m","G","G","A","Ab","B","Bm","Bm","C","C#m","D","D","Db","Dm","E","E","E","E","Eb","Em","F","Fm","G","A","A","A","B","Bbm","Bm","Bm","C","C","C","C","C#m","Cm","D","D","D","D","Db","Dm","Dm","F","F","F","F","F#","F#m","G#m","Gm","Ab","B","Bbm","Bm","C","C#m","Cm","D","D","D","Db","Db","Db","Db","Dm","Dm","E","E","Eb","Eb","Em","Em","F","F","F#","F#m","F#m","Fm","G","G","G","G","G#m","G#m","G#m","Gm","Gm","A","A","A","A","Ab","Ab","Bb","C","C","D","D","D","E","E","E","Em","Em","F#","G","G","A","A","Ab","Am","B","Bb","C","D","D","D","Db","Dm","Dm","E","E","E","Ebm","Em","F#m","G","A","Ab","Am","B","Bbm","C","C","C","Cm","D","Dm","E","E","Em","Em","F","F","Ab","Ab","Ab","Bb","Bm","C","C#m","D","Db","Db","Dm","E","E","Em","F","F","F","F#","F#","F#m","G","G","Gm","A","Ab","Am","B","B","B","B","Bb","Bm","C","C","Cm","D","D","Db","Db","Dm","E","E","Eb","Eb","Eb","Ebm","F","F","F","F#m","Fm","G","Gm","Gm","A","A","A","C","C","D","D","Db","Dm","E","E","Eb","F","F","F#","G","Gm","A","A","A","A","B","C","C","C#m","Cm","D","D","D","Dm","E","E","E","Em","Em","Em","F","F","F","Fm","Gm","Gm","A","A","A","Ab","Ab","Bm","C","Cm","D","D","Dm","E","Eb","Em","Fm","G","G","G#m","G#m","Gm","A","A","A","Am","Am","Am","Am","Am","B","Bb","C","C","Cm","D","D","D","D","D","E","E","F#m","Fm","G","G#m","A","A","A","Ab","Am","Am","B","C","C","C","Cm","D","D","D","Db","Dm","Eb","F","F#","F#","F#","F#m","F#m","G#m","A","A","A","Ab","Bm","C","C","C","C","C#m","D","Db","E","E","Em","F","F#m","Fm","G","Gm","Am","B","B","B","Bm","Bm","C","C","C","C","C","C#m","Cm","D","D","Dm","Dm","E","Ebm","Em","F#","F#m","G","G","G","G","Gm","A","Ab","Am","Am","Bb","Bb","C","C#m","C#m","Cm","D","D","E","E","E","F","F#","F#m","Fm","G","G","G#m","Gm","A","A","Am","Am","B","B","B","Bbm","E","E","E","Eb","Ebm","F","Fm","A","A","A","A","A","A","Ab","Ab","Am","Am","Am","B","Bb","Bb","Bb","Bbm","Bm","C","C","C","C","C","C","C","C","Cm","Cm","D","D","D","D","D","D","D","D","D","Db","Db","Db","Db","Db","Dm","Dm","Dm","E","E","E","E","Eb","Eb","Eb","Eb","Ebm","Em","Em","Em","F","F","F#","F#","Fm","Fm","G","G","G","G","G","G#m","G#m","Gm","Gm","Gm","Gm","A","B","Bm","C","C","D","D","Eb","Ebm","F","F#","F#","G","G#m","G#m","Gm","A","Ab","Am","Am","Am","B","B","Bb","Bb","C","C","C","C","C#m","Cm","D","D","Dm","Dm","Dm","Dm","Dm","E","Em","Em","F#","F#m","Fm","Fm","G","G#m","Gm","A","A","A","A","B","Bm","C","C","C","Cm","D","D","D","Dm","E","E","E","Eb","Eb","Ebm","Em","F","F","F#m","G","G","G#m","G#m","Gm","A","A","A","A","Am","B","B","Bbm","Bm","C","C","C","Cm","Cm","D","D","D","Dm","Dm","E","E","E","E","Eb","Ebm","Em","F","F","G","G#m","Gm","Gm","A","A","A","A","A","A","Am","Am","Am","Am","Am","B","B","Bb","Bb","Bb","Bb","Bm","Bm","C","Cm","D","D","D","Db","Db","Dm","Dm","Dm","Dm","Dm","E","E","E","E","Em","F","F","F","F#","F#","F#m","G","G","G","G","G","Gm","A","A","A","A","A","A","Ab","Am","Am","Am","Bb","Bb","Bb","Bbm","Bm","Bm","Bm","Bm","C","C","C","C#m","Cm","Cm","Cm","Cm","Cm","Cm","D","D","Db","Dm","E","E","E","Eb","Eb","Em","F","F#","F#","F#m","Fm","Fm","Fm","G","G","Gm","A","A","A","A","Am","Am","B","C","C","C","C","C","C","C","C#m","C#m","C#m","C#m","Cm","Cm","D","D","D","D","Dm","E","E","E","E","Eb","Eb","Ebm","Em","Em","Em","F","G","G","G","Gm","A","A","A","A","A","A","A","A","A","Ab","Ab","Ab","Ab","Ab","Am","Am","Am","Am","Am","Am","Am","Am","Am","Am","Am","B","B","B","B","B","Bb","Bb","Bb","Bb","Bb","Bbm","Bbm","Bbm","Bbm","Bbm","Bbm","Bm","Bm","Bm","Bm","C","C","C","C","C","C","C","C","C","C","C","C","C","C","C#m","C#m","C#m","Cm","Cm","Cm","Cm","Cm","Cm","Cm","Cm","Cm","Cm","D","D","D","D","D","D","D","Db","Db","Db","Dm","Dm","Dm","Dm","Dm","Dm","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","E","Eb","Eb","Eb","Eb","Eb","Eb","Eb","Eb","Eb","Eb","Eb","Eb","Eb","Ebm","Ebm","Ebm","Ebm","Em","Em","Em","Em","Em","Em","Em","Em","Em","Em","F","F","F","F","F","F","F","F","F","F#","F#","F#m","F#m","F#m","F#m","F#m","Fm","Fm","Fm","Fm","Fm","Fm","Fm","Fm","Fm","Fm","Fm","G","G","G","G","G","G","G","G","G","G","G","G#m","G#m","G#m","G#m","G#m","G#m","Gm","Gm","Gm","Gm","Gm","Gm","Gm","Gm","Gm","Gm","A","A","A","Ab","Am","Am","Am","B","Bb","C","D","D","Db","Dm","E","Eb","Ebm","Em","F#","F#m","G","Gm","Gm","A","A","A","A","A","A","Ab","Ab","Am","Am","Am","Am","B","B","B","Bb","Bbm","Bbm","Bm","Bm","Bm","Bm","C","C","C","C","C","C","Cm","Cm","Cm","Cm","Cm","Cm","Cm","Cm","D","D","D","D","D","Db","Db","Dm","Dm","Dm","Dm","Dm","E","E","E","E","E","E","E","Eb","Ebm","Ebm","Em","Em","Em","Em","F","F","F","F#","F#","F#","F#m","F#m","F#m","Fm","Fm","Fm","Fm","Fm","G","G","G","G","G","G","Gm","Gm","Gm","Gm","Gm","Gm","A","A","A","A","Ab","Ab","Am","Am","Am","B","Bb","C","C","C","Cm","D","D","D","D","Db","Dm","Ebm","Em","Em","Em","G","G","A","Ab","Ab","Am","Am","Am","Bbm","Bbm","Bbm","Bbm","Bbm","Bm","Bm","C","Cm","D","D","D","Db","Dm","E","E","E","Ebm","Ebm","Em","Em","F#m","G","G","G#m","Gm","A","A","Am","B","Bm","C","C","C","C","Cm","Cm","Cm","D","D","Db","Db","E","E","Eb","Ebm","F#","F#m","G","G","A","A","Bm","Cm","D","D","D","Dm","E","E","F","F#m","Fm","G","G#m","Gm","A","Am","Am","B","B","Bb","Bm","Bm","Bm","C","C","C#m","Cm","D","D","D","D","D","D","E","E","Em","Em","Em","F","F#","F#","F#","F#m","Fm","Fm","A","A","A","A","Ab","Am","B","B","Bb","Bb","E","Eb","Ebm","Ebm","Em","Em","Em","F","F","Fm","G","G#m","Gm","A","A","A","B","C","Cm","D","E","E","Eb","Eb","Eb","Em","Em","F","F","G","G","G","G","Ab","Am","B","Bb","Bb","Bb","Bbm","C","C#m","D","Dm","Dm","E","Eb","Eb","Em","Em","F","F","F","G","G#m","G#m","Gm","A","Bbm","Cm","D","D","Db","Eb","Eb","Ebm","F#m","G#m","A","A","A","Ab","Ab","Am","Am","Am","Am","Am","B","B","Bb","Bb","Bbm","Bbm","Bbm","Bbm","Bbm","Bm","Bm","Bm","Bm","C","C","C","C","C","Cm","Cm","Cm","Cm","Cm","D","Db","Dm","Dm","Dm","Dm","Dm","E","E","E","E","Eb","Ebm","Em","Em","Em","Em","Em","F","F","F#","F#","F#","F#m","F#m","F#m","Fm","Fm","Fm","Fm","Fm","G","G","G","G","G#m","G#m","G#m","G#m","G#m","Gm","Gm","A","A","C","D","Dm","E","Eb","Eb","F#","Gm","A","Am","Bb","Bm","C","C","Cm","Dm","Dm","E","F","F#","Fm","G","G","G","Ab","Am","Bm","Bm","Bm","C","D","Eb","Em","F","G","A","Ab","Ab","Am","Bb","Bb","Bm","C","Db","Dm","E","Ebm","Em","Em","F","Fm","Gm","A","Ab","B","Bm","Dm","E","Eb","Ebm","Em","F#m","Fm","Fm","G#m","G#m","Gm","A","C","C","C","D","E","Em","Em","Em","Fm","G","B","B","Bb","Bm","C","E","G","G","Gm","A","Am","Am","Bbm","Cm","D","D","Em","F","C","C","D","A","Am","Bb","Bbm","C","C","C#m","Cm","D","D","D","Dm","E","Eb","Eb","F#m","F#m","Fm","G#m","Gm","Am","B","Am","Bb","C","C","C","C","Cm","Em","F#","Gm","C","E","E","F","B","C","Eb","Ebm","F","A","Dm","Em","F#","G","A","Am","Dm","Ebm","Bbm","Fm","F","C","D","Ebm","F#","Fm","B","Cm","Db","G#m","G#m","E","F#m","Cm","Cm","Gm"};
        int keysN[];
        keysN = new int[keys.length];
        loadArray(keys, keysN);
        printArray(keysN);
        System.out.printf("\n%d", keys.length);
    }

    //fills array
    public static void loadArray(String keys[], int keysN[]) {
        for (int i = 1; i <= keys.length; i++) {
            if (keys[i - 1] == "C#") {
                keysN[i - 1] = 1;
            } else if (keys[i - 1] == "F#") {
                keysN[i - 1] = 2;
            } else if (keys[i - 1] == "B") {
                keysN[i - 1] = 3;
            } else if (keys[i - 1] == "E") {
                keysN[i - 1] = 4;
            } else if (keys[i - 1] == "A") {
                keysN[i - 1] = 5;
            } else if (keys[i - 1] == "D") {
                keysN[i - 1] = 6;
            } else if (keys[i - 1] == "G") {
                keysN[i - 1] = 7;
            } else if (keys[i - 1] == "C") {
                keysN[i - 1] = 8;
            } else if (keys[i - 1] == "F") {
                keysN[i - 1] = 9;
            } else if (keys[i - 1] == "Bb") {
                keysN[i - 1] = 10;
            } else if (keys[i - 1] == "Eb") {
                keysN[i - 1] = 11;
            } else if (keys[i - 1] == "Ab") {
                keysN[i - 1] = 12;
            } else if (keys[i - 1] == "Db") {
                keysN[i - 1] = 13;
            } else if (keys[i - 1] == "Gb") {
                keysN[i - 1] = 14;
            } else if (keys[i - 1] == "Cb") {
                keysN[i - 1] = 15;
            } else if (keys[i - 1] == "A#m") {
                keysN[i - 1] = 16;
            } else if (keys[i - 1] == "D#m") {
                keysN[i - 1] = 17;
            } else if (keys[i - 1] == "G#m") {
                keysN[i - 1] = 18;
            } else if (keys[i - 1] == "C#m") {
                keysN[i - 1] = 19;
            } else if (keys[i - 1] == "F#m") {
                keysN[i - 1] = 20;
            } else if (keys[i - 1] == "Bm") {
                keysN[i - 1] = 21;
            } else if (keys[i - 1] == "Em") {
                keysN[i - 1] = 22;
            } else if (keys[i - 1] == "Am") {
                keysN[i - 1] = 23;
            } else if (keys[i - 1] == "Dm") {
                keysN[i - 1] = 24;
            } else if (keys[i - 1] == "Gm") {
                keysN[i - 1] = 25;
            } else if (keys[i - 1] == "Cm") {
                keysN[i - 1] = 26;
            } else if (keys[i - 1] == "Fm") {
                keysN[i - 1] = 27;
            } else if (keys[i - 1] == "Bbm") {
                keysN[i - 1] = 28;
            } else if (keys[i - 1] == "Ebm") {
                keysN[i - 1] = 29;
            } else if (keys[i - 1] == "Abm") {
                keysN[i - 1] = 30;
            } else if (keys[i - 1] == "A#") {
                keysN[i - 1] = 31;
            } else if (keys[i - 1] == "B#") {
                keysN[i - 1] = 32;
            } else if (keys[i - 1] == "D#") {
                keysN[i - 1] = 33;
            } else if (keys[i - 1] == "E#") {
                keysN[i - 1] = 34;
            } else if (keys[i - 1] == "Fb") {
                keysN[i - 1] = 35;
            } else if (keys[i - 1] == "G#") {
                keysN[i - 1] = 36;
            } else if (keys[i - 1] == "B#m") {
                keysN[i - 1] = 37;
            } else if (keys[i - 1] == "Cbm") {
                keysN[i - 1] = 38;
            } else if (keys[i - 1] == "Dbm") {
                keysN[i - 1] = 39;
            } else if (keys[i - 1] == "E#m") {
                keysN[i - 1] = 40;
            } else if (keys[i - 1] == "Fbm") {
                keysN[i - 1] = 41;
            } else if (keys[i - 1] == "Gbm") {
                keysN[i - 1] = 42;
            } else {
                keysN[i - 1] = 999999999;
                System.out.printf("error at element %d %s\n", i - 1, keys[i - 1]);
            }
        }
    }

    //prints array 
    public static void printArray(int keysN[]) {
        for (int i = 1; i <= keysN.length; i++) {
            System.out.printf("%d,", keysN[i - 1]);
        }
    }
}
