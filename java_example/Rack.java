import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

/**
   A Rack of Scrabble tiles
 */

public class Rack {
   
   private String sequence;
   //a String contain filtered input, which represents that contant in the Rack.
   
   /**
   Create a Rack object contain the input. Also filter all non-character symbols.
   */
   public Rack(String s){
      s.replaceAll("[^a-zA-Z]", "");
      sequence = s;
      
      
   }
   
   /**
   Return all the subsets of the Rack.
   */
   
   public ArrayList<String> getSubset(){
      Map<Character, Integer> uniqueMap = new TreeMap<Character, Integer>();
      
      for(int i = 0; i < sequence.length(); i++){
         Integer numOccur = uniqueMap.get(sequence.charAt(i));
         if(numOccur != null){
            uniqueMap.put(sequence.charAt(i), numOccur + 1);
         }else{
            uniqueMap.put(sequence.charAt(i), 1);
         }
      }
      int[] multi = new int[uniqueMap.entrySet().size()];
      String unique = "";
      int i = 0;
      for (Map.Entry<Character, Integer> curr : uniqueMap.entrySet()){
         multi[i] = curr.getValue();
         i++;
         unique = unique + curr.getKey();
      }
      return allSubsets(unique, multi, 0);
      
   }

   private static ArrayList<String> allSubsets(String unique, int[] mult, int k) {
      ArrayList<String> allCombos = new ArrayList<>();
      
      if (k == unique.length()) {  // multiset is empty
         allCombos.add("");
         return allCombos;
      }
      
      // get all subsets of the multiset without the first unique char
      ArrayList<String> restCombos = allSubsets(unique, mult, k+1);
      
      // prepend all possible numbers of the first char (i.e., the one at position k) 
      // to the front of each string in restCombos.  Suppose that char is 'a'...
      
      String firstPart = "";          // in outer loop firstPart takes on the values: "", "a", "aa", ...
      for (int n = 0; n <= mult[k]; n++) {   
         for (int i = 0; i < restCombos.size(); i++) {  // for each of the subsets 
                                                        // we found in the recursive call
            // create and add a new string with n 'a's in front of that subset
            allCombos.add(firstPart + restCombos.get(i));  
         }
         firstPart += unique.charAt(k);  // append another instance of 'a' to the first part
      }
      
      return allCombos;
   }

   
}
