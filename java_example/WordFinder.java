import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;


public class WordFinder {


   public static void main(String[] args) {
      
      String dictionary;
      if (args.length > 0) {
         dictionary = args[0];
      }else{
         dictionary = "sowpods.txt";
      }
      
      try {
         AnagramDictionary anagram = new AnagramDictionary(dictionary);
         System.out.println("Type . to quit.");
         ScoreTable table = new ScoreTable();
         Scanner in = new Scanner(System.in);
         while(true){
            ArrayList<String> words = new ArrayList<String>();
            System.out.print("Rack? ");
            String input = in.next();
            
            if(input.equals(".")){
               break;
            }
            
            Rack rack = new Rack(input);
            ArrayList<String> sub = rack.getSubset();
            Collections.sort(sub);
            for(int i = 0; i < sub.size(); i++){
               if(anagram.getAnagramsOf(sub.get(i)) != null){
                  words.addAll(anagram.getAnagramsOf(sub.get(i)));
               }
            }
            int numWords = words.size();
            System.out.println("We can make " + numWords + " words from \"" + input + "\"");
            if(numWords>0){
               System.out.println("All of the words with their scores (sorted by score):");
               Collections.sort(words);
               Collections.sort(words, new ScoreComparator());
               
               for(int i = 0; i < numWords; i++){
                  System.out.println(table.getScore(words.get(i)) + ": " +words.get(i));
                  
               }
            }
         }
      }
      catch (FileNotFoundException e) {
         System.out.println("Dictionary file not found.");
      }
   }

}

//An Comparator to compare the string by its score using the infomation in the ScoreTable.
class ScoreComparator implements Comparator<String>{
   
   public int compare(String a, String b){
      ScoreTable table = new ScoreTable();
      return table.getScore(b)-table.getScore(a);
   }
   
}


