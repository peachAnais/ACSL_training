//SOLITAIRE- WRITTEN BY JEFFERSON S/T JR TEAM
#include <iostream>
#include <cstdio>
#include <deque>
#include <fstream>
#include <string>
   using namespace std;

   int main()
   {
      int N;
      fstream fin("solo.in", ios::in);
   
      for(int acsloop = 1; fin >> N; acsloop++) {
         string t;
         deque<string> piles;
      
         for(int i = 0; i < N; ++i) {
            fin >> t;
            piles.push_back(t);
            size_t last = piles.size()-1;
            while(last >= 1 && ( piles[last][0] == piles[last-1][0] || piles[last][1] == piles[last-1][1] ) ) {
               piles[last-1] = piles[last];
               piles.pop_back();
            	last--;
            }
         }
      
         cout << acsloop << ". ";
         for(size_t i = 0; i < piles.size(); ++i) {
            cout << piles[i] << ' ';
         }
         cout << endl;
      }
      return 0;
   }