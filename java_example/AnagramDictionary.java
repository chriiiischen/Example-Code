import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;
import java.util.Arrays;


public class AnagramDictionary {
   private Map<String, ArrayList<String>> anagram;
   //Map an String to an ArrayList<String>. The ArrayList contain anagrams that can be found in the given dictionary.
   //The String maps to the arraylist is the characters that consist in the arraylist anagram set. The characters are sorted alphabatically. 

   public AnagramDictionary(String fileName) throws FileNotFoundException {
      anagram = new TreeMap<String, ArrayList<String>>();
      File dictionary = new File(fileName);
      Scanner in = new Scanner(dictionary);
      while(in.hasNext()){
         String word = in.next();
         char temp[] = word.toCharArray();
         Arrays.sort(temp);
         String wordSorted = new String(temp);
         if(anagram.containsKey(wordSorted)){
            anagram.get(wordSorted).add(word);
         }else{
            ArrayList<String> list = new ArrayList<String>();
            list.add(word);
            anagram.put(wordSorted, list);
         }
      }
   }
   
   public ArrayList<String> getAnagramsOf(String s) {
      char temp[] = s.toCharArray();
      Arrays.sort(temp);
      String SSorted = new String(temp);
      return anagram.get(SSorted);
   }
   
   
}
