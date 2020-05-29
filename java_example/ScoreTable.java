public class ScoreTable{
   
   private int[] table;
   /**
   Array contain the score of each character. The index of the array represent the character: the score of a is in index 0, b is in 1 and z is in 25.
   a, e, i, o, u, l, n, s, t, r have score 1
   d, g have score 2
   b, c, m, p have score 3
   f, h, v, w, y have score 4
   k has score 5
   j, x have score 8
   q, z have score 10
   Both upper and lower case have the same score.
   */
   
   
   //create the ScoreTable object that contains the score table. 
   public ScoreTable(){
      table = new int[26];
      table[0] = 1;   //a
      table[1] = 3;   //b
      table[2] = 3;    //c
      table[3] = 2;    //d
      table[4] = 1;    //e
      table[5] = 4;    //f
      table[6] = 2;    //g
      table[7] = 4;    //h
      table[8] = 1;    //i
      table[9] = 8;    //j
      table[10] = 5;    //k
      table[11] = 1;    //l
      table[12] = 3;    //m
      table[13] = 1;    //n
      table[14] = 1;    //o
      table[15] = 3;    //p
      table[16] = 10;    //q
      table[17] = 1;    //r
      table[18] = 1;    //s
      table[19] = 1;    //t
      table[20] = 1;    //u
      table[21] = 4;    //v
      table[22] = 4;    //w
      table[23] = 8;    //x
      table[24] = 4;    //y
      table[25] = 10;    //z

   }
   
   
   //return the the total score of the String s using the scoretable infomation.
   public int getScore(String s){
      int score = 0;
      s = s.toLowerCase();
      for(int i = 0; i < s.length(); i++){
         int j = s.charAt(i) - 'a';
         score = score + table[j];
      }
      
      return score;
   }
   
}